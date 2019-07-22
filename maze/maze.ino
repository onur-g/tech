#include <Servo.h>
Servo motorL;
Servo motorR;
int foot = 5000;
void setup() {
  motorL.attach(3);
  motorR.attach(5);
}
void loop() {
  delay(6000);
  forward(7);
  turnRight();
  forward(5);
  turnRight();
  forward(2);
  turnLeft();
  forward(1.5);
  turnRight();
  forward(4);
  motorL.detach();
  motorR.detach();
}
void forward(double x) {
  motorL.write(0);
  motorR.write(180);
  delay(x * foot);
  brake();
}
void back(double x) {
  motorL.write(180);
  motorR.write(0);
  delay(x * foot);
  brake();
}
void turnRight() {
  motorL.write(0);
  motorR.write(0);
  delay(2000);
  brake();
}
void turnLeft() {
  motorL.write(180);
  motorR.write(180);
  delay(2000);
  brake();
}
void brake() {
  motorL.write(90);
  motorR.write(90);
}
