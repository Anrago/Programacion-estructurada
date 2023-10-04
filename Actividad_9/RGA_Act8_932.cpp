#include "bibliotecas.h"
void MatRand(int mtz[][4], int m, int n, int lim_in, int lim_sup);
void PrintMat(int mtz[][4],int m, int n);

int msg();
void menu();

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

int msg()
{
    system("CLS");
    printf("MENU\n");
    printf("1.-llenar vector\n");
    printf("2.-llenar matriz\n");
    printf("3.-imprimir vector\n");
    printf("4.-imprimir matriz\n");
    printf("5.-ordenar vector\n");
    printf("Elije una opcion");
    return valid("Escoje una opcion: ", 0, 6);
}

void menu()
{
    system("CLS");
    int vect[15];
    int mtz[4][4];
    int opc;
    do
    {
        opc = msg();
        switch (opc)
        {
        case 1:
            vectRand(vect, 15, 100, 200);
            break;
        case 2:
            MatRand(mtz, 4, 4, 1, 16);
            break;
        case 3:
            PrintVect(vect, 15);
            break;
        case 4:
            PrintMat(mtz,4,4);
            break;
        case 5:
            OrderVect(vect,15);
            break;
        default:
            break;
        }
    } while (opc != 0);
}

void MatRand(int mtz[][4], int m, int n, int lim_in, int lim_sup)
{
    int vect[16];
    int fil, colum, i = 0;
    vectRand(vect, 16, lim_in, lim_sup);
    system("CLS");
     // variables locales que accederan a los indices de los vectores y la matriz
    for (fil = 0; fil < m; fil++) // ciclo que controla las filas de la matriz
    {

        for (colum = 0; colum < n; colum++) // ciclo que controla las columnas de la matriz
        {

            mtz[fil][colum] = vect[i]; // asigna el valor de vect1 a la matriz
            i++;                        // aumenta contador para acceder al indice del vect1
        }
    }
    printf("**************************\n");
    printf("La matriz ha sido llenada\n");
    printf("**************************\n");
    system("PAUSE");
}

void PrintMat(int mtz[][4],int m,int n)
{
    int fil,colum;//valiables locales
    system("CLS");
    printf("\tMATRIZ 4x4\n");
    for ( fil = 0; fil < m; fil++)//ciclo que controla las filas de la matriz
    {
        
        for ( colum = 0; colum < n; colum++)//ciclo que controla las columnas de la matriz
        {
            printf("[%d]\t",mtz[fil][colum]);//imprime matriz
        }
        printf("\n");
        
    }
    system("PAUSE");
}







