// Antonio Ramos Gonzalez Mt: 372576
// 9/12/2023 || 9/24/2023
// Cadenas parte 1
// RGA_Act7_Pt1_932
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int msg();
void menu();
int largo_cadena(char cad[]);
int validar(const char msg[], int ran_i, int ran_s);
void normal(char cad[]);
void invertido(char cad[], int i);
void vertical(char cad[]);
void vertical_invertido(char cad[], int i);
void piramide(char cad[], int i);
void piramide_invertida(char cad[], int i);
void piramide_a(char cad[], int i);
void piramide_invertida_e(char cad[], int i);
void solo_consonantes(char cad[], int i);
void solo_vocales(char cad[], int i);
void mayusculas(char *cad);

int main()
{
    menu();
    return 0;
}

int msg()
{
    int opc;
    system("CLS");
    printf("Menu\n");
    printf("1.-Imprimir normal\n");
    printf("2.-Imprimir invertido\n");
    printf("3.-Imprimir vertical\n");
    printf("4.-Imprimir vertical invertida\n");
    printf("5.-Imprimir piramide(termona en E)\n");
    printf("6.-Imprimir piramide invertida(termina en A)\n");
    printf("7.-Imprimir piramide(termina en A)\n");
    printf("8.-Imprimir piramide invertida(termina en E)\n");
    printf("9.-Imprimir solo consonantes\n");
    printf("10.-Imprimir solo Vocales\n");
    printf("0.-Salir\n");
    return opc = validar("Elige una opcion: ", 0, 10);
    system("CLS");
}

void menu()
{

    char cadena[30];
    int opc, i;
    system("CLS");
    mayusculas(cadena);
    i = largo_cadena(cadena);
    do
    {
        opc = msg();
        switch (opc)
        {
        case 1:
            normal(cadena);
            break;
        case 2:
            invertido(cadena, i);
            break;
        case 3:
            vertical(cadena);
            break;
        case 4:
            vertical_invertido(cadena, i);
            break;
        case 5:
            piramide(cadena, i);
            break;
        case 6:
            piramide_invertida(cadena, i);
            break;
        case 7:
            piramide_a(cadena, i);
            break;
        case 8:
            piramide_invertida_e(cadena, i);
            break;
        case 9:
            solo_consonantes(cadena, i);
            break;
        case 10:
            solo_vocales(cadena, i);
            break;
        }
    } while (opc != 0);
}

//convierte los caracteres de la cadena a mayusculas
void mayusculas(char *cad)
{
    int j = 0,i;
    printf("ingresa la cadena: ");
    fflush(stdin);
    gets(cad);
    i=largo_cadena(cad);// llama a la funcion para calcular la cantidad de caracteres
    while (j < i)
    {
        if (cad[j] >= 'a')
        {
            if (cad[j] <= 'z')
            {
                cad[j] -= 32;// resta 32 en codigo ASCCI volviendo las minusculas a mayusculas
            }
        }
        j++;
    }

}
//Obtiene el largo de una cadena
int largo_cadena(char cad[])
{
    int i = 0;
    while (cad[i] != '\0')
    {
        i++;
    }
    return i;
}

// se usa para validar los datos ingresados por el usuario
int validar(const char msg[], int ran_i, int ran_s)
{
    int num;
    char cadena[100];
    do
    {
        printf("%s", msg);
        fflush(stdin);
        gets(cadena);
        num = atoi(cadena);
    } while (num < ran_i || num > ran_s);
    return num;
}

//imprime la cadena ingresada
//RGA_Act7_Pt1_01_932
void normal(char cad[])
{
    system("CLS");
    printf("Cadena normal\n");
    for (int i = 0; cad[i] != '\0'; i++)
    {
        printf("%c", cad[i]);
    }
    printf("\n");
    system("PAUSE");
}

//Imprime la cadena invertida
//RGA_Act7_Pt1_02_932
void invertido(char cad[], int i)
{
    int j;
    system("CLS");
    printf("Cadena invertido\n");

    for (j = i - 1; j >= 0; j--)//bucle que se encarga de invertir la cadena
    {
        printf("%c", cad[j]); // imprime la cadena invertida
    }

    printf("\n");
    system("PAUSE");
}

//Imprime la cadena de manera vertical
//RGA_Act7_Pt1_03_932
void vertical(char cad[])
{
    system("CLS");
    printf("Cadena vertical\n");
    for (int i = 0; cad[i] != '\0'; i++)
    {
        printf("%c\n", cad[i]);
    }

    system("PAUSE");
}

//Imprime la cadena de manera vertical e invertida
//RGA_Act7_Pt1_04_932
void vertical_invertido(char cad[], int i)
{
    int j;
    system("CLS");
    printf("Cadena vertical invertido\n");

    for (j = i - 1; j >= 0; j--)//bucle que se encarga de invertir la cadena
    {
        printf("%c\n", cad[j]);//imprime la cadena de manera vertical
    }

    system("PAUSE");
}

//imprime la cadena eliminando el ultimo caracter hasta quedar primer caracter
//RGA_Act7_Pt1_05_932
void piramide(char cad[], int i)
{
    int j;
    system("CLS");
    printf("Priramide(elimina ultimo)\n");

    while (i != 0)//Respite el ciclo para ir eliminando los caracteres
    {
        for (j = 0; j < i; j++)// imprime la cadena
        {
            printf("%c", cad[j]);
        }
        printf("\n");
        i--;// cada vez que disminuye se elimina el ultimo carcter de la cadena
    }
    system("PAUSE");
}

//imprime la cadena invertida eliminando el ultimo caracter hasta quedar el primer caracter
//RGA_Act7_Pt1_06_932
void piramide_invertida(char cad[], int i)
{
    int j, k;
    char invert[30];
    system("CLS");
    printf("Priramide invertida(elimina ultimo)\n");

    for (j = i - 1, k = 0; j >= 0; j--, k++)// invierte la cadena
    {
        invert[k] = cad[j];// guarda la cadena invertida
    }

    while (i != 0)
    {
        for (k = 0; k < i; k++)
        {
            printf("%c", invert[k]);//imprime la cadena invertida
        }
        printf("\n");

        i--;// cada vez que disminuye se elimina el ultimo carcter de la cadena 
    }
    system("PAUSE");
}

//imprime la cadena eliminando el primer caracter hasta quedar el ultimo caracter
//RGA_Act7_Pt1_07_932
void piramide_a(char cad[], int i)
{
    int j, k;
    char invert[30];
    system("CLS");
    printf("Priramide(elimina primero)\n");

    for (j = i - 1, k = 0; j >= 0; j--, k++)//invirtte la cadena
    {
        invert[k] = cad[j];//guarda la cadena invertida
    }

    while (i != 0)
    {
        for (k = i - 1; k >= 0; k--)//cuando k disminuye se elimina el primer caracter de la cadena
        {
            printf("%c", invert[k]);//imprime la cadena de manera normal
        }
        printf("\n");

        i--;//controla las veces que se repetira el ciclo
    }
    system("PAUSE");
}

//imprime la cadena invertida eliminando el primer caracter hasta quedar el ultimo caracter
//RGA_Act7_Pt1_08_932
void piramide_invertida_e(char cad[], int i)
{
    int j;
    system("CLS");
    printf("Priramide invertida(elimina primero)\n");

    while (i != 0)//bucle que contola la cadena
    {
        for (j = i - 1; j >= 0; j--)
        {
            printf("%c", cad[j]);//imprime la cadena invertida
        }
        printf("\n");
        i--;
    }
    system("PAUSE");
}

//imprime solo las consonantes de la cadena
//RGA_Act7_Pt1_09_932
void solo_consonantes(char cad[], int i)
{
    system("CLS");
    int j = 0;
    printf("Solo consonantes\n");
    while (j < i)
    {
        //if que se encarga de analizar si los caracteres son vocales o consonantes
        if (cad[j] != 'A')
        {
            if (cad[j] != 'E')
            {
                if (cad[j] != 'I')
                {
                    if (cad[j] != 'U')
                    {
                        if (cad[j] != 'U')
                        {
                            printf("%c", cad[j]);//imrpime las consonantes
                        }
                    }
                }
            }
        }

        j++;//controla el ciclo
    }
    printf("\n");
    system("PAUSE");
}

//imprime solo las vocales de la cadena
//RGA_Act7_Pt1_10_932
void solo_vocales(char cad[], int i)
{
    int j = 0;
    system("CLS");
    printf("Solo vocales\n");
    while (j < i)
    {
        //serie de if que se encargan de validar si los caracteres son vocales e imprimirlos
        if (cad[j] == 'A')
        {
            printf("%c", cad[j]);
        }
        if (cad[j] == 'E')
        {
            printf("%c", cad[j]);
        }
        if (cad[j] == 'I')
        {
            printf("%c", cad[j]);
        }
        if (cad[j] == 'O')
        {
            printf("%c", cad[j]);
        }
        if (cad[j] == 'U')
        {
            printf("%c", cad[j]);
        }
        j++;//controla el ciclo
    }
    printf("\n");
    system("PAUSE");
}
