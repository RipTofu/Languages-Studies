//Simple sum of a sequence
#include <stdio.h>

int main()
{
    float inicial, enesimo, cantidad;
    printf("Ingrese la cifra inicial: ");
    scanf("%f", &inicial);
    printf("\nIngrese cantidad de elementos: ");
    scanf("%f", &cantidad);
    printf("\nIngrese el enesimo termino");
    scanf("%f", &enesimo);
    printf("La suma de la secuencia se calcula como Sn = (a1 + an) * (n/2)");
    float sn = (inicial + enesimo) * (cantidad/2);
    printf("\nLa suma es %f", sn);
}