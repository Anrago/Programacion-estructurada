// Antonio Ramos Gonzalez Mt: 372576
// 9/12/2023 || 9/24/2023
// Cadenas parte 1
// RGA_Act10_Pt1_932
#include "Babilonia.h"

typedef struct _alumn
{
    char name[30];
    char lasP[30]; // apellido paterno
    char lasM[30]; // apellido materno
    int mt;        // matricula
    int age;       // edad
    char sex [10];       // sexo
    int status;    // dado de baja o no
} Talum;

int msg();
void nombAl(char nombre[], int sex);
void apellidoAl(char apellido[]);
void menu();
void printReg(Talum alumn[], int n);
int order_reg(Talum alumn[], int n, int band);
int searchSec(Talum alumn[], int n, int mt);
int searchBin(Talum alumn[], int inf, int sup, int mt);
Talum genAl();
Talum llenarManual();
Talum eliminar(Talum alumn);
void busq(int ind);

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
    printf("1.-Agalumnar(AUTOM 10 alumnISTROS)\n");
    printf("2.-Agalumnar manual\n");
    printf("3.-Eliminar alumnistro(logico)\n");
    printf("4.-Buscar\n");
    printf("5.-Ordenar\n");
    printf("6.-Imprimir\n");
    printf("0.-Salir\n");
    return valid("Elije una opcion: ", 0, 6);
}

void menu()
{
    Talum reg[500];
    int opc, el, i = 0, j;
    int mt, bus;
    bool band;

    do
    {
        opc = msg();
        switch (opc)
        {
        case 1:
            for (j = 0; j < 10; j++)
            {
                reg[i++] = genAl();
            }
            band = 1;
            break;

        case 2:
            reg[i++] = llenarManual();
            band = 1;
            break;

        case 3:
            el = valid("Que registro desea eliminar?", 300000, 399999);
            for(j=0;j<=i;j++)
            {
                if(reg[j].mt==el)
                {
                    reg[j].mt=0;
                }
            }
            break;

        case 4:
            mt = valid("Ingresa Matricula: ", 300000, 399999);

            if (band == 1)
            {
                printf("S\n");
                bus = searchSec(reg, i, mt);
            }
            else
            {
                printf("B\n");
                bus = searchBin(reg, 0, i, mt);
            }

            busq(bus);

            break;

        case 5:

            if (band == 1)
            {
                band = order_reg(reg, i, band);
            }

            break;

        case 6:
            printReg(reg, i);
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
            "ANA",
            "JULIETA",
            "JOSEFINA",
            "DANIELA",
            "CARMEN",
            "SOFIA",
            "LAURA",
            "ANDREA",
            "ELENA",
            "ISABEl"};

    char nombH[10][10] =
        {
            "JUAN",
            "CARLOS",
            "ROBERTO",
            "DAMIAN",
            "ANDRES",
            "DAVID",
            "ALEJANDR",
            "MIGUEL",
            "PEDRO",
            "FERNANDO"};

    if (sex == 1)
    {
        fil = rand() % 10;
        strcpy(nombre, nombH[fil]);
    }
    if (sex == 2)
    {
        fil = rand() % 10;
        strcpy(nombre, nombM[fil]);
    }
}

void apellidoAl(char apellido[])
{
    int fil;
    char ap[10][15] =
        {
            "GARCIA",
            "RODRIGUEZ",
            "PEREZ",
            "LOPEZ",
            "MARTINEZ",
            "GONZALEZ",
            "SANCHEZ",
            "ROMERO",
            "FRENANDEZ",
            "TORRES"};

    fil = rand() % 10;
    strcpy(apellido, ap[fil]);
}

Talum genAl()
{
    Talum alumn;
    int sex;
    char nombre[10], apellido[15];

    sex= rand() % 2 + 1;

    nombAl(nombre,sex);
    strcpy(alumn.name, nombre);

    apellidoAl(apellido);
    strcpy(alumn.lasP, apellido);

    apellidoAl(apellido);
    strcpy(alumn.lasM, apellido);

    alumn.age = rand() % 13 + 18;

    alumn.status = rand() % 2;

    alumn.mt = rand() % 100000 + 300000;

    if(sex==1)
    {
        strcpy(alumn.sex,"H");
    }
    else
    {
        strcpy(alumn.sex,"M");
    }
    
    return alumn;
}

Talum llenarManual()
{
    int sex;
    Talum alumn;
    system("CLS");
    fflush(stdin);


    alumn.mt=valid("Ingrese matricula: ",300000,399999);
    
    validCad("Ingrese nombre: ",alumn.name);
    validCad("Ingrese apellido paterno: ",alumn.lasP);
    validCad("Ingrese apellido materno: ",alumn.lasM);

    system("CLS");
    alumn.age=valid("Ingrese Edad: ",18,30);
    sex=valid("Ingresa el sexo(1.-H,2.-M): ",1,2);
    if(sex==1)
    {
        strcpy(alumn.sex,"H");
    }
    else
    {
        strcpy(alumn.sex,"M");
    }
    alumn.status=valid("Ingrese estatus: ",0,1);

    return alumn;
}

int searchSec(Talum alumn[], int n, int mt)
{
    int i;                   // define contador
    for (i = 0; i <= n; i++) //
    {
        if (alumn[i].mt == mt) // Busca en el vector el numero buscado
        {
            return i; // si encuentra el valor, retorna el valor del indice
        }
    }
    return 1; // si no encuentra el valor, retorna -1
}

int order_reg(Talum alumn[], int n, int band)
{
    int i, j;
    Talum temp; // guarda valor de manera temporal

    for (i = 0; i < n - 1; i++) // Busqueda secuencial
    {
        for (j = i + 1; j < n; j++)
        {
            if (alumn[j].mt < alumn[i].mt)
            {
                temp = alumn[i];     // Guarda el valor de vect[i] en temp
                alumn[i] = alumn[j]; // Guarda el valor de vect[j] en vect[i]
                alumn[j] = temp;     // Guarda el valor de temp en vect[j]
            }
        }
    }
    return band = 0;
}

void printReg(Talum alumn[], int n)
{
    int i;
    system("CLS");
    printf("%-10s %-10s %-10s %-10s %-4s %-5s %-8s\n",
           "Matricula", "Nombre", "ApP", "ApM", "Edad", "Sexo", "Estatus");
    for (i = 0; i < n; i++)
    {
        if (alumn[i].status == 1)
        {
            printf("%-10d %-10s %-10s %-10s %-4d %-5s %-8d\n",
                   alumn[i].mt, alumn[i].name, alumn[i].lasP,
                   alumn[i].lasM, alumn[i].age, alumn[i].sex,
                   alumn[i].status);
        }
    }
    system("PAUSE");
}

void busq(int ind)
{
    if (ind != -1)
    {
        printf("Alumno encontrado en el indice: %d", ind);
    }
    else
    {
        printf("Alumno no encontrado");
    }
    scanf("PAUSE");
}

int searchBin(Talum alumn[], int inf, int sup, int mt)
{
    int med;
    while (inf <= sup)
    {
        med = (inf + sup) / 2;
        if (alumn[med].mt == mt)
        {
            return med;
        }
        else
        {
            if (mt < alumn[med].mt)
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
