#include <16f887.h>
#device ADC=10
#fuses INTRC_IO,NOWDT,PROTECT,NOLVP,MCLR,NOBROWNOUT
#use delay(INTERNAL=4000000)
#include <lcd.c>

void main()
{
   int16 iAdc;
   int16 angle;
   int16 voltage;
   lcd_init();
   setup_adc_ports(sAN0); //setup_adc_ports(ALL_ANALOG);
   setup_adc(ADC_CLOCK_INTERNAL);
   while (true)
   {
      iAdc=read_adc();
      lcd_gotoxy(1,1);
      printf(lcd_putc,"\fADC");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Valor: %Lu",iAdc);
      delay_ms(500);
      voltage=(iAdc*5)/1023;
      lcd_gotoxy(1,1);
      printf(lcd_putc,"\fVoltaje");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Valor: %Lu",voltage);
      delay_ms(500);
      angle=(iAdc*270)/1023;
      lcd_gotoxy(1,1);
      printf(lcd_putc,"\fAngulo");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Valor: %Lu",angle);
      delay_ms(500);
   }
}
