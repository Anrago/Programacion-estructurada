#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void creattxt(void);

int main()
{
    creattxt();
    return 0;
}

void creattxt(void)
{
    FILE *fa;
    char nomb[10],app[10],edad[10],ciudad[10];
    fa = fopen("C:\\Users\\Anrago\\Documents\\GitHub\\Programacion-estructurada\\Taller\\3\\datos.txt", "a");

    fflush(stdin);
    gets(nomb);
    gets(app);
    gets(edad);
    gets(ciudad);

    fprintf(fa,"%s %s %s %s",nomb,app,edad,ciudad);

    fclose(fa);
}