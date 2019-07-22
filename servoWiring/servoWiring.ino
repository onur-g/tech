#include <Servo.h>
Servo motorL;
Servo motorR;
void setup() {
  motorL.attach(6);
  motorR.attach(3);
  Serial.begin(9600);
  motorL.write(88);
  motorR.write(87);
}
void loop() {
  for(int x=0; x<=180; x++) {
    motorL.write(x);
    Serial.println(x);
    delay(300);
  }
  motorL.write(88);
  for(int x=0; x<=180; x++) {
    motorR.write(x);
    Serial.println(x);
    delay(300);
  }
  motorR.write(87);
}
