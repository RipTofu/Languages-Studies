//Simple solution to a sequence sum
#include <stdio.h>

int main()
{
    int d, a1, n , an;
    printf("Ingrese diferencia entre valores: ");
    scanf("%d", &d);
    printf("\nIngrese cifra inicial: ");
    scanf("%d", &a1);
    printf("\nIngrese numero de la secuencia a obtener: ");
    scanf("%d", &n);
    printf("La formula es:\nan = a1+(n-1)*d");
    an = a1 +(n-1)*d;
    printf("\n%d = %d + (%d - 1) * %d", an, a1, n, d);

}