#define sr 15
#define srclk 14
#define rclk 15
#define we 10
#define oe A0

#define D0 2
#define D1 3
#define D2 4
#define D3 5
#define D4 6
#define D5 7
#define D6 8
#define D7 9

void setup() {

  // put your setup code here, to run once:
  pinMode(sr, OUTPUT);
  pinMode(srclk, OUTPUT);
  pinMode(rclk, OUTPUT);
  pinMode(we, OUTPUT);
  pinMode(oe, OUTPUT);
  digitalWrite(we, HIGH);
  digitalWrite(oe, HIGH);
  Serial.begin(19200);
  for (int i = 1; i < 10; i++) {
    pinMode(i, OUTPUT);
  }
  /*for (int i = 0; i <= 16; i++) {
    if (i == 0) {
      digitalWrite(srclk, LOW);
      digitalWrite(sr, HIGH);
      digitalWrite(srclk, HIGH);
    } else {
      digitalWrite(srclk, LOW);
      digitalWrite(sr, LOW);
      digitalWrite(srclk, HIGH);
    //}*/
  //}
  digitalWrite(srclk, LOW);
  shiftOut(sr, srclk, MSBFIRST, 0b00000000);
  shiftOut(sr, srclk, MSBFIRST, 0b00000000);

  digitalWrite(rclk, LOW);
  digitalWrite(rclk, HIGH);
  digitalWrite(rclk, LOW);

  delay(1000);
  Serial.println("Writing");

  digitalWrite(oe, HIGH);
  digitalWrite(we, LOW);
  delay(1);
  digitalWrite(D0, 0);
  digitalWrite(D1, 1);
  digitalWrite(D2, 0);
  digitalWrite(D3, 1);
  digitalWrite(D4, 0);
  digitalWrite(D5, 1);
  digitalWrite(D6, 0);
  digitalWrite(D7, 1);

  delay(1000);
  digitalWrite(we, HIGH);
  Serial.println("Written");


  //digitalWrite(sr, LOW);
  delay(5000);
  Serial.println("Reading");
  for (int i = 2; i < 9; i++) {
    pinMode(i, INPUT);
  }
  /*digitalWrite(srclk, LOW);
    shiftOut(sr, srclk, MSBFIRST, 0b00000000);
    shiftOut(sr, srclk, MSBFIRST, 0b00000000);
    digitalWrite(rclk, LOW);
    digitalWrite(rclk, HIGH);
    digitalWrite(rclk, LOW);*/
  digitalWrite(oe, LOW);
  delay(100);
  //delay(5000);
  Serial.println(digitalRead(D0));
  Serial.println(digitalRead(D1));
  Serial.println(digitalRead(D2));
  Serial.println(digitalRead(D3));
  Serial.println(digitalRead(D4));
  Serial.println(digitalRead(D5));
  Serial.println(digitalRead(D6));
  Serial.println(digitalRead(D7));
}

void loop() {
  // put your main code here, to run repeatedly:

}
