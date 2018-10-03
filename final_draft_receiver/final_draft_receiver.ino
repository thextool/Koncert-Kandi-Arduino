const int buttonPin = 13;
const int redPin1 = 6;
const int greenPin1 = 5;
const int bluePin1 = 4;
const int redPin2 = 9;
const int greenPin2 = 8;
const int bluePin2 = 7;

int counter = 0;
bool access2 = false;

void setup() {
  Serial.begin(1200);
  pinMode(buttonPin, INPUT);
  pinMode(redPin1, OUTPUT);
  pinMode(greenPin1, OUTPUT);
  pinMode(bluePin1, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(bluePin2, OUTPUT);
}

void loop() {
  if(Serial.available())  /* If data is available on serial port */
  {
    /*Serial.print(char(Serial.read()));*/
    /*Serial.print("-");*/
    if(char(Serial.read()) == 50) {
      access2 = true;
      Serial.println(access2);/* Print character received on to the serial monitor */
    }
  }
  int buttonState;
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW) {
    counter++;
    delay(300);
  }
  
  
  else if (counter == 0) {
    digitalWrite(redPin1, LOW);
    digitalWrite(greenPin1, LOW);
    digitalWrite(bluePin1, LOW);
    digitalWrite(bluePin2, LOW);
    digitalWrite(greenPin2, LOW);
    digitalWrite(redPin2, LOW);
    digitalWrite(bluePin3, LOW);
    digitalWrite(greenPin3, LOW);
    digitalWrite(redPin3, LOW);
  }
  
  else if (counter == 1) {
    digitalWrite(bluePin1, HIGH);
    digitalWrite(redPin1, HIGH);
    delay(500);
    digitalWrite(bluePin2, HIGH);
    digitalWrite(greenPin2, HIGH);
    delay(500);
    digitalWrite(bluePin1, LOW);
    digitalWrite(redPin1, LOW);
    delay(500);
    digitalWrite(bluePin2, LOW);
    digitalWrite(greenPin2, LOW);
  }
  
  else if (counter == 2) {
    if (access2 == true) {
      digitalWrite(bluePin1, LOW);
      digitalWrite(redPin1, HIGH);
      digitalWrite(bluePin2, HIGH);
      digitalWrite(greenPin2, LOW);
      digitalWrite(redPin2, LOW);
      delay(1000);
      digitalWrite(greenPin1, HIGH);
      digitalWrite(bluePin1, HIGH);
      digitalWrite(bluePin2, LOW);
      digitalWrite(redPin2, HIGH);
      delay(1000);
      digitalWrite(greenPin1, LOW);
      digitalWrite(redPin1, LOW);
      digitalWrite(greenPin2, HIGH);
      digitalWrite(bluePin2, HIGH);
      delay(1000);
      if(counter != 2) {
        counter++; 
      }
    } else {
        counter++;
      }
  }
    
  else {
    counter = 0;
  }
  
}
