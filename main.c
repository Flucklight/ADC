#include <16f887.h> //Incluimos la libreria para el PIC16F887
#device ADC = 10
#fuses INTRC_IO, NOWDT, PROTECT, NOLVP, MCLR, NOBROWNOUT //Configuramos los registros del PIC
#use delay(INTERNAL = 4000000) //Configuramos el reloj interno a 4MHz
#include <lcd.c> //Incluimos la libreria de la pantalla LCD

void main(){
   int32 iAdc, voltage, angle; //Declaramos variables
   lcd_init(); //Inicialización de la pantalla LCD
   setup_adc_ports(sAN0); //setup_adc_ports(ALL_ANALOG);
   setup_adc(ADC_CLOCK_INTERNAL); 
   
   while (true){
      iAdc = read_adc();
      voltage = (iAdc * 5) / 1023; //Convierte el valor del ADC a voltaje
      lcd_gotoxy(1, 1); //Mueve el apuntador interno a la 1ra fila
      printf(lcd_putc, "\fVoltaje: %Lu", voltage); //Imprime el valor del voltaje
      angle = (iAdc * 270) / 1023; //Convierte el valor del ADC a grados del angulo
      lcd_gotoxy(1, 2); //Mueve el apuntador interno a la segunda fila
      printf(lcd_putc, "Angulo: %Lu", angle);  //Imprime el valor del ángulo
      delay_ms(100); //Retraso de 100 milisegundos
   }
}
