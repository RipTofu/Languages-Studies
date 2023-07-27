//exponential operation with while loop

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, potencia, contador=0;
    printf("Ingresar numero\n>>");
    scanf("%d", &numero);
    printf("Ingresar potencia\n>>");
    scanf("%d", &potencia);
    while (contador<potencia-1)
    {
        numero = numero * potencia;
        contador = contador+1;
    }
    printf("\n%d", numero);
}