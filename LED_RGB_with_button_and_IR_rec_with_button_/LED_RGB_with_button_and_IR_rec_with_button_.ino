const int buttonPin = 3;
const int irButtonPin = 2;
const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;
int counter = 0;
bool access2 = false;
int irButtonState = 0;


void setup() {
  Serial.begin(1200);
  pinMode(buttonPin, INPUT);
  pinMode(irButtonPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  
  int irButtonState;
  irButtonState = digitalRead(irButtonPin);
  int buttonState;
  buttonState = digitalRead(buttonPin);

  if (irButtonState == HIGH && Serial.available()) {
      if(char(Serial.read()) == 50) {
        access2 = true;
    }
  } else {
    // turn IR receiver off:
    Serial.end();
  }
  
  if (buttonState == LOW) {
    counter++;
    delay(250);
  }
  
  
  else if (counter == 0) {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
  
  else if (counter == 1) {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
  
  else if (counter == 2) {
    if (access2 == true) {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, LOW);  
    } else {
        counter++;
      }
  }
  
  else if (counter == 3) {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  }
  
  else {
    counter = 0;
  }
  
}
