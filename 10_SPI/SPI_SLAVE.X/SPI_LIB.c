#include <xc.h>
#include "config.h"
#include "SPI_LIB.h"

void SPI_Master_Init(char MS_CLK_SS, char Forma){
    
    // configurar los pines a utilizar
    TRIS_SS = PIN_OUT;
    TRIS_SDO = PIN_OUT;
    TRIS_SDI = PIN_IN;
    TRIS_SCL = PIN_OUT;
    
    switch(Forma){
        case CLK0: SSPSTATbits.CKE=0; 
                   SSPCON1bits.CKP=0; 
                   break;
        case CLK1: SSPSTATbits.CKE=0; 
                   SSPCON1bits.CKP=1; 
                   break;
        case CLK2: SSPSTATbits.CKE=1; 
                   SSPCON1bits.CKP=0; 
                   break;
        case CLK3: SSPSTATbits.CKE=1; 
                   SSPCON1bits.CKP=1; 
                   break;
    }
    
    SSPSTATbits.SMP = SMP_MIDDLE;
    SSPCON1bits.SSPM = MS_CLK_SS;
    SSPCON1bits.SSPEN = SSP_ON;
    
}

void SPI_Slave_Init(char MS_CLK_SS, char Forma){
    
    // configurar los pines a utilizar
    TRIS_SS =  PIN_IN;
    TRIS_SDO = PIN_OUT;
    TRIS_SDI = PIN_IN;
    TRIS_SCL = PIN_IN;
    
    switch(Forma){
        case CLK0: SSPSTATbits.CKE=0; 
                   SSPCON1bits.CKP=0; 
                   break;
        case CLK1: SSPSTATbits.CKE=0; 
                   SSPCON1bits.CKP=1; 
                   break;
        case CLK2: SSPSTATbits.CKE=1; 
                   SSPCON1bits.CKP=0; 
                   break;
        case CLK3: SSPSTATbits.CKE=1; 
                   SSPCON1bits.CKP=1; 
                   break;
    }
    
    SSPSTATbits.SMP = 0;
    SSPCON1bits.SSPM = MS_CLK_SS;
    SSPCON1bits.SSPEN = SSP_ON;
    
}

void SPI_Tx(char dato){
    SSPBUF = dato;
    
}

char SPI_Rx(){
    
    return SSPBUF;
}