#include "Curp.h"
#define N 500
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
    int status;
    int kay;
    TNomb nombre;
    TFecha fecha;
    char sex[1];
    char estado[30];
    char curp[18];

} Treg;

int msg();
int msg2();
void menu();
void estados(int est, char nombestado[]);
Treg agregarM(Treg reg[], int i);
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
    int opc, elec;
    int i = 0;
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
                reg[i] = agregarM(reg, i);
                i++;
            }
            if (elec == 2)
            {
                printf("Entro cargar");
            }

            break;
        }
    } while (opc != 0);
}

Treg agregarM(Treg reg[], int i)
{
    char nomb[30], nomb2[30], apP[30], apM[30];
    char carp[18];
    int dia, mes, anio, bis, sex, est = 0;

    reg[i].kay = valid("Ingrese matricula: ", 300000, 399999);

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
    curp(carp, nomb, nomb2, apP, apM, dia, mes, anio, sex, est);

    strcpy(reg[i].nombre.nombre, nomb);
    strcpy(reg[i].nombre.nombre, nomb2);
    strcpy(reg[i].nombre.apP, nomb);
    strcpy(reg[i].nombre.apM, nomb);
    reg[i].fecha.anio = anio;
    reg[i].fecha.mes = mes;
    reg[i].fecha.dia = dia;
    estados(est, reg[i].estado);
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
    strcpy(estados[est], nombestado);
}