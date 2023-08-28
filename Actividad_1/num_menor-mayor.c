//Antonio Ramos Gonzalez Mt: 372576
//8/22/2023
//leer 3 numeros e imprimir en forma acendente
//RGA_Act1_9_932
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
            printf("El orden es:%d,%d,%d",num3,num2,num1);

        }else{
            if(num1>num3){
                printf("El orden es:%d,%d,%d",num2,num3,num1);
            }else{
                printf("El orden es:%d,%d,%d",num2,num1,num3);
            }

            
        }

    }else{
        if(num1>num3){
            printf("El orden es:%d,%d,%d",num3,num1,num2);

        }else{
            if(num2>num3){
                printf("El orden es:%d,%d,%d",num1,num3,num2);
            }else{
                printf("El orden es:%d,%d,%d",num1,num2,num3);
            }
        }
    }

}