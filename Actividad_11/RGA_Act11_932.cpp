// Antonio Ramos Gonzalez Mt: 372576
// 01/11/2023
// Se generara un archivo donde se almacenara datos generados por el usuario
// RGA_Act11_932
#include "Curp.h"
#define N 2000
typedef struct _NombC
{
    char nombre[30];
    char nombre2[30];
    char apP[30];
    char apM[30];
} TNomb;
typedef struct _FrechaN
{
    int dia;
    int mes;
    int anio;
} TFecha;
typedef struct _Reg
{
    bool status = 1;
    int kay;
    TNomb nombre;
    TFecha fecha;
    char sex[2];
    char estado[30];
    char curp[18];

} Treg;

int msg();
int msg2();
void menu();
int verMt(Treg reg[], int n, int mt);
void estados(int est, char nombestado[]);
void estadosAl(int est, char nombestado[]);
Treg agregarM(Treg reg[], int i);
Treg cargar(Treg reg[], int i);
void nombreAl(char nombre[], int sex);
void apAl(char apellido[]);
int month(int anio);
int day(int anio, int mes);
int searchSec(Treg reg[], int n, int mt);
int searchBin(Treg reg[], int inf, int sup, int mt);
int orderBu(Treg reg[], int n);
void pintReg(Treg reg[], int n);
void pintOneReg(Treg reg[], int n);
void swap(Treg reg[], int i, int j);
void createTXT(Treg reg[], int n);
int partition(Treg reg[], int low, int high);
void quicksort(Treg reg[], int low, int high);

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
    printf("1.-Agregar\n");
    printf("2.-Eliminar registro\n");
    printf("3.-Buscar Registro\n");
    printf("4.-Ordenar\n");
    printf("5.-Imprimir\n");
    printf("6.-Archivo texto\n");
    printf("0.-Salir\n");
    return valid("Elije una opcion: ", 0, 6);
}

int msg2()
{
    system("CLS");
    printf("Menu\n");
    printf("1.-Agregar Manual\n");
    printf("2.-Cargar\n");
    printf("0.-Regresar\n");
    return valid("Elije una opcion: ", 0, 2);
}

void menu()
{
    int opc, elec, kay;
    int i = 0, j, band, bus;
    Treg reg[N];
    do
    {
        opc = msg();
        switch (opc)
        {
        case 1:
            elec = msg2();
            if (elec == 1)
            {
                if (i < N)
                {
                    reg[i] = agregarM(reg, i);
                    i++;
                    band = 1;
                }
                else
                {
                    printf("Base de datos llena\n");
                    system("PAUSE");
                }
            }
            if (elec == 2)
            {
                if (i < N)
                {

                    for (j = 0; j < 100; j++)
                    {
                        if (i < N)
                        {
                            reg[i] = cargar(reg, i);
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
            }

            break;
        case 2:
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
        case 3:
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
        case 4:
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
        case 5:
            pintReg(reg, i);
            break;
        case 6:
            createTXT(reg, i);
            break;
        }
    } while (opc != 0);
}

Treg agregarM(Treg reg[], int i)
{
    char nomb[30], nomb2[30], apP[30], apM[30];
    char carp[18];
    int dia, mes, anio, bis, sex, est = 0;
    do
    {
        reg[i].kay = valid("Ingrese matricula: ", 300000, 399999);
    } while (verMt(reg, i, reg[i].kay));

    do
    {
        validCad("Ingrese nombre: ", nomb);

    } while (nomb[0] == '\0' || strlen(nomb) > 15);

    do
    {
        validCad("Ingrese 2do nombre(si tiene mas de 2 ingreselos aqui): ", nomb2);
    } while (strlen(nomb2) > 30);
    do
    {
        validCad("Ingrese apellido paterno: ", apP);
    } while (strlen(apP) > 15);
    do
    {
        validCad("Ingrese apellido materno: ", apM);
    } while (strlen(apM) > 15);

    system("CLS");
    anio = valid("Ingresa anio de nacimiento: ", 1950, 2023);
    if (anio == 2023)
    {
        mes = valid("Ingresa mes de nacimiento(enero=01,diciembre=12): ", 1, 10);
    }
    else
    {
        mes = valid("Ingresa mes de nacimiento(enero=01,diciembre=12): ", 1, 12);
    }
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        dia = valid("Ingresa dia de nacimiento: ", 1, 31);
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        dia = valid("Ingresa dia de nacimiento: ", 1, 30);
    }
    if (mes == 2)
    {
        bis = bisiesto(anio);
        if (!bis)
        {
            dia = valid("Ingresa dia de nacimiento: ", 1, 28);
        }
        else
        {
            dia = valid("Ingresa dia de nacimiento: ", 1, 29);
        }
    }

    printf("1.-Hombre");
    printf("2.-Mujer");
    sex = valid("INGRESE SEXO: ", 1, 2);
    imprimirEstados();
    est = valid("Ingrese estado: ", 1, 33);
    est--;
    printf("%d", est);
    system("PAUSE");
    estados(est, reg[i].estado);
    printf("%s", reg[i].estado);
    system("PAUSE");
    curp(carp, nomb, nomb2, apP, apM, dia, mes, anio, sex, est);
    strcpy(reg[i].nombre.nombre, nomb);
    strcpy(reg[i].nombre.nombre2, nomb2);
    strcpy(reg[i].nombre.apP, apP);
    strcpy(reg[i].nombre.apM, apM);
    strcpy(reg[i].curp, carp);
    reg[i].fecha.anio = anio;
    reg[i].fecha.mes = mes;
    reg[i].fecha.dia = dia;
    if (sex == 1)
    {
        strcpy(reg[i].sex, "H");
    }
    if (sex == 2)
    {
        strcpy(reg[i].sex, "M");
    }

    return reg[i];
}

void estados(int est, char nombestado[])
{

    char estados[33][30] = {
        "Aguascalientes",
        "Baja California",
        "Baja California Sur",
        "Campeche",
        "Chiapas",
        "Chihuahua",
        "Coahuila",
        "Colima",
        "Durango",
        "Guanajuato",
        "Guerrero",
        "Hidalgo",
        "Jalisco",
        "Estado de Mexico",
        "Michoacan",
        "Morelos",
        "Nayarit",
        "Nuevo Leon",
        "Oaxaca",
        "Puebla",
        "Queretaro",
        "Quintana Roo",
        "San Luis Potosi",
        "Sinaloa",
        "Sonora",
        "Tabasco",
        "Tamaulipas",
        "Tlaxcala",
        "Veracruz",
        "Yucatan",
        "Zacatecas",
        "Ciudad de Mexico",
        "Extranjero"};
    strcpy(nombestado, estados[est]);
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

int month(int anio)
{
    if (anio == 2023)
    {
        return rand() % 11 + 1;
    }
    else
    {
        return rand() % 12 + 1;
    }
}

int day(int anio, int mes)
{
    int bis;
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        return rand() % 31 + 1;
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        return rand() % 30 + 1;
    }
    if (mes == 2)
    {
        bis = bisiesto(anio);
        if (!bis)
        {
            return rand() % 28 + 1;
        }
        else
        {
            return rand() % 29 + 1;
        }
    }
}

Treg cargar(Treg reg[], int i)
{
    char nomb[30], nomb2[30], apP[30], apM[30];
    int sex, est = 0;
    int n, j = 0;
    do
    {
        reg[i].kay = rand() % 100000 + 300000;
    } while (verMt(reg, i, reg[i].kay));

    sex = rand() % 2 + 1;
    if (sex == 1)
    {
        strcpy(reg[i].sex, "H");
    }
    if (sex == 2)
    {
        strcpy(reg[i].sex, "M");
    }

    nombreAl(nomb, sex);

    strcpy(reg[i].nombre.nombre, nomb);
    while (j < 10)
    {
        n = rand() % 10 + 1;
        j++;
    }

    if (n % 2 == 0)
    {
        nomb2[0] = '\0';
    }
    else
    {
        nombreAl(nomb2, sex);
    }
    strcpy(reg[i].nombre.nombre2, nomb2);
    apAl(apP);
    strcpy(reg[i].nombre.apP, apP);
    apAl(apM);
    strcpy(reg[i].nombre.apM, apM);

    reg[i].fecha.anio = 1950 + rand() % (2023 - 1950 + 1);
    reg[i].fecha.mes = month(reg[i].fecha.anio);
    reg[i].fecha.dia = day(reg[i].fecha.anio, reg[i].fecha.mes);

    for (j = 0; j < 10; j++)
    {
        est = rand() % 33;
    }

    estados(est, reg[i].estado);

    curp(reg[i].curp, nomb, nomb2, apP, apM, reg[i].fecha.dia, reg[i].fecha.mes, reg[i].fecha.anio, sex, est);
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
    printf("%s", reg[n].sex);
    system("PAUSE");
    printf("%-6s %-15s %-23s %-15s %-10s %-10s %-10s %s \n",
           "No.", "Matricula", "Nombre", "ApP", "ApM", "Edad", "Sexo", "Curp");
    do
    {
        i = 0;
        if (j < n)
        {
            while (i < 40 && j < n)
            {

                if (reg[j].status)
                {
                    printf("%-6d %-10d %-10s %-15s %-15s %-13s %-10d %-5s %s\n",
                           j + 1, reg[j].kay, reg[j].nombre.nombre, reg[j].nombre.nombre2, reg[j].nombre.apP,
                           reg[j].nombre.apM, 2023 - reg[j].fecha.anio, reg[j].sex, reg[j].curp);
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
        printf("MATRICULA: %d\nNOMBRE: %s %s\nAPELLIDO PATERNO: %s\nAPELLIDO MATERNO: %s\nFECHA DE NACIMIENTO: %02d-%02d-%d\nSEXO:%s\nESTADO: %s\nCURP: %s\n",
               reg[n].kay, reg[n].nombre.nombre, reg[n].nombre.nombre2, reg[n].nombre.apP,
               reg[n].nombre.apM, reg[n].fecha.mes, reg[n].fecha.dia, reg[n].fecha.anio, reg[n].sex, reg[n].estado, reg[n].curp);
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
    fa = fopen("C:\\Users\\PC\\Desktop\\UABC 3er sem\\Programacion-estructurada\\Actividad_11\\Registros.txt", "w");
    fprintf(fa, "%-6s %-15s %-23s %-15s %-10s %-10s %-10s %s \n",
            "No.", "Matricula", "Nombre", "ApP", "ApM", "Edad", "Sexo", "Curp");
    for (i = 0; i < n; i++)
    {
        if (reg[i].status != 0)
        {
            fprintf(fa, "%-6d %-10d %-10s %-15s %-15s %-10s %02d-%02d-%-8d %-5s %s\n",
                    i + 1, reg[i].kay, reg[i].nombre.nombre, reg[i].nombre.nombre2, reg[i].nombre.apP,
                    reg[i].nombre.apM, reg[i].fecha.mes, reg[i].fecha.dia, reg[i].fecha.anio, reg[i].sex, reg[i].curp);
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