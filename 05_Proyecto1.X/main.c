
#include <xc.h>
#include "config.h"
#include "deco_catodo.h"

void mostrar(float valor);

void main(void) {
    ADCON1 = 0x0f;
    TRISA = 0xff;
    TRISB = 0x00;
    TRISD = 0x00;
    TRISE = 0xff;
    
    while(1){
        for(int i=0; i<=100; i++){
            mostrar(i);
        }
        
    }
    
    return;
}

void mostrar(int valor) //Funcion para mostrar tiempo
{
 int uni=0, dec=0, cen=0, mil=0;   //Declarar las variables UNI, DEC,CEN
   
   
   uni= valor %10;
   dec= (valor/10)%10; 
   cen =(valor/100)%10; 
   mil =(valor/1000)%10;
  
   //MOSTRAR UNIDADES
                     
   PORTBbits.RB4= 1;         //Enciende el display de unidades
   PORTD=uni;   //Muestra lo que hay en unidades  
   __delay_ms(10);            //Retardo de 1 milisegundos
   PORTBbits.RB4= 0;         //Apaga el display de unidades
   
   
   //MOSTRAR DECENAS
   
   PORTBbits.RB5= 1;         //Enciende el display de decenas
   PORTD=dec;             //Muestra lo que hay en decenas
   __delay_ms(10);            //Retardo de n milisegundos
   PORTBbits.RB5= 0;        //Apaga el display de decenas
   
          
  //MOSTRAR CENTENAS
   PORTBbits.RB6= 1;         //Enciende el display de centenas
   PORTD=cen;   //Muestra lo que hay en centenas
   __delay_ms(10)            //Retardo de n milisegundos
   PORTBbits.RB6= 0;         //Apaga el display de centenas
   
   
   //MOSTRAR MILLARES
   PORTBbits.RB7= 1;         //Enciende el display de millares
   PORTD=mil;   //Muestra lo que hay en millares
   __delay_ms(10)            //Retardo de n milisegundos
   PORTBbits.RB7= 0;         //Apaga el display de millares
               
}