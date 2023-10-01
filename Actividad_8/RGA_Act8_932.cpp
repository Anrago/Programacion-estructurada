// Antonio Ramos Gonzalez Mt: 372576
// 9/12/2023 || 9/24/2023
// Funciones e Introduccion a Arreglos en C
// RGA_Act8_932
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int msg();
void menu();
int validar(const char msg[], int li_in, int li_sup);
void vect_1(int vect1[], int m);
void vect_2(int vect2[], int lim_in, int lim_sup);
void vect_3(int vect1[], int vect2[], int vect3[], int m);
void imprimir_vetores(int vect1[], int vect2[], int vect3[], int m, int n);
void matriz(int vect1[], int vect2[], int mtz[][4], int m, int v);
void imprimir_matriz(int mtz[][4],int m);

int main()
{
    srand(time(NULL));//genera semilla para numeros aleatorios
    menu();
    return 0;
}

int msg()
{
    short int opc;//guardara la decision del usuario
    system("CLS");
    printf("MENU\n");
    printf("1.- LLENA VECTOR 1(MANUALMENTE)\n");
    printf("2.- LLENA VECTOR 2(ALEATORIAMENTE)\n");
    printf("3.- LLENA VECTOR 3(VECTOR 1 Y VECTOR 2)\n");
    printf("4.- IMPRIMIR VECTOES\n");
    printf("5.- LLENA MATRIZ(VECTOR 1 Y VECTOR 2)\n");
    printf("6.- IMPRIMIR MATRIZ\n");
    printf("0.- SALIR\n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%hd", &opc);//lee la decicion del usuario
    return opc;//retorna opc
}

void menu()
{
    int vect1[10], vect2[10], vect3[20];//definimos el tamaño de los vetores
    int mtz[4][4];//definimos el tamaño de la matriz
    short int opc;
    do
    {
        opc = msg();//leemos el valor retornado de la funcion msg
        switch (opc)
        {
        case 1:
            vect_1(vect1, 10);//se manda vect1, asi como su tamaño a la funcion

            break;
        case 2:
            vect_2(vect2, 1, 20);//se manda vect2, asi como su limite de datos a la funcion
            break;
        case 3:
            vect_3(vect1, vect2, vect3, 20);//se manda vect1,vect2 para llenar vect3
            break;
        case 4:
            imprimir_vetores(vect1, vect2, vect3, 10, 20);//se manda vect1,vect2 y vect3 para imprimirlos
            break;
        case 5:
            matriz(vect1, vect2, mtz, 4, 10);//se manda vect1,vect2 para llenar mtz
            break;
        case 6:
            imprimir_matriz(mtz,4);//se manda mtz para imprimirla
            break;
        default:
            break;
        }

    } while (opc != 0);
}

//valida los datos que entraran en la funcion vect_1
int validar(const char msg[], int li_in, int li_sup)
{
    char cad[3];//cadena que leera un numero
    int num;//guardara un numer

    do
    {
        printf("%s", msg);
        fflush(stdin);
        gets(cad);//lee el un numero como caracter
        num = atoi(cad);//convierte el caracter en un numero

        if (num < li_in || li_sup)//imprime mensaje en caso de que no se valido el numero
        {
            system("CLS");
            printf("SOLO NUMEROS DEL 30 AL 70\n");
        }
    } while (num < li_in || num > li_sup);//valida que el numero sea correcto
    return num;
}

//llena un vector mediante el usuario
//RGA_Act8_01_932
void vect_1(int vect1[], int m)
{
    int i, val;//variables locales
    system("CLS");
    printf("LLENA EL VECTOR\n");
    printf("SOLO NUMEROS DEL 30 al 70\n");
    system("PAUSE");
    for (i = 0; i < m; i++)//ciclo que controla el llenado del vector
    {
        system("CLS");
        printf("Vec[%d]", i + 1);
        val = validar(" =  ", 30, 70);//manda a llamar la funcion validar
        vect1[i] = val;//asigna el valor validado al vector
    }
    system("CLS");
    printf("**************************\n");
    printf("El vector ha sido llenado\n");
    printf("**************************\n");
    system("PAUSE");
}

//llena un vector con numeros aleatorios
//RGA_Act8_02_932
void vect_2(int vect2[], int lim_in, int lim_sup)
{
    int i, x, cont, j, ran;//variables locales
    x = (lim_sup - lim_in) + 1;

    for (i = 0; i < 10; i++)//llama a los vectores mediante su indice
    {
        do//ciclo encargado de validar que no se repitan los numeros
        {
            cont = 0;//se encargara de guardar la validacion
            ran = (rand() % x) + lim_in;//genera numero random

            for (j = 0; j < i; j++)//llama a los vectores mediante su indice
            {
                if (vect2[j] == ran)//valida que el valor random no se igual a los ya generados
                {
                    cont = 1;
                }
            }

        } while (cont != 0);//repite el ciclo en caso de que se repitan los numeros

        vect2[i] = ran;//se asigna el valor random al vecotor
    }
    system("CLS");
    printf("**************************\n");
    printf("El vector ha sido llenado\n");
    printf("**************************\n");
    system("PAUSE");
}

//llena un vector con los vectores 1 y 2
//RGA_Act8_03_932
void vect_3(int vect1[], int vect2[], int vect3[], int m)
{
    int i, j;//variables locales
    system("CLS");
    for (i = 0, j = 10; i < m / 2; i++, j++)//se encargara de acceder a los indices de los vectores
    {
        vect3[i] = vect1[i];//asigna el valor del vector 1 al vector 3 
        vect3[j] = vect2[i];//asigna el valor del vector 2 al vector 3
    }

    printf("**************************\n");
    printf("El vector ha sido llenado\n");
    printf("**************************\n");
    system("PAUSE");
}

//imprime todos los vectores
//RGA_Act8_04_932
void imprimir_vetores(int vect1[], int vect2[], int vect3[], int m, int n)
{
    int i;//variable local, se encargara de acceder a los indices de los vectores
    system("CLS");
    printf("VECTOR 1\n");
    printf("---------------------\n");
    for (i = 0; i < m; i++)//ciclo que controla la impresion del vector 1
    {
        printf("[%d]\n",vect1[i]);//imprime el vector 1
    }
    printf("---------------------");
    printf("\nVECTOR 2\n");
    printf("---------------------\n");

    for (i = 0; i < m; i++)//ciclo que controla la impresion del vector 2
    {
        printf("[%d]\n",vect2[i]);//imprime el vector 2
    }
    printf("---------------------");
    printf("\nVECTOR 3\n");
    printf("---------------------\n");
    for (i = 0; i < n; i++)//ciclo que controla la impresion del vector 3
    {
        printf("[%d]\n",vect3[i]);//imprime el vector 3
    }
    system("PAUSE");
}

//llena matriz con vector 1 y 2
//RGA_Act8_05_932
void matriz(int vect1[], int vect2[], int mtz[][4], int m, int v)
{
    system("CLS");
    int fil, colum,j=0, i = 0;//variables locales que accederan a los indices de los vectores y la matriz
    for (fil = 0; fil < m; fil++)//ciclo que controla las filas de la matriz
    {

        for (colum = 0; colum < 4; colum++)//ciclo que controla las columnas de la matriz
        {
            if (i<v)//controla con que se llenara la matriz
            {
                mtz[fil][colum]=vect1[i];//asigna el valor de vect1 a la matriz
                i++;//aumenta contador para acceder al indice del vect1
            }
            else
            {
                mtz[fil][colum]=vect2[j];// asigna el valor de vect2 a la matriz
                j++;//aumenta contador para acceder al indice del vect2
            }
            
        }
    }
     printf("**************************\n");
    printf("La matriz ha sido llenado\n");
    printf("**************************\n");
    system("PAUSE");
}

//imprime la matriz
//RGA_Act8_06_932
void imprimir_matriz(int mtz[][4],int m)
{
    int fil,colum;//valiables locales
    system("CLS");
    printf("\tMATRIZ 4x4\n");
    for ( fil = 0; fil < m; fil++)//ciclo que controla las filas de la matriz
    {
        
        for ( colum = 0; colum < 4; colum++)//ciclo que controla las columnas de la matriz
        {
            printf("[%d]\t",mtz[fil][colum]);//imprime matriz
        }
        printf("\n");
        
    }
    system("PAUSE");
    
}
















