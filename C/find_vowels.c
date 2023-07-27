//While loop for finding character in a string.

#include <stdio.h>
#include <string.h>

void main()
{
    char array[6] = "abcde", vocales[6] = "aeiou";
    int i = 0, contador = 0;
    while (i!= strlen(array))
    {
        int j = 0;
        char caracter_actual = array[i];
        printf("\nCaracter actual = %c", caracter_actual);
        while(j != strlen(vocales))
        {
            char vocal_actual = vocales[j];
            printf("\nComparando %c con %c", caracter_actual, vocal_actual);
            if (vocal_actual == caracter_actual)
            {
                printf("\nVocal encontrada!");
                contador ++;
                break;
            }
            j++;
        }
        i++;
    }
    printf("\nLa cantidad de vocales es %i", contador);
    return;
}


