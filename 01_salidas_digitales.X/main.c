
#include <xc.h>
#include "config.h"

void main(void) {
    
    ADCON1 = 0X0F;
    TRISAbits.RA0 = 0;
    
    while(1){
        PORTAbits.RA0 = 1;
        __delay_ms(500);
        PORTAbits.RA0 = 0;
        __delay_ms(500);
    }
    
    return;
}
