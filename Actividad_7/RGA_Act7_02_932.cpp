// Antonio Ramos Gonzalez Mt: 372576
// 9/23/2023
// Cadenas parte 2
// RGA_Act7_932
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int msg();
void menu();
int largo_cadena(char cad[]);
void mayuscula(char cad[], int i);
void minusculas(char cad[], int i);
void capital(char cad[], int i);
void al_reves(char cad[], int i);
void sin_espacios(char cad[], int i);
void carateres_alfabeticos(char cad[]);
void todas_funciones(char cad[], int i);
void palindromo(char cad[], int i);
void validar(char cad[]);

int main()
{
    menu();
    return 0;
}

int msg()
{
    int opc;
    system("CLS");
    printf("Menu\n");
    printf("1.-Imprimir Mayusculas\n");
    printf("2.-Imprimir minusculas\n");
    printf("3.-Imprimir Capital\n");
    printf("4.-Cantidad de caracteres\n");
    printf("5.-Imprimir al reves\n");
    printf("6.-Imprimir sin espacios\n");
    printf("7.-caracteres alfabeticos \n");
    printf("8.-Todas las funciones \n");
    printf("9.-Palindromo \n");
    printf("0.-Salir\n");
    printf("Elige una opcion: ");
    scanf("%d", &opc);
    return opc;
    system("CLS");
}

void menu()
{

    char cadena[30];
    int opc, i;
    do
    {
        opc = msg();
        switch (opc)
        {
        case 1:
            system("CLS");
            printf("Dame una cadena de texto: ");
            fflush(stdin);
            gets(cadena);
            i = largo_cadena(cadena);
            mayuscula(cadena, i);
            break;
        case 2:
            system("CLS");
            printf("Dame una cadena de texto: ");
            fflush(stdin);
            gets(cadena);
            i = largo_cadena(cadena);
            minusculas(cadena, i);
            break;
        case 3:
            system("CLS");
            printf("Dame una cadena de texto: ");
            fflush(stdin);
            gets(cadena);
            i = largo_cadena(cadena);
            capital(cadena, i);
            break;
        case 4:
            system("CLS");
            printf("Dame una cadena de texto: ");
            fflush(stdin);
            gets(cadena);
            i = largo_cadena(cadena);
            system("CLS");
            printf("El largo de la cadena es: %d\n", i);
            system("PAUSE");
            break;
        case 5:
            system("CLS");
            printf("Dame una cadena de texto: ");
            fflush(stdin);
            gets(cadena);
            i = largo_cadena(cadena);
            al_reves(cadena, i);
            break;
        case 6:
            system("CLS");
            printf("Dame una cadena de texto: ");
            fflush(stdin);
            gets(cadena);
            i = largo_cadena(cadena);
            sin_espacios(cadena, i);
            break;
        case 7:
            carateres_alfabeticos(cadena);
            for (int i = 0; cadena[i] != '\0'; i++)
            {
                printf("%c", cadena[i]);
            }
            printf("\n");
            system("PAUSE");
            break;
        case 8:
            system("CLS");
            printf("Dame una cadena de texto: ");
            fflush(stdin);
            gets(cadena);
            i = largo_cadena(cadena);
            todas_funciones(cadena, i);
            break;
        case 9:
            validar(cadena);
            i = largo_cadena(cadena);
            palindromo(cadena, i);
        }
    } while (opc != 0);
}

// Lee una cadena y la imprime en mayusculas
// RGA_Act7_Pt2_01_932
void mayuscula(char cad[], int i)
{
    int j = 0;
    system("CLS");
    printf("Cadena en MAYUSCULAS\n");
    while (j < i)
    {
        if (cad[j] >= 'a')
        {
            if (cad[j] <= 'z')
            {
                cad[j] -= 32; // resta 32 al caracter en minuscula para volverlo mayuscula
            }
        }
        printf("%c", cad[j]); // imrpime cadena
        j++;
    }
    printf("\n");
    system("PAUSE");
}

// Lee una cadena y la imrpime en minusculas
// RGA_Act7_Pt2_02_932
void minusculas(char cad[], int i)
{
    int j = 0;
    system("CLS");
    printf("Cadena en minusculas\n");
    while (j < i)
    {
        if (cad[j] >= 'A')
        {
            if (cad[j] <= 'Z')
            {
                cad[j] += 32; // suma 32 a los caracteres en mayusculas para volverlos minusculas
            }
        }
        printf("%c", cad[j]); // imprime cadena en minusculas
        j++;
    }
    printf("\n");
    system("PAUSE");
}

// Lee una cadena y le agrega capital (hola Mundo-->Hola mundo)
// RGA_Act7_Pt2_03_932
void capital(char cad[], int i)
{
    int j = 0;
    system("CLS");
    printf("Cadena en capital\n");
    while (j < i)
    {
        while (j == 0) // analiza si la primera letra de la cadena es minusculas y la convierte en mayuscula
        {
            if (cad[j] >= 'a')
            {
                if (cad[j] <= 'z')
                {
                    cad[j] -= 32;
                }
            }
            printf("%c", cad[j]); // imrpmie la primera letra en mayuscula
            j++;
        }
        while (j < i) // analiza si las letras de la cadena y las vuelve minusculas
        {
            if (cad[j] >= 'A')
            {
                if (cad[j] <= 'Z')
                {
                    cad[j] += 32;
                }
            }
            printf("%c", cad[j]); // imprime las letras en minusculas
            j++;
        }
    }
    printf("\n");
    system("PAUSE");
}

// Obtiene el largo de una cadena
// RGA_Act7_Pt2_04_932
int largo_cadena(char cad[])
{
    int i = 0;
    while (cad[i] != '\0')
    {
        i++;
    }
    return i;
}

// Lee una cadena y la imprime al reves
// RGA_Act7_Pt2_05_932
void al_reves(char cad[], int i)
{
    system("CLS");
    printf("Cadena al reves\n");
    for (int j = i - 1; j >= 0; j--) // invierte la cadena
    {
        printf("%c", cad[j]); // imprime la cadena invertida
    }
    printf("\n");
    system("PAUSE");
}

// Lee una cadena y la imprime devuelta pero sin espacios(hola mundo-->holamundo)
// RGA_Act7_Pt2_06_932
void sin_espacios(char cad[], int i)
{
    int j = 0;
    system("CLS");
    printf("Cadena sin espacios\n");
    while (j < i)
    {
        if (cad[j] != ' ') // controla los espacios en la cadena
        {
            printf("%c", cad[j]); // imprime los caracteres diferentes del espacio
        }

        j++;
    }
    printf("\n");
    system("PAUSE");
}

// Lee una cadena y valida si esta escrita de manera correta
// RGA_Act7_Pt2_07_932
void carateres_alfabeticos(char cad[])
{

    int val = 0, j, i, k;
    // el contador val se encarga de validar si los datos son los correctos
    do
    {

        system("CLS");
        if (val != 0) // manda error
        {
            printf("error en cadena.Intente de nuevo\n");
        }

        val = 0;
        i = 0;
        j = 0;
        k = 0;
        printf("SOLO CARACTERES DEL ALFABETO,No INICIAR NI TERMINAR CON ESPACIOS,\n");
        printf("SIN DOBLES ESPACIOS!!\n");
        printf("Dame una palabra: ");
        fflush(stdin);
        gets(cad);

        while (cad[i] != '\0') // obtiene el tamaño de la cadena
        {
            i++; // almacena el tamaño de la cadena
        }

        if (cad[0] == ' ') // no puede iniciar con espacio
        {
            val++;
        }
        if (cad[i - 1] == ' ') // no puede terminar con espacio
        {
            val++;
        }

        while (j < i)
        {
            if (cad[j] == ' ')
            {
                if (cad[j + 1] == ' ') // no pueden haber 2 espacios juntos
                {
                    val++;
                }
            }
            j++;
        }

        while (k < i) // ciclo que controla si los caracteres de la cadena son caracteres alfabeticos
        {
            if (cad[k] > 'z')
            {
                val++;
            }
            else
            {
                if (cad[k] < 'a')
                {
                    if (cad[k] > 'Z')
                    {
                        val++;
                    }
                    else
                    {
                        if (cad[k] < 'A')
                        {
                            if (cad[k] != ' ')
                            {
                                val++;
                            }
                        }
                    }
                }
            }
            k++;
        }

    } while (val != 0);

    printf("La cadena fue escrita correctamente\n");
}

// Lee una cadena y llama a todas las funciones hasta la funcion sin espacio
// RGA_Act7_Pt2_08_932
void todas_funciones(char cad[], int i)
{
    mayuscula(cad, i);
    minusculas(cad, i);
    capital(cad, i);
    al_reves(cad, i);
    sin_espacios(cad, i);
}

// Se encarga de validar si una palabra es un palindromo(se lee igual al derecho y al reves)
// RGA_Act7_Pt2_09_932
void palindromo(char cad[], int i)
{
    int j, k, palin = 0;
    system("CLS");
    
    for (j = 0, k = i - 1; k < j; j++, k--)
    {
        if (cad[j] != cad[k])
        {

            palin++; // cuenta las diferencias entre los valores de la cadena
        }
    }
    
    if (palin == 0) // analisa el valor de palin envia un resultado
    {
        printf("Si es un palindromo");
    }
    else
    {
        printf("No es un palindromo");
    }

    printf("\n");
    system("PAUSE");
}

// Funcion para validar los datos a ingresar en la funcion palindromo
// RGA_Act7_Pt2_10_932
void validar(char cad[])
{
    int val = 0, j, i, k;
    do
    {

        system("CLS");
        if (val != 0)
        {
            printf("error en cadena.Intente de nuevo\n");
        }

        val = 0;
        i = 0;
        j = 0;
        k = 0;
        printf("SOLO MAYUSCULAS Y SIN DOBLES ESPACIOS!!\n");
        printf("Dame una palabra: ");
        fflush(stdin);
        gets(cad);

        while (cad[i] != '\0') // obtiene la longitud de la cadena
        {
            i++;
        }

        if (cad[0] == ' ') // no puede iniciar con espacios
        {
            val++;
        }
        if (cad[i - 1] == ' ') // no puede terminar con espacios
        {
            val++;
        }

        while (j < i)
        {
            if (cad[j] == ' ')
            {
                if (cad[j + 1] == ' ') // verifica que no haya 2 espacios seguidos
                {
                    val++;
                }
            }
            j++;
        }

        while (k < i) // verifica que los caracteres dados sean en mayusculas
        {
            if (cad[k] > 'Z')
            {
                val++;
            }
            else
            {
                if (cad[k] < 'A')
                {
                    if (cad[k] != ' ')
                    {
                        val++;
                    }
                }
            }
            k++;
        }

    } while (val != 0);
}