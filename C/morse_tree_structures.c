#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct a{
    char letra;
    struct a *izq;
    struct a *der;
} arbolito;

arbolito *T;
FILE *arch;

/*
 * Entrada: Una letra
 * Salida: Nodo creado
 * Proceso: Crea un nodo que almacena la información del struct arbolito.
 */
arbolito *creaNodo(char letra)
{
    arbolito *lol = (arbolito*)(malloc(sizeof(arbolito)));
    lol->letra = letra;
    lol->der = NULL;
    lol->izq = NULL;
    return lol;
}

// Función de la profe c:
arbolito *creaAB()
{
    T = creaNodo('#');
    T->izq = creaNodo('E');
    T->der = creaNodo('T');
    T->izq->izq = creaNodo('I');
    T->izq->der = creaNodo('A');
    T->der->izq = creaNodo('N');
    T->der->der = creaNodo('M');
    T->izq->izq->izq = creaNodo('S');
    T->izq->izq->der = creaNodo('U');
    T->izq->der->izq = creaNodo('R');
    T->izq->der->der = creaNodo('W');
    T->der->izq->izq = creaNodo('D');
    T->der->izq->der = creaNodo('K');
    T->der->der->izq = creaNodo('G');
    T->der->der->der = creaNodo('O');
    T->izq->izq->izq->izq = creaNodo('H');
    T->izq->izq->izq->der = creaNodo('V');
    T->izq->izq->der->izq = creaNodo('F');
    T->izq->izq->der->der = creaNodo('#');
    T->izq->der->izq->izq = creaNodo('L');
    T->izq->der->izq->der = creaNodo('#');
    T->izq->der->der->izq = creaNodo('P');
    T->izq->der->der->der = creaNodo('J');
    T->der->izq->izq->izq = creaNodo('B');
    T->der->izq->izq->der = creaNodo('X');
    T->der->izq->der->izq = creaNodo('C');
    T->der->izq->der->der = creaNodo('Y');
    T->der->der->izq->izq = creaNodo('Z');
    T->der->der->izq->der = creaNodo('Q');
    T->der->der->der->izq = creaNodo('#');
    T->der->der->der->der = creaNodo('#');
    T->izq->izq->izq->izq->izq = creaNodo('5');
    T->izq->izq->izq->izq->der = creaNodo('4');
    T->izq->izq->izq->der->der = creaNodo('3');
    T->izq->izq->der->der->izq = creaNodo('#');
    T->izq->izq->der->der->der = creaNodo('2');
    T->izq->der->izq->izq->izq = creaNodo('&');
    T->izq->der->izq->izq->der = creaNodo('#');
    T->izq->der->izq->der->izq = creaNodo('+');
    T->izq->der->der->izq->der = creaNodo('#');
    T->izq->der->der->der->der = creaNodo('1');
    T->der->izq->izq->izq->izq = creaNodo('6');
    T->der->izq->izq->izq->der = creaNodo('=');
    T->der->izq->izq->der->izq = creaNodo('/');
    T->der->izq->der->izq->der = creaNodo('#');
    T->der->izq->der->der->izq = creaNodo('(');
    T->der->der->izq->izq->izq = creaNodo('7');
    T->der->der->izq->izq->der = creaNodo('#');
    T->der->der->izq->der->der = creaNodo(165);// Ñ
    T->der->der->der->izq->izq = creaNodo('8');
    T->der->der->der->der->izq = creaNodo('9');
    T->der->der->der->der->der = creaNodo('0');
    T->izq->izq->der->der->izq->izq = creaNodo('?');
    T->izq->izq->der->der->izq->der = creaNodo('_');
    T->izq->der->izq->izq->der->izq = creaNodo('"');
    T->izq->der->izq->der->izq->der = creaNodo('.');
    T->izq->der->der->izq->der->izq = creaNodo('@');
    T->izq->der->der->der->der->izq = creaNodo(39); // '
    T->der->izq->izq->izq->izq->der = creaNodo('-');
    T->der->izq->der->izq->der->izq = creaNodo(';');
    T->der->izq->der->izq->der->der = creaNodo('!');
    T->der->izq->der->der->izq->der = creaNodo(')');
    T->der->der->izq->izq->der->der = creaNodo(',');
    T->der->der->der->izq->izq->izq = creaNodo(':');

    return T;
}

/*
 * Entrada: Puntero a un elemento del árbol, dato a buscar.
 * Salida: Booleano que representa si el dato se encuentra o no.
 * Proceso: Busca el elemento en los subárboles asociados al árbol principal.
 */
bool buscaElemento(arbolito *A, char dato)
{
    if(A==NULL)
    {
        return false;
    }
    if(A->letra == dato)
    {
        return true;
    }
    return buscaElemento(A->izq, dato) || buscaElemento(A->der, dato);
}

/*
 * Entrada: Puntero a un elemento del árbol, letra a traducir.
 * Salida: Escritura del archivo
 * Proceso: Compara las letras para determinar si es punto, espacio o guión.
 */
void espanolAmorse(arbolito *A, char letra)
{
    if(A->letra == letra || letra == ' ')
    {
        fputc(' ', arch);
        return;
    }
    if(buscaElemento(A->izq,letra) == true)
    {
        fputc('.', arch);
        return espanolAmorse(A->izq,letra);
    }

    else
    {
        fputc('-', arch);
        return espanolAmorse(A->der,letra);
    }
}

/*
 * Entrada: String obtenido del archivo, nombre del archivo.
 * Salida: Nada
 * Proceso: Abre el archivo en modo de adjuntar y recorre el string para evaluar sus elementos.
 */

void palabraAmorse(char linea[4000], char nomarch[100])
{
    arch = fopen(nomarch, "a");
    fputc('\n', arch);
    int i;
    for(i=0;i<strlen(linea);i++)
    {
        espanolAmorse(T, linea[i]);
    }
}

/*
 * Entrada: Letra, puntero al árbol.
 * Salida: puntero al árbol.
 * Proceso: evalúa si la letra corresponde a un punto, guión o espacio, y recorre el árbol.
 */
arbolito *traduccion(char letra, arbolito *actual)
{

    if(letra == '.')
    {
        return actual->izq;
    }

    else if(letra == '-')
    {
        return actual->der;
    }
    else if(letra == ' ')
    {
        return actual;
    }
    return actual;

}

/*
 * Entrada: Nombre del archivo.
 * Salida: línea obtenida del archivo.
 * Proceso: Asigna memoria al puntero del string a obtener, abre el archivo en modo de lectura y evalúa si existe. Recibe su primera línea.
 */
char *leer_archivo(char nomarch[100]) {
    char *linea = (char*)malloc(200*sizeof(char)); //Se asigna un espacio de memoria para retornar el puntero al string.

    arch = fopen(nomarch, "r");

    if (arch == NULL) {
        printf("El archivo no exise.");
        exit(1);
    }
    fgets(linea, 200, arch); //Recibe el string del archivo
    return linea;
}

/*
 * Entrada: Nombre del archivo, string a traducir
 * Salida: Escritura en el archivo.
 * Proceso: Abre el archivo en modo de adjuntar e inserta un salto de linea. Recorre la línea a traducir y envía cada
 * caracter a la traducción. Lo modifica en el archivo cuando encuentra un espacio, e inserta un espacio si encuentra
 * dos consecutivos.
 */
void morseAEspanol(char nomarch[100], char linea[4000])
{
    arbolito *act = T;
    arch = fopen(nomarch, "a");
    fputc('\n', arch); //Se inserta un salto de linea.

    for(int i=0;i<=strlen(linea);i++)
    {
        if(linea[i] == ' ' && linea[i-1] != ' ')
        {
            fputc(act->letra, arch);
            act = T;
        }
        else if(linea[i] == ' ')
        {
            fputc(' ',arch);
        }
        act = traduccion(linea[i], act);
    }
    fputc(act->letra,arch);
}

/*
 * Entrada: Nada
 * Salida: Nada (Interacción por consola)
 * Proceso: Se mantiene en el bucle mientras la opción no sea 3. Obtiene del usuario el tipo de traducción a realizar y
 * el nombre del archivo, y lo envía a la función correspondiente.
 */

void menu()
{
    int opcion = 0;
    char nomarch[100];
    char *linea;
    while(opcion != 3)
    {
        fflush(stdin);
        system("cls");
        printf("\n1.- Lenguaje natural a codigo morse.\n2.- Codigo morse a lenguaje natural.\n3.- Salir\nIngresa una opcion\n>>");
        scanf("%d", &opcion);
        if(opcion == 3)
        {
            return;
        }
        fflush(stdin);
        printf("\nNombre del archivo de entrada\n>>");
        gets(nomarch);
        linea = leer_archivo(nomarch);
        if(opcion == 1)
        {
            palabraAmorse(linea, nomarch);
            printf("\nCodificacion realizada.");
        }
        else if(opcion == 2)
        {
            morseAEspanol(nomarch, linea);
            printf("\nDecodificacion realizada.");
        }
        else
        {
            printf("\nopcion invalida.\n");
        }
        system("pause");
    }
}

int main()
{
    creaAB();
    menu();

}
