void setup() {
  Serial.begin(1200);  /* Define baud rate for serial communication */
  Serial.println("Start Listening...");
}

void loop() {
if(Serial.available())  /* If data is available on serial port */
  {
    Serial.print(char(Serial.read()));  /* Print character received on to the serial monitor */
  }
}
