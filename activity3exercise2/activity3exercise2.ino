// pins
int buttonPin = 3;
int ledOnePin = 4;
int ledTwoPin = 5;
// delays
int longDelay = 200;
int shortDelay = 5;
// state
bool buttonState = HIGH;

void setup() {
  // initialize led pins as outputs
  pinMode(ledOnePin, OUTPUT);
  pinMode(ledTwoPin, OUTPUT);
  
  // initialize button pin as input
  pinMode(buttonPin, INPUT);

  // initialize interrupt
  attachInterrupt(digitalPinToInterrupt(buttonPin), blink, RISING);
  Serial.begin(9600);
}

void loop() {
    // alternate flashing the two LEDs
    Serial.println(buttonState);
    digitalWrite(ledOnePin, HIGH);
    delay(longDelay);
    digitalWrite(ledOnePin, LOW);
    while(buttonState==LOW)
    {
      delay(shortDelay);
      
    }
    delay(shortDelay); 
    digitalWrite(ledTwoPin, HIGH);
    delay(longDelay);
    digitalWrite(ledTwoPin, LOW);
    while(buttonState==LOW)
    {
      delay(shortDelay);
    }
  
  
}

void blink() {
  buttonState = !buttonState;
  delay(100);
}
