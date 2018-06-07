unsigned receiveddata =0;

void setup()

{

                Serial.begin(9600);//serial data rate is set for 19200BPS

                pinMode(0,INPUT);//RXD pin is set for INPUT

                pinMode(1,OUTPUT);

                Serial.println("starting at 9600");
             //   pinMode(7,OUTPUT);//PIN1,PIN7 are set for output

               

}

void loop()

{
               //  
                if (Serial.available() > 0){ //if data received is available
                                receiveddata = Serial.read();//read serial data available
                                Serial.println((char)receiveddata);
                               // Serial.write(receiveddata);//send received data
                             
                             
                                

                }

}
