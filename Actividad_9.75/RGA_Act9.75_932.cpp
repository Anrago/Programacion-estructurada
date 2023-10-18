// Antonio Ramos Gonzalez Mt: 372576
// 10/9/2023 || 10/12/2023
// En esta Practica se definira un tipo de variable como un struct, para ingresar datos de distintos alumnos con un menu
// RGA_Act10_Pt1_932

#include "Babilonia.h"

int msg();
void menu();
void curp();
int nombre(char curp[], char nomb[], char nomb2[], char apP[], char apM[]);
int nacimiento(char curp[]);
void sexo(char curp[]);
void estados(char curp[]);
void imprimirEstados();
void consonantes(char curp[], char nomb[], char nomb2[], char apP[], char apM[], int val);
void generacio(char curp[], int year);
void numAl(char curp[]);
int nomb_Novalid(char nomb[]);
int main()
{
    srand(time(NULL));
    fflush(stdin);
    menu();
    return 0;
}

int msg()
{
    printf("MENU\n");
    printf("1.-Generar curp\n");
    printf("0.-Salir\n");
    return valid("Ingresa una opcion: ", 0, 1);
}

void menu()
{
    int opc;
    do
    {
        system("CLS");
        opc = msg();
        switch (opc)
        {
        case 1:
            curp();
            break;
        }
    } while (opc != 0);
}

void curp()
{
    char curp[18];
    char nomb[15], nomb2[51], apP[15], apM[15];
    int year, val;
    
    validCad("Ingrese nombre: ", nomb);
    validCad("Ingrese 2do nombre: ", nomb2);
    validCad("Ingrese apellido paterno: ", apP);
    validCad("Ingrese apellido materno: ", apM);

    val=nombre(curp, nomb, nomb2, apP, apM);

    year = nacimiento(curp);

    sexo(curp);

    estados(curp);

    consonantes(curp, nomb, nomb2, apP, apM, val);

    generacio(curp, year);

    numAl(curp);

    printf("%s\n", curp);
    system("PAUSE");
}

int nombre(char curp[], char nomb[], char nomb2[], char apP[], char apM[])
{
    int val;
    strncpy(curp, apP, 2);
    curp[2] = '\0';
    strncat(curp, apM, 1);
    curp[3] = '\0';

    val = nomb_Novalid(nomb);
    if (!val)
    {
        strncat(curp, nomb, 1);
        curp[4] = '\0';
    }
    else
    {
        strncat(curp, nomb2, 1);
        curp[4] = '\0';
    }
    return val;
}

int nacimiento(char curp[])
{
    char anio[5], mes[3], dia[3], cero[2];
    int year, mont, day, lar;
    strcpy(cero, "0");

    system("CLS");
    year = valid("Ingresa year de nacimiento: ", 1950, 2023);
    mont = valid("Ingresa mes de nacimiento: ", 1, 12);
    day = valid("Ingresa dia de nacimiento: ", 1, 31);

    snprintf(anio, 5, "%d", year);
    snprintf(mes, 3, "%d", mont);
    snprintf(dia, 2, "%d", day);

    lar = strlen(anio);
    anio[0] = anio[lar - 2];
    anio[1] = anio[lar - 1];

    strncat(curp, anio, 2);
    curp[6] = '\0';
    strncat(curp, mes, 2);
    curp[8] = '\0';
    strncat(curp, cero, 1);
    curp[9] = '\0';
    strncat(curp, dia, 2);
    curp[10] = '\0';

    return year;
}

void sexo(char curp[])
{
    char sex[2];
    int s;
    s = valid("ingresa sexo: ", 1, 2);

    if (s == 1)
    {
        strcpy(sex, "H");
        strncat(curp, sex, 1);
    }
    else
    {
        strcpy(sex, "M");
        strncat(curp, sex, 1);
    }

    curp[11] = '\0';
}

void estados(char curp[])
{
    char est[2];
    int a;
    char estados[33][20] = {
        "AG", "BC", "BS", "CC", "CS", "CH", "CL", "CM",
        "CM", "DG", "GR", "GT", "HG", "JC", "EM", "MN",
        "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP",
        "SL", "SR", "TC", "TS", "TL", "VZ", "YN", "ZS",
        "NE"};

    imprimirEstados();

    a = valid("Ingrese estado: ", 1, 33);
    strcpy(est, estados[a - 1]);
    strncat(curp, est, 2);
    curp[13] = '\0';
}

void imprimirEstados()
{
    int i;
    char estados[33][30] = {
        "Aguascalientes",
        "Baja California",
        "Baja California Sur",
        "Campeche",
        "Coahuila",
        "Colima",
        "Chiapas",
        "Chihuahua",
        "Ciudad de mexico",
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
        "Quertaro",
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
        "Nacido en el extrangero"};

    for (i = 0; i < 33; i++)
    {
        printf("%d.- %s\n", i + 1, estados[i]);
    }
}

void consonantes(char curp[], char nomb[], char nomb2[], char apP[], char apM[], int val)
{
    char conso_nomb[10], conso_apP[10], conso_apM[10];
    char consN[2], consP[2], consM[2];
    int lar_nomb, lar_apP, lar_apM;

    lar_apP = strlen(apP);
    solo_consonantes(apP, lar_apP, conso_apP);

    consP[0] = conso_apP[1];

    strncat(curp, consP, 2);

    curp[14] = '\0';

    lar_apM = strlen(apM);
    solo_consonantes(apM, lar_apM, conso_apM);

    consM[0] = conso_apM[1];

    strncat(curp, consM, 2);
    curp[15] = '\0';

    printf("%d",val);
    system("PAUSE");
    if (val==0)
    {
        lar_nomb = strlen(nomb);
        solo_consonantes(nomb, lar_nomb, conso_nomb);

        consN[0] = conso_nomb[0];
    }
    else
    {
        lar_nomb = strlen(nomb2);
        solo_consonantes(nomb2, lar_nomb, conso_nomb);
        consN[0] = conso_nomb[0];
    }

    

    strncat(curp, consN, 2);
    curp[16] = '\0';
}

void generacio(char curp[], int year)
{
    char gen[2];
    if (year < 2000)
    {
        strcpy(gen, "0");
        strncat(curp, gen, 2);
    }
    else
    {
        if (year < 2010)
        {
            strcpy(gen, "A");
            strncat(curp, gen, 2);
        }
        else
        {
            if (year < 2020)
            {
                strcpy(gen, "B");
                strncat(curp, gen, 2);
            }
        }
    }
    curp[18] = '\0';
}

void numAl(char curp[])
{
    int num, i;
    char n[2];
    for (i = 0; i < 10; i++)
    {
        num = rand() % 10;
    }
    snprintf(n, 2, "%d", num);

    strncat(curp, n, 2);
}

int nomb_Novalid(char nomb[])
{
    int i, band;
    char noVali[8][10] = {
        "MARIA/",
        "MA.",
        "MA",
        "M.",
        "M",
        "JOSE",
        "J.",
        "J"};

    
    for (i = 0; i < 8; i++)
    {
        if (strcmp(nomb, noVali[i])==1)
        {
              return band=1;
        }
    }
    return band=0;
}
