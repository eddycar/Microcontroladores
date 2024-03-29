#ifndef myADC_H
#define	myADC_H

#include <xc.h> 

// generadmos un tiempo conver > 2.45 us K*TAD
#define _TAD_20 7
#define _TAD_16 6
#define _TAD_12 5
#define _TAD_8  4
#define _TAD_6  3
#define _TAD_4  2
#define _TAD_2  1
#define _TAD_0  0

//generamos un TAD > 0.8us
#define _TOSC_2  0  
#define _TOSC_4  4
#define _TOSC_8  1
#define _TOSC_16 5
#define _TOSC_32 2
#define _TOSC_64 6
#define _RC_     3


void ADC_Init(int kTad, int kTosc){// Tad = Tosc*K
    ADCON2bits.ACQT =kTad;
    ADCON2bits.ADCS =kTosc;
    ADCON2bits.ADFM = 1; // justificamos a la derecha
}

int ADC_Read(char miCanal){ 
    int miConver;
     ADCON0bits.CHS=miCanal; // seleccionamos el canal cero
     ADCON0bits.ADON = 1; // habilitamos el modulo ADC
     ADCON0bits.GO_nDONE = 1;
     while( ADCON0bits.GO_nDONE==1);
     miConver = ADRESH<<8 | ADRESL;
     return miConver;
}




#endif	/* XC_HEADER_TEMPLATE_H */



