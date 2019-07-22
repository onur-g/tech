int var = 1000; // set int variable var to 1000

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  Serial.println(var); // prints var
  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(var);                       // wait for var's value
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  delay(var); // wait for var's value
  var = var * 0.99; // multiply var by 0.9
}
