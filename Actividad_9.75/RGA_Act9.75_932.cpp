// Antonio Ramos Gonzalez Mt: 372576
// 10/9/2023 || 10/12/2023
// En esta Practica se definira un tipo de variable como un struct, para ingresar datos de distintos alumnos con un menu
// RGA_Act10_Pt1_932

#include "Babilonia.h"

int msg();
void menu();
void agregarACurp(char agreg[]);
void nomb();
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
//     char curp[18], nom[15], apP[15], apM[15];
//     char anio[4], mes[2], dia[2],est[2];
    apP();
//     int i, j, k, ani, me, di,sex;

//     validCad("Ingrese nombre: ", nom);
//     validCad("Ingrese apellido paterno: ", apP);
//     validCad("Ingrese apellido materno: ", apM);

//     for (i = 0; i < 2; i++)
//     {
//         curp[i] = apP[i];
//     }
//     for (j = i; j < 4; i++, j++)
//     {
//         if (i == 2)
//         {
//             curp[i] = apM[0];
//         }

//         if (i == 3)
//         {
//             curp[i] = nom[0];
//         }
//     }

//     system("CLS");
//     ani = valid("Ingresa year de nacimiento: ", 1950, 2023);
//     me = valid("Ingresa mes de nacimiento: ", 01, 12);
//     di = valid("Ingresa dia de nacimiento: ", 1, 31);

//     snprintf(anio, 20, "%d", ani);
//     snprintf(mes, 20, "%d", me);
//     snprintf(dia, 20, "%d", di);

//     for (k = 2, j = i; j < 6; j++, i++, k++)
//     {
//         curp[j] = anio[k];
//     }
//     for (k = 0, j = i; j < 8; j++, i++, k++)
//     {
//         curp[j] = mes[k];
//     }
//     for (k = 0, j = i; j < 9; j++, i++, k++)
//     {
//         curp[j]='0';
//         curp[j+1] = dia[k];
//     }

//     sex=valid("Ingresa sexo: ",1,2);
//     if (sex==1)
//     {
//         curp[j+1]='H';
//     }
//     if (sex==2)
//     {
//         curp[j+1]='M';
//     }
    
    
//     estados(est);
    
//     for (k=0, j = i+1; j < 12; k++,j++,i++)
//     {
//         curp[j]=est[k];
//     }
    

//     printf("%s", curp);
//     system("PAUSE");
}

void agregarACurp(char agreg[],char curp[18])
{
    static int i,j;

}


void apP()
{
    char aP[15];
    validCad("Ingrese apellido paterno ", aP);
    agregarACurp(aP);

}































void estados(char est[])
{
    int a;
    char estados[32][20]= {
        "AG", "BC", "BS", "CC", "CS", "CH", "CL", "CM",
        "DF", "DG", "GR", "GT", "HG", "JC", "MC", "MN",
        "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP",
        "SL", "SR", "TC", "TS", "TL", "VZ", "YN", "ZS"
    };
    a=valid("Ingrese estado",1,32);
    strcpy(est,estados[a-1]);
}