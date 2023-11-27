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
void printReg(TWrKr reg);
void eliminar(TWrKr reg[], int n);
void buscar(TWrKr reg[], int n);
void agregarbin(TWrKr reg);
int orderBu(TWrKr reg[], int n);

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
    printf("%d", reg[0].enrollement);
    do
    {
        opc = msg();
        switch (opc)
        {
        case 1:
            if (numReg < tam)
            {
                agregar(reg, numReg);
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
                printReg(reg[pos]);
                printf("\n");
                eliminar(reg, pos);
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
    do
    {
        reg[n].CellPhone = rand() % 1000000 + 1999999;
    } while (verMt(reg, n, reg[n].CellPhone));
    agregarbin(reg[n]);
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

void printReg(TWrKr reg)
{
    printf("NOMBRE: %s\n", reg.name);
    printf("APELLIDO PATERNO: %s\n", reg.LastName1);
    printf("APELLIDO MATERNO: %s\n", reg.LastName2);
    printf("MATRICULA: %d\n", reg.enrollement);
    printf("EDAD: %d\n", reg.age);
    printf("SEXO: %s\n", reg.sex);
    printf("PUESTO: %s\n", reg.JobPstion);
    printf("ESTADO: %s\n", reg.state);
}

void eliminar(TWrKr reg[], int n)
{
    int opc;
    FILE *fa;
    TWrKr temp;

    fa = fopen("datos.dat", "rb+");
    fseek(fa, n * sizeof(TWrKr), SEEK_SET);
    fread(&temp, sizeof(TWrKr), 1, fa);

    printf("%d", temp.status);
    system("pause");
    if (temp.status == 1)
    {
        printReg(temp);
        opc = valid("\nDesea eliminarlo?\n1.-Si\n2.-No  ", 1, 2);
    }
    else
    {
        printf("El registro ya esta eliminado\n");
    }

    if (opc == 1)
    {
        temp.status = 0;
        fseek(fa, n * sizeof(TWrKr), SEEK_SET);
        fwrite(&temp, sizeof(TWrKr), 1, fa);
        reg[n].status = 0;
        printf("Se ha eliminado con exito\n");
    }
    else
    {
        printf("No se ha eliminado\n");
    }
    fclose(fa);
}

void buscar(TWrKr reg[], int n)
{
    FILE *fa;
    TWrKr temp;

    fa = fopen("datos.dat", "rb+");
    fseek(fa, n * sizeof(TWrKr), SEEK_SET);
    fread(&temp, sizeof(TWrKr), 1, fa);

    if (temp.status == 1)
    {
        printReg(temp);
       
    }
    else
    {
        printf("Registro no existente\n");
    }
   
}

void agregarbin(TWrKr reg)
{
    FILE *fa;
    fa = fopen("datos.dat", "ab");
    if (fa == NULL)
    {
        printf("ERROR AL ABRIR ARCHIVO");
    }
    else
    {
        fwrite(&reg, sizeof(TWrKr), 1, fa);
    }
    fclose(fa);
}

int orderBu(TWrKr reg[], int n)
{
    int i, j;
    TWrKr temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (reg[j].enrollement < reg[i].enrollement)
            {
                temp = reg[i];
                reg[i] = reg[j];
                reg[j] = temp;
            }
        }
    }
    return 0;
}
