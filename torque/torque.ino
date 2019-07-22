#include <Servo.h>
Servo motorL;
Servo motorR;
int foot = 5000;
void setup() {
  motorL.attach(3);
  motorR.attach(5);
}
void loop() {
  delay(10000);
  forward(2.5);
  motorL.detach();
  motorR.detach();
}
void forward(double x) {
  motorL.write(0);
  motorR.write(180);
  delay(x * foot);
  motorL.write(90);
  motorR.write(90);
}
