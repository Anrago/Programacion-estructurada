// Antonio Ramos Gonzalez Mt: 372576
// 07/11/2023 || 12/11/2023
// Se generara un archivo donde se almacenara datos generados por el usuario, y la lectura de archivos
// RGA_Act12_932
#include "Babilonia.h"
#define N 2000
typedef struct _Reg
{
    bool status = 1;
    int kay;
    char nombre[30];
    char apP[30];
    char apM[30];
    int edad;
    char sex[10];

} Treg;

int msg();
void menu();
int verMt(Treg reg[], int n, int mt);
int cargar(Treg reg[], int n, char filename[]);
Treg agregar(Treg reg[], int i);
void nombreAl(char nombre[], int sex);
void apAl(char apellido[]);
int searchSec(Treg reg[], int n, int mt);
int searchBin(Treg reg[], int inf, int sup, int mt);
int orderBu(Treg reg[], int n);
void pintReg(Treg reg[], int n);
void pintOneReg(Treg reg[], int n);
void swap(Treg reg[], int i, int j);
void createTXT(Treg reg[], int n);
int partition(Treg reg[], int low, int high);
void quicksort(Treg reg[], int low, int high);
void RegEnArch();
void regEliminados(Treg reg[], int n);

int main()
{
    srand(time(NULL));
    fflush(stdin);
    menu();
    return 0;
}

int msg()
{
    system("CLS");
    printf("Menu\n");
    printf("1.-Cargar\n");
    printf("2.-Agregar\n");
    printf("3.-Eliminar registro\n");
    printf("4.-Buscar Registro\n");
    printf("5.-Ordenar\n");
    printf("6.-Imprimir\n");
    printf("7.-Archivo texto\n");
    printf("8.-Cantidad de registros\n");
    printf("9.-Registros eliminados\n");
    printf("0.-Salir\n");
    return valid("Elije una opcion: ", 0, 9);
}

void menu()
{
    int opc, kay;
    int i = 0, j, band, bus;
    int fileBand = 0;
    Treg reg[N];
    do
    {
        opc = msg();
        switch (opc)
        {
        case 1:
            if (!fileBand)
            {

                if (i + 313 < N)
                {
                    i = cargar(reg, i, "datos.txt");
                    fileBand = 1;
                    band=1;
                }
                else
                {
                    printf("LA BASE DE DATOS HA SIDO LLENADA\n");
                    system("PAUSE");
                }
            }
            else
            {
                printf("YA SE HA CARGADO EL ARCHIVO\n");
                system("PAUSE");
            }
            break;

        case 2:
            if (i < N)
            {

                for (j = 0; j < 10; j++)
                {
                    if (i < N)
                    {
                        reg[i] = agregar(reg, i);
                        i++;
                        band = 1;
                    }
                }
            }
            else
            {
                printf("Base de datos llena\n");
                system("PAUSE");
            }

            break;
        case 3:
            kay = valid("Ingrese matricula que desea eliminar: ", 300000, 399999);
            if (band)
            {
                bus = searchSec(reg, i, kay);
                pintOneReg(reg, bus);
            }
            else
            {
                bus = searchBin(reg, 0, i, kay);
                pintOneReg(reg, bus);
            }
            if (valid("DESEA ELIMINAR ALUMNO\n1.-Si\n0.-NO\n", 0, 1))
            {
                reg[bus].status = 0;
            }

            break;
        case 4:
            kay = valid("Ingrese matricula que desea Buscar: ", 300000, 399999);
            if (band)
            {
                bus = searchSec(reg, i, kay);
                pintOneReg(reg, bus);
            }
            else
            {
                bus = searchBin(reg, 0, i, kay);
                pintOneReg(reg, bus);
            }
            system("PAUSE");
            break;
        case 5:
            if (band)
            {
                if (i < 500)
                {
                    band = orderBu(reg, i);
                }
                else
                {
                    band = 1;
                    quicksort(reg, 0, i - 1);
                }
            }
            break;
        case 6:
            pintReg(reg, i);
            break;
        case 7:
            createTXT(reg, i);
            break;
        case 8:
            RegEnArch();
            system("PAUSE");
            break;
        case 9:
            regEliminados(reg, i);
            break;
        }
    } while (opc != 0);
}

void nombreAl(char nombre[], int sex)
{
    int i, al;
    char nombH[50][20] = {
        "JUAN", "PEDRO", "LUIS", "CARLOS", "ANDRES", "MIGUEL", "DAVID", "RAFAEL", "FRANCISCO",
        "ALEJANDRO", "JORGE", "DANIEL", "GUILLERMO", "SERGIO", "PABLO", "JAVIER", "ALBERTO",
        "SERGIO", "OSCAR", "GUILLERMO", "MARIO", "RICARDO", "IGNACIO", "FEDERICO", "RODRIGO",
        "MANUEL", "ANTONIO", "RAUL", "ALFREDO", "FERNANDO", "ROBERTO", "EDUARDO", "HUGO", "ENRIQUE",
        "EMILIO", "ARMANDO", "JULIO", "ADRIAN", "GUSTAVO", "ARTURO", "ANGEL", "HORACIO",
        "RODOLFO", "LUCAS", "RAMON", "OMAR", "CESAR", "SANTIAGO", "GERARDO", "ERNESTO"};
    char nombM[50][20] = {
        "ANA", "SOFIA", "CARMEN", "ISABEL", "ANDREA", "PATRICIA", "ELENA", "MARTA", "BEATRIZ",
        "PAULA", "JULIA", "VALERIA", "RAQUEL", "NATALIA", "CLAUDIA", "VALENTINA", "LORENA",
        "ELENA", "MARIANA", "ADRIANA", "LAURA", "ANTONIA", "MARTINA", "ANGELA", "LUISA",
        "SARA", "VERONICA", "ALICIA", "ROSA", "LUCIA", "VICTORIA", "GLORIA", "INES",
        "ROCIO", "VANESA", "RAFAELA", "ANAIS", "EVA", "SANDRA", "LOLA", "ANA", "ESTHER",
        "MIRIAM", "LIDIA", "YOLANDA", "INES", "MARINA", "CAROLINA", "PILAR", "IRENE"};
    for (i = 0; i < 10; i++)
    {
        al = rand() % 50;
    }
    if (sex == 1)
    {
        strcpy(nombre, nombH[al]);
    }
    else
    {
        strcpy(nombre, nombM[al]);
    }
}

void apAl(char apellido[])
{
    int i, al;
    char ap[87][20] =
        {
            "PEREZ", "LOPEZ", "GONZALEZ", "RODRIGUEZ", "MARTINEZ", "SANCHEZ", "FERNANDEZ", "GARCIA", "RODRIGUEZ", "DIAZ", "TORRES", "RAMIREZ", "JIMENEZ",
            "VARGAS", "MORALES", "RUIZ", "CASTRO", "HERRERA", "MEDINA", "NAVARRO", "DELGADO", "ROMERO", "MORENO", "GOMEZ", "VARGAS", "PEREZ", "FLORES", "GONZALEZ",
            "NUNEZ", "SILVA", "SOTO", "MENDOZA", "ROJAS", "MENDEZ", "SALAS", "AGUIRRE", "BENITEZ", "GUZMAN", "PAREDES", "RIOS", "VALENZUELA", "CORDERO", "ESCOBAR",
            "OCHOA", "MORALES", "PIZARRO", "ARAYA", "CABRERA", "LOPEZ", "ORTEGA", "FERNANDEZ", "NAVARRO", "GUZMAN", "MENDEZ", "ROJAS", "SALAZAR", "VILLANUEVA", "PAREDES",
            "RIVAS", "SANDOVAL", "ESPINOZA", "MUNOZ", "ACOSTA", "DELGADO", "CASTRO", "NAVARRO", "GONZALEZ", "MENDOZA", "SILVA", "RIOS", "ROJAS", "AGUIRRE", "MORALES", "GOMEZ",
            "SOTO", "TORRES", "PEREZ", "MEDINA", "BENITEZ", "GARCIA", "VARGAS", "RODRIGUEZ", "RAMIREZ", "TORRES", "MORALES", "HERRERA", "JIMENEZ"};
    for (i = 0; i < 10; i++)
    {
        al = rand() % 87;
    }
    strcpy(apellido, ap[al]);
}

Treg agregar(Treg reg[], int i)
{
    int sex, min = 18, max = 35;
    do
    {
        reg[i].kay = rand() % 100000 + 300000;
    } while (verMt(reg, i, reg[i].kay));

    sex = rand() % 2 + 1;
    if (sex == 1)
    {
        strcpy(reg[i].sex, "Masculino");
    }
    if (sex == 2)
    {
        strcpy(reg[i].sex, "Femenino");
    }

    nombreAl(reg[i].nombre, sex);

    apAl(reg[i].apP);
    apAl(reg[i].apM);

    reg[i].edad = rand() % (max - min + 1) + min;

    return reg[i];
}

int searchSec(Treg reg[], int n, int mt)
{
    int i;
    i = 0;
    for (i = 0; i <= n; i++)
    {
        if (reg[i].kay == mt)
        {
            return i;
        }
    }
    return -1;
}

int searchBin(Treg reg[], int inf, int sup, int mt)
{
    int med; // variable local
    while (inf <= sup)
    {
        med = (inf + sup) / 2;
        if (reg[med].kay == mt)
        {
            return med;
        }
        else
        {
            if (mt < reg[med].kay)
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

int orderBu(Treg reg[], int n)
{
    int i, j;
    Treg temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (reg[j].kay < reg[i].kay)
            {
                temp = reg[i];
                reg[i] = reg[j];
                reg[j] = temp;
            }
        }
    }
    return 0;
}

void pintReg(Treg reg[], int n)
{
    int i = 0, j = 0, elec;
    
    do
    {
        i = 0;
        if (j < n)
        {
            system("CLS");
            printf("%-6s %-15s %-23s %-15s %-10s %-10s %-10s\n",
           "No.", "Matricula", "Nombre", "ApP", "ApM", "Edad", "Sexo");
            while (i < 40 && j < n)
            {

                if (reg[j].status)
                {
                    printf("%-6d.- %-10d %-10s %-15s  %-13s %-10d %-5s\n",
                           j + 1, reg[j].kay, reg[j].nombre, reg[j].apP,
                           reg[j].apM, reg[i].edad, reg[j].sex);
                }
                i++;
                j++;
            }
            elec = valid("1.-SI\n0.-NO\nSEGUIR IMPRIMIENDO: ", 0, 1);
        }
        else
        {
            printf("LIMITE ALCANZADO\n");
            elec = 0;
        }
    } while (elec);
    system("PAUSE");
}

void pintOneReg(Treg reg[], int n)
{
    if (n != -1)
    {
        printf("MATRICULA: %d\nNOMBRE: %s \nAPELLIDO PATERNO: %s\nAPELLIDO MATERNO: %s\nEDAD: %d\nSEXO:%s\n",
               reg[n].kay, reg[n].nombre, reg[n].apP,
               reg[n].apM, reg[n].edad, reg[n].sex);
    }
    else
    {
        printf("Registro no encontrado\n");
    }
}

int verMt(Treg reg[], int n, int mt)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (reg[j].kay == mt)
            {
                return 1;
            }
        }
    }

    return 0;
}

void createTXT(Treg reg[], int n)
{
    FILE *fa;
    int i = 0;
    char namefile[30];

    validCad("Ingrese nombre del arvhivo: ", namefile);
    strcat(namefile, ".txt");
    fa = fopen(namefile, "w");
    
    for (i = 0; i < n; i++)
    {
        if (reg[i].status != 0)
        {
            fprintf(fa, "%d.- %-10d %-10s %-15s %-10s %-8d %s\n",
                    i + 1, reg[i].kay, reg[i].nombre, reg[i].apP,
                    reg[i].apM, reg[i].edad, reg[i].sex);
        }
    }
    fclose(fa);
}

void swap(Treg reg[], int i, int j)
{
    Treg temp = reg[i];
    reg[i] = reg[j];
    reg[j] = temp;
}

int partition(Treg reg[], int low, int high)
{
    Treg pivot;
    pivot.kay = reg[high].kay;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (reg[j].kay <= pivot.kay)
        {
            i++;
            swap(reg, i, j);
        }
    }
    swap(reg, i + 1, high);
    return i + 1;
}

void quicksort(Treg reg[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(reg, low, high);

        quicksort(reg, low, pi - 1);
        quicksort(reg, pi + 1, high);
    }
}

int cargar(Treg reg[], int n, char filename[])
{
    FILE *fa;
    Treg regTemp;
    int No = 0;
    fa = fopen(filename, "r");
    if (fa)
    {
        do
        {
            fscanf(fa, "%d.- %d %s %s %s %d %s", &No, &regTemp.kay, regTemp.nombre, regTemp.apP, regTemp.apM,
                   &regTemp.edad, regTemp.sex);
            reg[n++] = regTemp;

        } while (!feof(fa));
        fclose(fa);
    }
    else
    {
        printf("ARCHIVO NO ENCONTRADO\n");
        system("PAUSE");
    }

    return n - 1;
}

void RegEnArch()
{
    int count;
    char fileName[50];
    char cmd[50];

    validCad("Ingrese el nombre del archivo ", fileName);

    system("mingw32-gcc-6.3.0.exe countTXT.c -o countTXT"); 
    sprintf(cmd, "countTXT.exe %s", fileName);
    count = system(cmd);

    if (count != -1)
    {
        printf("El archivo %s contiene %d registros\n", fileName, count);
    }
    else
    {
        printf("El archivo no fue encontrado\n");
    }
}

void regEliminados(Treg reg[], int n)
{

    FILE *fa;
    int i = 0;
    char namefile[30];

    strncpy(namefile, "RegEliminados.txt", 30);
    fa = fopen(namefile, "w");
    for (i = 0; i < n; i++)
    {
        if (reg[i].status == 0)
        {
            fprintf(fa, "%d.- %-10d %-10s %-15s %-10s %-8d %s\n",
                    i + 1, reg[i].kay, reg[i].nombre, reg[i].apP,
                    reg[i].apM, reg[i].edad, reg[i].sex);
        }
    }
    fclose(fa);
}