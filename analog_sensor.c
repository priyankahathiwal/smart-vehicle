#include<avr/io.h>
#include<util/delay.h>
 void lcd_init()
 {
   lcd_cmd(0x02);
   lcd_cmd(0x28);
   lcd_cmd(0x0c);
   lcd_cmd(0x06);
   lcd_cmd(0x01);
  }
 void lcd_cmd(int cmd)
  {
    PORTB = cmd & 0xf0;
	PORTB = PORTB + 0x04;
	_delay_ms(1);
	PORTB = PORTB - 0x04;

	PORTB = (cmd<<4)&0xf0;
	PORTB = PORTB + 0x04;
	_delay_ms(1);
	PORTB = PORTB - 0x04;
   }
   
      
 void lcd_data(int data)
  {
    PORTB = data & 0xf0;
	PORTB = PORTB + 0x05;
	_delay_ms(1);
	PORTB = PORTB - 0x04;

	PORTB = (data<<4)&0xf0;
	PORTB = PORTB + 0x05;
	_delay_ms(1);
	PORTB = PORTB - 0x04;
   }

   void lcd_string(char *str)
   {
     int i=0;
     while(str[i]!= '\0')
	 {
	   lcd_data(str[i]);
	   i++;
	  }
	  }

   void lcd_num(int num)
   {
     int a=0;
	 if(num==0)
	 {
	   lcd_data(48);
      }
	  lcd_cmd(0x04);
	  while(num!=0)
	  {
	    a = num%10;
		lcd_data(48+a);
		num = num/10;
    	}
		lcd_cmd(0x06);
	}

	int adc_read(int chnl)
	{
	  ADMUX = 0x40+chnl;
	  ADCSRA = 0xd7;
	  while((ADCSRA & 0x10)==0);
	  return ADC;
	  }

	  int main()
	  {
	    DDRB = 0xff;
		DDRC = 0xff;
		lcd_init();
		_delay_ms(10);
		while(1)
		{
		  int a = adc_read(0);
		  lcd_cmd(0x01);
		  lcd_cmd(0x87);
		  lcd_num(a);
		  if (a>600)
		  {
		   PORTC = 0x01;
		   lcd_cmd(0xc0);
		   lcd_data('A');
		  }
		  else if(a<600)
		  {
		   PORTC = 0x00;
		   lcd_cmd(0xc0);
		   lcd_data('B');
		  }
		  _delay_ms(1000);
		  }
		}
