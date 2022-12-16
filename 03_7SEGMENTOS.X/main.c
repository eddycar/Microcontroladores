
#include <xc.h>
#include "config.h"

int num = 0;

void main(void) {
    // CONFIGRAR LOS PUERTOS TRIS
    TRISA = 0;
    TRISB = 7;
    TRISD = 0;
    
    // MANIPULAR LOS PUERTOS
    LATD = 0x00;
    LATA = 63;
    
    while(1){
        switch(num){
            case 0:  LATA = 63; break;
            case 1:  LATA = 6; break;
            case 2:  LATA = 91; break;
            case 3:  LATA = 79; break;
            case 4:  LATA = 102; break;
            case 5:  LATA = 109; break;
            case 6:  LATA = 125; break;
            case 7:  LATA = 7; break;
            case 8:  LATA = 127; break;
            case 9:  LATA = 111; break;
            default: LATA = 63;
        }
        
        num ++;
        if(num == 10) num =0;
        
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
