/*
Antonio Ramos Gonzalez Mt: 372576
24/11/2023 || 27/11/2023
El ususario podra agregar, eliminar, buscar, ordenar, imprimir el registro original y el ordenado, crear un archivo de texto y empaquetar
RGA_Act14_932
*/
#include "Babilonia.h"
typedef int Tkay;

int msg();
void menu(int numReg);
int cargar();
void cargar2(TWrKr reg[], Tindex index[]);
TWrKr agregar(TWrKr reg[], int n);
int searchSec(Tindex index[], int n, int mt);
void printReg(TWrKr reg);
void eliminar(int n);
void buscar(int n);
void agregarbin(TWrKr reg);
int orderBu(Tindex reg[], int n);
void printOrder(Tindex indice[], int n);
void printOriginal(int n);
void crearTxtOrig();
void crearTxtOrd(Tindex indice[], int n);
void Empaqueta(int n);
void quicksort(Tindex reg[], int low, int high);
void swap(Tindex reg[], int i, int j);
int partition(Tindex reg[], int low, int high);
void insertionSort(Tindex reg[], int n);
int searchBin(Tindex reg[], int inf, int sup, int mt);
void printRegOr(Tindex reg);

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

    return valid("ELIJE UNA OPCION: ", 0, 8);
}

void menu(int numReg)
{
    int opc;
    int tam, band = 0;
    int band_order = 0;
    tam = numReg * 1.25;
    TWrKr reg[tam];
    Tindex index[tam];
    cargar2(reg, index);
    do
    {
        opc = msg();
        switch (opc)
        {
        case 1:
            if (numReg < tam)
            {
                reg[numReg] = agregar(reg, numReg);
                index[numReg].id = reg[numReg].enrollement;
                printf("%d\n", index[numReg].id);
                index[numReg].index = numReg;

                numReg++;
                band = 0;
                if (band_order == 3)
                {
                    band = rand() % 2 + 1;
                }
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
                printf("BUSQUEDA SECUENCIAL\n");
                mt = valid("INGRESA MATRICULA A ELIMINAR: ", 300000, 399999);
                pos = searchSec(index, numReg, mt);
                if (pos = -1)
                {
                    printReg(reg[pos]);
                }
            }
            else
            {
                printf("BUSQUEDA BINARIA\n");
                mt = valid("INGRESA MATRICULA A ELIMINAR: ", 300000, 399999);
                pos = searchBin(index, 0, numReg, mt);
                if (pos != -1)
                {
                    printRegOr(index[pos]);
                }
            }
            break;
        case 3:
            if (band == 0)
            {
                printf("BUSQUEDA SECUENCIAL\n");
                mt = valid("INGRESA MATRICULA A BUSCAR: ", 300000, 399999);
                pos = searchSec(index, numReg, mt);
                if (pos = -1)
                {
                    printReg(reg[pos]);
                }
            }
            else
            {
                printf("BUSQUEDA BINARIA\n");
                mt = valid("INGRESA MATRICULA A BUSCAR: ", 300000, 399999);
                pos = searchBin(index, 0, numReg, mt);
                if (pos != -1)
                {
                    printRegOr(index[pos]);
                }
            }

            break;
        case 4:
            if (band == 0)
            {
                if (band_order == 0)
                {
                    quicksort(index, 0, numReg - 1);
                    band_order = 3;
                }
                if (band_order == 1)
                {
                    insertionSort(index, numReg);
                }

                if (band_order == 2)
                {
                    orderBu(index, numReg);
                }
            }

            band = 1;
            break;
        case 5:
            printOriginal(numReg);
            break;
        case 6:
            printOrder(index, numReg);
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
        case 8:
            Empaqueta(numReg);
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
    fclose(fa);
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
        fclose(fa);
    }
}

TWrKr agregar(TWrKr reg[], int n)
{

    TWrKr temp;
    int sex;
    temp.status = 1;
    do
    {
        temp.enrollement = rand() % 100000 + 300000;
    } while (verMt(reg, n, temp.enrollement));
    sex = rand() % 2 + 1;
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
    return temp;
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

void printRegOr(Tindex reg)
{
    FILE *fa;
    TWrKr temp;
    fa = fopen("datos.dat", "rb");
    fseek(fa, reg.index * sizeof(TWrKr), SEEK_SET);
    fread(&temp, sizeof(TWrKr), 1, fa);
    fclose(fa);
    printf("NOMBRE: %s\n", temp.name);
    printf("APELLIDO PATERNO: %s\n", temp.LastName1);
    printf("APELLIDO MATERNO: %s\n", temp.LastName2);
    printf("MATRICULA: %d\n", temp.enrollement);
    printf("EDAD: %d\n", temp.age);
    printf("SEXO: %s\n", temp.sex);
    printf("PUESTO: %s\n", temp.JobPstion);
    printf("ESTADO: %s\n", temp.state);
}

void eliminar(int n)
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
    fclose(fa);
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
    fclose(fa);
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

void Empaqueta(int n)
{
    FILE *fad, *fab;
    TWrKr temp;
    char nombre[11] = "datos.dat";
    rename("datos.dat", "datos.bak");
    fad = fopen(nombre, "wb");
    fab = fopen("datos.bak", "rb");
    if (fad == NULL)
    {
        printf("ERROR AL ABRIR ARCHIVO");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            fseek(fab, i * sizeof(TWrKr), SEEK_SET);
            fread(&temp, sizeof(TWrKr), 1, fab);
            if (temp.status == 1)
            {
                fwrite(&temp, sizeof(TWrKr), 1, fad);
            }
        }
        fclose(fad);
        fclose(fab);
    }
}

void quicksort(Tindex reg[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(reg, low, high);

        quicksort(reg, low, pi - 1);
        quicksort(reg, pi + 1, high);
    }
}

int partition(Tindex reg[], int low, int high)
{
    Tindex pivot;
    pivot.id = reg[high].id;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (reg[j].id <= pivot.id)
        {
            i++;
            swap(reg, i, j);
        }
    }
    swap(reg, i + 1, high);
    return i + 1;
}

void swap(Tindex reg[], int i, int j)
{
    Tindex temp = reg[i];
    reg[i] = reg[j];
    reg[j] = temp;
}

void insertionSort(Tindex reg[], int n)
{
    Tindex temp;
    int j;
    for (int i = 1; i < n; i++)
    {
        temp = reg[i];
        j = i - 1;
        while (j >= 0 && reg[j].id > temp.id)
        {
            reg[j + 1] = reg[j];
            j--;
        }
        reg[j + 1] = temp;
    }
}

int searchBin(Tindex reg[], int inf, int sup, int mt)
{
    int med;
    while (inf <= sup)
    {
        med = (inf + sup) / 2;
        if (reg[med].id == mt)
        {
            return med;
        }
        else
        {
            if (mt < reg[med].id)
            {
                sup = med--;
            }
            else
            {
                inf = med++;
            }
        }
    }
    return -1;
}
