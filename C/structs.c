#include <stdio.h>

typedef struct nombre{
    int x, y, z;
} estructura;

int main()
{
    estructura variable1 = {2,3,4}; //Esto es sólo una variable del tipo "estructura"
    estructura *puntero; //Puntero para el tipo de dato estructura.
    //Para usarse, se debe inicializar:
    puntero = (estructura*)malloc(sizeof(estructura));
    puntero->x = 4;
    printf("%i", puntero->x);
}
