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
    char curp[18], nom[15], apP[15], apM[15];
    char anio[4], mes[2], dia[2], est[2], sex[2],lon[2];
    int ani, me, di,lar;

    validCad("Ingrese nombre: ", nom);
    validCad("Ingrese apellido paterno: ", apP);
    validCad("Ingrese apellido materno: ", apM);

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

    snprintf(anio, 4, "%d", ani);
    snprintf(mes, 2, "%d", me);
    snprintf(dia, 2, "%d", di);

    lar=strlen(anio);
    lon[0] = anio[lar - 2];
    lon[1] = anio[lar - 1];

    strncat(curp, lon , 2);
    curp[6] = '\0';
    // strncat(curp, mes, 2);
    curp[8] = '\0';
    strncat(curp, dia, 2);

    // s=valid("Ingresa sexo: ",1,2);
    // if (s==1)
    // {
    //     strcpy(sex,'H');
    // }
    // if (s==2)
    // {
    //     curp[j+1]='M';
    // }

    estados(est);
    printf("%s\n",lon);
    printf("%s", curp);
    system("PAUSE");
}

void estados(char est[])
{
    int a;
    char estados[32][20] = {
        "AG", "BC", "BS", "CC", "CS", "CH", "CL", "CM",
        "DF", "DG", "GR", "GT", "HG", "JC", "MC", "MN",
        "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP",
        "SL", "SR", "TC", "TS", "TL", "VZ", "YN", "ZS"};
    a = valid("Ingrese estado", 1, 32);
    strcpy(est, estados[a - 1]);
}