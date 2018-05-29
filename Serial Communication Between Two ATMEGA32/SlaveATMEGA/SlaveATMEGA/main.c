/*
 * SlaveATMEGA.c
 *
 * Created: 29-May-18 12:35:39 PM
 * Author : Latif Siddiq Suuny
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
    /* Replace with your application code */
	DDRA=0xFF;
	DDRB=0x00;
	URAT_SETUP();
	char ch= 0b11110000;
    while (1) 
    {
		if(URAT_RECEIVE()==ch){
			PORTA=~PORTA;
			_delay_ms(200);
		}
		
		/*if(PINB&1){
			URAT_SEND(ch);
			_delay_ms(200);
		}*/
		
    }
}

