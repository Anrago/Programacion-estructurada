//Antonio Ramos Gonzalez Mt: 372576
//9/1/2023
//Pedir 5 calificaiones, descartar la de menor calificacion e imprimir el promedio de las restantes
//RGA_Act2_7_932
#include <stdio.h>

int main ()
{
    int pib,cal1,cal2,cal3,cal4,cal5;
    float total;
    
    printf("Dame la pirmera calificacion\n");
    scanf("%d",&cal1);
    printf("Dame la segunda calificacion\n");
    scanf("%d",&cal2);
    printf("Dame la tercera calificacion\n");
    scanf("%d",&cal3);
    printf("Dame la cuarta calificacion\n");
    scanf("%d",&cal4);
    printf("Dame la quinta calificacion\n");
    scanf("%d",&cal5);
    pib=cal1;
    if(cal2<pib)
    {
        pib=cal2;
    }
    if(cal3<pib)
    {
        pib=cal3;
    }
    if(cal4<pib)
    {
        pib=cal4;
    }
    if(cal5<pib)
    {
        pib=cal5;
    }
    total=((cal1+cal2+cal3+cal4+cal5-pib)/4);
    printf("el promedio es:%.2f",total);
}