 
#ifndef UART_LIB_H
#define	UART_LIB_H

void UART_Init(long BAUDRATE);
void UART_Write_Chr(char letra);
char UART_Read();
void UART_Write_Text(char *texto);

#endif	/* XC_HEADER_TEMPLATE_H */

