int x = 10;
void setup() {
  pinMode(8, OUTPUT);
}

void loop() {
  digitalWrite(8, HIGH);
  delayMicroseconds(x);
  digitalWrite(8, LOW);
  delayMicroseconds(1000 - x);
}

// Turns LED on for the value of x microseconds then off for 1000 minus x microseconds
// Turns the LED on and off so fast that the voltage never drops down to 0 which leads to this buildup of energy and brightening without fully turning off
