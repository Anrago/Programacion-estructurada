// Antonio Ramos Gonzalez Mt: 372576
// 10/9/2023 || 15/13/2023
// En esta Practica se definira un tipo de variable como un struct, para ingresar datos 315985 de distintos alumnos con un menu
// RGA_Act10_932
#include "Babilonia.h" 
#define N 500 
typedef struct _alumn
{
    char name[30];
    char lasP[30]; 
    char lasM[30]; 
    int mt;        
    int age;       
    char sex[10]; 
    int status;    
} Talum;           

int msg();
void nombAl(char nombre[], int sex);
void apellidoAl(char apellido[]);
void menu();
void printReg(Talum alumn[], int n);
int order_reg(Talum alumn[], int n, int band);
int searchSec(Talum alumn[], int n, int mt);
int searchBin(Talum alumn[], int inf, int sup, int mt);
Talum genAl(Talum alumn[], int i);
Talum llenarManual(Talum alumn[], int i);
Talum eliminar(Talum alumn);
void busq(int ind);
int verMt(Talum alumn[], int n, int mt);

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

// Muestra mensaje
int msg()
{
    system("CLS");
    printf("MENU\n");
    printf("1.-Agrega alumnar(AUTOM 10 alumnos)\n");
    printf("2.-Agrega alumno manual\n");
    printf("3.-Eliminar alumno(logico)\n");
    printf("4.-Buscar\n");
    printf("5.-Ordenar\n");
    printf("6.-Imprimir\n");
    printf("0.-Salir\n");
    return valid("Elije una opcion: ", 0, 6);
}

// MenoD de elecciones
void menu()
{
    Talum reg[N]; 
    int opc, el, i = 0, j;
    int mt, bus;
    bool band;

    do
    {
        opc = msg(); 
        switch (opc)
        {
        case 1:
            if (i < N) 
            {
                for (j = 0; j < 10; j++)
                {
                    if (i < N)
                    {
                        reg[i] = genAl(reg, i);
                        i++;
                    }
                }
                band = 1;
            }
            else
            {
                printf("BASE DE DATOS LLENA\n");
                system("PAUSE");
            }
            break;

        case 2:
            if (i < N) 
            {
                reg[i] = llenarManual(reg, i);
                i++; 
                band = 1;
            }
            else
            {
                printf("BASE DE DATOS LLENA\n");
                system("PAUSE");
            }
            break;

        case 3:
            el = valid("Ingrese matricula: ", 300000, 399999);
            if (band == 1) 
            {
                bus = searchSec(reg, i, el);
            }
            else
            {
                bus = searchBin(reg, 0, i, el);
            }
            reg[bus].status=0;
            break;

        case 4:
            mt = valid("Ingresa Matricula: ", 300000, 399999);

            if (band == 1) 
            {
                bus = searchSec(reg, i, mt);
            }
            else
            {
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
        }
    } while (opc != 0);
}

// Funcion para nombres
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

// Funcio para apellidos
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

// Funcion que verifica que no se repitan matriculas
int verMt(Talum alumn[], int n, int mt)
{
    int i, j, cont; 
    cont = 0;
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j <=i; j++) 
        {
            if (alumn[j].mt == mt) 
            {
                cont = 1;
            }
        }
    }
    if (cont == 1) 
    {
        return 1; 
    }
    else
    {
        return 0; 
    }
}

// Funcion que genera datos de alumnos aleatorios
Talum genAl(Talum alumn[], int i)
{

    int sex, val;                  
    char nombre[10], apellido[15]; 

    sex = rand() % 2 + 1; 

    nombAl(nombre, sex);           
    strcpy(alumn[i].name, nombre); 

    apellidoAl(apellido);            
    strcpy(alumn[i].lasP, apellido); 

    apellidoAl(apellido);            
    strcpy(alumn[i].lasM, apellido); 

    alumn[i].age = rand() % 13 + 18; 

    alumn[i].status = 1;

    do
    {
        val = 0;
        alumn[i].mt = rand() % 100000 + 300000; 
        val = verMt(alumn, i, alumn[i].mt);     

    } while (val != 0); 

    if (sex == 1)
    {
        strcpy(alumn[i].sex, "H"); 
    }
    else
    {
        strcpy(alumn[i].sex, "M"); 
    }

    return alumn[i];
}

// Funcion para ingresar a un alumno de manera manual
Talum llenarManual(Talum alumn[], int i)
{
    int sex, val; 
    system("CLS");
    fflush(stdin);
    do
    {
        val = 0;
        alumn[i].mt = valid("Ingrese matricula: ", 300000, 399999); 
        val = verMt(alumn, i, alumn[i].mt);                        

        if (val != 0) 
        {
            printf("Matricula ya existente\n");
        }

    } while (val != 0); 

    validCad("Ingrese nombre: ", alumn[i].name);           
    validCad("Ingrese apellido paterno: ", alumn[i].lasP); 
    validCad("Ingrese apellido materno: ", alumn[i].lasM); 

    system("CLS");
    alumn[i].age = valid("Ingrese Edad: ", 18, 30);

    sex = valid("Ingresa el sexo(1.-H,2.-M): ", 1, 2); 

    if (sex == 1) 
    {
        strcpy(alumn[i].sex, "H");
    }
    else
    {
        strcpy(alumn[i].sex, "M");
    }
    alumn[i].status = 1;

    return alumn[i];
}

// Funcion de busqueda secuencial
int searchSec(Talum alumn[], int n, int mt)
{
    int i; 
    i = 0;
    for (i = 0; i <= n; i++)
    {
        if (alumn[i].mt == mt) 
        {
            return i; 
        }
    }
    return -1; 
}

// Funcion que ordena el vector
int order_reg(Talum alumn[], int n, int band)
{
    int i, j;
    Talum temp; 

    for (i = 0; i < n - 1; i++) 
    {
        for (j = i + 1; j < n; j++)
        {
            if (alumn[j].mt < alumn[i].mt)
            {
                temp = alumn[i];  
                alumn[i] = alumn[j]; 
                alumn[j] = temp;   
            }
        }
    }
    return band = 0;
}

// Funcion para imprimir el vector
void printReg(Talum alumn[], int n)
{
    int i;
    system("CLS");
    printf("%-10s %-10s %-10s %-10s %-4s %-5s\n",
           "Matricula", "Nombre", "ApP", "ApM", "Edad", "Sexo"); 
    for (i = 0; i < n; i++)                                                
    {
        if (alumn[i].status == 1) 
        {
            printf("%-10d %-10s %-10s %-10s %-4d %-5s\n",
                   alumn[i].mt, alumn[i].name, alumn[i].lasP, 
                   alumn[i].lasM, alumn[i].age, alumn[i].sex);
        }
    }
    system("PAUSE");
}

// Funcion que imprime el alumno buscado
void busq(int ind)
{
    if (ind != -1)
    {
        printf("Alumno encontrado en el indice: %d\n", ind+1);
    }
    else
    {
        printf("Alumno no encontrado\n");
    }
    system("PAUSE");
}

// Funcion de busqueda binaria
int searchBin(Talum alumn[], int inf, int sup, int mt)
{
    int med; // variable local
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
