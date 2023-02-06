
#ifndef SPI_SOFT_LIB_H
#define	SPI_SOFT_LIB_H

#include <xc.h>

#define TRIS_SDO    TRISDbits.RD0
#define TRIS_SS     TRISDbits.RD1
#define TRIS_CLK    TRISDbits.RD2
#define TRIS_SDI    TRISDbits.RD3

#define SDO PORTDbits.RD0
#define SS  PORTDbits.RD1
#define CLK PORTDbits.RD2
#define SDI PORTDbits.RD3

#define OUT 0
#define IN  1

void SPI_SOFT_INIT(void);
void SPI_SOFT_TX(char cmd);
char SPI_SOFT_RX(void);


#endif	/* SPI_SOFT_LIB_H */

