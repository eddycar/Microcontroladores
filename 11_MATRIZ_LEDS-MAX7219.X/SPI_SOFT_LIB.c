#include <xc.h>
#include "config.h"
#include "SPI_SOFT_LIB.h"

void SPI_SOFT_INIT(void){
    
    TRIS_SDI = IN;
    TRIS_SDO = OUT;
    TRIS_CLK = OUT;
    TRIS_SS  = OUT;
}

void SPI_SOFT_TX(char cmd){
    
    for(char j=0; j<8; j++){
        CLK = 0;
        SDO = ((cmd<<j)&0x80)?1:0;
        CLK = 1;
    }
}

char SPI_SOFT_RX(void){
    char paquete = 0;
    for(int j=7; j>=0; j--){
        CLK = 0;
        paquete = paquete + (SDI<<j);
        CLK = 1;
    }
    return paquete;
}