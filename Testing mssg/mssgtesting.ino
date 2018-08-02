#include<SoftwareSerial.h>
SoftwareSerial GPRS(7,8);

unsigned char buffer[64];
int count=0;

void setup() {
GPRS.begin(9600);
Serial.begin(9600);
Serial.write("Hello\n");
}

void loop() {
while(GPRS.available()){
  buffer[count++]=GPRS.read();
  if(count==64)break;
}
Serial.write(buffer,count);
count=0;
for(int i=0;i<64;i++) buffer[i]='\0';

if(Serial.available()){
  byte b=Serial.read();
  Serial.write(b);
  if(b=='*'){
    GPRS.write(0x1a);
  }
  else{
    GPRS.write(b);
  }
}

}
