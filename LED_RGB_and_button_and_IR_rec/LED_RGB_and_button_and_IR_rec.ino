const int buttonPin = 3;
const int redPin1 = 11;
const int greenPin1 = 10;
const int bluePin1 = 9;
const int redPin2 = 8;
const int greenPin2 = 7;
const int bluePin2 = 6;
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
    delay(250);
  }
  
  
  else if (counter == 0) {
    digitalWrite(redPin1, LOW);
    digitalWrite(greenPin1, LOW);
    digitalWrite(bluePin1, LOW);
  }
  
  else if (counter == 1) {
    digitalWrite(bluePin2, HIGH);
    digitalWrite(bluePin1, LOW);
    digitalWrite(redPin1, HIGH);
    delay(1000);
    digitalWrite(greenPin1, HIGH);
    digitalWrite(bluePin1, HIGH);
    delay(1000);
    digitalWrite(greenPin1, LOW);
    digitalWrite(redPin1, LOW);
    digitalWrite(bluePin1, HIGH);
    delay(1000);
  }
  
  else if (counter == 2) {
    if (access2 == true) {
      digitalWrite(redPin1, HIGH);
      digitalWrite(greenPin1, HIGH);
      digitalWrite(bluePin1, HIGH);  
    } else {
        counter++;
      }
  }
  
  else if (counter == 3) {
    digitalWrite(redPin1, LOW);
    digitalWrite(greenPin1, LOW);
    digitalWrite(bluePin1, HIGH);
  }
  
  else {
    counter = 0;
  }
  
}
