//Antonio Ramos Gonzalez Mt: 372576
//9/1/2023
//Pedir 5 numero e imprimir cual es el mayor
//RGA_Act2_3_932
#include<stdio.h>
int main()
{
    int pib;
    int num1,num2,num3,num4,num5,num6;
    printf("dame el primer numero\n");
    scanf("%d",&num1);
    printf("dame el seegundo numero\n");
    scanf("%d",&num2);
    printf("dame el tercer numero\n");
    scanf("%d",&num3);
    printf("dame el cuarto numero\n");
    scanf("%d",&num4);
    printf("dame el quinto numero\n");
    scanf("%d",&num5);
    printf("dame el sexto numero\n");
    scanf("%d",&num6);

    pib=num1;

    if(num2>pib)
    {
        pib=num2;
    }
    if(num3>pib)
    {
        pib=num3;
    }
    if(num4>pib)
    {
        pib=num4;
    }
    if(num5>pib)
    {
        pib=num5;
    }
    if(num6>pib)
    {
        pib=num6;
    }
    printf("El mayor es:%d",pib);
}