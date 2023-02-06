#include <xc.h>
#include "config.h"
#include "SPI_SOFT_LIB.h"
#include "MAX7219_LIB.h"

void MAX7219_Init(char n_matrices) {
    SPI_SOFT_INIT();
    while (n_matrices) {
        n_matrices--;
        MAX7219_Config(n_matrices);
    }
}

void MAX7219_Config(char matrices) {
    MAX7219_Tx(DECODE_MODE, NO_DECODE, matrices);
    MAX7219_Tx(SCAN_LIMIT, SCAN_7, matrices);
    MAX7219_Tx(INTENSITY, DUTY_17_32, matrices);
    MAX7219_Tx(SHUTDOWN, NORMAL_OPERATION, matrices);
    MAX7219_Tx(DISPLAY_TEST, NO_TEST, matrices);
}

void MAX7219_Tx(char dir, char dato, char matrices) {
    SS = 0;
    SPI_SOFT_TX(dir);
    SPI_SOFT_TX(dato);
    while (matrices) {
        matrices--;
        MAX7219_No_OP();
    }
    SS = 1;
}

void MAX7219_No_OP(void) {
    
    SPI_SOFT_TX(NO_OP);
    SPI_SOFT_TX(0x00);
    
}


