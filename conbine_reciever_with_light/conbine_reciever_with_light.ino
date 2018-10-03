bool access2 = false;


void setup() {
  Serial.begin(1200);  /* Define baud rate for serial communication */
  Serial.println("Start Listening...");
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
    delay(5000);
  }
}
