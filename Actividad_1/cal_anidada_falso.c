//Antonio Ramos Gonzalez Mt: 372576
//8/22/2023
//leer 3 calificaciones y anidar el promedio por el verdadero
//RGA_Act1_6_932
#include <stdio.h>

int main (){
     int cal1,cal2,cal3;
    float prom;
    printf("dame la calificacion 1\n");
    scanf("%d",&cal1);
    printf("dame la calificacion 2\n");
    scanf("%d",&cal2);
    printf("dame la calificacion 3\n");
    scanf("%d",&cal3);
    
    prom=(cal1+cal2+cal3)/3;

    if(prom>100){
        printf("error en promedio");
    }else{
        if(prom>=98){
            printf("excelente");
        }else{
            if(prom>=90){
                printf("muy bien");


            }else{
                if(prom>=80){
                    printf("bien");
                }else{
                    if(prom>=70){
                        printf("regular");
                        
                    }else{
                        if(prom>=60){
                            printf("suficiente");
                        }else{
                            if(prom>=30){
                                printf("extraordinario");

                            }else{
                                printf("repetir");
                            }
                        }
                    }
                }
            }
        }
    }
    
    
    
    printf("\nel promedio es:%f",prom);
    
    
    }