

#include <xc.h>
#include "config.h"

int tiempo = 0;
int contador = 0;
int RPM = 1234;

void mostrar(int valor);

// Tiempo requerido = 4/Fosc x Preescaler x (255- TMR0)
void tmr0_Init(){
    
    OPTION_REGbits.T0CS = 0; // Timer0 como temporizador
    OPTION_REGbits.PSA = 0; // Asignamos el preescaler al Timer0
    OPTION_REGbits.PS = 0b100; //Preescaler = 32
    TMR0 = 100; // Valor a cargar en el registro TMR0 
    INTCONbits.T0IE = 1;
    INTCONbits.T0IF = 0; // Bandera de interrupción del timer0
    
}

void __interrupt() interrupciones(){
    if(INTCONbits.INTF){
       contador++;
        INTCONbits.INTF = 0;
    }
    
    if(INTCONbits.T0IF){
            INTCONbits.T0IF = 0;
            tiempo++;
         if (tiempo==1000){
             //PORTBbits.RB3 =  ~PORTBbits.RB3;
            RPM = contador * 60;
            contador = 0;
            tiempo =  0;
        }
        
    }
    
}

void main(void) {
    
    //CMCONbits.CM= 0b111; // Deshabilitamos el modo comparador
    INTCONbits.GIE = 1; // registro para habilitar las interrupciones globales
    
    TRISA = 0x00;
    TRISB = 0x01;
    PORTB = 0;
    
    tmr0_Init();
   
    //CONFIGURACION DE INTERRUPCION CAMBIO DE ESTADO RB0
    INTCONbits.INTF = 0; // se limpia el registro, este se establece cuando ocurre la interrupcion
    INTCONbits.INTE = 1; // se habilita la interrupcion por cambiio de estado pin RB0
    OPTION_REGbits.INTEDG = 1;
    
    while(1){
    
        mostrar(RPM);
    }
    
    return;
}

void mostrar(int valor) //Funcion para mostrar tiempo
{
 unsigned char uni=0, dec=0, cen=0, mil=0;   //Declarar las variables UNI, DEC,CEN
 const int retardo = 50;
   
   uni= valor %10;
   dec= (valor/10)%10; 
   cen =(valor/100)%10; 
   mil = (valor/1000)%10;
  
    
    
   //MOSTRAR UNIDADES
                     
   PORTBbits.RB7= 0;         //Enciende el display de unidades
   PORTA= uni;   //Muestra lo que hay en unidades  
   __delay_ms(retardo);            //Retardo de 1 milisegundos
   PORTBbits.RB7= 1;         //Apaga el display de unidades
   //MOSTRAR DECENAS
   
   PORTBbits.RB6= 0;         //Enciende el display de decenas
   PORTA=dec;             //Muestra lo que hay en decenas
   __delay_ms(retardo);            //Retardo de n milisegundos
   PORTBbits.RB6= 1;        //Apaga el display de decenas
   
          
  //MOSTRAR CENTENAS
   PORTBbits.RB5= 0;         //Enciende el display de centenas
   PORTA=cen;   //Muestra lo que hay en centenas
   __delay_ms(retardo);            //Retardo de n milisegundos
   PORTBbits.RB5= 1;         //Apaga el display de centenas
   
   
   //MOSTRAR MILLARES
   PORTBbits.RB4= 0;         //Enciende el display de millares
   PORTA=mil;   //Muestra lo que hay en millares
   __delay_ms(retardo);            //Retardo de n milisegundos
   PORTBbits.RB4= 1;         //Apaga el display de millares
               
}
