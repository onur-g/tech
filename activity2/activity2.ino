int var = 500; // sets var to 1000
int pin = 3; // sets pin to 3
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(; pin <= 12; pin++) { // for loop - increment pin until it no longer <= 12
    pinMode(pin, OUTPUT); // initialize pin "pin"
    Serial.println(pin); // print which pin is being init
  }
  pin = 3; // set pin back to 3
}

void loop() {
  // put your main code here, to run repeatedly:
  for(; pin <= 12; pin++) { // same for loop as above
    Serial.println(pin);
    digitalWrite(pin, HIGH); // turn on the pin with value "pin"
    delay(var); // wait for "var" ms
    Serial.println(pin);
    digitalWrite(pin, LOW); // turn off the pin with value "pin"
    delay(var); // wait for "var" ms
  }
}
