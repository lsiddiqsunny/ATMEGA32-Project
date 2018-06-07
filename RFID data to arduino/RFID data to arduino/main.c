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
 
	UCSRA = 0b00000010;  // Double speed
	UCSRB = 0b00011000;  // Enable Tx and Rx, polling
	UCSRC = 0b10000110;  // Asynchronous mode, no parity, 1 stop bit,8 data bits
 
	UBRRH = 0;
	UBRRL = 12; // Baud rate 9600bps, assuming 1MHz clock

 }

 char URAT_RECEIVE(){
	while ((UCSRA & (1<<RXC)) == 0x00);// Wait until RXC flag is set to logic 1
	unsigned char ch= UDR;
	return ch;
 }

 void URAT_SEND(unsigned char ch){
  while (! (UCSRA & (1 << UDRE)) );// wait until UDRE flag is set to logic 1
  UDR=ch;
  return ;
 }

 int main(void)

 {

	 URAT_SETUP();
	 unsigned char var[12];
	 while (1)
	{
	unsigned char c=URAT_RECEIVE();
	 while(c==2){

	 int co=0;
	 while(c!=3 && co!=12){
	   c=URAT_RECEIVE();
	   if(((c<='F' && c>='A')||(c<='9' && c>='0')) && co<12){
			var[co]=c;
			co++;
	   }
	 }
	 for(int i=0;i<12;i++) URAT_SEND(var[i]);
		_delay_ms(1000);

	 }
	 }
		 
		
	
} 