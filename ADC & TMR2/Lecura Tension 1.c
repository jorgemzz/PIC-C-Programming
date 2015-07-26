//Lectura de tension analogica por el canal AN0

   #include <16F877A.h>
   #device adc=10
   #fuses HS,NOWDT,NOPROTECT,PUT,NOBROWNOUT
   #use delay(clock=20000000)
   #include <lcd.c>
   
  void main(void){
   
   int16 q;
   float p;
   
   setup_adc_ports(AN0);
   setup_adc(ADC_CLOCK_INTERNAL);
   
   lcd_init();
   
   for(;;){
      set_adc_channel(0);
      delay_ms(20);
      
      q=read_adc();
      p=5.0*q/1024.0;
      
      printf(lcd_putc,"\fADC=%4ld",q);
      printf(lcd_putc,"\nVoltage=%1.5fv",p);
      
      delay_ms(100);
   }
   
  }
