// Antonio Ramos Gonzalez Mt: 372576
// 10/9/2023 || 10/13/2023
// En esta Practica se definira un tipo de variable como un struct, para ingresar datos de distintos alumnos con un menu
// RGA_Act10_932
#include "Babilonia.h" //llamar mi biblioteca
#define N 500 
typedef struct _alumn
{
    char name[30];
    char lasP[30]; // apellido paterno
    char lasM[30]; // apellido materno
    int mt;        // matricula
    int age;       // edad
    char sex[10];  // sexo
    int status;    // dado de baja o no
} Talum;           // defino mi tipo de bariable de tipo struct

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

// Meno de elecciones
void menu()
{
    Talum reg[N]; // genera vector del tipo Talum
    int opc, el, i = 0, j;
    int mt, bus;
    bool band;

    do
    {
        opc = msg(); // lee el valor recivido de msg
        switch (opc)
        {
        case 1:
            if (i < N) // valida que no se supere el limite maximo
            {
                for (j = 0; j < 50; j++)
                {
                    if (i < N)
                    {
                        reg[i] = genAl(reg, i);
                        i++;
                    }
                }
                band = 1; // se usa para los tipos de busqueda
            }
            else
            {
                printf("BASE DE DATOS LLENA\n");
                system("PAUSE");
            }
            break;

        case 2:
            if (i < N) // valida que no se supere el limite maximo
            {
                reg[i] = llenarManual(reg, i);
                i++; // aumenta el indice del vector
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
            if (band == 1) // verifica si el vectro ya fue ordenado
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

            if (band == 1) // verifica si el vectro ya fue ordenado
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
                band = order_reg(reg, i, band); // ordena registro
            }

            break;

        case 6:
            printReg(reg, i); // imprime vector
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
            "ISABEl"}; // Nombres de mujeres

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
            "FERNANDO"}; // Nombres de hombre

    if (sex == 1) // Se encarga de leer el sexo para decidir si el nombre sera de hombre
    {
        fil = rand() % 10;          // elige un nombre de manera aleatoria
        strcpy(nombre, nombH[fil]); // copia el valor del nombre el la variable
    }
    if (sex == 2) // Se encarga de leer el sexo para decidir si el nombre sera de mujer
    {
        fil = rand() % 10;          // elige un nombre de manera aleatoria
        strcpy(nombre, nombM[fil]); // copia el valor del nombre el la variable
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
            "TORRES"}; // Apellidos generales

    fil = rand() % 10;         // elige un apellido de manera aleatoria
    strcpy(apellido, ap[fil]); // copia el valor del apellido en la variable
}

// Funcion que verifica que no se repitan matriculas
int verMt(Talum alumn[], int n, int mt)
{
    int i, j, cont; // variables locales
    cont = 0;
    for (i = 0; i < n; i++) // ciclo que aumenta el valor de i
    {
        for (j = 0; j < i; j++) // ciclo que aumenta el valor de j
        {
            if (alumn[j].mt == mt) // valida que no existan
            {
                cont = 1;
            }
        }
    }
    if (cont == 1) // verifica el valor de cont
    {
        return 1; // si se repiten matriculas retorna un 1
    }
    else
    {
        return 0; // si no se repiten retorna un 0
    }
}

// Funcion que genera datos de alumnos aleatorios
Talum genAl(Talum alumn[], int i)
{

    int sex, val;                  // variables locales
    char nombre[10], apellido[15]; // variables que guardaran nombres y apellidos

    sex = rand() % 2 + 1; // genera un sexo aleatorio

    nombAl(nombre, sex);           // ingresa a la funcion para decidir un nombre
    strcpy(alumn[i].name, nombre); // copia nombre en el struct

    apellidoAl(apellido);            // ingresa a la funcion para decidir un apellido
    strcpy(alumn[i].lasP, apellido); // copia apellido en el struct

    apellidoAl(apellido);            // ingresa a la funcion para decidir un apellido
    strcpy(alumn[i].lasM, apellido); // copia apellido en el struct

    alumn[i].age = rand() % 13 + 18; // genera una edad aleatoria entre 18 y 30

    alumn[i].status = 1; // aplica un estatus al alumno

    do
    {
        val = 0;
        alumn[i].mt = rand() % 100000 + 300000; // genera una matricula entre 300k y 399k
        val = verMt(alumn, i, alumn[i].mt);     // ingresa a la funcion para validar

    } while (val != 0); // ciclo que se repite si 2 matriculas son iguales

    if (sex == 1) // valida el sexo del usuario
    {
        strcpy(alumn[i].sex, "H"); // si sex es 1 entonces sera hombre
    }
    else
    {
        strcpy(alumn[i].sex, "M"); // si no sera mujer
    }

    return alumn[i]; // retorna alumn
}

// Funcion para ingresar a un alumno de manera manual
Talum llenarManual(Talum alumn[], int i)
{
    int sex, val; // variables locales
    system("CLS");
    fflush(stdin);
    do
    {
        val = 0;
        alumn[i].mt = valid("Ingrese matricula: ", 300000, 399999); // lee una matricula
        val = verMt(alumn, i, alumn[i].mt);                         // rntra a la funcion de validar

        if (val != 0) // si se repiten imprime mensaje
        {
            printf("Matricula ya existente\n");
        }

    } while (val != 0); // ciclo que se repite si 2 matriculas son iguales

    validCad("Ingrese nombre: ", alumn[i].name);           // ingresa y valida nombre
    validCad("Ingrese apellido paterno: ", alumn[i].lasP); // ingresa y valida apellido paterno
    validCad("Ingrese apellido materno: ", alumn[i].lasM); // ingresa y valida apellido materno

    system("CLS");
    alumn[i].age = valid("Ingrese Edad: ", 18, 30); // ingresa y valida edad

    sex = valid("Ingresa el sexo(1.-H,2.-M): ", 1, 2); // ingresa y valida sexo

    if (sex == 1) // decide si es hombre o mujer
    {
        strcpy(alumn[i].sex, "H");
    }
    else
    {
        strcpy(alumn[i].sex, "M");
    }
    alumn[i].status = 1; // ingresa y valida estatus

    return alumn[i];
}

// Funcion de busqueda secuencial
int searchSec(Talum alumn[], int n, int mt)
{
    int i; // define contador
    i = 0;
    for (i = 0; i <= n; i++)
    {
        if (alumn[i].mt == mt) // Busca en el vector el numero buscado
        {
            return i; // si encuentra el valor, retorna el valor del indice
        }
    }
    return -1; // si no encuentra el valor, retorna -1
}

// Funcion que ordena el vector
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
                temp = alumn[i];     // Guarda el valor de alumn[i] en temp
                alumn[i] = alumn[j]; // Guarda el valor de alumn[j] en alumn[i]
                alumn[j] = temp;     // Guarda el valor de temp en alumn[j]
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
           "Matricula", "Nombre", "ApP", "ApM", "Edad", "Sexo"); // imrpirme las columnas, como datos
    for (i = 0; i < n; i++)                                                 // ciclo que aumenta el valor del vector
    {
        if (alumn[i].status == 1) // verifica que el estatus sea 1
        {
            printf("%-10d %-10s %-10s %-10s %-4d %-5s\n",
                   alumn[i].mt, alumn[i].name, alumn[i].lasP, // imprime el vector
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
        med = (inf + sup) / 2;   // definir la mitad del vector
        if (alumn[med].mt == mt) // verifica si el valor buscado se encuentra en la actual pocicion de med
        {
            return med; // retorna el valor de med
        }
        else
        {
            if (mt < alumn[med].mt) // verifica que el valor buscado sea menor al valor en med
            {
                sup = med--; // resta 1 a med y lo asigna al valor sup para que disminuya asi el valor central
            }
            else
            {
                inf = med++; // suma 1 a med y lo asigna al valor inf para que disminuya asi el valor central
            }
        }
    }
    return -1; // si no encuentra coincidencia retorna -1
}
