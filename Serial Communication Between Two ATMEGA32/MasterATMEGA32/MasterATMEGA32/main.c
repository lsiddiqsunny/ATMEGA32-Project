#ifndef F_CPU
#define F_CPU 1000000UL // 16 MHz clock speed
#endif
#define D4 eS_PORTD4
#define D5 eS_PORTD5
#define D6 eS_PORTD6
#define D7 eS_PORTD7
#define RS eS_PORTC6
#define EN eS_PORTC7

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h" //Can be download from the bottom of this article
char str[15];
	int i=0;
void URAT_SETUP(){
	
	UCSRA = 0b00000010;  // Single speed
	UCSRB = 0b00011000;  // Enable Tx and Rx, polling
	UCSRC = 0b10000110;  // Asynchronous mode, no parity, 1 stop bit,8 data bits
	
	UBRRH = 0x00;
	UBRRL = 12; // Baud rate 1200bps, assuming 1MHz clock

}

char URAT_RECEIVE(){
	while ((UCSRA & (1<<RXC)) == 0x00);// Wait until RXC flag is set to logic 1
	  char ch= UDR;
	 str[i]=ch;
	// Lcd4_Write_Char(ch);
	return ch;
}
void invalid(){
Lcd4_Set_Cursor(1,1);
Lcd4_Clear();
Lcd4_Write_String("Invalid card!");
	_delay_ms(1000);
	Lcd4_Set_Cursor(1,1);
	Lcd4_Clear();
	Lcd4_Write_String("Enter card,pls!");
}

int main(void)
{
	DDRD = 0xFF;
	DDRC = 0xFF;
	URAT_SETUP();
	Lcd4_Init();
	Lcd4_Set_Cursor(1,1);
	Lcd4_Clear();
	Lcd4_Write_String("Enter card,pls!");
	int ok=0;
	while(1)
	{	if(ok==0){
		if(URAT_RECEIVE()=='n'){
		if(URAT_RECEIVE()=='u'){
		if(URAT_RECEIVE()=='m'){
			ok=1;i=0;
			
		}else{
		invalid();
	
	}
		}
		else{
		invalid();
		}
		}
		
		/*invalid();
		_delay_ms(5000);
		Lcd4_Set_Cursor(1,1);
		Lcd4_Clear();
		Lcd4_Write_String("Enter card,pls!");*/
		}
		if(ok){
			URAT_RECEIVE();
			i++;
		}
		
		if(i==12){
		str[i]='\0';
		Lcd4_Set_Cursor(1,1);
		Lcd4_Clear();
		if(str[0]=='0'){
		Lcd4_Write_String("Not enough bal!");
		}
		else{
		Lcd4_Write_String("Ticket confirmed!");
		}
		//Lcd4_Write_String(str);
		i=0; 
		_delay_ms(5000);
		Lcd4_Set_Cursor(1,1);
		Lcd4_Clear();
		Lcd4_Write_String("Enter card,pls!");
		str[i]='\0';
		ok=0;
		}
	}
}
