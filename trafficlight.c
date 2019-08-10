#include<avr/io.h>
#include<util/delay.h>
int main()
{
 DDRC = 0xff;
 DDRD = 0xff;
  while(1)
  {
    PORTC = 0x54;
	PORTD = 0x02;
	_delay_ms(2000);

   	PORTC = 0xa1;
	PORTD = 0x02;
	_delay_ms(2000);
	
    PORTC = 0x09;
	PORTD = 0x05;
	_delay_ms(2000);
	
    PORTC = 0x4a;
	PORTD = 0x08;
	_delay_ms(2000);
	}
}
  
  
