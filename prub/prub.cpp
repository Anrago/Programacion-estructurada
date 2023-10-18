#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void validCad(const char msg[], char cad[]);
void mayusculas(char cad[]);

int main()
{

    char nombre[15];
    validCad("Ingrese nombre: ", nombre);
    printf("%s", nombre);

    return 0;
}

void validCad(const char msg[], char cad[])
{
    int band, i, len;
    band = 1;
    do
    {

        system("CLS");
        if (band != 1)
        {
            printf("INTENTE DENUEVO.(SOLO MAYUSCULAS)\n");
        }
        band = 1;
        i = 0;
    
        printf("%s", msg);
        fflush(stdin);
        gets(cad);
        mayusculas(cad);

        len = strlen(cad);

        for (i = 0; i < len; i++)
        {
            if (!isalpha(cad[i]))
            {
                if (cad[i] == ' ')
                {
                    if (cad[i + 1] == ' ') // verifica que no haya 2 espacios seguidos
                    {
                        band = 0;
                    }
                }
                else
                {

                    if (cad[i] == -92 || cad[i] == -91)
                    {
                        cad[i] = 'X';
                    }
                }
            }
        }

        if (cad[0] == '\0')
        {
            band = 0;
        }

        if (cad[0] == ' ') // no puede iniciar con espacios
        {
            band = 0;
        }

        if (cad[i - 1] == ' ') // no puede terminar con espacios
        {
            band = 0;
        }

    } while (band != 1);
}

void mayusculas(char cad[])
{
    int i = 0,len;
    len = strlen(cad); // llama a la funcion para calcular la cantidad de caracteres
    while (i < len)
    {
        if (cad[i] >= 'a')
        {
            if (cad[i] <= 'z')
            {
                cad[i] -= 32; // resta 32 en codigo ASCCI volviendo las minusculas a mayusculas
            }
            
        }
        i++;
    }
}