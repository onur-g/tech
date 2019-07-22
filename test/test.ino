#include <Servo.h>
Servo motorL;
Servo motorR;
int foot = 5000;
void setup() {
  motorL.attach(3);
  motorR.attach(5);
  Serial.begin(9600);
}
void loop() {
  turnLeft();
  brake();
  delay(2000);
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
  motorL.write(180);
  motorR.write(90);
  delay(2000);
  brake();
}
void turnLeft() {
  motorL.write(90);
  motorR.write(180);
  delay(2000);
  brake();
}
void brake() {
  motorL.write(90);
  motorR.write(90);
}
