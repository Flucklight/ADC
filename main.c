#include <16f887.h> //Incluye la biblioteca para el PIC16F887
#device ADC = 10 //Configura el convertidor analógico digital con resolución de 10 bits
#fuses INTRC_IO, NOWDT, PROTECT, NOLVP, MCLR, NOBROWNOUT //Configuramos los registros del PIC
#use delay(INTERNAL = 4000000) //Configura el reloj interno a 4MHz
#include <lcd.c> //Incluye la libreria de la pantalla LCD

void main(){
   int32 iAdc, voltage, angle; //Declaramos variables de 32 bits
   lcd_init(); //Inicialización de la pantalla LCD
   setup_adc_ports(sAN0); //Configura la entrada analógica 0 del microcontrolador
   setup_adc(ADC_CLOCK_INTERNAL); //Configura frecuencia de muestro con reloj interno
   
   while (true){
      iAdc = read_adc(); //Obtiene valor del ADC en ese momento y lo guarda en iADC
      voltage = (iAdc * 5) / 1023; //Convierte el valor del ADC a voltaje
      lcd_gotoxy(1, 1); //Mueve el apuntador interno a la 1ra fila
      printf(lcd_putc, "\fVoltaje: %Lu", voltage); //Imprime el valor del voltaje
      angle = (iAdc * 270) / 1023; //Convierte el valor del ADC a grados del angulo
      lcd_gotoxy(1, 2); //Mueve el apuntador interno a la segunda fila
      printf(lcd_putc, "Angulo: %Lu", angle);  //Imprime el valor del ángulo
      delay_ms(100); //Retraso de 100 milisegundos
   }
}
