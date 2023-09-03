//Antonio Ramos Gonzalez Mt: 372576
//9/1/2023
//crear una calculadora de conversiones de unidades de medida
//RGA_Act2_2_932
#include<stdio.h>
int main()
{
    int opc;
    float conv,med;
    printf("Ingresa la medida que deseas convertir\n");
    scanf("%f",&med);
    printf("MENU\n");
    printf("1-cm a pulgadas\n2-cm a pies\n");
    printf("3-Km a millas\n");
    printf("4-Pulgadas a cm\n5-Pies a cm\n");
    printf("6-millas a km\n");
    scanf("%d",&opc);

    if(opc==1)
    {
        conv=med/2.54;

    }
    else
    {
        if(opc==2)
        {
            conv=med/30.48;
        }
        else
        {
            if(opc==3)
            {
                conv=med/1.609;
            }
            else
            {
                if (opc==4)
                {
                    conv=med*2.54;
                }
                else
                {
                    if(opc==5)
                    {
                        conv=med*30.48;
                    }
                    else
                    {
                        conv=med*1.609;
                    }
                }
            }
        }
    }

    printf("EL resultado de la conversion es: %.3f",conv);
}