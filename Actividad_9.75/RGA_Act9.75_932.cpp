// Antonio Ramos Gonzalez Mt: 372576
// 10/9/2023 || 10/12/2023
// En esta Practica se definira un tipo de variable como un struct, para ingresar datos de distintos alumnos con un menu
// RGA_Act10_Pt1_932

#include "Babilonia.h"

int msg();
void menu();
void curp();
void nombre(char curp[],char nomb[],char apP[],char apM[]);
void nacimiento(char curp[]);
void sexo(char curp[]);
void estados(char curp[]);
void consonantes(char curp[],char nomb[],char apP[],char apM[]);

int main()
{
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
    char nomb[15], apP[15], apM[15];

    validCad("Ingrese nombre: ", nomb);
    validCad("Ingrese apellido paterno: ", apP);
    validCad("Ingrese apellido materno: ", apM);
    

    nombre(curp,nomb,apP,apM);

    nacimiento(curp);

    sexo(curp);

    estados(curp);

    consonantes(curp,nomb,apP,apM);

    printf("%s\n", curp);
    system("PAUSE");
}

void nombre(char curp[],char nomb[],char apP[],char apM[])
{
    mayusculas(nomb);
 
    mayusculas(apP);
    
    mayusculas(apM);

    strncpy(curp, apP, 2);
    curp[2] = '\0';
    strncat(curp, apM, 1);
    curp[3] = '\0';
    strncat(curp, nomb, 1);
    curp[4] = '\0';
}

void nacimiento(char curp[])
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
    int a, i;
    char estados[32][20] = {
        "AG", "BC", "BS", "CC", "CS", "CH", "CL", "CM",
        "DF", "DG", "GR", "GT", "HG", "JC", "MC", "MN",
        "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP",
        "SL", "SR", "TC", "TS", "TL", "VZ", "YN", "ZS"};

    for (i = 0; i < 32; i++)
    {
        printf("Estado %d: %s\n", i + 1, estados[i]);
    }

    a = valid("Ingrese estado: ", 1, 32);
    strcpy(est, estados[a - 1]);
    strncat(curp, est, 2);
    curp[13] = '\0';
}

void consonantes(char curp[],char nomb[],char apP[],char apM[])
{
    char conso_nomb[10],conso_apP[10],conso_apM[10];
    char consN[2],consP[2],consM[2];
    int lar_nomb,lar_apP,lar_apM;

    lar_apP=strlen(apP);
    solo_consonantes(apP,lar_apP,conso_apP);

    consP[0] = conso_apP[1];
    
    strncat(curp,consP,2);

    curp[14] = '\0';


    lar_apM=strlen(apM);
    solo_consonantes(apM,lar_apM,conso_apM);

    consM[0] = conso_apM[1];
    
    strncat(curp,consM,2);
    curp[15] = '\0';


    lar_nomb=strlen(nomb);
    solo_consonantes(nomb,lar_nomb,conso_nomb);

    consN[0] = conso_nomb[0];
    
    strncat(curp,consN,2);
    curp[16] = '\0';

    
}
