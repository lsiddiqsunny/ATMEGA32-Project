#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX
char data[15];
int i=0;
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
  i=0;
}

void loop() { // run over and over
  if (mySerial.available()) {
    data[i]=mySerial.read();
    i++;
  }
  if(i==14){
    data[13]='\n';
    data[14]='\0';
    Serial.write(data);
    i=0;
  }
}
