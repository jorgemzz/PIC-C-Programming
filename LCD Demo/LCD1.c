#include <16F877A.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=20000000)
#include <lcd.c>
void main() {
char k;
int desp=0b00011100;//el driver TS1620A-17 DIFIERE CON EL HITACHI en el bit de desplazamiento left right(tercer bit)
int i;
lcd_init();
lcd_putc("\f Jorge Luis Miranda Zarate \n");
lcd_putc("Ejemplo LCD en CCS C");
//lcd_gotoxy(1,1);
//lcd_putc("Jorge");
while(1) {
for (i=0;i<16;i++){
   lcd_send_byte(0, desp);
   delay_ms(400);
   }
   //lcd_putc("\b");
}

//lcd_send_byte(0, desp);
//lcd_send_byte(0, desp);


//lcd_putc("\f");
//lcd_output_rs(0);
//lcd_output_rw(0);
}
