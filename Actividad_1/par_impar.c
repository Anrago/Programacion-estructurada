//Antonio Ramos Gonzalez Mt: 372576
//8/22/2023
//saber si un numero es par o impar
//RGA_Act1_2_932
#include <stdio.h>

int main (){
    int num;
    printf("dame un numero\n");
    scanf("%d",&num);
    if(num%2==0){
        printf("este numero es par\n");
    }
    if (num%2!=0) {
        printf("este numero es impar\n");
    }
}
