
#include <xc.h>
#include "config.h"
#include "SPI_SOFT_LIB.h"
#include "MAX7219_LIB.h"
#include "MAX_SIMBOL.h"

void main(void) {
    
    ADCON1 = 15;
    
    MAX7219_Init(4);
    
    while(1){
        
        
     
    }
    
    return;
}
