// Antonio Ramos Gonzalez Mt: 372576
// 10/3/2023 || 10/12/2023
// Esta biblioteca contiene las funciones que usare durante proximas practicas
// Babilonia
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
typedef int Tkay;
typedef struct _index
{
    Tkay id;
    int index;
} Tindex;

typedef struct _WrKr
{
    int status;
    Tkay enrollement;
    char name[30];
    char LastName1[50];
    char LastName2[50];
    char sex[15];
    char JobPstion[30];
    char state[30];
    int age;
    Tkay CellPhone;

} TWrKr;


int valid(const char msg[], int lim_inf, int lim_sup);
void vectRand(int vect[], int m, int lim_inf, int lim_sup);
void PrintVect(int vect[], int m);
void OrderVect(int vect[], int m);
int SearchVect(int vect[], int m, int num);
int bisiesto(int year);
int verMt(TWrKr reg[], int n, int mt);
// Cadenas
void mayusculas(char cad[]);
void validCad(const char msg[], char cad[]);
void solo_consonantes(char cad[], int i, char conso[]);
void solo_vocales(char cad[], int i, char voc[]);
void apAl(char apellido[]);
void nombreAl(char nombre[], int sex);
void puestoAl(char puesto[]);
void estados( char nombestado[]);

int verMt(TWrKr reg[], int n, int mt)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (reg[j].enrollement == mt)
            {
                return 1;
            }
        }
    }

    return 0;
}

// Genera numero aleatorios no repetidos en un vector
void vectRand(int vect[], int m, int lim_in, int lim_sup)
{
    int i, x, cont, j, ran; // variables locales
    x = (lim_sup - lim_in) + 1;

    for (i = 0; i < m; i++) // llama a los vectores mediante su indice
    {
        do // ciclo encargado de validar que no se repitan los numeros
        {
            cont = 0;                    // se encargara de guardar la validacion
            ran = (rand() % x) + lim_in; // genera numero random

            for (j = 0; j < i; j++) // llama a los vectores mediante su indice
            {
                if (vect[j] == ran) // valida que el valor random no se igual a los ya generados
                {
                    cont = 1;
                }
            }

        } while (cont != 0); // repite el ciclo en caso de que se repitan los numeros

        vect[i] = ran; // se asigna el valor random al vecotor
    }
}

// Imprime vector
void PrintVect(int vect[], int m)
{
    int i; // variable local, se encargara de acceder a los indices de los vectores
    system("CLS");
    printf("VECTOR \n");
    printf("---------------------\n");
    for (i = 0; i < m; i++) // ciclo que controla la impresion del vector 1
    {
        printf("[%d]\n", vect[i]); // imprime el vector 1
    }
    system("PAUSE");
}

// valida las opciones
int valid(const char msg[], int lim_in, int lim_sup)
{
    char cad[10]; // cadena que leera un numero
    int opc;      // guardara un numer

    do
    {
        printf("%s", msg);
        fflush(stdin);
        gets(cad);       // lee el un numero como caracter
        opc = atoi(cad); // convierte el caracter en un numero
        system("CLS");
    } while (opc < lim_in || opc > lim_sup); // valida que el numero sea correcto
    return opc;
}

// ordena un vector
void OrderVect(int vect[], int m)
{
    int i, j;
    int temp;                   // guarda valor de manera temporal
    for (i = 0; i < m - 1; i++) // Busqueda secuencial
    {
        for (j = i + 1; j < m; j++)
        {
            if (vect[j] < vect[i])
            {
                temp = vect[i];    // Guarda el valor de vect[i] en temp
                vect[i] = vect[j]; // Guarda el valor de vect[j] en vect[i]
                vect[j] = temp;    // Guarda el valor de temp en vect[j]
            }
        }
    }
}

// Busca en el vector
int SearchVect(int vect[], int m, int num)
{
    int i;                  // define contador
    for (i = 0; i < m; i++) //
    {
        if (vect[i] == num) // Busca en el vector el numero buscado
        {
            return i; // si encuentra el valor, retorna el valor del indice
        }
    }
    return -1; // si no encuentra el valor, retorna -1
}

// año bisiesto
int bisiesto(int year)
{

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }

    return 0;
}
//*********************Cadenas*********************

void mayusculas(char cad[])
{
    int j = 0, i;
    i = strlen(cad); // llama a la funcion para calcular la cantidad de caracteres
    while (j < i)
    {
        if (cad[j] >= 'a')
        {
            if (cad[j] <= 'z')
            {
                cad[j] -= 32; // resta 32 en codigo ASCCI volviendo las minusculas a mayusculas
            }
        }
        j++;
    }
}

// RGA_Act7_Pt2_10_932
void validCad(const char msg[], char cad[])
{
    int band, i, len;
    band = 0;
    do
    {

        band = 0;
        i = 0;
        system("CLS");
        printf("%s", msg);
        fflush(stdin);
        gets(cad);
        mayusculas(cad);

        len = strlen(cad);

        if (cad[0] == ' ') // no puede iniciar con espacios
        {
            band = 1;
        }

        if (cad[len - 1] == ' ') // no puede terminar con espacios
        {
            band = 1;
        }

        i = 0;
        while (i < len)
        {
            if (cad[i] == ' ')
            {
                if (cad[i + 1] == ' ') // verifica que no haya 2 espacios seguidos
                {
                    band = 1;
                }
            }
            i++;
        }

        i = 0;
        while (i < len) // verifica que los caracteres dados sean en mayusculas
        {
            if (cad[i] > 'Z')
            {
                band = 1;
            }
            else
            {
                if (cad[i] < 'A')
                {
                    if (cad[i] != ' ')
                    {
                        if ((unsigned char)cad[i] == 164 || (unsigned char)cad[i] == 165)
                        {
                            cad[i] = 'X';
                        }
                        else
                        {
                            if ((unsigned char)cad[i] == 129 || (unsigned char)cad[i] == 154)
                            {
                                cad[i] = 'U';
                            }
                            else
                            {
                                if ((unsigned char)cad[i] == 160)
                                {
                                    cad[i] = 'A';
                                }
                                else
                                {
                                    if ((unsigned char)cad[i] == 130)
                                    {
                                        cad[i] = 'E';
                                    }
                                    else
                                    {
                                        if ((unsigned char)cad[i] == 161)
                                        {
                                            cad[i] = 'I';
                                        }
                                        else
                                        {
                                            if ((unsigned char)cad[i] == 162)
                                            {
                                                cad[i] = 'O';
                                            }
                                            else
                                            {
                                                if ((unsigned char)cad[i] == 163)
                                                {
                                                    cad[i] = 'U';
                                                }
                                                else
                                                {
                                                    if ((unsigned char)cad[i] == 181)
                                                    {
                                                        cad[i] = 'A';
                                                    }
                                                    else
                                                    {
                                                        if ((unsigned char)cad[i] == 144)
                                                        {
                                                            cad[i] = 'E';
                                                        }
                                                        else
                                                        {
                                                            if ((unsigned char)cad[i] == 214)
                                                            {
                                                                cad[i] = 'I';
                                                            }
                                                            else
                                                            {
                                                                if ((unsigned char)cad[i] == 224)
                                                                {
                                                                    cad[i] = 'O';
                                                                }
                                                                else
                                                                {
                                                                    if ((unsigned char)cad[i] == 233)
                                                                    {
                                                                        cad[i] = 'U';
                                                                    }
                                                                    else
                                                                    {
                                                                        if (cad[i] != '/' && cad[i] != '.' && cad[i] != '`' && cad[i] != '-' && cad[i] != 39)
                                                                        {
                                                                            band = 1;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                i++;
            }
        }
    } while (band != 0);
}

void solo_consonantes(char cad[], int i, char conso[])
{
    system("CLS");
    int j = 0;
    int k = 0;
    while (j < i)
    {
        // if que se encarga de analizar si los caracteres son vocales o consonantes
        if (cad[j] != 'A')
        {
            if (cad[j] != 'E')
            {
                if (cad[j] != 'I')
                {
                    if (cad[j] != 'O')
                    {
                        if (cad[j] != 'U')
                        {
                            conso[k] = cad[j];
                            k++;
                        }
                    }
                }
            }
        }

        j++; // controla el ciclo
    }
    conso[k] = '\0';
}

void solo_vocales(char cad[], int i, char voc[])
{
    int j = 0;
    int k = 0;
    while (j < i)
    {
        // if que se encarga de analizar si los caracteres son vocales o consonantes
        if (cad[j] == 'A')
        {
            voc[k] = cad[j];
            k++;
        }
        if (cad[j] == 'E')
        {
            voc[k] = cad[j];
            k++;
        }
        if (cad[j] == 'I')
        {
            voc[k] = cad[j];
            k++;
        }
        if (cad[j] == 'O')
        {
            voc[k] = cad[j];
            k++;
        }
        if (cad[j] == 'U')
        {
            voc[k] = cad[j];
            k++;
        }

        j++; // controla el ciclo
    }
    voc[k] = '\0';
}

void apAl(char apellido[])
{
    int i, al;
    char ap[87][20] =
        {
            "PEREZ", "LOPEZ", "GONZALEZ", "RODRIGUEZ", "MARTINEZ", "SANCHEZ", "FERNANDEZ", "GARCIA", "RODRIGUEZ", "DIAZ", "TORRES", "RAMIREZ", "JIMENEZ",
            "VARGAS", "MORALES", "RUIZ", "CASTRO", "HERRERA", "MEDINA", "NAVARRO", "DELGADO", "ROMERO", "MORENO", "GOMEZ", "VARGAS", "PEREZ", "FLORES", "GONZALEZ",
            "NUNEZ", "SILVA", "SOTO", "MENDOZA", "ROJAS", "MENDEZ", "SALAS", "AGUIRRE", "BENITEZ", "GUZMAN", "PAREDES", "RIOS", "VALENZUELA", "CORDERO", "ESCOBAR",
            "OCHOA", "MORALES", "PIZARRO", "ARAYA", "CABRERA", "LOPEZ", "ORTEGA", "FERNANDEZ", "NAVARRO", "GUZMAN", "MENDEZ", "ROJAS", "SALAZAR", "VILLANUEVA", "PAREDES",
            "RIVAS", "SANDOVAL", "ESPINOZA", "MUNOZ", "ACOSTA", "DELGADO", "CASTRO", "NAVARRO", "GONZALEZ", "MENDOZA", "SILVA", "RIOS", "ROJAS", "AGUIRRE", "MORALES", "GOMEZ",
            "SOTO", "TORRES", "PEREZ", "MEDINA", "BENITEZ", "GARCIA", "VARGAS", "RODRIGUEZ", "RAMIREZ", "TORRES", "MORALES", "HERRERA", "JIMENEZ"};
    for (i = 0; i < 10; i++)
    {
        al = rand() % 87;
    }
    strcpy(apellido, ap[al]);
}

void nombreAl(char nombre[], int sex)
{
    int i, al;
    char nombH[50][20] = {
        "JUAN", "PEDRO", "LUIS", "CARLOS", "ANDRES", "MIGUEL", "DAVID", "RAFAEL", "FRANCISCO",
        "ALEJANDRO", "JORGE", "DANIEL", "GUILLERMO", "SERGIO", "PABLO", "JAVIER", "ALBERTO",
        "SERGIO", "OSCAR", "GUILLERMO", "MARIO", "RICARDO", "IGNACIO", "FEDERICO", "RODRIGO",
        "MANUEL", "ANTONIO", "RAUL", "ALFREDO", "FERNANDO", "ROBERTO", "EDUARDO", "HUGO", "ENRIQUE",
        "EMILIO", "ARMANDO", "JULIO", "ADRIAN", "GUSTAVO", "ARTURO", "ANGEL", "HORACIO",
        "RODOLFO", "LUCAS", "RAMON", "OMAR", "CESAR", "SANTIAGO", "GERARDO", "ERNESTO"};
    char nombM[50][20] = {
        "ANA", "SOFIA", "CARMEN", "ISABEL", "ANDREA", "PATRICIA", "ELENA", "MARTA", "BEATRIZ",
        "PAULA", "JULIA", "VALERIA", "RAQUEL", "NATALIA", "CLAUDIA", "VALENTINA", "LORENA",
        "ELENA", "MARIANA", "ADRIANA", "LAURA", "ANTONIA", "MARTINA", "ANGELA", "LUISA",
        "SARA", "VERONICA", "ALICIA", "ROSA", "LUCIA", "VICTORIA", "GLORIA", "INES",
        "ROCIO", "VANESA", "RAFAELA", "ANAIS", "EVA", "SANDRA", "LOLA", "ANA", "ESTHER",
        "MIRIAM", "LIDIA", "YOLANDA", "INES", "MARINA", "CAROLINA", "PILAR", "IRENE"};
    for (i = 0; i < 10; i++)
    {
        al = rand() % 50;
    }
    if (sex == 1)
    {
        strcpy(nombre, nombH[al]);
    }
    else
    {
        strcpy(nombre, nombM[al]);
    }
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
    strcpy(nombestado, estados[est]);
}

void puestoAl(char puesto[])
{
    int num;
    char pus[11][30]{
        "COMERCIAL",
        "TECNICO",
        "INGENIERO",
        "REPRESENTANTE",
        "INTENDENTE",
        "CONTADOR",
        "REPARTIDOR",
        "ADMINISTRADOR",
        "SECRETARIA",
        "AUXILIAR",
        "TELEFONISTA"};

    for (int i = 0; i < 11; i++)
    {
        num = rand() % 11;
    }
    strcpy(puesto, pus[num]);
}

void estados( char nombestado[])
{
    int est=rand()%33+1;
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
    strcpy(nombestado, estados[est]);
}
