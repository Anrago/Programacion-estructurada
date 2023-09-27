// Antonio Ramos Gonzalez Mt: 372576
// 9/12/2023 || 9/24/2023
// Arreglos
// RGA_Act8_932
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int msg();
void menu();
void vect_1(int vect1[], int lim_in, int lim_sup);
void vect_2(int vect2[], int lim_in, int lim_sup);
void vect_3();

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

int msg()
{
    short int opc;
    system("CLS");
    printf("MENU\n");
    printf("1.- LLENA VECTOR 1(MANUALMENTE)\n");
    printf("2.- LLENA VECTOR 2(ALEATORIAMENTE)\n");
    printf("3.- LLENA VECTOR 3(VECTOR 1 Y VECTOR 2)\n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%hd", &opc);
    return opc;
}

void menu()
{
    int vect1[10], vect2[10];
    short int opc, i;
    do
    {
        opc = msg();
        switch (opc)
        {
        case 1:
            vect_1(vect1, 30, 70);
            break;
        case 2:
            vect_2(vect2, 1, 20);
            for ( i = 0; i < 10; i++)
            {
                printf("%d\n",vect2[i]);
            }
            system("PAUSE");
            break;
        default:
            break;
        }

    } while (opc != 0);
}
void vect_1(int vect1[], int lim_in, int lim_sup)
{
    int i;
    system("CLS");
    printf("LLENA EL VECTOR\n");
    printf("SOLO NUMEROS DEL %d al %d\n", lim_in, lim_sup);
    for (i = 0; i < 10; i++)
    {
        do
        {
            system("CLS");
            printf("vect[%d]=", i + 1);
            scanf("%d", &vect1[i]);
            if (vect1[i] < lim_in)
            {
                printf("NUMERO MENOR NO VALIDO. INTENTE DENUEVO:\n");
            }
            if (vect1[i] > lim_sup)
            {
                printf("NUMERO MAYOR NO VALIDO. INTENTE DENUEVO:\n");
            }

        } while (vect1[i] < lim_in && vect1[i] > lim_sup);
    }
}

void vect_2(int vect2[], int lim_in, int lim_sup)
{
    int i, x,ran ,ig, j;
    x = (lim_sup - lim_in) + 1;

    for (i = 0; i < 10; i++)
    {
        do
        {
            ig=0;
            vect2[i] = (rand() % x) + lim_in;
            for (j = 0; j<i; i++)
            {
                if (vect2[i]==vect2[j])
                {
                    ig++;
                }
                
            }
        
        } while (ig!=0);
        
            
    }
}
