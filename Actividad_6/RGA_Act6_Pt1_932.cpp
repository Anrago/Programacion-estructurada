// Antonio Ramos Gonzalez Mt: 372576
// 9/12/2023
// Parte 1
// RGA_Act6_Pt1_932
#include <stdio.h>
#include <stdlib.h>

int msg();
void menu();
void fibonaccis();
void fib_f(void);
void fib_w(void);
void fib_d(void);
void factoriales();
void fact_f(void);
void fact_w(void);
void fact_d(void);
void digitos();
void dig_f(void);
void dig_w(void);
void dig_d(void);

int main()
{
    menu();
    return 0;
}

int msg()
{
    short int opc;
    system("CLS");
    printf("Menu\n");
    printf("1.-Fibonacci\n");
    printf("2.-Factorial\n");
    printf("3.-Digitos de un numero\n");
    printf("0.-salir\n");
    printf("Elige una opcion: ");
    scanf("%hd", &opc);
    return opc;
}

void menu()
{
    short int opc;
    do
    {

        opc = msg();
        system("CLS");
        switch (opc)
        {
        case 1:
            fibonaccis();
            break;
        case 2:
            factoriales();
            break;
        case 3:
            digitos();
            break;
        default:
            break;
        }
    } while (opc != 0);
}

// Menu de fibonacci
void fibonaccis(void)
{
    short int opc;
    do
    {
        system("CLS");
        printf("Menu fibonacci\n");
        printf("1.-Fibonacci - for\n");
        printf("2.-Fibonacci - while\n");
        printf("3.-Fibonacci - do-while\n");
        printf("0.-Volver al menu principal\n");
        printf("Elige una opcion: ");
        scanf("%hd", &opc);
        switch (opc)
        {
        case 1:
            fib_f();
            break;
        case 2:
            fib_w();
            break;
        case 3:
            fib_d();
            break;
        }
    } while (opc != 0);
}

// Numeros de fionacci con ciclo for
void fib_f(void)
{
    int n_ant, n_act, i, n;
    int result;
    system("CLS");
    n_ant = -1;
    n_act = 1;
    printf("Cuantos numeros de fibonacci quieres: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        result = n_act + n_ant;
        printf("%d,", result);
        n_ant = n_act;
        n_act = result;
    }
    printf("\n");
    system("PAUSE");
}

// Numeros de fionacci con ciclo while
void fib_w(void)
{
    int n_ant, n_act, i, n;
    int result;
    system("CLS");
    i = 0;
    n_ant = -1;
    n_act = 1;
    printf("Cuantos numeros de fibonacci quieres: ");
    scanf("%d", &n);
    while (i < n)
    {
        result = n_act + n_ant;
        printf("%d,", result);
        n_ant = n_act;
        n_act = result;
        i++;
    }
    printf("\n");
    system("PAUSE");
}

// Numeros de fionacci con ciclo do-while
void fib_d(void)
{
    int n_ant, n_act, i, n;
    int result;
    system("CLS");
    i = 0;
    n_ant = -1;
    n_act = 1;
    printf("Cuantos numeros de fibonacci quieres: ");
    scanf("%d", &n);
    do
    {
        result = n_act + n_ant;
        printf("%d,", result);
        n_ant = n_act;
        n_act = result;
        i++;
    } while (i < n);
    printf("\n");
    system("PAUSE");
}

// Menu de factoriales
void factoriales(void)
{
    short int opc;
    do
    {
        system("CLS");
        printf("Menu Factorial\n");
        printf("1.-Factorial - for\n");
        printf("2.-Factorial - while\n");
        printf("3.-Factorial - do-while\n");
        printf("0.-Volver al menu principal\n");
        printf("Elige una opcion: ");
        scanf("%hd", &opc);
        switch (opc)
        {
        case 1:
            fact_f();
            break;
        case 2:
            fact_w();
            break;
        case 3:
            fact_d();
            break;
        }
    } while (opc != 0);
}

// Resultado de factorial con ciclo for
void fact_f(void)
{
    int n, i, fact;
    system("CLS");
    printf("Dame el numero que desee el factorial: ");
    scanf("%d", &n);
    fact = n;
    for (i = 1; i < n; i++)
    {
        fact *= i;
    }
    printf("El resultado es:%d \n", fact);
    system("PAUSE");
}

// Resultado de factorial con ciclo whil
void fact_w(void)
{
    int n, i, fact;
    i = 1;
    system("CLS");
    printf("Dame el numero que desee el factorial: ");
    scanf("%d", &n);
    fact = n;
    while (i < n)
    {
        fact *= i;
        i++;
    }
    printf("El resultado es:%d \n", fact);
    system("PAUSE");
}

// Resultado de factorial con ciclo do-while
void fact_d(void)
{
    int n, i, fact;
    i = 1;
    system("CLS");
    printf("Dame el numero que desee el factorial: ");
    scanf("%d", &n);
    fact = n;
    do
    {
        fact *= i;
        i++;
    } while (i < n);
    printf("El resultado es:%d \n", fact);
    system("PAUSE");
}

// Menu digitos de un numero
void digitos(void)
{
    short int opc;
    do
    {
        system("CLS");
        printf("Menu digitos\n");
        printf("1.-digitos - for\n");
        printf("2.-digitos - while\n");
        printf("3.-digitos - do-while\n");
        printf("0.-Volver al menu principal\n");
        printf("Elige una opcion: ");
        scanf("%hd", &opc);
        switch (opc)
        {
        case 1:
            dig_f();
            break;
        case 2:
            dig_w();
            break;
        case 3:
            dig_d();
            break;
        }
    } while (opc != 0);
}

// obtener los digitos de un numero con ciclo for
void dig_f(void)
{
    int n, dig, i;
    system("CLS");
    printf("Dame el numero: ");
    scanf("%d", &n);
    for (dig = 1, i = 0; dig < n; i++)
    {
        dig *= 10;
    }
    printf("El numero %d tiene %d digitos\n", n, i);
    system("PAUSE");
}

// obtener los digitos de un numero con ciclo while
void dig_w(void)
{
    int n, dig, i;
    i = 0;
    dig = 1;
    system("CLS");
    printf("Dame el numero: ");
    scanf("%d", &n);
    while (dig < n)
    {
        dig *= 10;
        i++;
    }
    printf("El numero %d tiene %d digitos\n", n, i);
    system("PAUSE");
}
// obtener los digitos de un numero con ciclo do-while
void dig_d(void)
{
    int n, dig, i;
    i = 0;
    dig = 1;
    system("CLS");
    printf("Dame el numero: ");
    scanf("%d", &n);
    do
    {
        dig *= 10;
        i++;
    } while (dig < n);
    printf("El numero %d tiene %d digitos\n", n, i);
    system("PAUSE");
}
