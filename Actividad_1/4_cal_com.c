//Antonio Ramos Gonzalez Mt: 372576
//8/22/2023
//obtener promedio con condiciones compuestas
//RGA_Act1_3_932
#include <stdio.h>

int main (){
    int cal1,cal2,cal3,cal4;
    float prom;
    printf("dame la calificacion 1\n");
    scanf("%d",&cal1);
    printf("dame la calificacion 2\n");
    scanf("%d",&cal2);
    printf("dame la calificacion 3\n");
    scanf("%d",&cal3);
    printf("dame la calificacion 4\n");
    scanf("%d",&cal4);
    prom=(cal1+cal2+cal3+cal4)/4;

    if(prom>=60){
        printf("usted esta aprobado\n su promedio es:%f",prom);
    }else{
        printf("usted esta reprobado\n su promedio es:%f",prom);
    }
}