//Lectura de tension analogica por el canal AN0 cada cierto tiempo

   #include <16F877A.h>
   #device adc=10
   #fuses HS,NOWDT,NOPROTECT,PUT,NOBROWNOUT
   #use standard_io(B)
   #use delay(clock=20000000)
   #include <lcd.c>
   
   #int_TIMER2    //cada 1ms el flujo del programa se dirige a esta interrupcion
   void TIMER2_isr(void){
      output_TOGGLE(pin_b0);
      set_timer2(11);
   }
   
  void main(void){
   
   setup_timer_2(T2_DIV_BY_4,124,1);
   enable_interrupts(INT_TIMER2);
   enable_interrupts(global);
   
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
