#include <SoftwareSerial.h>

char data[15];
int i=0;
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  

  Serial.println("Goodnight moon!");

  i=0;
}

void loop() { // run over and over
  if (Serial.available()) {
    Serial.write(Serial.read());

  }
  
}
