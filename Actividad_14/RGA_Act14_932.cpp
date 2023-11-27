/*

*/
#include "Babilonia.h"
typedef int Tkay;

int msg();
void menu(int numReg);
int cargar();
void agregar(TWrKr reg[]);
void cargar2(TWrKr reg[], Tindex index[]);
void agregar(TWrKr reg[], int n);
int searchSec(Tindex index[], int n, int mt);
void printReg(TWrKr reg[], int n);

int main()
{
    int tam = (cargar());
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
    int tam, band = 0;
    tam = numReg * 1.25;
    TWrKr reg[tam];
    Tindex index[tam];
    cargar2(reg, index);
    printf("%d", reg[255].enrollement);
    do
    {
        opc = msg();
        switch (opc)
        {
        case 1:
            if (numReg < tam)
            {
                agregar(reg, numReg);
                printf("%s", reg[numReg].name);
                numReg++;
                band = 1;
            }
            else
            {
                printf("NO HAY ESPACIO DISPONIBLE\n");
            }

            break;
        case 2:
            int mt;
            int pos;
            if (band == 0)
            {
                mt = valid("INGRESA MATRICULA A ELIMINAR: ", 300000, 399999);
                pos = searchSec(index, numReg, mt);
            }
            else
            {
            }
            if (pos != -1)
            {
                printReg(reg, pos);
                system("pause");
            }
            else
            {
                printf("NO SE ENCONTRO EL REGISTRO\n");
            }
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
    TWrKr temp;
    int i = 0;
    FILE *fa;
    fa = fopen("datos.dat", "rb");
    if (fa == NULL)
    {
        printf("ERROR AL ABRIR ARCHIVO");
    }
    else
    {
        while (fread(&temp, sizeof(TWrKr), 1, fa))
        {
            i++;
        }
    }

    return i;
}

void cargar2(TWrKr reg[], Tindex index[])
{
    TWrKr temp;
    int i = 0;
    FILE *fa;
    fa = fopen("datos.dat", "rb");
    if (fa == NULL)
    {
        printf("ERROR AL ABRIR ARCHIVO");
    }
    else
    {
        while (fread(&temp, sizeof(TWrKr), 1, fa))
        {
            reg[i] = temp;
            index[i].id = temp.enrollement;
            index[i].index = i;
            i++;
        }
    }
}

void agregar(TWrKr reg[], int n)
{

    int sex;
    reg[n].status = 1;
    do
    {
        reg[n].enrollement = rand() % 100000 + 399999;
    } while (verMt(reg, n, reg[n].enrollement));
    sex = rand() % 1 + 2;
    nombreAl(reg[n].name, sex);
    apAl(reg[n].LastName1);
    apAl(reg[n].LastName2);
    if (sex == 1)
    {
        strcat(reg[n].sex, "HOMBRE");
    }
    else
    {
        strcat(reg[n].sex, "MUJER");
    }
    puestoAl(reg[n].JobPstion);

    estados(reg[n].state);

    reg[n].age = rand() % 60 + 18;
}

int searchSec(Tindex index[], int n, int mt)
{
    int i;
    i = 0;
    for (i = 0; i <= n; i++)
    {
        if (index[i].id == mt)
        {
            return i;
        }
    }
    return -1;
}
void printReg(TWrKr reg[], int n)
{
    printf("NOMBRE: %s\n", reg[n].name);
    printf("APELLIDO PATERNO: %s\n", reg[n].LastName1);
    printf("APELLIDO MATERNO: %s\n", reg[n].LastName2);
    printf("MATRICULA: %d\n", reg[n].enrollement);
    printf("EDAD: %d\n", reg[n].age);
    printf("SEXO: %s\n", reg[n].sex);
    printf("PUESTO: %s\n", reg[n].JobPstion);
    printf("ESTADO: %s\n", reg[n].state);
}
