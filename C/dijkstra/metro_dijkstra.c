#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Variables globales
char estaciones[126][40];
int **Grafo;

//FUNCIONES DE LECTURA Y ESTACIONES DEL METRO
/*
 ENTRADA: nula
 SALIDA: nula
 PROCESO: inicializa el grafo rellenando con 0 sus casillas
 */
void inicializar(void)
{
    Grafo = calloc(126, sizeof(int*));
    for(int i=0; i<126;i++){
        Grafo[i] = calloc(126, sizeof(int));
    }
    if(Grafo == NULL)
    {
        printf("No hay memoria suficiente para generar la matriz");
        exit(1);
    }
}
/*
 ENTRADA: nombre de una estacion
 SALIDA: indice asociado a la estación
 PROCESO: busca dentro de las filas de la matriz "estaciones" para indicar en que posición
 se ubica esta y así poder compararla dentro del Grafo asociado. Si la estación está mal
 escrita o no se encontrase: la función lo indica por pantalla.
 */
int buscaPorEstacion(char nomEstacion[40])
{
    int i;

    for(i=0 ;i<126 ;i++)
    {
        if(strcmp(estaciones[i],nomEstacion) == 0) //revisa si ambos strings son iguales
        {
            return i;
        }
    }
    printf("La estacion no fue encontrada\n\n");
    exit(1);
}
/*
 ENTRADA: nula
 SALIDA: nula
 PROCESO:
    Primer proceso: revisa si el archivo "metro.txt" se encuentra en el directorio para poder leerlo.
    Si no lo encuentra se indica por pantalla y luego se termina la ejecución.

    Segundo proceso: lee todas las estaciones escritas en el archivo y las guarda en la matriz de
    listado "estaciones"

    Tercer proceso: una vez confirmado el archivo reescribe el grafo con la información asociada a
    sus costos y arcos entre estaciones. Lo hace de forma simétrica al tratarse de un grafo NO
    dirigido.
 */
void leeArchivo(void)
{
    FILE *archivo;
    int numNodos, i, largo;
    char linea[200];
    //PRIMER PROCESO
    archivo = fopen("metro.txt","r");
    //valisaci�n de la existencia del archivo (fopen)
    if(archivo == NULL)
    {
        printf("El archivo 'metro.txt' no se encuentra en el directorio");
        exit(1);
    }
    //SEGUNDO PROCESO
    fscanf(archivo, "%i",&numNodos); //obtiene la primera linea de el archivo
    //Se crea listado de estaciones asociado a un indice
    for(i=0;i<=126;i++)
    {
        fgets(linea,200,archivo);

        //Se utiliza para quitar el '\n' de cada una de las lineas
        largo = strlen(linea);
        linea[largo-1] = '\0';

        if(strlen(linea) != 0)
        {
            strcpy(estaciones[i-1],linea); //Copia linea dentro de estaciones, correspondiendo con su indice
        }
    }
    //TERCER PROCESO
    //definicion de variables
    char *estacion1, *estacion2;
    int distancia,j;
    i = 0;
    j = 0;
    while(!feof(archivo)
    {
        fgets(linea,200,archivo);
        //Se utiliza para quitar el '\n' de cada una de las lineas
        largo = strlen(linea);
        linea[largo-1] = '\0';

        //Separa las lineas leidas por estacion 1, estacion2, distancia
        estacion1 = strtok(linea, ",");
        estacion2 = strtok(NULL, ",");
        distancia = atoi(strtok(NULL, ","));

        //Convierte los nombres de las estaciones en indices, para escribir la "distancia" en el "Grafo"
        i = buscaPorEstacion(estacion1);
        j = buscaPorEstacion(estacion2);

        //Ingresa las distancias entre estaciones de forma simetrica, ya que el grafo es no dirigido
        Grafo[i][j]= distancia;
        Grafo[j][i]= distancia;
    }


}
/*
 ENTRADA: array de caracteres de tamaño 200 caracteres
 SALIDA: nula
 PROCESO: el array entregado hacia la funcion se utiliza como variable auxiliar para separarla en
 2 estaciones. Luego coloca estas con un valor de 0 para realizar el corte, al ser simétrica se
 guarda en casillas analogas
 */
//Caso 3
void corte(char auxCorte[200])
{
    char *conCor1,*conCor2;
    int index_c1, index_c2;
    //Separa lo ingresado por el usuario
    conCor1 = strtok(auxCorte, ",");
    conCor2 = strtok(NULL, "\n");
    //Transforma las estaciones en indices del grafo
    index_c1 = buscaPorEstacion(conCor1);
    index_c2 = buscaPorEstacion(conCor2);
    //Realiza el corte en el grafo al colocar los arcos como 0
    Grafo[index_c1][index_c2] = 0;
    Grafo[index_c2][index_c1] = 0;
}



/*Definicion de constantes: */
#define numNodos 126
#define infinito 3000000

//DIJKSTRA
bool Visitado[numNodos];
float Costo[numNodos];
int NodoAnterior[numNodos];
int Camino[numNodos];
//int Grafo[numNodos][numNodos];

void inicializaVisitados()
{
    int i;

    for(i=0; i<numNodos; i++)
    {
        Visitado[i] = false;
    }
}
/*
 ENTRADA: nodo inicial, nodo final y la opcion ingresada que sería la operacion a realizar en forma
 de un entero
 SALIDA: nula
 PROCESO: evalua y recorre el array de nodos anteriores hasta encontrar el nodo el inicial ingresado
 Dependiendo de la opcion ingresada muestra por pantalla la distancia mínima o ruta asociada al recorrido
 del nodo muestra cada elemento de la lista "estaciones" que coincide con el camino entregado por la
 funcion "Dijkstra" desde el nodo inicial
 */
void imprimeCaminoYCosto(int v0, int vf, int opcion)
{
    int i, nodo;

    i = 0;
    Camino[i] = vf;
    i++;
    nodo = NodoAnterior[vf];
    while(nodo != v0)
    {
        Camino[i] = nodo;
        i++;
        nodo = NodoAnterior[nodo];
    }
    Camino[i] = nodo;
    if (Costo[vf] == infinito)
    {
        printf("\nNo existe camino.\n");
        return;
    }
    switch (opcion){
        case 1:
            printf("\nDistancia minima: %.2f km\n", Costo[vf]/1000);
        break;
        case 2:
            printf("\nRuta: ");
        break;
        case 3:
            printf("\nRuta alternativa: ");
        break;

    }

    if(opcion == 2 || opcion == 3)

    {
        for (; i>0; i--)
        {
            nodo = Camino[i];

            printf("%s, ", estaciones[nodo]);
        }
        nodo = Camino[i];
        printf("%s.", estaciones[nodo]);
        printf("\n");
    }
}
int cantidadNodosSinVisitar()
{
    int i, cont;

    i = 0;
    cont = 0;

    for(i=0; i<numNodos; i++)
    {
        if (!Visitado[i])
        {
            cont++;
        }
    }
    return cont;
}
int nodoMinimoCostoSinVisitar()
{
    int i, nodo, minimo;
    bool esElPrimero;

    esElPrimero = true;
    i = 0;
    for(i=0; i<numNodos; i++)
    {
        if (!Visitado[i])
        {
            if (esElPrimero)
            {
                minimo = Costo[i];
                nodo = i;
                esElPrimero = false;
            }
            else
            {
                if (Costo[i] < minimo)
                {
                    minimo = Costo[i];
                    nodo = i;
                }
            }
        }
    }
    return nodo;
}
void Dijkstra(int v0)
{
    int i, j, nodoSeleccionado;

    inicializaVisitados();  //Inicialmente todos los nodos están sin visitar (arreglo "Visitados" parte con "falsos").
    Visitado[v0] = true;    //Se marca como visitado a v0
    for(i=0;i<numNodos;i++)
    {
        if (Grafo[v0][i] == 0)  //Si el nodo i no tiene un arco directo desde v0 entonces:
        {
            Costo[i] = infinito;     //El costo del nodo i es infinitoinito
        }
        else
        {
            Costo[i] = Grafo[v0][i];    //Si i tiene un arco directo el costo al nodo es el costo del arco desde v0.
        }
        NodoAnterior[i] = v0;   //El nodo anterior de todos los nodos es v0 (valor entre par�ntesis)
    }
    while (cantidadNodosSinVisitar()>0)
    {
        nodoSeleccionado = nodoMinimoCostoSinVisitar(); //Escoge al nodo con menor costo y que no est� visitado.

        Visitado[nodoSeleccionado] = true;  //El nodo escogido se marca como visitado.
        for(j=0;j<numNodos;j++)
        {
            if ((Grafo[nodoSeleccionado][j] != 0) && (!Visitado[j])) //Si el nodo j es adyacente al nodo elegido, y no est� visitado:
            {
                if (Costo[nodoSeleccionado] + Grafo[nodoSeleccionado][j] < Costo[j]) //Si el costo es menor a trav�s del nodo elegido:
                {
                    Costo[j] = Costo[nodoSeleccionado] + Grafo[nodoSeleccionado][j]; //Se actualiza el costo para llegar al adyacente.
                    NodoAnterior[j] = nodoSeleccionado; //Se actualiza el nodo anterior para llegar al adyacente.

                }
            }
        }
    }
}

int main()
{
    //Definición de variables
    int opcion, index_so, index_sd;
    char estacion_origen[200];
    char estacion_destino[200];
    char temp[10];
    //Caso 3
    char auxCorte1[200], auxCorte2[200];

    //Creación de matriz
    inicializar();
    leeArchivo();

    //Creacion de Menu
    do
    {
        printf("\nSeleccione opcion: \n1) Distancia entre estaciones.\n2) Ruta entre estaciones.\n3) Tramo alternativo en caso de corte.\n4) Salir\n>>");
        fgets(temp,10,stdin);
        opcion = atoi(temp);

        switch(opcion)
        {

            case 1:
                printf("\nEstacion de origen:");
                gets(estacion_origen);
                index_so = buscaPorEstacion(estacion_origen);

                printf("Estacion de destino:");
                gets(estacion_destino);
                index_sd = buscaPorEstacion(estacion_destino);

                Dijkstra(index_so);
                imprimeCaminoYCosto(index_so, index_sd,opcion);

            break;
            case 2:
                printf("\nEstacion de origen:");
                gets(estacion_origen);
                index_so = buscaPorEstacion(estacion_origen);

                printf("Estacion de destino:");
                gets(estacion_destino);
                index_sd = buscaPorEstacion(estacion_destino);

                Dijkstra(index_so);
                imprimeCaminoYCosto(index_so, index_sd,opcion);

            break;
            case 3:
                printf("\nEstacion de origen:");
                gets(estacion_origen);
                index_so = buscaPorEstacion(estacion_origen);

                printf("Estacion de destino:");
                gets(estacion_destino);
                index_sd = buscaPorEstacion(estacion_destino);

                printf("Conexion cortada 1:");
                fgets(auxCorte1, 200, stdin);
                corte(auxCorte1);


                printf("Conexion cortada 2:");
                fgets(auxCorte2,200,stdin);
                corte(auxCorte2);

                Dijkstra(index_so);
                imprimeCaminoYCosto(index_so, index_sd,opcion);

                //libera el espacio de memoria
                for(int i = 0; i < 126; i++)
                {
                    free(Grafo[i]);
                }
                free(Grafo);

                inicializar();
                leeArchivo();
            break;

        }
    } while(opcion != 4);

    printf("\n\n");
    return 0;
}
