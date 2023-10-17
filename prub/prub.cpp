#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void validCad(const char msg[], char cad[]);

int main()
{

    char nombre[15];
    validCad("Ingrese nombre: ", nombre);
    printf("%s", nombre);

    return 0;
}

void validCad(const char msg[], char cad[])
{
    int band, j, i, k;
    do
    {

        system("CLS");
        if (band != 0)
        {
            printf("INTENTE DENUEVO.(SOLO MAYUSCULAS)\n");
        }
        band = 0;
        i = 0;
        j = 0;
        k = 0;
        printf("%s", msg);
        fflush(stdin);
        gets(cad);

        while (cad[i] != '\0') // obtiene la longitud de la cadena
        {
            i++;
        }

        if (cad[0] == '\0')
        {
            band = 1;
        }

        if (cad[0] == ' ') // no puede iniciar con espacios
        {
            band = 1;
        }

        if (cad[i - 1] == ' ') // no puede terminar con espacios
        {
            band = 1;
        }

        while (j < i)
        {
            if (cad[j] == ' ')
            {
                if (cad[j + 1] == ' ') // verifica que no haya 2 espacios seguidos
                {
                    band = 1;
                }
            }
            j++;
        }

        while (k < i) 
        {
            if (cad[k] < 97)
            {
                if (cad[k] > 90)
                {
                    band = 1;
                }
                else
                {
                    if (cad[k] < 65)
                    {
                        if (cad[k] != ' ')
                        {
                            band = 1;
                        }
                    }
                }
            }
            else
            {
                if (cad[k] > 122)
                {
                    if (cad[k]!=164)
                    {
                        if (cad[k]!=165)
                        {
                            band=1;
                        }
                        
                    
                    }
                    
                    
                }
            }

            k++;
        }

      

        // k = 0;
        // while (k < i)
        // {
        //     if (cad[k] == 'Á')
        //     {
        //         band = 1;
        //     }
        //     else
        //     {
        //         if (cad[k] == 'É')
        //         {
        //             band = 1;
        //         }
        //         else
        //         {
        //             if (cad[k] == 'Í')
        //             {
        //                 band = 1;
        //             }
        //             else
        //             {
        //                 if (cad[k] == 'Ó')
        //                 {
        //                     band = 1;
        //                 }
        //                 else
        //                 {
        //                     if (cad[k] == 'Ú')
        //                     {
        //                         band = 1;
        //                     }
        //                 }
        //             }
        //         }
        //     }
        //     k++;
        // }

    } while (band != 0);
}