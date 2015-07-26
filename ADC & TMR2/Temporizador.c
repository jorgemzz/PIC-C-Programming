//Programa de un temporizador, permite temporizar tiempos en milisegundos desde 50ms a mas

   #include <16F877A.h>
   #fuses HS,NOWDT,NOPROTECT,PUT,NOBROWNOUT
   #use delay(clock=20000000)
   #include <lcd.c>
   
   unsigned int16 t=500;
   
   //
   void incrementar(void);
   void decrementar(void);
   void temporizar(unsigned int16 t);
   //
   
   void main(void){
      
      lcd_init();
      
      while(TRUE){
         if(input(pin_b0)) incrementar();
         if(input(pin_b1)) decrementar();
         if(input(pin_b2)) temporizar(t);
         
         printf(lcd_putc,"\fTiempo=%4Lums",t);
         delay_ms(100);
      }
   
   }
   
   void temporizar(unsigned int16 t){
   //salidas de la temporizacion por el PORTB
   while(TRUE){
      printf(lcd_putc,"\fTemporizar??");
      printf(lcd_putc,"\n  [SI]    [NO]  ");
      delay_ms(50);
      if(input(pin_b1)){
         printf(lcd_putc,"\f  INICIADO...!  ");
         output_high(pin_b7);
         delay_ms(t);
         output_low(pin_b7);
         printf(lcd_putc,"\f      FIN   !   ");
         delay_ms(500);
         break;
      }
      if(input(pin_b0)){
         printf(lcd_putc,"\f   CANCELADO!   ");
         delay_ms(500);
         break;
      }
   }
   
   
   }
   
   void incrementar(void){
   int i=0;//la variable i sirve para incrementar la velocidad de aumento
   inicio:
      while(input(pin_b0)&&t<5000){
         while(i<10){
         i++;
         t++;
         printf(lcd_putc,"\fTiempo=%4Lums",t);
         delay_ms(200);
         goto inicio;
         }
         while(i<50){
         i++;
         t++;
         printf(lcd_putc,"\fTiempo=%4Lums",t);
         delay_ms(100);
         goto inicio;
         }
         t++;
         printf(lcd_putc,"\fTiempo=%4Lums",t);
         delay_ms(10);
      }
   }
   
   void decrementar(void){
   int i=0;//la variable i sirve para incrementar la velocidad de aumento
   inicio:
      while(input(pin_b1)&&t>50){
         while(i<10){
         i++;
         t--;
         printf(lcd_putc,"\fTiempo=%4Lums",t);
         delay_ms(200);
         goto inicio;
         }
         while(i<50){
         i++;
         t--;
         printf(lcd_putc,"\fTiempo=%4Lums",t);
         delay_ms(100);
         goto inicio;
         }
         t--;
         printf(lcd_putc,"\fTiempo=%4Lums",t);
         delay_ms(10);
      }
   }
