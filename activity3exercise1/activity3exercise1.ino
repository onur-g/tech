// pins
int buttonPin = 3;
int ledOnePin =  4;
int ledTwoPin = 5;
// delays
int longDelay = 200;
int shortDelay = 5;
// state
int buttonState = 0;

void setup() {
  // initialize led pins as outputs
  pinMode(ledOnePin, OUTPUT);
  pinMode(ledTwoPin, OUTPUT);
  // initialize button pin as input
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read state of button pin and set button state
  buttonState = digitalRead(buttonPin);

  // if button state is high
  if(buttonState == HIGH) {
    // alternate flashing the two LEDs
    digitalWrite(ledOnePin, HIGH);
    delay(longDelay);
    digitalWrite(ledOnePin, LOW);
    delay(shortDelay);
    digitalWrite(ledTwoPin, HIGH);
    delay(longDelay);
    digitalWrite(ledTwoPin, LOW);
  }
}
