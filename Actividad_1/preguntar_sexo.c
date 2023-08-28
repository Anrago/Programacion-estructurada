//Antonio Ramos Gonzalez Mt: 372576
//8/22/2023
//preguntar sexo
//RGA_Act1_4_932
#include <stdio.h>

int main (){
    int sex;
    printf("cual es su sexo\n1.-hombre\n2.-mujer\n");
    scanf("%d",&sex);
    if(sex==1){
        printf("usted es hombre");
    }else {
        printf("usted es mujer");
    }
}