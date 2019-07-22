#include <Servo.h>
Servo motorR;
Servo motorL;

void setup() {
  Serial.begin(9600);
  motorR.attach(9);
  motorL.attach(10); 
}

void loop() {
  for(int x = 0; x <= 70; x++) {
    motorR.write(0);
    motorL.write(180);
    Serial.println(x);
    delay(300);
  }
  for(int x = 0; x <= 50; x++) {
    motorR.write(180);
    motorL.write(0);
    Serial.println(x);
    delay(300);
  }
  int x = 4;
  while(x==4) {
    motorL.write(85);
    motorR.write(85);
  }
} 
