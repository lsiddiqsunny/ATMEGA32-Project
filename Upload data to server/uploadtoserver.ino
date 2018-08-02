

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>

/* Set these to your desired credentials. */
const char *ssid = "Sunny";  //ENTER YOUR WIFI SETTINGS
const char *password = "sunnysunny";

//Web/Server address to read/write from 
const char *host = "192.168.43.58";   

SoftwareSerial mySerial(12, 13); // RX, TX
char data[15];
int i=0;
int flag=0;

void setup() {
  delay(1000);
  Serial.begin(115200);
  WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
  delay(1000);
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");

  Serial.print("Connecting");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
  mySerial.begin(9600);
  i=0;
}

//=======================================================================
//                    Main Program Loop
//=======================================================================
void loop() {
  if (mySerial.available()) {
    data[i]=mySerial.read();
    Serial.write(data[i]);
    i++;
    if(i==1 && data[0]!=2){
      i--;
    }
    
  }
  if(i==14){
    for(int i=1;i<=12;i++){
      data[i-1]=data[i];
    }
    data[12]='\0';
   // data[13]='\0';
   
  i=0;
  HTTPClient http;    //Declare object of class HTTPClient

  String postData;
  String link=String("http://192.168.43.58/Test/postdemo.php?id=")+data;
  
  http.begin(link);              //Specify request destination
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header

  int httpCode = http.GET();   //Send the request
  String payload = http.getString();    //Get the response payload
 // Serial.println(payload); 
  if(payload.length()==0){
  mySerial.write('n');    //Print request response payload
  mySerial.write('o');  
  mySerial.write('t');  
     mySerial.println("\nNOT A VALID CARD.\nTRY AGAIN.\n");    
  }
  if(payload.length()==15){
    for(int i=0;i<payload.length();i++){
  mySerial.write(payload[i]);    //Print request response payload
    delay(10);
    }
  Serial.println(payload);    //Print request response payload
  }else{
  mySerial.write('n');    //Print request response payload
  mySerial.write('o');  
  mySerial.write('t');  
  Serial.println("\nNOT A VALID CARD.\nTRY AGAIN.\n");    

  }
  http.end();  //Close connection
  data[0]='\0';
  delay(5000);  //Post Data at every 10 seconds
  }
  //Serial.println("No card till now\n");
 // delay(10);
 
  
}
//=======================================================================
