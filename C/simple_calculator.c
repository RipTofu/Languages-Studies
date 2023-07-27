//Basic calculator, first approach to math operations.

#include <stdio.h>

void main()
{
    //condicionales
    int num1, num2, menu, resultado;
    printf("Ingrese operacion a realizar\n0 multiplicacion | 1 division | 2 suma | 3 resta\n>>");
    scanf("%i", &menu);
    printf("Ingrese primer numero\n>>");
    scanf("%i", &num1);
    printf("Ingrese segundo numero\n>>");
    scanf("%i", &num2);

    if (menu == 0)
    {
        resultado = num1 * num2;
        printf("%i * %i = %i", num1, num2, resultado);
    }

    else if(menu == 1)
    {
        if(num2 == 0)
        {
            printf("Mensaje de error, wuu!");
        }
        else
        {
            resultado = num1 / num2;
            int resto = num1 % num2;
            printf("%i / %i = %i\nresto = %i", num1, num2, resultado, resto);
        }

    }
    else if(menu == 2)
    {
        resultado = num1 + num2;
        printf("%i + %i = %i", num1, num2, resultado);
    }

}

