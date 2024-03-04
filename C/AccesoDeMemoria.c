#include <stdio.h>

typedef struct personas {
    char nombre[50];
    int rut;
    struct personas *sig;
} personas;

int main()
{
    int tamano = 10;
    personas *p;
    p = (personas*) malloc(tamano * sizeof(personas));
}
