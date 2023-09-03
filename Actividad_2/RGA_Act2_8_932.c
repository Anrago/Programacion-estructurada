//Antonio Ramos Gonzalez Mt: 372576
//9/1/2023
//Juego de chin chan pu con condiciones anidadas
//RGA_Act2_8_932
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    short int us,cp;
    
    srand(time(NULL));
    cp=rand()%3+1;
    printf("MENU\n");
    printf("Elije una opccion\n");
    printf("1.-Piedra\n2.-Papel\n3.-Tijeras\n");
    scanf("%hd",&us);
   
    if(us==cp)
    {
        printf("Empate");
    }
    else
    {
        if (us==1)
        {
            if(cp==2)
            {
                printf("Gana CPU");
            }
            else
            {
                printf("Gana usuario");
            }
        }
        else
        {
            if(us==2)
            {
                if(cp==3)
                {
                    printf("Gana CPU");
                }
                else
                {
                    printf("Gana usuario");
                }
            }
            else
            {
                if(cp==1)
                {
                    printf("Gana CPU");
                }
                else
                {
                    printf("Gana usuario");
                }
            }
        }
    }
    
}