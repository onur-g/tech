const int red = 7;
const int green = 4;
const int sensor = A1;
boolean x = true;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  int value = analogRead(sensor);
  
  if(value < 250) {
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    Serial.println("covered, green");
  }
  else {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    Serial.println("not covered, red");
  }
}
