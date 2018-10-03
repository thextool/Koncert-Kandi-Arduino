#define cr_pin 3
const int buttonPin = 2;
const int redPin1 = 13;
const int greenPin1 = 12;
const int bluePin1 = 11;
const int redPin2 = 9;
const int greenPin2 = 6;
const int bluePin2 = 5;

int counter = 0;
bool access1 = false;
int buttonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(cr_pin, OUTPUT);
  pinMode(redPin1, OUTPUT);
  pinMode(greenPin1, OUTPUT);
  pinMode(bluePin1, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(bluePin2, OUTPUT);
  Serial.begin(1200);  /* Define baud rate for serial communication */
  tone(cr_pin, 38000);  /* For modulation at 38kHz */
}

void loop() {
  buttonState = digitalRead(buttonPin);
   if (buttonState == HIGH) {
    // turn IR on:
    digitalWrite(cr_pin, HIGH);
    Serial.println(2);
    delay(2000);
  } else {
    // turn IR off:
    digitalWrite(cr_pin, LOW);
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
  }
}
