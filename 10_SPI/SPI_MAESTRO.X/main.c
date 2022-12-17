
#include <xc.h>
#include "config.h"
#include "SPI_LIB.h"

void main(void) {
    ADCON1=0x0F;
    
    SPI_Master_Init(MasterCLK64, CLK0);
    
    while(1){
        SS = 0;
        for(int i=0; i<=15; i++){
            SPI_Tx(i);
            __delay_ms(500);
        }
        SS= 1;
        __delay_ms(100);
    
    }
    return;
}
