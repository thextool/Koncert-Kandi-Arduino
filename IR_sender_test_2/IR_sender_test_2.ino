#include <SoftwareSerial.h>
#define cr_pin 9

SoftwareSerial mySerial(0, 1); // RX, TX

void setup() {
  mySerial.begin(19200);  /* Define baud rate for serial communication */
  tone(cr_pin, 38000);  /* For modulation at 38kHz */
}

void loop() {
  int count;
  for(count = 0; count<100; count++)
  {
    mySerial.println(count);
    delay(2000);
  }
}
