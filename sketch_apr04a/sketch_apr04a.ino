#include <Servo.h>
Servo motorL;
Servo motorR;
void setup() {
  motorL.attach(3);
  motorR.attach(5);
}
void loop() {
  delay(3000);
  motorL.write(0);
  motorR.write(180);
  delay(25000);
  motorL.detach();
  motorR.detach();
}

