
#include <xc.h>
#include "config.h"
#include "SPI_LIB.h"

char dato;

void main(void) {
    ADCON1 = 0x0F;
    TRISD = 0x00;
    LATD = 0x00;
    SPI_Slave_Init(SlaveSS, CLK0);
    
    while(1){
        dato = SPI_Rx();
        LATD = dato;
        __delay_ms(100);
                
    }
    return;
}
