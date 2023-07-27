//Some math formulas and a menu.

#include <stdio.h>
#include <conio.h>

int DobleSumatoria(int n)
{
    int i, j;
    int acum = 0;
    i = 1;
    while (i <= n)
    {
        j = i;
        while (j <= n)
        {
            acum = acum + (i + j);
            j = j + 1;
        }
        i = i + 1;
    }
    return acum;
}

float Potencia(int base, int exp)
{
    float acum;
    int i;

    acum = 1;
    i = 0;
    while (i < exp)
    {
        acum = acumbase;
        i = i + 1;
    }
    return acum;
}


float SumatoriaEjercicio3(int n, int x)
{
    float acum;
    int i;
    acum = 1;
    i = 1;
    while (i <= n)
    {
        acum = acum + Potencia(-1,i)*i/Potencia(x,i);
        i = i + 1;
    }
    return acum;
}

void main()
{
    char a;
    int dx = 1;
    while (dx != 0)
    {
        fflush(stdin);
        printf("\nIngresar opcion:\na)Primeros terminos de la serie\nb)Calcular doble sumatoria\nc)Salir\n>>");
        scanf("%c", &a);
        switch (a) {
            case 'a':
            {
                float n, x;
                printf("Ingresar n y x\n>>");
                scanf("%f %f", &n, &x);
                float res = SumatoriaEjercicio3(n, x);
                printf("\n%f\n", res);
                break;
            }
            case 'b':
            {
                int n;
                printf("Ingresar n\n>>");
                scanf("%i", &n);
                int res = DobleSumatoria(n);
                printf("\n%i", res);
                break;
            }
            case 'c':
            {
                dx = 0;
                printf("Terminando programa.");
            }
            default:
            {
                printf("Reintentar con una opcion coherente, por favor.\n");
            }

        }
    }
}
