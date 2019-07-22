void setup() {
  // put your setup code here, to run once:
  pinMode(3, INPUT);
  Serial.begin(9600);
  Serial.print("will it work?");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(3)==HIGH) {
    Serial.println("it works");
  }
}
