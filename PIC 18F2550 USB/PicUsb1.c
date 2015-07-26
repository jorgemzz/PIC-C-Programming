#include <18F2550.h>
#device adc=10
#fuses HSPLL,NOWDT,NOPROTECT,NOLVP,NODEBUG,USBDIV,PLL5,CPUDIV1,VREGEN
#use delay(clock=48000000)
#use rs232(baud=9600,xmit=pin_c1,rcv=pin_c2,force_sw)

 #define USB_CON_SENSE_PIN PIN_A2

 #include <usb_cdc.h>
 #include <lcd.c>
 #include <string.h>


void main() {
   BYTE i, j, address, value;
   int valor,indicador;
   
   int16 q,q1;
   float p;
   char comando,comBorrado;
   comBorrado="z";

   q1=0;
   
   setup_adc_ports(AN0|VSS_VDD);
   setup_adc(ADC_CLOCK_INTERNAL);
   set_adc_channel(0);

   usb_cdc_init();
   usb_init();
   lcd_init();
   delay_ms(50);
   printf(lcd_putc,"PicUsb(FIS UNCP)\n");
   delay_ms(50);

//      while(!usb_cdc_connected()) {}

   do {
      usb_task();
      if (usb_enumerated()) {
      
      if(usb_cdc_kbhit()){             //hay un caracter esperando en el buffer
         comando=usb_cdc_getc();       //lee el caracter
         indicador=strcmp(comando,comBorrado);
         if (indicador==0){
            printf(lcd_putc,"\f");
            printf(lcd_putc,"PicUsb(FIS UNCP)\n");
         }else{
            //delay_ms(5);
            printf(lcd_putc,"%c",comando);
         }
                    
         }

      //delay_ms(500);
      //q = read_adc();
      //if (q!=q1){
      //p = 5.0 * q / 1024.0;
      //printf(usb_cdc_putc,"\r Voltaje=%01.2fV", p);
      //printf(lcd_putc,"\fVoltaje");
      //printf(lcd_putc,"\n%1.4fV",p);
      //}
      //q1=q;
   }
      } while (TRUE);
}
