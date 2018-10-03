#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 1); // RX, TX

void setup() {
  
  mySerial.begin(19200);
  Serial.begin(19200);  /* Define baud rate for serial communication */
  Serial.println("Start Listening...");
}

void loop() {
if(mySerial.available())  /* If data is available on serial port */
  {
    Serial.println(int(mySerial.read()));  /* Print character received on to the serial monitor */
  }
}
