/*

*/
#include "Babilonia.h"
typedef int Tkay;
typedef struct _reg
{
    int status;
    Tkay key;
    char nomb[30];
    char apP[50];
    char apM[50];
    char sex[15];
    char puesto[30];
    char estado[30];
    int edad;
    Tkay Cel;

} Treg;

int msg();
void menu(int numReg);
int cargar();
void agregar(Treg reg[]);
void cargar2(Treg reg[]);
void agregar(Treg reg[],int n);

int main()
{
    int tam = (cargar());
    // printf("%d",tam);
    // system("PAUSE");
    fflush(stdin);
    srand(time(NULL));
    menu(tam);
    return 0;
}

int msg()
{
    printf("MENU\n");
    printf("1.-AGREGAR\n");
    printf("2.-ELIMINAR\n");
    printf("3.-BUSCAR\n");
    printf("4.-ORDENAR\n");
    printf("5.-IMPRIMIR REGISTRO ORIGINAL\n");
    printf("6.-IMPRIMIR REGISTRO ORDENADO\n");
    printf("7.-EMPAQUETAR\n");
    printf("0.-SALIR\n");

    return valid("ELIJE UNA OPCION: ", 0, 7);
}

void menu(int numReg)
{
    int opc;
    int tam = numReg * 1.25;
    Treg reg[tam];
    cargar2(reg);

    do
    {
        opc = msg();
        switch (opc)
        {
        case 1:
            printf("AGREGAR\n");
            numReg++;
            agregar(reg,numReg);
            printf("%s",reg[numReg-1].nomb);
            system("PAUSE");
            
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:

            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        }
    } while (opc != 0);
}

int cargar()
{
    Treg temp;
    int i = 0;
    FILE *fa;
    fa = fopen("datos.dat", "rb");
    if (fa == NULL)
    {
        printf("ERROR AL ABRIR ARCHIVO");
    }
    else
    {
        while (fread(&temp, sizeof(Treg), 1, fa))
        {
            i++;
        }
    }

    return i;
}

void cargar2(Treg reg[])
{
    Treg temp;
    int i = 0;
    FILE *fa;
    fa = fopen("datos.dat", "rb");
    if (fa == NULL)
    {
        printf("ERROR AL ABRIR ARCHIVO");
    }
    else
    {
        while (fread(&temp, sizeof(Treg), 1, fa))
        {
            reg[i] = temp;
            i++;
        }
    }
}

void agregar(Treg reg[],int n)
{

    validCad("Ingresa nombre: ",reg[n].nomb);
    validCad("Ingresa apelldio paterno: ",reg[n].apP);
    validCad("Ingresa apelldio materno: ",reg[n].apM);
    validCad("Ingresa sexo: ",reg[n].sex);
    validCad("Ingresa puesto ",reg[n].puesto);
    reg[n].edad=valid("Ingrese edad: ",18,40);
    reg[n].Cel=valid("Ingrese edad: ",18,40);

}
