/*

*/
#include "Babilonia.h"
typedef int Tkay;

int msg();
void menu(int numReg);
int cargar();
void cargar2(TWrKr reg[], Tindex index[]);
void agregar(TWrKr reg[], int n);
int searchSec(Tindex index[], int n, int mt);
void printReg(TWrKr reg);
void eliminar( int n);
void buscar( int n);
void agregarbin(TWrKr reg);
int orderBu(Tindex reg[], int n);
void printOrder(Tindex indice[], int n);
void printOriginal(int n);
void crearTxtOrig();
void crearTxtOrd(Tindex indice[], int n);

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
    printf("7.-CREAR TXT\n");
    printf("8.-EMPAQUETAR\n");
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
                index[numReg].id = reg[numReg].enrollement;
                index[numReg].index = numReg;
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
                eliminar(pos);
            }
            else
            {
                printf("NO SE ENCONTRO EL REGISTRO\n");
            }
            break;
        case 3:
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
            }
            else
            {
                printf("NO SE ENCONTRO EL REGISTRO\n");
            }
            break;
        case 4:
            orderBu(index, numReg);
            break;
        case 5:
            printOrder(index, numReg);
            break;
        case 6:
            printOriginal(numReg);
            break;
        case 7:
            int elec;
            printf("1.-ORDENADO\n");
            printf("2.-Desordenado\n");
            printf("0.-SALIR\n");
            elec = valid("COMO DESEA GENERAR EL ARCHIVO DE TEXTO: ", 0, 2);
            if (elec == 1)
            {
                crearTxtOrd(index, numReg);
            }
            else
            {
                crearTxtOrig();
            }

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

    TWrKr temp;
    int sex;
    temp.status = 1;
    do
    {
        temp.enrollement = rand() % 100000 + 399999;
    } while (verMt(reg, n, temp.enrollement));
    sex = rand() % 1 + 2;
    nombreAl(temp.name, sex);
    apAl(temp.LastName1);
    apAl(temp.LastName2);
    if (sex == 1)
    {
        strcat(temp.sex, "HOMBRE");
    }
    else
    {
        strcat(temp.sex, "MUJER");
    }
    puestoAl(temp.JobPstion);

    estados(temp.state);

    temp.age = rand() % 60 + 18;
    do
    {
        temp.CellPhone = rand() % 1000000 + 1999999;
    } while (verMt(reg, n, temp.CellPhone));
    agregarbin(temp);
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

void eliminar( int n)
{
    int opc;
    FILE *fa;
    TWrKr temp;

    fa = fopen("datos.dat", "rb+");
    fseek(fa, n * sizeof(TWrKr), SEEK_SET);
    fread(&temp, sizeof(TWrKr), 1, fa);
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
        printf("Se ha eliminado con exito\n");
    }
    else
    {
        printf("No se ha eliminado\n");
    }
    fclose(fa);
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

int orderBu(Tindex reg[], int n)
{
    int i, j;
    Tindex temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (reg[j].id < reg[i].id)
            {
                temp = reg[i];
                reg[i] = reg[j];
                reg[j] = temp;
            }
        }
    }
    return 0;
}

void printOrder(Tindex indice[], int n)
{
    FILE *fa;

    TWrKr temp;
    fa = fopen("datos.dat", "rb");
    for (int i = 0; i < n; i++)
    {

        fseek(fa, indice[i].index * sizeof(TWrKr), SEEK_SET);
        fread(&temp, sizeof(TWrKr), 1, fa);

        printf("%s %s %s %s %s %s %d %d\n", temp.name, temp.LastName1, temp.LastName2,
               temp.sex, temp.JobPstion, temp.state, temp.age, temp.CellPhone);
    }
}

void printOriginal(int n)
{
    FILE *fa;

    TWrKr temp;
    fa = fopen("datos.dat", "rb");
    for (int i = 0; i < n; i++)
    {

        fseek(fa, i * sizeof(TWrKr), SEEK_SET);
        fread(&temp, sizeof(TWrKr), 1, fa);

        printf("%s %s %s %s %s %s %d %d\n", temp.name, temp.LastName1, temp.LastName2,
               temp.sex, temp.JobPstion, temp.state, temp.age, temp.CellPhone);
    }
}

void crearTxtOrig()
{
    FILE *fabin;
    FILE *fatxt;

    TWrKr temp;

    fabin = fopen("datos.dat", "rb");
    fatxt = fopen("datos.txt", "w");

    if (fabin == NULL || fatxt == NULL)
    {
        printf("ERROR AL ABRIR ARCHIVO");
    }
    else
    {
        while (fread(&temp, sizeof(TWrKr), 1, fabin))
        {

            fprintf(fatxt, "%-10s %-10s %-10s %-10s %-10s %-10s %-10d %d\n", temp.name, temp.LastName1,
                    temp.LastName2, temp.sex, temp.JobPstion, temp.state, temp.age, temp.CellPhone);
        }
    }
    printf("SE HA CREADO EL ARCHIVO DE TEXTO\n");

    fclose(fabin);
    fclose(fatxt);
}

void crearTxtOrd(Tindex indice[], int n)
{

    FILE *fabin;
    FILE *fatxt;

    TWrKr temp;

    fabin = fopen("datos.dat", "rb");
    fatxt = fopen("datosOrdenados.txt", "w");

    if (fabin == NULL || fatxt == NULL)
    {
        printf("ERROR AL ABRIR ARCHIVO");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            fseek(fabin, indice[i].index * sizeof(TWrKr), SEEK_SET);
            fread(&temp, sizeof(TWrKr), 1, fabin);

            fprintf(fatxt, "%-10s %-10s %-10s %-10s %-10s %-10s %-10d %d\n", temp.name, temp.LastName1,
                    temp.LastName2, temp.sex, temp.JobPstion, temp.state, temp.age, temp.CellPhone);
        }
        printf("SE HA CREADO EL ARCHIVO DE TEXTO\n");

        fclose(fabin);
        fclose(fatxt);
    }
}
