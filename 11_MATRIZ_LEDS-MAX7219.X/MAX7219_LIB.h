
#ifndef MAX7219_LIB_H
#define	MAX7219_LIB_H

#include <xc.h>

// Mapa de direcciones de registro a utilizar

#define NO_OP               0x00
#define DIGIT_0             0x01
#define DIGIT_1             0x02 
#define DIGIT_2             0x03
#define DIGIT_3             0x04 
#define DIGIT_4             0x05 
#define DIGIT_5             0x06 
#define DIGIT_6             0x07 
#define DIGIT_7             0x08 

#define DECODE_MODE         0x09
#define INTENSITY           0x0A
#define SCAN_LIMIT          0x0B
#define SHUTDOWN            0x0C
#define DISPLAY_TEST        0x0F



//Operaciones para shutdown

#define SHUTDOWN_MODE       0x00
#define NORMAL_OPERATION    0x01


//Operaciones para modo decodificador

#define NO_DECODE           0x00
#define CODE_B1             0x01
#define CODE_B2             0x0F           
#define CODE_B3             0xFF


//Operaciones en modo intensidad

#define DUTY_1_32           0x00
#define DUTY_5_32           0x01
#define DUTY_7_32           0x02
#define DUTY_9_32           0x03
#define DUTY_11_32          0x04
#define DUTY_13_32          0x05
#define DUTY_15_32          0x06
#define DUTY_17_32          0x07
#define DUTY_19_32          0x08
#define DUTY_21_32          0x09
#define DUTY_23_32          0x0A
#define DUTY_25_32          0x0B
#define DUTY_27_32          0x0C
#define DUTY_29_32          0x0E
#define DUTY_31_32          0x0F


//Operaciones del Scan Limit

#define SCAN_0              0x00
#define SCAN_1              0x01
#define SCAN_2              0x02
#define SCAN_3              0x03
#define SCAN_4              0x04
#define SCAN_5              0x05
#define SCAN_6              0x06
#define SCAN_7              0x07


//Operaciones en modo Display Test

#define NO_TEST             0x00
#define DISPLAY_TEST        0x01


void MAX7219_Init(char n_matrices);
void MAX7219_Config(char matrices);
void MAX7219_Tx(char dir, char dato, char matrices);
void MAX7219_No_OP(void);



#endif	/* MAX7219_LIB_H */