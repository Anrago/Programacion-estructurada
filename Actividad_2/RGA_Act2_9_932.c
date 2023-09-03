//Antonio Ramos Gonzalez Mt: 372576
//9/1/2023
//Juego de chin chan pu con seleccion multiple
//RGA_Act2_9_932
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    short int us, cp;
    srand(time(NULL));
    cp=rand()%3+1;
    printf("MENU\n");
    printf("Elije una opccion\n");
    printf("1-piedra\n2-papel\n3-tijera\n");
    scanf("%hd",&us);
   
    switch(us-cp)
    {
        case 1:
        
            printf("Gana usuario");
            break;

        case -1:

            printf("Gana CPU");
            break;

        case -2:

            printf("Gana usuario");
            break;

        case 2:

            printf("Gana CPU");
            break;

        default:

            printf("empate");
    }
    
}