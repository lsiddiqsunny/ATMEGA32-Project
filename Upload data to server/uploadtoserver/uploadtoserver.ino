

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>

/* Set these to your desired credentials. */
const char *ssid = "Net Buzz @ Sunny WiFi";  //ENTER YOUR WIFI SETTINGS
const char *password = "01817661097 ";

//Web/Server address to read/write from 
const char *host = "192.168.0.102";   

SoftwareSerial mySerial(12, 13); // RX, TX
char data[15];
int i=0;

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
  mySerial.println("Hello, world?");
  i=0;
}

//=======================================================================
//                    Main Program Loop
//=======================================================================
void loop() {

  if (mySerial.available()) {
    data[i]=mySerial.read();
    
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
  String link=String("http://192.168.0.102/Test/postdemo.php?id=")+data;
  
  http.begin(link);              //Specify request destination
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header

  int httpCode = http.GET();   //Send the request
  String payload = http.getString();    //Get the response payload

 // Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload

  http.end();  //Close connection
  data[0]='\0';
  delay(10000);  //Post Data at every 10 seconds
  }
  Serial.println("No card till now\n");
  delay(10);
 
  
}
//=======================================================================