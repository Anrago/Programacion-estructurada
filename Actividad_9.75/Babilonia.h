// Antonio Ramos Gonzalez Mt: 372576
// 10/3/2023 || 10/12/2023
// Esta biblioteca contiene las funciones que usare durante proximas practicas
// Babilonia
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int valid(const char msg[], int lim_inf, int lim_sup);
void vectRand(int vect[], int m, int lim_inf, int lim_sup);
void PrintVect(int vect[], int m);
void OrderVect(int vect[], int m);
int SearchVect(int vect[], int m, int num);
int bisiesto(int year);
// Cadenas
void mayusculas(char cad[]);
void validCad(const char msg[], char cad[]);
void solo_consonantes(char cad[], int i, char conso[]);

// Genera numero aleatorios no repetidos en un vector
void vectRand(int vect[], int m, int lim_in, int lim_sup)
{
    int i, x, cont, j, ran; // variables locales
    x = (lim_sup - lim_in) + 1;

    for (i = 0; i < m; i++) // llama a los vectores mediante su indice
    {
        do // ciclo encargado de validar que no se repitan los numeros
        {
            cont = 0;                    // se encargara de guardar la validacion
            ran = (rand() % x) + lim_in; // genera numero random

            for (j = 0; j < i; j++) // llama a los vectores mediante su indice
            {
                if (vect[j] == ran) // valida que el valor random no se igual a los ya generados
                {
                    cont = 1;
                }
            }

        } while (cont != 0); // repite el ciclo en caso de que se repitan los numeros

        vect[i] = ran; // se asigna el valor random al vecotor
    }
}

// Imprime vector
void PrintVect(int vect[], int m)
{
    int i; // variable local, se encargara de acceder a los indices de los vectores
    system("CLS");
    printf("VECTOR \n");
    printf("---------------------\n");
    for (i = 0; i < m; i++) // ciclo que controla la impresion del vector 1
    {
        printf("[%d]\n", vect[i]); // imprime el vector 1
    }
    system("PAUSE");
}

// valida las opciones
int valid(const char msg[], int lim_in, int lim_sup)
{
    char cad[10]; // cadena que leera un numero
    int opc;      // guardara un numer

    do
    {
        printf("%s", msg);
        fflush(stdin);
        gets(cad);       // lee el un numero como caracter
        opc = atoi(cad); // convierte el caracter en un numero

        if (opc < lim_in || opc > lim_sup) // imprime mensaje en caso de que no se valido el numero
        {
            system("CLS");
            printf("SOLO OPCIONES VALIDAS\n");
        }
        system("CLS");
    } while (opc < lim_in || opc > lim_sup); // valida que el numero sea correcto
    return opc;
}

// ordena un vector
void OrderVect(int vect[], int m)
{
    int i, j;
    int temp;                   // guarda valor de manera temporal
    for (i = 0; i < m - 1; i++) // Busqueda secuencial
    {
        for (j = i + 1; j < m; j++)
        {
            if (vect[j] < vect[i])
            {
                temp = vect[i];    // Guarda el valor de vect[i] en temp
                vect[i] = vect[j]; // Guarda el valor de vect[j] en vect[i]
                vect[j] = temp;    // Guarda el valor de temp en vect[j]
            }
        }
    }
}

// Busca en el vector
int SearchVect(int vect[], int m, int num)
{
    int i;                  // define contador
    for (i = 0; i < m; i++) //
    {
        if (vect[i] == num) // Busca en el vector el numero buscado
        {
            return i; // si encuentra el valor, retorna el valor del indice
        }
    }
    return -1; // si no encuentra el valor, retorna -1
}

// año bisiesto
int bisiesto(int year)
{

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }

    return 0;
}
//*********************Cadenas*********************

void mayusculas(char cad[])
{
    int j = 0, i;
    i = strlen(cad); // llama a la funcion para calcular la cantidad de caracteres
    while (j < i)
    {
        if (cad[j] >= 'a')
        {
            if (cad[j] <= 'z')
            {
                cad[j] -= 32; // resta 32 en codigo ASCCI volviendo las minusculas a mayusculas
            }
        }
        j++;
    }
}

// RGA_Act7_Pt2_10_932
void validCad(const char msg[], char cad[])
{
    int band, i, len;
    band = 0;
    do
    {

        system("CLS");
        if (band == 1)
        {
            printf("CARACTER NO VALIDO\n");
        }
        band = 0;
        i = 0;

        printf("%s", msg);
        fflush(stdin);
        gets(cad);
        mayusculas(cad);

        len = strlen(cad);

        if (cad[0] == ' ') // no puede iniciar con espacios
        {
            band = 1;
        }

        if (cad[i - 1] == ' ') // no puede terminar con espacios
        {
            band = 1;
        }
        i = 0;
        while (i < len)
        {
            if (cad[i] == ' ')
            {
                if (cad[i + 1] == ' ') // verifica que no haya 2 espacios seguidos
                {
                    band = 1;
                }
            }
            i++;
        }

        i = 0;
        while (i < len) // verifica que los caracteres dados sean en mayusculas
        {
            if (cad[i] > 'Z')
            {
                band = 1;
            }
            else
            {
                if (cad[i] < 'A')
                {
                    if (cad[i] != ' ')
                    {
                        if (cad[i] == -92 || cad[i] == -91)
                        {
                            cad[i] = 'X';
                        }
                        else
                        {
                            if ((unsigned char)cad[i] == 154 )
                            {
                                cad[i] = 'U';
                            }
                            else
                            {
                                band = 1;
                            }
                        }
                        
                    }
                }
            }
            i++;
            ;
        }

    } while (band != 0);
}

void solo_consonantes(char cad[], int i, char conso[])
{
    system("CLS");
    int j = 0;
    int k = 0;
    while (j < i)
    {
        // if que se encarga de analizar si los caracteres son vocales o consonantes
        if (cad[j] != 'A')
        {
            if (cad[j] != 'E')
            {
                if (cad[j] != 'I')
                {
                    if (cad[j] != 'O')
                    {
                        if (cad[j] != 'U')
                        {
                            conso[k] = cad[j];
                            k++;
                        }
                    }
                }
            }
        }

        j++; // controla el ciclo
    }
    printf("\n");
}