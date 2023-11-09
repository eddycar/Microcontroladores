
#include <xc.h>
#include "config.h"
#include "ADC_LIB.h"
#include "stdio.h"
#include <math.h>
#include "UART_LIB.h"

#define PULSO  LATDbits.LATD0

int angulo;
int adcValue;
int tiempo;
char trigger = 0; // == dispara == angulo
char buffer[20];
//Variables cruce por cero 
float valorAnguloDisparo = 0; // valor en porcentaje del angulo de disparo
int cargaTimer = 0; // valor que se calcula para convertir porcentaje a carga en PR2 del timer2

void tmr2_init(void);

void __interrupt() interrupts() {
    // zero crossing interrupt 
    if (INTCONbits.INT0IF) {
        PULSO = 0;
        PR2 = cargaTimer; // carga el tiempo a temporizar en el timer2
        PIR1bits.TMR2IF = 0; // limpia bandera timer2
        PIE1bits.TMR2IE = 1; // activa interrupcion de timer cero
        T2CONbits.TMR2ON = 1;
        INTCONbits.INT0IF = 0; // external interrupt flag is cleared
    }
    // Timer2 Interrupt
    if (PIR1bits.TMR2IF) {
        PULSO = 1;
        __delay_us(10);
        PULSO = 0;
        PIR1bits.TMR2IF = 0; // limpia bandera timer2
        PIE1bits.TMR2IE = 0; // desactiva interrupcion de timer cero
        T2CONbits.TMR2ON = 0;
    }
}

void main(void) {
    ADCON1 = 0x0E;
    TRISBbits.RB0 = 1; // Entrada señal de cruce por cero 
    TRISDbits.RD0 = 0; // Salida Triac
    PULSO = 0; // PULSO corresponde a LATDbits.LATD1

    //led de prueba 
    TRISDbits.RD1 = 0;
    LATDbits.LATD1 = 0;

    //Gloabasl nterrupts 
    INTCONbits.GIE = 1; // Global interrupts are enable
    INTCONbits.PEIE = 1; // Peripheral interrupts are enable

    //RB0 External interrupts
    INTCONbits.INT0IF = 0; // External interrupt flag is cleared 
    INTCONbits.INT0IE = 1; // External interrupt is enable
    INTCON2bits.INTEDG0 = 1; // External interrupt is set on rising edge

    tmr2_init();

    ADC_Init(_TAD_4, _TOSC_4);

    //UART_Init(9600);

    while (1) {
        adcValue = ADC_Read(0);
//        sprintf(buffer, "Adc value: %d\r\n", adcValue);
//        UART_Write_Text(buffer);
        valorAnguloDisparo = adcValue * 0.097656;
//        sprintf(buffer, "Angulo disp: %.2f\r\n", valorAnguloDisparo);
//        UART_Write_Text(buffer);
        if (valorAnguloDisparo <= 5) {
            INTCONbits.INT0IE = 0; // External interrupt is disable
            PULSO = 0; // apaga la carga
        } else if (valorAnguloDisparo >= 95) {
            INTCONbits.INT0IE = 0; // External interrupt is disable
            PULSO = 1; // Mantiene encendida la carga
        } else {
            cargaTimer = round(valorAnguloDisparo * 2.6); // Expresión obtenida a partir del archivo excel cruce por cero
            INTCONbits.INT0IE = 1;
//            sprintf(buffer, "Carga timer: %d\r\n", cargaTimer);
//            UART_Write_Text(buffer);
        }
        __delay_ms(100);
    }
    return;
}

void tmr2_init(void) {
    T2CONbits.T2CKPS = 0b01; //Prescale 1:4
    T2CONbits.TOUTPS = 0b0111; // Postcale 1:8
    //Timer 2 interrups 
    PIR1bits.TMR2IF = 0;
    PIE1bits.TMR2IE = 0;
    T2CONbits.TMR2ON = 0;
}
