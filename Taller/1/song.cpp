#include <stdio.h>
#include <stdlib.h>

void readtxt(void);

int main()
{
    readtxt();
    return 0;
}

void readtxt(void)
{
    FILE *fa;
    char carac;
    fa = fopen("C:\\Users\\Anrago\\Documents\\GitHub\\Programacion-estructurada\\Taller\\1\\cancion.txt", "r");

    if (fa)
    {

        do
        {
            carac = fgetc(fa);
            printf("%c", carac);
        } while (!feof(fa));
        fclose(fa);
    }
}
