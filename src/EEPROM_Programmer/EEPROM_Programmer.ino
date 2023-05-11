#define EEPROM_SIZE 8192
/*
 * EEPROM Sizes:
 * 2KB  2048
 * 4KB  4096
 * 8KB  8192
 */
#define SHIFT_DATA 15
#define SHIFT_SRCLK 14
#define SHIFT_RCLK 16
#define EEPROM_D0 2
#define EEPROM_D7 9
#define WRITE_EN A1
#define READ_EN A0
#define ENABLE A2
#define BUSREQ 10
#define BUSACK A3

void setAddress(int _addr, bool readEN) { // Set an address on the ROM
  // Check if the address is not out of range
  if(_addr >= EEPROM_SIZE){_addr = EEPROM_SIZE;}
  // Set the address in the shift registers
  shiftOut(SHIFT_DATA, SHIFT_SRCLK, MSBFIRST, (_addr >> 8));
  shiftOut(SHIFT_DATA, SHIFT_SRCLK, MSBFIRST, _addr);

  // Set the read enable pin
  digitalWrite(READ_EN, !readEN);

  // Put the shift register content on the output
  digitalWrite(SHIFT_RCLK, LOW);
  digitalWrite(SHIFT_RCLK, HIGH);
  digitalWrite(SHIFT_RCLK, LOW);
}

byte Read(int _addr) { // Read a byte from the ROM
  // Set all the data pins for reading
  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin += 1) {
    pinMode(pin, INPUT);
  }
  // Set the address
  setAddress(_addr, true);
  delayMicroseconds(1);
  // Read each bit
  byte data = 0;
  for (int pin = EEPROM_D7; pin >= EEPROM_D0; pin -= 1) {
    data = (data << 1) + digitalRead(pin);
  }
  return data;
}

void Write(int _addr, byte data) { // Write a byte to the ROM
  // Set the address
  setAddress(_addr, false);
  // Set all data pins for writing
  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin += 1) {
    pinMode(pin, OUTPUT);
  }
  // Write each bit
  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin += 1) {
    digitalWrite(pin, data & 1);
    data = data >> 1;
  }
  // Write the entire byte
  digitalWrite(WRITE_EN, LOW);
  delayMicroseconds(1);
  digitalWrite(WRITE_EN, HIGH);
  delay(10);
}

void printContents(int _nBytes) { // Print the entire ROM in a CSV format
  if(_nBytes == 0){
    _nBytes = EEPROM_SIZE;
  }
  for (int base = 0; base <= _nBytes - 1; base += 16) {
    byte data[16];
    for (int offset = 0; offset <= 15; offset += 1) {
      data[offset] = Read(base + offset);
    }

    char buf[80];
    sprintf(buf, "%04x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x",
            base, data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7],
            data[8], data[9], data[10], data[11], data[12], data[13], data[14], data[15]);

    Serial.println(buf);
  }
}

void blockWrite(uint32_t _numBytes) { // Write multiple bytes sequentially from the start of the ROM
  uint32_t n = 0;
  uint8_t dataLength;
  byte _serialData[3];
  while (n < _numBytes) {
    if (Serial.available() > 0) {
      dataLength = Serial.readBytes(_serialData, 3);
      if(_serialData[1] == '\n'){
        Write(n, _serialData[0]);
        Serial.println(String("Written ") + String(_serialData[0], HEX) + String(" to ") + String(n, HEX));
        n++;
      }
    }
  }
  
}

void setup() {
  pinMode(ENABLE, OUTPUT);
  digitalWrite(ENABLE, HIGH);
  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin += 1) {
    pinMode(pin, INPUT);
  }
  
  Serial.begin(115200);
  while(!Serial){} // Wait for a serial connection
  // Request usage of the system bus
  pinMode(BUSACK, INPUT);
  pinMode(BUSREQ, OUTPUT);
  digitalWrite(BUSREQ, LOW);
  delay(100);
  Serial.print("Waiting for the z80 to enter high-impedance state");
  while(digitalRead(BUSACK)){Serial.print(".");delay(500);} // wait until z80 is ready
  Serial.println("");

  // Set up shift register pins
  pinMode(SHIFT_DATA, OUTPUT);
  pinMode(SHIFT_SRCLK, OUTPUT);
  pinMode(SHIFT_RCLK, OUTPUT);

  // Set up enable pins
  digitalWrite(ENABLE, LOW);
  pinMode(READ_EN, OUTPUT);
  digitalWrite(READ_EN, HIGH);
  pinMode(WRITE_EN, OUTPUT);
  digitalWrite(WRITE_EN, HIGH);
  
  Serial.println("For instructions on how to use this tool, see https://github.com/tristanvandeweg/z80/wiki/Programming");
  Serial.println("Ready.");
}

byte serialData[3];
uint8_t dataLength;
uint8_t serialMode = 0;
uint16_t address = 0;
uint8_t writeData = 0;
uint16_t numBytes = 0;

void loop() {
  if (Serial.available() > 0) {
    dataLength = Serial.readBytes(serialData, 3);

    switch (serialMode) {
      case 1:
      case 2:
        if (address == 0 && serialData[0] == 'A') {
          if (dataLength > 1) {
            address = serialData[1] << 8 | serialData[2];
            Serial.println(String("Selected Address: ") + String(address, HEX));
          }
        } else if (serialData[0] == 'R' && serialMode == 1) {
          Serial.println(String("Reading from EEPROM at address: ") + String(address, HEX));
          Serial.println(String(Read(address), HEX));
          address = 0;
          serialMode = 0;
        } else if (writeData == 0 && serialData[0] == 'D') {
          writeData = serialData[1];
          Serial.println(String("Writing Data: ") + String(writeData, HEX));
        } else if (serialData[0] == 'W' && serialMode == 2) {
          Serial.println(String("Writing ") + String(writeData, HEX) + String(" to EEPROM at address: ") + String(address, HEX));
          Write(address, writeData);
          writeData = 0;
          address = 0;
          serialMode = 0;
        } else if (serialData[0] == '0') {
          serialMode = 0;
        }
        break;
      case 3:
        if(numBytes == 0 && serialData[0] == 'B') {
          if(dataLength > 1) {
            numBytes = serialData[1] << 8 | serialData[2];
            Serial.println(String("Bulk writing ") + String(numBytes) + String("bytes"));
            blockWrite(numBytes);
            numBytes = 0;
            serialMode = 0;
          }
        }
        break;
      default:
        address = 0;
        writeData = 0;
        switch (serialData[0]) {
          case 'r':
            serialMode = 1;
            Serial.println("Reading");
            break;
          case 'w':
            serialMode = 2;
            Serial.println("Writing");
            break;
          case 'b':
            serialMode = 3;
            Serial.println("Block writing");
            break;
          case 'R':
          default:
            serialMode = 0;
            Serial.println("Dumping Contents");
            printContents(0);
            break;
        }
        break;
    }
  }
}
