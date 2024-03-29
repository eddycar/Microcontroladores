#include <xc.h>
#include "config.h"
#include "UART_LIB.h"


void UART_Init(long BAUDRATE){
    TRISCbits.TRISC6=0; // TX OUT
    TRISCbits.TRISC7=1; // RX IN
    
    if(_XTAL_FREQ<=4000000){
        SPBRG = (unsigned char)((_XTAL_FREQ/(16.0*BAUDRATE))-1);
        TXSTA = 0x24;
    }
    else{
        SPBRG = (unsigned char)((_XTAL_FREQ/(64.0*BAUDRATE))-1);
        TXSTA = 0x24;
    }
    RCSTA=0x90;
}

void UART_Write_Chr(char letra){
    TXREG = letra;
    while(TXSTAbits.TRMT==0);
      
}

char UART_Read(){
    if(RCSTAbits.OERR==0){
        CREN=0;
        NOP();
        CREN=1;
    }
    return(RCREG);
}

void UART_Write_Text(char *texto){
    while(*texto){
        UART_Write_Chr(*texto);
        texto++;
    }
}

