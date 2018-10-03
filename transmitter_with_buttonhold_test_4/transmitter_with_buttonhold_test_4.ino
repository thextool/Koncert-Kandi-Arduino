#define cr_pin 9
int inPin = 7;  // the pin number for input (for me a push button)
int ledPin = 13; 

int current;         // Current state of the button
                     // (LOW is pressed b/c i'm using the pullup resistors)
long millis_held;    // How long the button was held (milliseconds)
long secs_held;      // How long the button was held (seconds)
long prev_secs_held; // How long the button was held in the previous check
byte previous = HIGH;
unsigned long firstTime; // how long since the button was first pressed 


void setup() {
  Serial.begin(1200);         // Use serial for debugging
  pinMode(ledPin, OUTPUT);
  digitalWrite(inPin, HIGH);  // Turn on 20k pullup resistors to simplify switch input
}

void loop() {
  current = digitalRead(inPin);

  // if the button state changes to pressed, remember the start time 
  if (current == LOW && previous == HIGH && (millis() - firstTime) > 200) {
    firstTime = millis();
  }

  millis_held = (millis() - firstTime);
  secs_held = millis_held / 1000;

  // This if statement is a basic debouncing tool, the button must be pushed for at least
  // 100 milliseconds in a row for it to be considered as a push.
  if (millis_held > 50) {

    // check if the button was released since we last checked
    if (current == HIGH && previous == LOW) {
      // HERE YOU WOULD ADD VARIOUS ACTIONS AND TIMES FOR YOUR OWN CODE
      // ===============================================================================

      // Button held for 1-3 seconds, print out some info
      if (secs_held >= 3) {
        Serial.print("It Works!!! Seconds held: ");
        Serial.print(secs_held);
        Serial.print("   Milliseconds held: ");
        Serial.println(millis_held);
      }
      // ===============================================================================
    }
  }

  previous = current;
  prev_secs_held = secs_held;
}
