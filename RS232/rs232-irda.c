// ir_capture ANSONIC SDG-20H (TDT) with NEC-32 Protocol
//
#include "16f877a.h"
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=20000000)
#use  rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7, bits=8, parity=N)

const char Version[]="1.0.H\0";

const int total_bits=32;
const int total_bytes=4;

char sbits[total_bits];
int1 first_ext=0;
int1 start_recived=0;
int i,j,k,cte=0;
long tt,tti,t;
int ntbits=0;
int1 hay_dato=0;
char sbit1;
int bits[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
int bytes[total_bytes]={0x00,0x00,0x00,0x00};

void limpia_bits(void);

// INTERRUPCION por RECEPCION SERIE -------------------------------------------

#int_rda
void serial_isr() {
  if(kbhit()){
    putchar(getc());
  }
}

// INTERRUPCION EXT por RB0 --------------------------------------------------

#int_ext
void ext_isr() {

 // Obtengo datos de Timer0
  
  
  if (pin_c1==1)  { output_low(pin_c1);
  }
  else{
   output_high(pin_c1);
  }
  /*tt = get_timer0();
  if (tt < tti){
   t = tt-tti+255;
   tti= tt;
  }
  else{
   t = tt-tti;
   tti= tt;
  }

  // Si he recibido el Start Bit puedo guardar
  if(start_recived==1){
    // Bit "0"
    if(t>40 && t<50){ sbits[ntbits]='0'; }
    // Bit "1"
    if(t>85 && t<90){ sbits[ntbits]='1'; }
    // Si he recibido 32 bits entonces hay dato
    if(++ntbits==total_bits){
      hay_dato=1;
    }
  }

  // Detecto Start Bit
  if(t>300 && t<700){
    start_recived=1;
    limpia_bits();
    printf("bit de inicio recibido");
  }
  */
  
}

//-----------------------------------------------------------------------------

void flash_porte(void){

  for(i=0;i<3;i++){
    output_e(0x07);
    delay_ms(75);
    output_e(0x00);
    delay_ms(75);
  }
}

void limpia_bits(void){

  for(i=0;i<total_bits;++i){
    sbits[i]='\0';
  }
  ntbits=0;
}

void convierte_bits_a_bytes(void){

  for(i=0;i<4;++i){
    Bytes[i]=0x00;
    for(j=0;j<8;++j){
      if(sbits[(i*8)+j]=='1'){
        bytes[i]=bytes[i]|Bits[j];
      }
    }
  }
}

void muestra_bits(void){

  printf("\r\nPULSO RECIBIDO -----------------------\r\n");

  for(i=0;i<4;++i){
    printf("Byte %u = ",i+1);
    for(k=0;k<2;++k){
      if(k==1){
        printf("%2u ",i+1);
      }
      for(j=0;j<8;++j){
        switch(k){
          case 0: printf("%2u ",(i*8)+j+1);
                  break;
          case 1: printf("%2c ",sbits[(i*8)+j]);
                  break;
        }
      }
      if(k==0){ printf("\r\n"); }
    }
    printf(" Valor = %u\r\n",Bytes[i]);
  }
  printf("Address = %u Command = %u\r\n",Bytes[0],Bytes[2]);

  ntbits=0;
}

void main() {

  //disable_interrupts(global);
  setup_adc_ports(NO_ANALOGS);
  setup_adc(ADC_OFF);
  setup_spi(FALSE);
  setup_psp(PSP_DISABLED);
  setup_counters(RTCC_INTERNAL,RTCC_DIV_2);
  setup_timer_1(T1_INTERNAL | T1_DIV_BY_1);
  setup_timer_2(T2_DISABLED,0,1);
 // setup_timer_3(T3_DISABLED);
  setup_comparator(NC_NC_NC_NC);
  setup_vref(FALSE);
  port_b_pullups(FALSE);

  setup_timer_0(RTCC_INTERNAL | RTCC_DIV_128);

  set_tris_b(0b00000001);
  set_tris_c(0b10000000);
  set_tris_e(0b00010000);
  output_e(0x00);

  delay_ms(500);
  printf("\r\n");
  printf("[PIC TRAINER 2.0] IR TSOP1738 Reader-Decoder version %s\r\n",version);
  printf("for JORGE MIRANDA ZARATE SDG-20H (TDT) with NEC-32 Protocol\r\n\n");
  flash_porte();

  ext_int_edge(H_TO_L);
  first_ext=0;
  start_recived=0;
  hay_dato=0;

  limpia_bits();

  enable_interrupts(int_rda);
  enable_interrupts(int_ext);
  enable_interrupts(global);

  do {

    if(hay_dato==1){
       hay_dato=0;
       convierte_bits_a_bytes();
       muestra_bits();
       limpia_bits();
    }

  } while (TRUE);
}

