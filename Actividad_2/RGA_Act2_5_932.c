//Antonio Ramos Gonzalez Mt: 372576
//9/1/2023
//pedir que tipo de llamada realizo el usuario y desplegar el monto que devera pagar
//RGA_Act2_5_932
#include <stdio.h>

int main (){
    int min,tipo;
    float sub_T;
    printf("MENU\nTipo de llamada\n1:Local\n2:Nacional\n3:Internacional\n");
    scanf("%d",&tipo);
    printf("cuantos minutos duro\n");
    scanf("%d",&min);

    if(tipo==1){
        sub_T=3;
    }
    if(tipo==2){
        if(min<=3){
            sub_T=7*min;
        }else{
            sub_T=(7*3)+(2*(min-3));
        }
    }
    if(tipo==3){
        if(min<=2){
            sub_T=9*min;
        }else{
            sub_T=(9*2)+(4*(min-2));
        }

    }
    printf("subtotal:%.2f:\n",sub_T);
    printf("IVA:%.2f\n",(sub_T*0.16));
    printf("Total:%.2f\n",sub_T+(sub_T*0.16));
}