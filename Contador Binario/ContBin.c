#include <16F628A.H>
#fuses HS,NOWDT
#use delay(clock=20000000)

   long time=25;//variable global
   
   //
   void incrementar(void);
   void decrementar(void);
   //

   void main(){
   int i=0;
      while(1){
         for(i=0;i<=15;i++){
            if(input(pin_a0)) incrementar();
            if(input(pin_a1)) decrementar();
            OUTPUT_B(i);
            delay_ms(time*10);
         }
      }
   }
   
   void incrementar(void){
      while(input(pin_a0)&&time<50){
         delay_ms(10);
         time=time+1;
         break;
      }
      return;
   }
   
   void decrementar(void){
      while(input(pin_a1)&&time>2){
         delay_ms(10);
         time=time-1;
         break;
      }
      return;
   }
