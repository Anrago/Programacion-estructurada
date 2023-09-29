// Antonio Ramos Gonzalez Mt: 372576
// 9/12/2023 || 9/24/2023
// Arreglos
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
void vect_3(int vect1[],int vect2[],int vect3[] ,int m);
void imprimir_vetores(int vect1[],int vect2[],int vect3[] ,int m,int n);

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
    printf("4.- IMPRIMIR VECTOES\n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%hd", &opc);
    return opc;
}

void menu()
{
    int vect1[10], vect2[10],vect3[20];
    short int opc;
    do
    {
        opc = msg();
        switch (opc)
        {
        case 1:
            vect_1(vect1, 10);
            
            break;
        case 2:
            vect_2(vect2, 1, 20);
            break;
        case 3:
            vect_3(vect1,vect2,vect3,20);
            break;
        case 4:
            imprimir_vetores(vect1,vect2,vect3,10,20);
        default:
            break;
        }

    } while (opc != 0);
}

int validar(const char msg[], int li_in, int li_sup)
{
    char cad[3];
    int num;
    
    do
    {
        printf("%s", msg);
        fflush(stdin);
        gets(cad);
        num=atoi(cad);

        if(num<li_in || li_sup)
        {
            system("CLS");
            printf("SOLO NUMEROS DEL 30 AL 70\n");
        }
    }while(num<li_in || num>li_sup);
    return num;
}

void vect_1(int vect1[], int m)
{
    int i,val;
    system("CLS");
    printf("LLENA EL VECTOR\n");
    printf("SOLO NUMEROS DEL 30 al 70\n");
    system("PAUSE");
    for (i = 0; i < m; i++)
    {
        system("CLS");
        printf("Vec[%d]",i+1);
        val=validar(" =  ",30,70);
        vect1[i]=val;
    }
    system("CLS");
    printf("**************************\n");
    printf("El vector ha sido llenado\n");
    printf("**************************\n");
    system("PAUSE");
}

void vect_2(int vect2[], int lim_in, int lim_sup)
{
    int i, x, band, j, ran;
    x = (lim_sup - lim_in) + 1;

    for (i = 0; i < 10; i++)
    {
        do
        {
            band = 0;
            ran = (rand() % x) + lim_in;

            for (j = 0; j < i; j++)
            {
                if (vect2[j] == ran)
                {
                    band = 1;
                }
            }

        } while (band != 0);

        vect2[i] = ran;
    }
    system("CLS");
    printf("**************************\n");
    printf("El vector ha sido llenado\n");
    printf("**************************\n");
    system("PAUSE");
}

void vect_3(int vect1[],int vect2[], int vect3[],int m)
{
    int i,j;
    system("CLS");
    for (i=0,j=10; i<m/2;i++,j++)
    {
        vect3[i]=vect1[i];
        vect3[j]=vect2[i];
    }
    
    printf("**************************\n");
    printf("El vector ha sido llenado\n");
    printf("**************************\n");
    system("PAUSE");

}

void imprimir_vetores(int vect1[],int vect2[],int vect3[] ,int m,int n)
{
    int i;
    system("CLS");
    printf("ARREGLO 1\n");
    printf("---------------------\n");
    for(i=0;i<m;i++)
    {
        printf("VECT[%d]=\t%d\n",i,vect1[i]);
    }
    printf("---------------------");
    printf("\nARREGLO 2\n");
    printf("---------------------\n");

    for(i=0;i<m;i++)
    {
        printf("VECT[%d]=\t%d\n",i,vect2[i]);
    }
    printf("---------------------");
    printf("\nARREGLO 3\n");
    printf("---------------------\n");
    for(i=0;i<n;i++)
    {
        printf("VECT[%d]=\t%d\n",i,vect3[i]);
    }
    system("PAUSE");
}

















