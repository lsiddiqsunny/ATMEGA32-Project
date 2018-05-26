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

 

 int main(void)

 {

 char data[]="hello";
 char nodata[]="bye";
	 DDRB =0x00;//PORTB is set as INPUT
	 DDRA=0xFF;
	// DDRD=0xFF;


	UCSRA = 0b00000000;  // double speed
	UCSRB = 0b00011000;  // Enable Tx and Rx, polling
	UCSRC = 0b10000110;  // Async mode, no parity, 1 stop bit, 				8 data bits
	
	UBRRH = 0x00;
	UBRRL = 0x33; // Baud rate 1200bps, assuming 1MHz clock
	
	
	 

	 while (1)

	 {

		 if (PINB&0b00000001)//once button is pressed

		 {

			
			 for(int i=0;i<5;i++){
			 while (! (UCSRA & (1 << UDRE)) );
			 UDR=data[i];
			 }
			
			 _delay_ms(1000);

		 }
		 else{
		
		 for(int i=0;i<3;i++){
			 while (! (UCSRA & (1 << UDRE)) );
			 UDR=nodata[i];
		 }
		 
		 _delay_ms(1000);
		 }

	}	
	
} 