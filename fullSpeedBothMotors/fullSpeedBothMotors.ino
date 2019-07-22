#include <Servo.h>
Servo motorL;
Servo motorR;
void setup() {
  motorL.attach(3);
  motorR.attach(6);
  Serial.begin(9600);
}
void loop() {
  motorL.write(180);
  motorR.write(0);
}
