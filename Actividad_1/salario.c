//Antonio Ramos Gonzalez Mt: 372576
//8/22/2023
//Preguntar el salario por hora y horas trabajadas para obtener el salario total
//RGA_Act1_10_932
#include <stdio.h>

int main (){
    int sal_h,sal,salx,h,hx;
    
    salx=0;
    printf("Ingresa el salario por hora\n");
    scanf("%d",&sal_h);
    printf("Cantas horas a trabajado\n");
    scanf("%d",&h);
    if (h<=40){
        sal=sal_h*h;
        

    }else{
        
        if(h<=49){
            hx=h-40;
            salx=salx + ((sal_h*2)*(h-40));
            sal=sal_h*(h-hx);
            

        }else{
            hx=h-40;
            salx=salx + ((sal_h*2)*(9))+((sal_h*3)*(h-49));
            sal=sal_h*(h-hx);
            
            

        }

        
    }


    printf("salarioxhoras:%d\n horas trabajadas:%d\n",sal_h,h);
    printf("salario normal:%d\nsalario extra%d\n",sal,salx);
    printf("salario total:%d",sal+salx);


}