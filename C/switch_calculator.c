//Switch case study, second approach to math operators.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    char signo;
    float num1, num2;
    printf("Ingresar operacion");
    scanf("%c", &signo);
    switch (signo)
    {
        case '+':
        {
            printf("Ingresar dos números para sumar");
            scanf("%f %f", &num1, &num2);
            printf("%f + %f = %f", num1, num2, num1+num2);
        }
        case'-':
        {
            printf("Ingresar dos números para restar");
            scanf("%f %f", &num1, &num2);
            printf("%f + %f = %f", num1, num2, num1 - num2);
        }
        case '*':
        {
            printf("Ingresar dos números para multiplicar");
            scanf("%f %f", &num1, &num2);
            printf("%f + %f = %f", num1, num2, num1*num2);
        }
        case '/':
            printf("Ingresar dos números para dividir");
            scanf("%f %f", &num1, &num2);
            printf("%f / %f = %f\nresto = %d", num1, num2, num1/num2, ((int)num1)%((int)num2));
    }
}