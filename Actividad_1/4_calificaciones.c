//Antonio Ramos Gonzalez Mt: 372576
//8/22/2023
//obtener promedio condiciones simples
//RGA_Act1_1_932
#include <stdio.h>

int main (){
    int cal1,cal2,cal3,cal4;
    float prom;
    printf("dame la primera calificacion\n");
    scanf("%d",&cal1);
    printf("dame la segunda calificacion\n");
    scanf("%d",&cal2);
    printf("dame la tercera calificacion\n");
    scanf("%d",&cal3);
    printf("dame la cuarta calificacion\n");
    scanf("%d",&cal4);
    prom=(cal1+cal2+cal3+cal4)/4;
    if(prom>=60){
    printf("usted esta aprobado.\nEl promedio fue:%f ",prom);
    }else
    { 
        printf("usted esta reprobado.\nEl promedio fue:%f ",prom);

    }
     
        
    
}