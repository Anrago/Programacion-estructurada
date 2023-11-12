// Antonio Ramos Gonzalez Mt: 372576
// 07/11/2023 || 12/11/2023
// Se generara un archivo donde se almacenara datos generados por el usuario, y la lectura de archivos
// RGA_Act12_932
#include <stdio.h>
#include <string.h>

int main(int args, char *arg[])
{
    FILE *fa;
    int i = 0;
    char fileName[50];
    int tempNum;
    int tempNum2;
    char nomb[20], apP[20], apM[20];
    int edad;
    char sex[10];

    strcpy(fileName, arg[1]);
    strcat(fileName,".txt");
    
    fa = fopen(fileName, "r");
    if (fa)
    {
        do
        {
            fscanf(fa, "%d.- %d %s %s %s %d %s",
                       &tempNum, &tempNum2, nomb, apP, apM, &edad, sex);
            i++;
        } while (!feof(fa));
        fclose(fa);
        return i-1;
    }
    else
    {
        return -1;
    }
    return 0;
}