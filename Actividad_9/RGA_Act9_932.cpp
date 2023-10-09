// Antonio Ramos Gonzalez Mt: 372576
// 3/10/2023 || 10/5/2023
// Menu de eleciones para el llenado de matrices y vectores
// RGA_Act9_932

// Mandamos a llamra nuestra libreria
#include "Babilonia.h"
void MatRand(int mtz[][4], int m, int n, int lim_in, int lim_sup);
void PrintMat(int mtz[][4], int m, int n);

// Declaramos nuestras funciones
int msg();
void menu();

int main()
{
    // Genera semilla para numeros aleatoreos
    srand(time(NULL));
    menu();
    return 0;
}

// Menu de eleccion
int msg()
{
    system("CLS");
    printf("MENU\n");
    printf("1.-llenar vector\n");
    printf("2.-llenar matriz\n");
    printf("3.-imprimir vector\n");
    printf("4.-imprimir matriz\n");
    printf("5.-ordenar vector\n");
    printf("6.-buscar en vector\n");
    printf("0.-salir\n");
    printf("Elije una opcion");
    // Retorna el valor de de eleccion
    return valid("Escoje una opcion: ", 0, 6);
}

void menu()
{
    // Variables que definen a nuestro vector y matriz
    system("CLS");
    int vect[15];
    int mtz[4][4];
    int opc, bus, num;

    do
    {
        // Recive el valor de nuestro menu
        opc = msg();
        switch (opc) //
        {
        case 1:
            vectRand(vect, 15, 100, 200); // Manda a llenar el vector de con numeros aleatorios
            system("CLS");
            printf("**************************\n");
            printf("El vector ha sido llenado\n");
            printf("**************************\n");
            system("PAUSE");
            break;
        case 2:
            MatRand(mtz, 4, 4, 1, 16); // Manda a llenar la matriz con numeros aleatorios
            printf("**************************\n");
            printf("La matriz ha sido llenada\n");
            printf("**************************\n");
            system("PAUSE");
            break;
        case 3:
            PrintVect(vect, 15); // Imprime vector
            break;
        case 4:
            PrintMat(mtz, 4, 4); // Imprime matriz
            break;
        case 5:
            OrderVect(vect, 15); // Ordena vector de menor a mayor
            system("CLS");
            printf("**************************\n");
            printf("El vector ha sido ordenado\n");
            printf("**************************\n");
            system("PAUSE");
            break;
        case 6:

            system("CLS");
            bus = valid("Que numero deseas buscar: ", 100, 200); // valoda el numero buscado dentro del rango
            num = SearchVect(vect, 15, bus);                     // busca numero en vector
            system("CLS");
            if (num != -1) // Controla si se encuentra el numero fue encontrado
            {
                printf("Numero encontrado en el indice: %d\n", num); // imprime el indice del numero encontrado
            }
            else
            {
                printf("Numero no encontrado\n");
            }
            system("PAUSE");
            break;

        default:
            break;
        }
    } while (opc != 0); // Controla que se repita el ciclo
}

// llena la matriz de manera random
void MatRand(int mtz[][4], int m, int n, int lim_in, int lim_sup)
{
    int vect[16];
    int fil, colum, i = 0;
    vectRand(vect, 16, lim_in, lim_sup); // Ob
    system("CLS");
    // variables locales que accederan a los indices de los vectores y la matriz
    for (fil = 0; fil < m; fil++) // ciclo que controla las filas de la matriz
    {

        for (colum = 0; colum < n; colum++) // ciclo que controla las columnas de la matriz
        {

            mtz[fil][colum] = vect[i]; // asigna el valor de vect1 a la matriz
            i++;                       // aumenta contador para acceder al indice del vect1
        }
    }
}

// imprime la matriz
void PrintMat(int mtz[][4], int m, int n)
{
    int fil, colum; // valiables locales
    system("CLS");
    printf("\tMATRIZ 4x4\n");
    for (fil = 0; fil < m; fil++) // ciclo que controla las filas de la matriz
    {

        for (colum = 0; colum < n; colum++) // ciclo que controla las columnas de la matriz
        {
            printf("[%d]\t", mtz[fil][colum]); // imprime matriz
        }
        printf("\n");
    }
    system("PAUSE");
}
