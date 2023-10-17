// Antonio Ramos Gonzalez Mt: 372576
// 10/9/2023 || 10/12/2023
// En esta Practica se definira un tipo de variable como un struct, para ingresar datos de distintos alumnos con un menu
// RGA_Act10_Pt1_932

#include "Babilonia.h"

int msg();
void menu();
void apP();
void apM();
void curp();
void estados(char est[]);

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
    char curp[18], nom[15], apP[15], apM[15],est[3];
    char anio[5], mes[3], dia[3], lon[2], cero[2],sex[2];
    int ani, me, di, lar,s;

    strcpy(cero,"0");

    validCad("Ingrese nombre: ", nom);
    mayusculas(nom);
    validCad("Ingrese apellido paterno: ", apP);
    mayusculas(apP);
    validCad("Ingrese apellido materno: ", apM);
    mayusculas(apM);

    strncpy(curp, apP, 2);
    curp[2] = '\0';
    strncat(curp, apM, 1);
    curp[3] = '\0';
    strncat(curp, nom, 1);
    curp[4] = '\0';

    system("CLS");
    ani = valid("Ingresa year de nacimiento: ", 1950, 2023);
    me = valid("Ingresa mes de nacimiento: ", 1, 12);
    di = valid("Ingresa dia de nacimiento: ", 1, 31);

    snprintf(anio, 5, "%d", ani);
    snprintf(mes, 3, "%d", me);
    snprintf(dia, 2, "%d", di);

    lar = strlen(anio);
    lon[0] = anio[lar - 2];
    lon[1] = anio[lar - 1];

    strncat(curp, lon, 2);
    curp[6] = '\0';
    strncat(curp, mes, 2);
    curp[8] = '\0';
    strncat(curp, cero, 1);
    curp[9] = '\0';
    strncat(curp, dia, 2);
    curp[10]='\0';

    s=valid("ingresa sexo: ",1,2);

    if (s==1)
    {
        strcpy(sex,"H");
        strncat(curp,sex,1);
    }
    else
    {
        strcpy(sex,"M");
        strncat(curp,sex,1);
    }

    curp[11]='\0';

    estados(est);

    strncat(curp,est,2);
    
    
    printf("%s\n", curp);
    system("PAUSE");
}

void estados(char est[])
{
    int a,i;
    char estados[32][20] = {
        "AG", "BC", "BS", "CC", "CS", "CH", "CL", "CM",
        "DF", "DG", "GR", "GT", "HG", "JC", "MC", "MN",
        "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP",
        "SL", "SR", "TC", "TS", "TL", "VZ", "YN", "ZS"};

    for ( i = 0; i < 32; i++)
    {
        printf("Estado %d: %s\n",i+1,estados[i]);
    }
    
    a = valid("Ingrese estado: ", 1, 32);
    strcpy(est, estados[a - 1]);
}