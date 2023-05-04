// Divide_Controller.c
//
// Software for the 'SubHarmonics' Harmonic Division VCO
// m0xpd
// 2023
// https://github.com/m0xpd/SubHarmonics
//
//
// PIC16F676 Configuration Bit Settings...

#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSC oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RA3/MCLR pin function select (RA3/MCLR pin function is MCLR)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)


#include <xc.h>
#define _XTAL_FREQ 4000000

int Divide1 = 0;
int Divide2 = 0;
int voltage;

void ADC_Init()
{
  ADCON0 = 0x81; //ADC Module Turned ON and Clock is selected
  ADCON1 = 0b100; ; 
}

unsigned int ADC_Read(unsigned char channel)
{
  if(channel > 7)           //If Invalid channel selected 
    return 0;               //Return 0
  ADCON0 &= 0x81;               //Clear the Channel Selection Bits
  ADCON0 |= channel<<2;         //Setting the required Bits
  __delay_ms(2);                //time to charge hold capacitor
  GO_nDONE = 1;                 //Initializes A/D Conversion
  while(GO_nDONE);              //Wait for A/D Conversion to complete
  return ((ADRESH<<8)+ADRESL);  //Return Result
}

void setDiv1(){  // set Divider 1
    if(Divide1&1){
        RC5=1;
    }
    else{
        RC5=0;
    }
    if(Divide1&2){
        RC4=1;
    }
    else{
        RC4=0;
    }            
    if(Divide1&4){
        RC3=1;
    }
    else{
        RC3=0;
    }            
}

void setDiv2(){ // set Divider 2
    if(Divide2&1){
        RA5=1;
    }
    else{
        RA5=0;
    }
    if(Divide2&2){
        RA4=1;
    }
    else{
        RA4=0;
    }            
    if(Divide2&4){
        RC0=1;
    }
    else{
        RC0=0;
    }            
}
void main(){
    ANSEL=0X00;     // all pins are digital
    TRISC=0X00;
    TRISA=0X00;
                    // AN6 is analog input for Divide1 Potentiometer
    TRISC2 = 1;     // on RC2, pin 8 
                    // AN5 is analog input for DIVIDE 2 Potentiometer
    TRISC1 = 1;     // on RC1, pin 10
    ADC_Init();


    while(1){
    voltage=ADC_Read(0x6);      // Just loop round doing this...
    Divide1=voltage/128;  
    voltage=ADC_Read(0x5);
    Divide2=voltage/128;   
    setDiv1();
    setDiv2();
    __delay_ms(5);
    }
    
}


