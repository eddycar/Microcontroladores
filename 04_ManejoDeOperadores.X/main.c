
#include <xc.h>
#include "config.h"
#include "deco_catodo.h"
 
void main(void) {
    TRISA = 0x00;
    TRISB = 0xff;
    TRISD = 0x00;
    int i;
    char num1, num2, resultado;
    
    while(1){
       /* num1 = PORTB & 0b00001111;
        PORTA = deco_cc(num1);
        num2 = (PORTB & 0b11110000)>>4;
        PORTD = deco_cc(num2); */
        
        num1 = PORTB & 0b00001111;
        num2 = (PORTB & 0b11110000)>>4;
        resultado = num1 + num2;
        PORTA = deco_cc(resultado / 10);
        PORTD = deco_cc(resultado % 10);
    }
    
    return;
}
