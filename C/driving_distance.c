#include <stdio.h>

int main()
{
    float distance, speed;
    printf("\nIngresar distancia: ");
    scanf("%f", &distance);
    printf("\nIngresar velocidad del movil: ");
    scanf("%f", &speed);

    float tiempo = distance * speed;
    printf("\nEl tiempo que demora de A a B es: %1.f horas", tiempo);

}