
#include <xc.h>
#include "config.h"
#include "LIBRERIA_LCD.h"
#include <stdio.h>
#include <pic18f4550.h>

char aux[20] = " ";
float periodo = 0.0;
int pasos = 0;

void __interrupt() captura() {
    pasos = CCPR1H << 8 | CCPR1L;
    TMR1H = 0;
    TMR1L = 0;
    //T = Tins * preescaler * #pasos
    //#pasos = (1/4x10e6 ) * 8 * 4 = 1us entonces:
    periodo = (pasos * 0.000008)/4;  //Se divide entre 4 porque cada 4 flancos se hace un solo conteo

    PIR1bits.CCP1IF = 0;
}

void config_interrups();
void config_timer1();
void ccp1_config();
void timer1_init();

void main(void) {
    ADCON1 = 0x0F;
    TRISC = 0xFF;

    config_interrups();
    config_timer1();
    ccp1_config();
    timer1_init();

    timer1_init();
    LCD_Init();
    LCD_Cmd(_LCD_CURSOR_OFF);

    while (1) {
        sprintf(aux, "T: %f", periodo);
        LCD_Out(2, 1, aux);
        //  __delay_ms(300);
    }
    return;
}

void config_interrups() {
    INTCONbits.GIE = 1; //Habilita interrupciones globales
    INTCONbits.PEIE = 1; //Habilita interrupciones por periferico
    PIR1bits.CCP1IF = 0; //inicializa bandera de interrupcion
    PIE1bits.CCP1IE = 1; // Habilita interrupcion del modulo CCP1
}

void config_timer1() {
    T1CONbits.T1CKPS = 0b11; //Preescaler del timer 1:8
    T1CONbits.TMR1CS = 0; // Timer trabaja con el reloj interno
    T1CONbits.RD16 = 1; // Timer se configura a 16 bits
    TMR1H = 0;
    TMR1L = 0;
}

void ccp1_config() {
    CCP1CONbits.CCP1M = 0b0110;  // Capture mode: every rising edge(0101) || Capture mode: every 4th rising edge(0110)  || Capture mode: every 16th rising edge (0111)
}

void timer1_init() {
    T1CONbits.TMR1ON = 1;
}
