//Antonio Ramos Gonzalez Mt: 372576
//8/22/2023
//leer 3 numeros y imprimir el numero del medio
//RGA_Act1_8_932
#include <stdio.h>

int main (){
    int num1,num2,num3;
    printf("dame el primer numero\n");
    scanf("%d",&num1);
    printf("dame el segundo numero\n");
    scanf("%d",&num2);
    printf("dame el tercer numero\n");
    scanf("%d",&num3);

    if(num1>num2){
        if(num2>num3){
            printf("el numero del medio es:%d ",num2);

        }else{
            if(num1>num3){
                printf("el numero del medio es:%d ",num3);
            }else{
                printf("el numero del medio es:%d ",num1);

            }
        }

    }else{
        if(num1>num3){
            printf("el numero del medio es:%d ",num1);


        }else{
            if(num2>num3){
                printf("el numero del medio es:%d ",num3);


            }else{
                printf("el numero del medio es:%d ",num2);

            }
        }

    }




}