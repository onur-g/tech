int ledDelay; // LED timeout
int score; // points you get
byte currentLed; // the one that is lit up right now
boolean started; // Are you playing the game?
boolean needNewLed = true; // we need a new LED
byte health = 6; // health remaining
boolean updateScreen=true; // do we need to update the screen?
boolean lostHealth=false; // do we need to subtract one from the health?

int val2,val3,val4,val5;                        // variable for reading the pin status
int buttonState2,buttonState3,buttonState4,buttonState5;                // variable to hold the last button state


void setup() {
  // mode the pins
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  // for showing the score
  Serial.begin(9600);
  Serial.println("+---------------------------------------------------------------+");
  Serial.println("|Welcome to ButtonHero!                                         |");
  Serial.println("|When a light lights up, press the corrisponding button.        |");
  Serial.println("|You lose points by being too slow or pressing the wrong button.|");
  Serial.println("|Press any button to start...                                   |");
  Serial.print("+---------------------------------------------------------------+");
}

void loop() {
  // 
  if (digitalRead(2)==HIGH || digitalRead(3)==HIGH || digitalRead(4)==HIGH || digitalRead(5)==HIGH){
    started=true; //start the game if any button is pressed
  }
  if (started==true){
    if (needNewLed ==true){ //we need another LED
      digitalWrite(currentLed, LOW); // turn off the old one
      byte randomLed = random(9,13); // pick a random LED
      while(currentLed == randomLed){ //make sure it's not the same as the last one
        randomLed = random(9,13); 
      } 
      currentLed = randomLed; 
      digitalWrite(currentLed, HIGH); //light up the new LED
      delay(100); //wait a little bit
      needNewLed = false;
    }

    val2 = digitalRead(2);      // read input value and store it in val
    val3 = digitalRead(3);      // read input value and store it in val
    val4 = digitalRead(4);      // read input value and store it in val
    val5 = digitalRead(5);      // read input value and store it in val

    if (val2 != buttonState2 && val2 == HIGH || val3 != buttonState3 && val3 == HIGH || val4 != buttonState4 && val4 == HIGH || val5 != buttonState5 && val5 == HIGH) {          // the button state has changed!
      if (currentLed == 9 && digitalRead(5) == HIGH){ // did they hit the right button? 
        score++;
        needNewLed = true;
        ledDelay = 0;
        updateScreen=true;
      }
      else if (currentLed == 10 && digitalRead(4) == HIGH){ // did they hit the right button? 
        score++;
        needNewLed = true;
        ledDelay = 0;
        updateScreen=true;
      }
      else if (currentLed == 11 && digitalRead(3) == HIGH){ // did they hit the right button? 
        score++;
        needNewLed = true;
        ledDelay = 0;
        updateScreen=true;
      }
      else if (currentLed == 12 && digitalRead(2) == HIGH){ // did they hit the right button? 
        score++;
        needNewLed = true;
        ledDelay = 0;
        updateScreen=true;
      }
      else if (digitalRead(2)==HIGH || digitalRead(3)==HIGH || digitalRead(4)==HIGH || digitalRead(5)==HIGH) { // did they hit the wrong button? 
        loseHealth();
        lostHealth=true;
      }
    }
    else { // they didnt press anything
      ledDelay++;
      delay(1);
    }

    buttonState2 = val2;                 // save the new state in our variable
    buttonState3 = val3;                 // save the new state in our variable
    buttonState4 = val4;                 // save the new state in our variable
    buttonState5 = val5;                 // save the new state in our variable
    
    // did the LED reach the timeout threshold?
    if (score <= 10){
      if(ledDelay == 1000){
        loseHealth();
        lostHealth=true;
      }
    }
    else if (score <= 15){
      if(ledDelay == 800){
        loseHealth();
        lostHealth=true;
      }
    }
    else if (score <= 20){
      if(ledDelay == 600){
        loseHealth();
        lostHealth=true;
      }
    }
    else if (score <= 25){
      if(ledDelay == 400){
        loseHealth();
        lostHealth=true;
      }
    }
    else if (score <= 30){
      if(ledDelay == 200){
        loseHealth();
        lostHealth=true;
      }
    }
    else if (score > 30){
      if(ledDelay == (220-score)){
        loseHealth();
        lostHealth=true;
      }
    }
    
    // update the display
    if(updateScreen==true){
      Serial.println(' ');
      Serial.println("+---------------------------------------------------------------+");
      Serial.println("|                                                               |");
      Serial.print("| Score: ");
      Serial.print(score);
      if(score<10){
        Serial.println("                                                      |");
      }
      else if(score<100){
        Serial.println("                                                     |");
      }
      else if(score<1000){
        Serial.println("                                                    |");
      }

      if(health==6){
        health=5;
      }

      if(health==5){
        Serial.println("| Lives: <3 <3 <3 <3 <3                                         |");
        Serial.println("|                                                               |");
      }
      else if(health==4){
        Serial.println("| Lives: <3 <3 <3 <3                                            |");
        Serial.println("|                                                               |");
      }
      else if(health==3){
        Serial.println("| Lives: <3 <3 <3                                               |");
        Serial.println("|                                                               |");
      }
      else if(health==2){
        Serial.println("| Lives: <3 <3                                                  |");
        Serial.println("|                                                               |");
      }
      else if(health==1){
        Serial.println("| Lives: <3                                                     |");
        Serial.println("|                                                               |");
      }
      else if(health==0){
        Serial.println("| Lives:                                                        |");
        Serial.println("|                          YOU LOSE!                            |");
        health = 6;
        score = 0;
      }
      Serial.print("+---------------------------------------------------------------+");
      updateScreen=false;
    }
  }
  lostHealth=false;
}

// subtract one health
void loseHealth(){
  if(lostHealth==false){
    health--;
    updateScreen=true;
    needNewLed=true;
    ledDelay = 0;
    if(health <= 0){ // did they lose the game?
      started=false;
      updateScreen=true; 
      // blink 3 times
      digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      delay(200);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      delay(200);
      digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      delay(200);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      delay(200);
      digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12,HIGH);
      delay(200);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
    }
  }
}
