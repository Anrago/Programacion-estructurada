//Antonio Ramos Gonzalez Mt: 372576
//9/1/2023
//crear una calculadora basica donde se pidan dos numero y la operacion a realizar
//RGA_Act2_1_932
#include<stdio.h>
int main()
{
    float opc,num1,num2;
    float total;
    printf("Dame un numero\n");
    scanf("%f",&num1);
    printf("Dame otro numero\n");
    scanf("%f",&num2);
    printf("MENU\n");
    printf("Operacion que desea realizar\n");
    printf("1-suma\n2-resta\n3-multiplicacion\n4-division\n");
    scanf("%f",&opc);
    if(opc==1){
        total=num1+num2;
    }
    else
    {
        if(opc==2)
        {
            total=num1-num2;
        }
        else
        {
            if(opc==3)
            {
                total=num1*num2;
            }
            else
            {
                if(opc==4)
                {
                    total=num1/num2;
                }
               
            }
        }
    
    }
    printf("El resultado es:%.2f",total);
    
}

