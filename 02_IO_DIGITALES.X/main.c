
#include <xc.h>
#include "config.h"

void main(void) {
    // CONFIGRAR LOS PUERTOS TRIS
    TRISB = 7;
    TRISD = 0;
    
    // MANIPULAR LOS PUERTOS
    LATD = 0x00;
    
    while(1){
    /*    if(PORTBbits.RB0 == 1){
            LATD = 0xF0;
        }
        if(PORTBbits.RB1 == 1){
            LATD = 0x0F;
        }
        if(PORTBbits.RB2 == 1){
            LATD = 0x3F;
        }  */
        
        if(PORTB == 1){
            LATD = 0xF0;
        }
        if(PORTB == 2){
            LATD = 0x0F;
        }
        if(PORTB == 4){
            LATD = 0x3F;
        }
        
       __delay_ms(100);
    }
    
    return;
}
