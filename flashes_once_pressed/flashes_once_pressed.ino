// pin numbers and wait time
const int buttonPin = 2; // the number of the pushbutton pin
const int ledPin1 =  3; // the number of the LED pin
const int ledPin2 = 5; // the number of the second LED pin
const int waitTime = 200; // the wait time in ms

// variable
int buttonState = 0; // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  while(buttonState == LOW) {
    digitalWrite(ledPin1, HIGH);
    delay(waitTime);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    delay(waitTime);
    digitalWrite(ledPin2, LOW);
    if(buttonState == HIGH) {
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
    }
  }
}
