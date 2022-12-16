
#ifndef SHOW_H
#define	SHOW_H

#include <xc.h>

void mostrar(float valor) //Funcion para mostrar tiempo
{
 int uni, dec, cen, mil;   //Declarar las variables UNI, DEC,CEN
   
   
   uni= valor %10;
   dec= (valor/10)%10; 
   cen =(valor/100)%10; 
   mil =(valor/1000)%10;
  
   //MOSTRAR UNIDADES
                     
   PORTBbits.RB4= 1;         //Enciende el display de unidades
   PORTA=uni;   //Muestra lo que hay en unidades  
   __delay_ms(10);            //Retardo de 1 milisegundos
   PORTBbits.RB4= 0;         //Apaga el display de unidades
   
   
   //MOSTRAR DECENAS
   
   PORTBbits.RB5= 1;         //Enciende el display de decenas
   PORTA=dec;             //Muestra lo que hay en decenas
   __delay_ms(10);            //Retardo de n milisegundos
   PORTBbits.RB5= 0;        //Apaga el display de decenas
   
          
  //MOSTRAR CENTENAS
   PORTBbits.RB6= 1;         //Enciende el display de centenas
   PORTA=cen;   //Muestra lo que hay en centenas
   __delay_ms(10)            //Retardo de n milisegundos
   PORTBbits.RB6= 0;         //Apaga el display de centenas
   
   
   //MOSTRAR MILLARES
   PORTBbits.RB7= 1;         //Enciende el display de millares
   PORTA=mil;   //Muestra lo que hay en millares
   __delay_ms(10)            //Retardo de n milisegundos
   PORTBbits.RB7= 0;         //Apaga el display de millares
               
}

#endif	/* SHOW_H */

