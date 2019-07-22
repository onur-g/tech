char var = 8 * 11; // sets an integer variable var to the product of 8 * 11 (changed to various datatypes from int for #9)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello, this is a message from the great beyond!"); // prints the message
  Serial.println("What's 7 * 11?"); // ditto ("" taken out for #3)
  Serial.print("The answer is:"); // ditto
  delay(1000); // makes the program wait for 1000 ms
  Serial.println(7 * 11); // prints the product of  7 and 11 (changed to BINary and HEXadecimal for #5)
  

  var = var * 10;
  
  Serial.println(var); // prints the int variable var
  delay(var); // delays the program for the value of var in ms
}
