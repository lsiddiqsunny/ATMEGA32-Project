/*
 * SerialTransmissionFromAtmegaToArduino.c
 *
 * Created: 26-May-18 8:07:18 PM
 * Author : Latif Siddiq Sunny
 */ 
 #include <avr/io.h>

 //header to enable data flow control over pins

 #define F_CPU 1000000UL

 //telling controller crystal frequency attached

 #include <util/delay.h>

 //header to enable delay function in program

 void URAT_SETUP(){
 
	UCSRA = 0b00000000;  // Single speed
	UCSRB = 0b00011000;  // Enable Tx and Rx, polling
	UCSRC = 0b10000110;  // Asynchronous mode, no parity, 1 stop bit,8 data bits
 
	UBRRH = 0x00;
	UBRRL = 0x33; // Baud rate 1200bps, assuming 1MHz clock

 }

 char URAT_RECEIVE(){
	while ((UCSRA & (1<<RXC)) == 0x00);// Wait until RXC flag is set to logic 1
	unsigned char ch= UDR;
	return ch;
 }

 void URAT_SEND(char ch){
  while (! (UCSRA & (1 << UDRE)) );// wait until UDRE flag is set to logic 1
  UDR=ch;
  return ;
 }

 int main(void)

 {

 char data[]="hello";
 char nodata[]="bye";
	 DDRB =0x00;//PORTB is set as INPUT
	 DDRA=0xFF;//PORTA is set as OUTPUT
	 while (1)

	 {

		 if (PINB&1)//once button is pressed

		 {
			for(int i=0;i<5;i++){
				 URAT_SEND(data[i]);
			}
			
			_delay_ms(1000);

		 }
		 else{
		
			for(int i=0;i<3;i++){
				URAT_SEND(nodata[i]);
			}
		 
			_delay_ms(1000);
		 }
		unsigned char ch=URAT_RECEIVE();//If received data is 'e' ,then turn on the led
		if(ch=='e'){
			PORTA=1;
			_delay_ms(1000);
		} 
		else 
			PORTA=0;
		 
	}	
	
} 