#define SHIFT_DATA 15
#define SHIFT_SRCLK 14
#define SHIFT_RCLK 16
#define EEPROM_D0 2
#define EEPROM_D7 9
#define WRITE_EN 10
#define READ_EN A0

void setAddress(int _addr, bool readEN) {
  shiftOut(SHIFT_DATA, SHIFT_SRCLK, MSBFIRST, (_address >> 8));
  shiftOut(SHIFT_DATA, SHIFT_SRCLK, MSBFIRST, _address);
  digitalWrite(READ_EN, !readEN);

  digitalWrite(SHIFT_RCLK, LOW);
  digitalWrite(SHIFT_RCLK, HIGH);
  digitalWrite(SHIFT_RCLK, LOW);
}


/*
   Read a byte from the EEPROM at the specified address.
*/
byte Read(int address) {
  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin += 1) {
    pinMode(pin, INPUT);
  }
  setAddress(address, true);
  delayMicroseconds(1);
  byte data = 0;
  for (int pin = EEPROM_D7; pin >= EEPROM_D0; pin -= 1) {
    data = (data << 1) + digitalRead(pin);
  }
  return data;
}


/*
   Write a byte to the EEPROM at the specified address.
*/
void Write(int _address, byte data) {
  setAddress(_address, false);
  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin += 1) {
    pinMode(pin, OUTPUT);
  }

  for (int pin = EEPROM_D0; pin <= EEPROM_D7; pin += 1) {
    digitalWrite(pin, data & 1);
    data = data >> 1;
  }
  digitalWrite(WRITE_EN, LOW);
  delayMicroseconds(1);
  digitalWrite(WRITE_EN, HIGH);
  delay(10);
}


/*
   Read the contents of the EEPROM and print them to the serial monitor.
*/
void printContents() {
  for (int base = 0; base <= 255; base += 16) {
    byte data[16];
    for (int offset = 0; offset <= 15; offset += 1) {
      data[offset] = Read(base + offset);
    }

    char buf[80];
    sprintf(buf, "%03x:  %02x %02x %02x %02x %02x %02x %02x %02x   %02x %02x %02x %02x %02x %02x %02x %02x",
            base, data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7],
            data[8], data[9], data[10], data[11], data[12], data[13], data[14], data[15]);

    Serial.println(buf);
  }
}

void setup() {
  pinMode(SHIFT_DATA, OUTPUT);
  pinMode(SHIFT_SRCLK, OUTPUT);
  pinMode(SHIFT_RCLK, OUTPUT);
  digitalWrite(READ_EN, HIGH);
  pinMode(READ_EN, OUTPUT);
  digitalWrite(WRITE_EN, HIGH);
  pinMode(WRITE_EN, OUTPUT);
  Serial.begin(19200);
}

byte serialData[3];
uint8_t dataLength;
uint8_t serialMode = 0;
uint16_t address = 0;
uint8_t writeData = 0;

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
      default:
        address = 0;
        writeData = 0;
        switch (serialData[0]) {
          case 'r':
            serialMode = 1;
            Serial.println("r Reading from EEPROM");
            break;
          case 'w':
            serialMode = 2;
            Serial.println("w Writing to EEPROM");
            break;
          case 'R':
          default:
            serialMode = 0;
            Serial.println("R Printing EEPROM Contents");
            printContents();
            break;
        }
        break;
    }
  }
}
