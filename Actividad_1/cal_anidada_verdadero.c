//Antonio Ramos Gonzalez Mt: 372576
//8/22/2023
//leer 3 calificaciones y anidar el promedio por el verdadero
//RGA_Act1_5_932
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

if(prom>=30){
    if(prom>=60){
        if(prom>=70){
            if(prom>=80){
                if(prom>=90){
                    if(prom>=98){
                        if(prom>100){
                            printf("error en promedio");
                        }else {
                            printf("excelente");
                        }

                    }else{
                        printf("muy bien");
                    }

                }else{
                    printf("bien");
                }

            }else{
                printf("regular");
            }
        }else{
            printf("suficiente");
        }


    }else{
        printf("extraordinario");
    }

}else{
    printf("repetir");
}
printf("\nel promedio es:%f",prom);
}