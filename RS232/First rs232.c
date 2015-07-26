#include "16f877a.h"
#use delay(clock=20000000)
#use  rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7, bits=8, parity=N)

void main () {
   char acap='A';
   delay_ms(1000);
   putc(254);putc(1);
   delay_ms(10);
   while(1){
      putc(acap);
      putc(254); putc(192); delay_ms(10);
      //printf("ASCII %c CHAR %d",acap,acap);
      printf("hola");
      while(1);
   }
}
