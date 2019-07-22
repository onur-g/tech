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
  // accelerate from stop values to clockwise values
  for(int x = motorLstop; x <= motorLc; x++) {
    motorL.write(x);
    Serial.println("L: " + x);
  }
  for(int x = motorRstop; x >= motorRc; x--) {
    motorR.write(x);
    Serial.println("R: " + x);
  }
  
  // go forward for footTime
  delay(footTime);

  // detach motors for they are no longer needed
  motorL.detach();
  motorR.detach();
}
