// Antonio Ramos Gonzalez Mt: 372576
// 9/12/2023 || 9/24/2023
// Cadenas parte 1
// RGA_Act7_Pt1_932
#include "Babilonia.h"

int msg();
void nombAl(char nombre[],int sex);
char apellido();
void menu();
void al(Talum alumn);

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

int msg()
{
    system("CLS");
    printf("MENU\n");
    printf("1.-Agregar(AUTOM 10 REGISTROS)\n");
    printf("2.-Agregar manual\n");
    printf("3.-Eliminar registro(logico)\n");
    printf("4.-Buscar\n");
    printf("5.-Ordenar\n");
    printf("6.-Imprimir\n");
    printf("0.-Salir\n");
    return valid("Elije una opcion: ", 0, 6);
}

void menu()
{
    Talum alumn[500];
    int opc, i;
    do
    {
        opc = msg();
        switch (opc)
        {
        case 1:
            for (i = 0; i < 10; i++)
            {
                al(alumn[i]);
            }
            break;

        default:
            break;
        }
    } while (opc != 0);
}

void nombAl(char nombre[], int sex)
{
    int fil;
    char nombM[10][10] =
        {
            "Ana",
            "Julieta",
            "Josefina",
            "Dianna",
            "Carmen",
            "Sofia",
            "Laura",
            "Andrea",
            "Elena",
            "Isabel"};

    char nombH[10][10] =
        {
            "Juan",
            "Carlos",
            "Roberto",
            "Damian",
            "Andres",
            "David",
            "Alejandro",
            "Miguel",
            "Pedro",
            "Fernando"};

    if (sex == 1)
    {
        fil = rand() % 10;
        strcpy(nombre,nombH[fil]);
    }
    if(sex==2)
    {
        fil = rand() % 10;
        strcpy(nombre,nombM[fil]);
    }
}

// char apellido()
// {
//     char ap[10][15] =
//         {
//             "García",
//             "Rodríguez",
//             "Pérez",
//             "López",
//             "Martínez",
//             "González",
//             "Sánchez",
//             "Romero",
//             "Fernández",
//             "Torres"};
// }

void al(Talum alumn)
{
    char nombre[10];
    int sex;
    sex = rand() % 2 + 1;
    nombAl(nombre, sex);
    strcpy(alumn.name, nombre);
    system("CLS");
    printf("%d\n",sex);
    printf("%s\n",alumn.name);
    system("PAUSE");
}