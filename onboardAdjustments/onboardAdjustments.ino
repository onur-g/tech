#include <Servo.h>

Servo motorL;
Servo motorR;

int footTime = 640;
int motorLstop = 88;
int motorRstop = 87;
int motorLc = 180;
int motorRc = 0;
int motorLcc = 0;
int motorRcc = 180;

void setup() {
  motorL.attach(5);
  motorR.attach(3);
  motorL.write(motorLstop);
  motorR.write(motorRstop);
}

void loop() {
  
}
