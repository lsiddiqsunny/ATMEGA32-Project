#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>

const char* ssid = "Net Buzz @ Sunny WiFi";
const char* password = "01817661097 ";

SoftwareSerial mySerial(12, 13); // RX, TX
char data[15];
int i=0;
int ledPin = 13; // GPIO13
WiFiServer server(80);

 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
  i=0;
 
}
 
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
    data[12]='\n';
    data[13]='\0';
   // Serial.write(data);
    i=0;
  }
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 

 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("RFID Data : ");
  if(strlen(data)<13)
    client.println("No data");
  else  
  client.println(data);

  client.println("<br><br>");
 
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
 
