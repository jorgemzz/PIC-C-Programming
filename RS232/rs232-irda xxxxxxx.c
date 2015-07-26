// ir_capture ANSONIC SDG-20H (TDT) with NEC-32 Protocol
//
#include "16f877a.h"
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=20000000)
#use  rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7, bits=8, parity=N)

const char Version[]="1.0.H\0";

const int total_bits=32;
const int total_bytes=4;
long Timer1Values[40];
int Timer0Values[40];
char sbits[total_bits];
int1 first_ext=0;
int1 start_recived=0;
int i,j,k,cte,cc=0;
long tt,tti,t,ti;
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

  // Obtengo datos de Timer1
  tt = get_timer1();
   //t =tt-tti;
   //tti= tt;

    Timer1Values[cte]=tt;
    if (cte==39){
      hay_dato=1;
    }
     cte++;  
  //printf(" TMR1 = %Lu  Long=%Lu\r\n",tt,t);
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
   
  int l;
  //disable_interrupts(global);
  setup_adc_ports(NO_ANALOGS);
  setup_adc(ADC_OFF);
  setup_spi(FALSE);
  setup_psp(PSP_DISABLED);
  setup_counters(RTCC_INTERNAL,RTCC_DIV_2);
  setup_timer_1(T1_INTERNAL | T1_DIV_BY_8);
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
  
  for (l=0;l<40;l++){//borro todos los dato en timer1values
  Timer1Values[l]=0;
  }
  cc=0;

  do {

    if(hay_dato==1){
    disable_interrupts(int_ext);
    printf("DATOS DEL TRM1  By  Jorge Miranda Zarate");
       hay_dato=0;
       for (cc=1;cc<40;cc++){
      printf(" Numero=%u TMR1 =%Lu-----Diferencia Lectura TMR1=%Lu\r\n",cc,Timer1Values[cc],(Timer1Values[cc]-Timer1Values[cc-1]));
      }
       /*convierte_bits_a_bytes();
       muestra_bits();
       limpia_bits();*/
       enable_interrupts(int_ext);
    }

  } while (TRUE);
}

