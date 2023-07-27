//Some format

#include <stdio.h>
#include <stdlib.h>

int main() {
    int segundos, horas, minutos, segun2;
    printf("Ingresar segundos: ");
    scanf("%d", &segundos);
    horas = segundos/3600;
    minutos = (segundos-horas*3600) / 60;
    segun2 = (segundos - horas*3600) % 60;
    printf("%02d: %02d: %02d", horas, minutos, segun2);//Formato de dos ceros
}
