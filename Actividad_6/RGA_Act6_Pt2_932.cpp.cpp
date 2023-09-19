// Antonio Ramos Gonzalez Mt: 372576
// 9/17/2023
// Parte 2
// RGA_Act6_Pt2_932
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int msg();
void menu();
int validar(const char msg[], int ran_i, int ran_s);
void alumnos_derecho(void);
void tabla_de_multiplicar(void);
void rango(void);
void kilos(void);
void alumno(void);
int main()
{

    menu();
    return 0;
}

int msg()
{
    short int opc;
    system("CLS");
    printf("Menu\n");
    printf("1.-Alumnos derecho a nuvelacion\n");
    printf("2.-Tablas del 1 al 10\n");
    printf("3.-Rango de numeros\n");
    printf("4.-Kilos en barco\n");
    printf("5.-Verificar alumno\n");
    printf("0.-salir\n");
    printf("Elige una opcion: ");
    scanf("%hd", &opc);
    return opc;
}

void menu()
{

    short int opc;
    do
    {

        opc = msg();
        system("CLS");
        switch (opc)
        {
        case 1:
            alumnos_derecho();
            break;
        case 2:
            tabla_de_multiplicar();
            break;
        case 3:
            rango();
            break;
        case 4:
            kilos();
            break;
        case 5:
            alumno();
            break;
        default:
            break;
        }
    } while (opc != 0);
}

//pedir calificaciones y verificar cuales tienen derecho al examen de recuperacion, asi como su promedio y quienes no
void alumnos_derecho(void)
{
    const int al = 40;
    int con_dere = 0, sin_dere = 0, i, j = 0;
    float prom = 0;
    while (j < al) // repite el ciclo hast que se llegue al alumno final 
    {
        printf("Alumno %d\n", j + 1);
        for (i = 1; i <= 5; i++) // Lee las 5 calificaciones
        {
            printf("Unidad %d\n", i);
            prom += validar("Ingresa la calificacion: ", 0, 100);
        }
        prom /= 5;

        if (prom < 50) //Verifica si el prmedio es suficiente o no para el examen de nivelacion
        {
            sin_dere++;
        }
        else
        {
            if (prom >= 50)
            {
                con_dere++;
            }
        }
        j++;

        system("CLS");
    }
    printf("Los alumnos con derecho a examen de nivelacion:%d\n", con_dere);
    printf("los alumnos sin derecho a examen de nivelacion:%d\n", sin_dere);
    system("PAUSE");
}

//imprimir las tablas de multiplicar del 1 al 100
void tabla_de_multiplicar(void)
{
    int i, j;
    j = 1;
    while (j <= 10)
    {
        printf("Tabla del %d\n", j); // imprime la tabla que se esta ejecutando en ese momento
        for (i = 1; i <= 10; i++)
        {
            printf("%d X %d = %d\n", j, i, (j * i)); // genera la tabla de multiplicar del numero actual
        }
        system("PAUSE");
        system("CLS");
        j++;
    }
}

//Pedir n numeros, asi como in rango menor y mayor donde tendermos que obtener el promedio de los numeros dentro del rango
void rango(void)
{
    int min, max, n, i = 0, j = 0;
    float prom = 0, num;
    printf("Ingresa la cantidad de numeros: ");
    scanf("%d", &n);
    printf("Cual sera el rango minimo?: ");
    scanf("%d", &min);
    printf("Cual sera el rango maximo?: ");
    scanf("%d", &max);
    system("CLS");
    while (i < n) //Ver cuantras veces se pediran los numeros
    {
        printf("Ingresa numero %d: ",i+1);
        scanf("%f", &num);
        if (num >= min && num <= max) // Control para contar, asi como obtener la suma de los numeros validos
        {
            prom += num;
            j++;
        }

        i++;
    }
    printf("El promedio de los numero validos fue:%.2f \n", (prom / j));
    system("PAUSE");
}

//Controlar el numero de pasajeros en una embracacion, asi como el peso que este resiste
void kilos(void)
{
    int i = 0;
    float sum_peso = 0;
    while (i < 10 && sum_peso<=815)// se saldra si se llega al numero maximo de pasajeros o o si se llega al maximo peso
    {
        printf("pasajero %d\n", i + 1);
        sum_peso += validar("Ingrese su peso: ", 45, 150); //Se pide el peso del pasajero

        i++;
        
    }
    system("CLS");
    printf("El promedio del peso es:%.2f \n", sum_peso / 10);
    if (sum_peso >= 815)
    {
        printf("Se superaron los 700 kg\n");
        printf("Numero final de pasajeros fue: %d\n", i);
    }
    if (i == 10)
    {
        printf("Se llego al maximo numero de pasajeros: %d\n", i);
        printf("El peso actual es: %.2f\n", sum_peso);
    }
    system("PAUSE");
}

//Leer calificaciones de un alumno, calcular el promedio e impromir si este reprobo, aprobo o sera dado de baja
void alumno(void)
{
    int inten = 1, unid;
    float cal_suma, prom = 0;
    system("CLS");
    while (inten <= 3 && prom < 60)//Se saldra del siclo si el alumno aprueba o si se llega al numero maximo de intentos
    {
        cal_suma = 0;
        printf("Intento %d\n", inten);
        for (unid = 1; unid <= 3; unid++)//Lee las calificaciones de las 3 unidades
        {
            printf("\nUnidad %d\n", unid);
            cal_suma += validar("Dame la calificacion de la unidad: ", 0, 100);
        }
        prom=cal_suma / 3;//Calcula el promedio
        system("CLS");

        if (prom >= 60)// compara el promedio para ver si el alumno aprobo
        {
            printf("Usted esta aprobado: intento %d\n", inten);
            printf("su promedio fue: %.2f\n", prom);
        }
        else        //si no, este reprobo 
        {
            printf("Usted esta reprobado: intento %d\n", inten);
            printf("su promedio fue: %.2f\n", prom);
            if (inten >= 3)// si este reprobo y era su ultimo intento es dado de baja
            {
                printf("USTED HA SIDO DADO DE BAJA\n");
            }
            else    //si no, este debera repetir la materia
            {
                printf("Usted debera de repetir la materia\n");
            }
            inten++;
        }
        system("PAUSE");
        system("CLS");
    }
}

//se usa para validar los datos ingresados por el usuario
int validar(const char msg[], int ran_i, int ran_s)
{
    int num;
    char cadena[100];
    do
    {
        printf("%s", msg);
        fflush(stdin);
        gets(cadena);
        num = atoi(cadena);
    } while (num < ran_i || num > ran_s);
    return num;
}