
#ifndef DECO_ANODO_H
#define	DECO_ANODO_H

#include <xc.h>

char deco_ac(char numero){
    char my_Deco = 0;
    
    switch(numero){
        case 0: my_Deco = 64; break;
        case 1: my_Deco = 121; break;
        case 2: my_Deco = 36; break;
        case 3: my_Deco = 48; break;
        case 4: my_Deco = 25; break;
        case 5: my_Deco = 18; break;
        case 6: my_Deco = 2; break;
        case 7: my_Deco = 120; break;
        case 8: my_Deco = 0; break;
        case 9: my_Deco = 16; break;
    }
    return my_Deco;
}

#endif	/* XC_HEADER_TEMPLATE_H */

