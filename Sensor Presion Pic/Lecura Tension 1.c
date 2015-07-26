//Lectura de tension analogica por el canal AN0

   #include <18f2550.h>
   #device adc=10
   #fuses HS,NOWDT,NOPROTECT,PUT,NOBROWNOUT
   #use delay(clock=4000000)
   #include <lcd.c>
   
  void main(void){
   
   int16 q;
   float p;
   float t;
   float r;
   
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(AN0);
   //setup_adc_ports(AN0_VREF_VREF);
   set_adc_channel(0);
   lcd_init();
   
   for(;;){
      //set_adc_channel(0);
      delay_ms(200);
      
      q=read_adc();
      p=5*q/1024.0;
      t=p*100;
      r=220*p/(5-p);
      
      //printf(lcd_putc,"\fADC=%4ld",q);
      //printf(lcd_putc,"\nV = %1.4fV",p);
      printf(lcd_putc,"\fV = %1.4fV",p);
      printf(lcd_putc,"\nR = %1.4fohm",r);
      //printf(lcd_putc,"\nTemp=%1.5fv",t);
      
      delay_ms(200);
   }
   
  }
