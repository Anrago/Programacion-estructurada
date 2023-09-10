// Antonio Ramos Gonzalez Mt: 372576
// 9/10/2023
// Atividad 5
// RGA_Act5_932
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 35

int msges();
void menu();
void menor_n(void);
void par_impar(void);
void mayor_menor(void);
void nX20(void);

int main()
{
    menu();

    return 0;
}

int msges()
{
    int op;
    system("CLS");
    printf("   M  E   N   U \n");
    printf("1.- menor que n \n");
    printf("2.- par imapr \n");
    printf("3.- 200 mayor menor \n");
    printf("4.- numero multiplicado por la tabla del 20 \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}

void menu()
{
    int op;
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            menor_n();
            break;
        case 2:
            par_impar();
            break;
        case 3:
            mayor_menor();
            break;
        case 4:
            nX20();
            break;
        }

    } while (op != 0);
}

//pedir un numero positivo y entero e imprimir los numeros menores que este
void menor_n(void)
{
    int n, i;
    system("CLS");
    printf("Dame un numero entero y positivo: ");
    printf("Los numero menores que %d son: ", n);
    scanf("%d", &n);
    for (i = 1; i < n; i++)
    {
        printf("%d, ", i);
    }
    system("PAUSE");
}

//generar 40 numero aleatorios, identificar cuales son pares o impares y la suma de estos numeros
void par_impar(void)
{
    srand(time(NULL));
    int n, i, par, impar, sum_p, sum_i;
    i = 0;
    par = 0;
    impar = 0;
    sum_p = 0;
    sum_i = 0;

    system("CLS");
    while (i < 40)
    {

        n = rand() % 201;

        printf("%d\n", n);
        if (n % 2 == 0)
        {
            par++;
            sum_p = sum_p + n;
        }
        if (n % 2 != 0)
        {
            impar++;
            sum_i = sum_i + n;
        }
        i++;
    }
    printf("La cantidad de numeros pares fue: %d\n", par);
    printf("Y el resultado de la suma de los numero pares fue: %d\n", sum_p);
    printf("La cantidad de numeros impares fue: %d\n", impar);
    printf("Y el resultado de la suma de los numero impares fue: %d\n", sum_i);

    system("PAUSE");
}

//generar N(35) numero aleatorios de l 100 al 200 e identificar el numero mayor y el menor
void mayor_menor(void)
{
    int n, i, pib, me_ant = 200, ma_ant = 0;
    i = 0;
    system("CLS");
    do
    {
        n = rand() % 100 + 101;
        pib = n;

        printf("%d\n", n);
        if (pib > ma_ant)
        {
            ma_ant = pib;
        }

        if (pib < me_ant)
        {
            me_ant = pib;
        }

        i++;
    } while (i < N);
    printf("El numero mayor es: %d\n", ma_ant);
    printf("El numero menor es: %d\n", me_ant);

    system("PAUSE");
}

//pedir numero e iprimir su tabla del 20
void nX20(void)
{
    int n, i;
    system("CLS");
    printf("Dame un numero: ");
    scanf("%d", &n);
    printf("Tabla del %d\n", n);
    for (i = 1; i <= 20; i++)
    {
        printf("%d X %d=%d\n", n, i, (n * i));
    }

    system("PAUSE");
}