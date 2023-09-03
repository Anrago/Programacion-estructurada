//Antonio Ramos Gonzalez Mt: 372576
//9/1/2023
//Calcular el monto a pagar en base a los m3 de agua gastados
//RGA_Act2_6_932
#include <stdio.h>

int main ()
{
    int bas;
    float m3,subt;
    bas=50;
    printf("Ingresar los m3 consumidos\n");
    scanf("%f",&m3);
    if(m3<=4)
    {
        subt=bas;
    }
    else
    {
        if(m3<=15)
        {
            
            subt=bas+(8*(m3-4));
        }
        else
        {
            if(m3<=50)
            {
                subt=bas+(8*11)+(10*(m3-15));
            }
            else
            {
                subt=bas+(8*11)+(10*35)+(11*(m3-50));
            }
        }
    }
    printf("subtoatl:| %.2f\n",subt);
    printf("iva:     | %.2f\n",(subt*0.16));
    printf("total:   | %.2f ",subt+(subt*0.16));
}