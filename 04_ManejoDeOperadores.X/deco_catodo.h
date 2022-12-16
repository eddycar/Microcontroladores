
#ifndef DECO_CATODO_H
#define	DECO_CATODO_H

#include <xc.h>

char deco_cc(char numero){
    char my_Deco = 0;
    
    switch(numero){
        case 0: my_Deco = 63; break;
        case 1: my_Deco = 6; break;
        case 2: my_Deco = 91; break;
        case 3: my_Deco = 79; break;
        case 4: my_Deco = 102; break;
        case 5: my_Deco = 109; break;
        case 6: my_Deco = 125; break;
        case 7: my_Deco = 7; break;
        case 8: my_Deco = 127; break;
        case 9: my_Deco = 111; break;
    }
    return my_Deco;
}

#endif	/* XC_HEADER_TEMPLATE_H */

