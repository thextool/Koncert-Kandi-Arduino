const int buttonPin = 13;
const int redPin1 = 6;
const int greenPin1 = 5;
const int bluePin1 = 4;
const int redPin2 = 9;
const int greenPin2 = 8;
const int bluePin2 = 7;
const int redPin3 = 12;
const int greenPin3 = 11;
const int bluePin3 = 10;

int black[3]  = { 0, 0, 0 };
int white[3]  = { 100, 100, 100 };
int red[3]    = { 100, 0, 0 };
int green[3]  = { 0, 100, 0 };
int blue[3]   = { 0, 0, 100 };
int yellow[3] = { 40, 95, 0 };
int dimWhite[3] = { 30, 30, 30 };

int redVal = black[0];
int grnVal = black[1]; 
int bluVal = black[2];

int wait = 2;      // 10ms internal crossFade delay; increase for slower fades
int hold = 2;       // Optional hold when a color is complete, before the next crossFade
int DEBUG = 1;      // DEBUG counter; if set to 1, will write values back via serial
int loopCount = 60; // How often should DEBUG report?
int repeat = 0;     // How many times should we loop before stopping? (0 for no stop)
int j = 0;          // Loop counter for repeat

int prevR = redVal;
int prevG = grnVal;
int prevB = bluVal;

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
  pinMode(redPin3, OUTPUT);
  pinMode(greenPin3, OUTPUT);
  pinMode(bluePin3, OUTPUT);
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
    crossFade(yellow);
    delay(wait);
    crossFade(white);
    delay(wait);
    crossFade(blue);
    delay(wait);

    if (repeat) { // Do we loop a finite number of times?
      j += 1;
      if ((j >= repeat) || (buttonState == LOW)) { // Are we there yet?
        exit(j);         // If so, stop.
        counter ++;
        delay(500);
      }
    }
  }
  
  else if (counter == 2) {
    if (access2 == true) {
      digitalWrite(bluePin1, LOW);
      digitalWrite(redPin1, HIGH);
      digitalWrite(bluePin2, HIGH);
      digitalWrite(greenPin2, LOW);
      digitalWrite(redPin2, LOW);
      digitalWrite(greenPin3, HIGH);
      digitalWrite(redPin3, HIGH);
      digitalWrite(bluePin3, HIGH);
      delay(1000);
      digitalWrite(greenPin1, HIGH);
      digitalWrite(bluePin1, HIGH);
      digitalWrite(bluePin2, LOW);
      digitalWrite(redPin2, HIGH);
      digitalWrite(greenPin3, LOW);
      digitalWrite(redPin3, LOW);
      delay(1000);
      digitalWrite(greenPin1, LOW);
      digitalWrite(redPin1, LOW);
      digitalWrite(greenPin2, HIGH);
      digitalWrite(bluePin2, HIGH);
      digitalWrite(bluePin3, LOW);
      digitalWrite(redPin3, HIGH);
      delay(1000);
      if(counter != 2) {
        counter++; 
      }
    } else {
        counter++;
      }
  }
  
//  else if (counter == 3) {
//    digitalWrite(redPin1, LOW);
//    digitalWrite(greenPin1, LOW);
//    digitalWrite(bluePin1, HIGH);
//    digitalWrite(bluePin2, LOW);
//    digitalWrite(greenPin2, LOW);
//    digitalWrite(redPin2, LOW);
//  }
  
  else {
    counter = 0;
  }
  
}

int calculateStep(int prevValue, int endValue) {
  int step = endValue - prevValue; // What's the overall gap?
  if (step) {                      // If its non-zero, 
    step = 1020/step;              //   divide by 1020
  } 
  return step;
}

int calculateVal(int step, int val, int i) {

  if ((step) && i % step == 0) { // If step is non-zero and its time to change a value,
    if (step > 0) {              //   increment the value if step is positive...
      val += 1;           
    } 
    else if (step < 0) {         //   ...or decrement it if step is negative
      val -= 1;
    } 
  }
  // Defensive driving: make sure val stays in the range 0-255
  if (val > 255) {
    val = 255;
  } 
  else if (val < 0) {
    val = 0;
  }
  return val;
}

void crossFade(int color[3]) {
  // Convert to 0-255
  int R = (color[0] * 255) / 100;
  int G = (color[1] * 255) / 100;
  int B = (color[2] * 255) / 100;

  int stepR = calculateStep(prevR, R);
  int stepG = calculateStep(prevG, G); 
  int stepB = calculateStep(prevB, B);

  for (int i = 0; i <= 1020; i++) {
    redVal = calculateVal(stepR, redVal, i);
    grnVal = calculateVal(stepG, grnVal, i);
    bluVal = calculateVal(stepB, bluVal, i);

    analogWrite(redPin1, redVal);   // Write current values to LED pins
    analogWrite(greenPin1, grnVal);      
    analogWrite(bluePin1, bluVal);

    delay(wait);

    analogWrite(redPin2, redVal);   // Write current values to LED pins
    analogWrite(greenPin2, grnVal);      
    analogWrite(bluePin2, bluVal);

    delay(wait);

    analogWrite(redPin3, redVal);   // Write current values to LED pins
    analogWrite(greenPin3, grnVal);      
    analogWrite(bluePin3, bluVal);

    delay(wait); // Pause for 'wait' milliseconds before resuming the loop
  }
  // Update current values for next loop
  prevR = redVal; 
  prevG = grnVal; 
  prevB = bluVal;
  delay(hold); // Pause for optional 'wait' milliseconds before resuming the loop
}
