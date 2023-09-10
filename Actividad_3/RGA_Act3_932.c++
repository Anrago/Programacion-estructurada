// Antonio Ramos Gonzalez Mt: 372576
// 9/10/2023
// Atividad 3
// RGA_Act3_932
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu();
int msg();
void cal(void);
void chin_anid(void);
void chin_selec(void);
void mayor(void);
void medio(void);
void orden(void);
void zodiaco(void);

int main()
{
    menu();
    return 0;
}
int msg()
{
    int opc;
    system("CLS");
    printf("   M  E   N   U \n");
    printf("1.- Obtene promedio de 3 calificacion \n");
    printf("2.- Jugar Chin-chan-pu  (anidado) \n");
    printf("3.- Jugar Chin-cha-npu (seleccion multiple) \n");
    printf("4.- Leer 3 numeros y dar el mayor \n");
    printf("5.- Leer 3 numeros y dar el del medio \n");
    printf("6.- Leer 3 numero y ordenar de forma ascendente \n");
    printf("7.- Signo zodiacal y horoscopo \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &opc);
    return opc;
}

void menu()
{
    int opc;
    do
    {
        opc = msg();
        switch (opc)
        {
        case 1:
            cal();
            break;
        case 2:
            chin_anid();
            break;
        case 3:
            chin_selec();
            break;
        case 4:
            mayor();
            break;
        case 5:
            medio();
            break;
        case 6:
            orden();
            break;
        case 7:
            zodiaco();
            break;
        }

    } while (opc != 0);
}

//Leer 3 calificaciones y proporcionar el promedio, asi como un texto que mencione que tan buena es si calificacion
void cal(void)
{
    float cal1,cal2,cal3;
    float prom;
    system("CLS");
    
    printf("dame la calificacion 1\n");
    scanf("%f", &cal1);
    printf("dame la calificacion 2\n");
    scanf("%f", &cal2);
    printf("dame la calificacion 3\n");
    scanf("%f", &cal3);

    prom = (cal1 + cal2 + cal3) / 3;
    if (prom >= 80)
    {
        if (prom >= 90)
        {
            if (prom >= 98)
            {
                if (prom > 100)
                {
                    printf("Error en promedio\n");
                }
                else
                {
                    printf("Su calificacion es Exelente\n");
                    printf("Su promedio fue de: %.2f\n", prom);
                }
            }
            else
            {
                printf("Su calificacion esta Muy bien\n");
                printf("Su promedio fue de: %.2f\n", prom);
            }
        }
        else
        {
            printf("Su calificacion esta Bien\n");
            printf("Su promedio fue de: %.2f\n", prom);
        }
    }
    else
    {
        if (prom < 70)
        {
            if (prom < 60)
            {
                if (prom < 30)
                {
                    printf("Usted debera Repetir\n");
                    printf("Su promedio fue de: %.2f\n", prom);
                }
                else
                {
                    printf("Usted realizara Extraordinario\n");
                    printf("Su promedio fue de: %.2f\n", prom);
                }
            }
            else
            {
                printf("Su calificacion es Suficiente\n");
                printf("Su promedio fue de: %.2f\n", prom);
            }
        }
        else
        {
            printf("Su calificacion es Regular\n");
            printf("Su promedio fue de: %.2f\n", prom);
        }
    }
    
    system("PAUSE");
}

//Juego de chin chan pu con condiciones anidadas
void chin_anid(void)
{
    short int us, cp;
    system("CLS");
    
    srand(time(NULL));
    cp = rand() % 3 + 1;
    printf("MENU\n");
    printf("Elije una opccion\n");
    printf("1.-Piedra\n2.-Papel\n3.-Tijeras\n");
    scanf("%hd", &us);

    if (us == cp)
    {
        printf("Empate\n");
    }
    else
    {
        if (us == 1)
        {
            if (cp == 2)
            {
                printf("Gana CPU\n");
            }
            else
            {
                printf("Gana usuario\n");
            }
        }
        else
        {
            if (us == 2)
            {
                if (cp == 3)
                {
                    printf("Gana CPU\n");
                }
                else
                {
                    printf("Gana usuario\n");
                }
            }
            else
            {
                if (cp == 1)
                {
                    printf("Gana CPU\n");
                }
                else
                {
                    printf("Gana usuario\n");
                }
            }
        }
    }
    system("PAUSE");
}

//Juego de chin chan pu con seleccion multiple
void chin_selec(void)
{
    short int us, cp;
    system("CLS");
    
    srand(time(NULL));
    cp = rand() % 3 + 1;
    printf("MENU\n");
    printf("Elije una opccion\n");
    printf("1-piedra\n2-papel\n3-tijera\n");
    scanf("%hd", &us);

    switch (us - cp)
    {
    case 1:

        printf("Gana usuario\n");
        break;

    case -1:

        printf("Gana CPU\n");
        break;

    case -2:

        printf("Gana usuario\n");
        break;

    case 2:

        printf("Gana CPU\n");
        break;

    default:

        printf("empate\n");
    }
    system("PAUSE");
}

//Pedir 3 numeros e imprimir cual es el mayor (AND u OR)
void mayor(void)
{
    int n1, n2, n3;

    system("CLS");
    
    printf("Dame el primer numero\n");
    scanf("%d", &n1);
    printf("Dame el segundo numero\n");
    scanf("%d", &n2);
    printf("Dame el tercer numero\n");
    scanf("%d", &n3);

    if (n1 > n2 && n1 > n3)
    {
        printf("El numero mayor es el primero: %d\n", n1);
    }
    else
    {
        if (n2 > n3 && n2 > n1)
        {
            printf("El numero mayor es el segundo: %d\n", n2);
        }
        else
        {

            printf("El numero mayor es el tercero: %d\n", n3);
        }
    }
    system("PAUSE");
}

//Pedir 3 numeros e imprimir cual es el del medio (AND u OR)
void medio(void)
{
    int n1, n2, n3;
    system("CLS");
    
    printf("Dame el primer numero\n");
    scanf("%d", &n1);
    printf("Dame el segundo numero\n");
    scanf("%d", &n2);
    printf("Dame el tercer numero\n");
    scanf("%d", &n3);

    if ((n1 > n2 && n2 > n3) || (n1 < n2 && n2 < n3))
    {
        printf("El numero medio es el segundo: %d\n", n2);
    }
    else
    {
        if ((n2 > n1 && n1 > n3) || (n2 < n1 && n1 < n3))
        {
            printf("El numero medio es el primero: %d\n", n1);
        }
        else
        {

            printf("El numero medio es el tercero: %d\n", n3);
        }
    }
    system("PAUSE");
}

//Pedir 3 numeros e imprimir de forma ascendente (AND u OR)
void orden(void)
{
    int n1, n2, n3;
    system("CLS");
    
    printf("Dame el primer numero\n");
    scanf("%d", &n1);
    printf("Dame el segundo numero\n");
    scanf("%d", &n2);
    printf("Dame el tercer numero\n");
    scanf("%d", &n3);

    if ((n1 > n2 && n2 > n3))
    {
        printf("El orden es:%d,%d,%d\n", n3, n2, n1);
    }
    else
    {
        if ((n1 < n2 && n2 < n3))
        {
            printf("El orden es:%d,%d,%d\n", n1, n2, n3);
        }
        else
        {
            if ((n2 > n1 && n1 > n3))
            {
                printf("El orden es:%d,%d,%d\n", n3, n1, n2);
            }
            else
            {
                if ((n2 < n1 && n1 < n3))
                {
                    printf("El orden es:%d,%d,%d\n", n2, n1, n3);
                }
                else
                {
                    if (n1 < n3 && n3 < n2)
                    {
                        printf("El orden es:%d,%d,%d\n", n1, n3, n2);
                    }
                    else
                    {
                        printf("El orden es:%d,%d,%d\n", n2, n3, n1);
                    }
                }
            }
        }
    }
    system("PAUSE");
}

//Pedir dia y mes de nacimiento para devolver su signo zodiacal y su horoscopo del dia 
void zodiaco(void)
{
    int d, m;
    system("CLS");
    
    printf("Que dia naciste?\n");
    scanf("%d", &d);
    printf("Que mes naciste? escribir en numero(enero=1)\n");
    scanf("%d", &m);

    if ((d >= 22 && m == 12) || (d <= 19 && m == 1))
    {
        printf("Su signo del zodiaco es: Capricornio\n");
        printf("Su horoscopo del dia es:");
        printf("Sería oportuno que comience a implementar las soluciones convenientes a muchos de los obstáculos que se le han presentado en estos días.\n ");
    }
    if ((d >= 20 && m == 1) || (d <= 18 && m == 2))
    {
        printf("Su signo del zodiaco es: Acuario\n");
        printf("Su horoscopo del dia es:");
        printf("Acuario es conocido por su originalidad y pensamiento innovador. Aproveche esta influencia para explorar nuevas ideas y compartir conocimientos con su comunidad.\n ");
    }
    if ((d >= 19 && m == 2) || (d <= 20 && m == 3))
    {
        printf("Su signo del zodiaco es: Picis\n");
        printf("Su horoscopo del dia es:");
        printf("Piscis es conocido por su sensibilidad y compasion. Utilice estas cualidades para conectarse con los demás y promover la empatia.\n ");
    }
    if ((d >= 21 && m == 3) || (d <= 19 && m == 4))
    {
        printf("Su signo del zodiaco es: Aries\n");
        printf("Su horoscopo del dia es:");
        printf("La energia de Aries es dinamica y energica, asi que aproveche esta fuerza para abordar desafíos y tomar la iniciativa en su vida.\n ");
    }
    if ((d >= 20 && m == 4) || (d <= 20 && m == 5))
    {
        printf("Su signo del zodiaco es: Tauro\n");
        printf("Su horoscopo del dia es:");
        printf("Tauro es conocido por su determinación y perseverancia. Aproveche esa energía para establecer metas realistas y trabaje con paciencia hacia ellas.\n ");
    }
    if ((d >= 21 && m == 5) || (d <= 20 && m == 6))
    {
        printf("Su signo del zodiaco es: Geminis\n");
        printf("Su horoscopo del dia es:");
        printf("La versatilidad de Geminis es su fortaleza. Explore nuevas ideas y mantenga su mente abierta a diferentes perspectivas.\n ");
    }
    if ((d >= 21 && m == 6) || (d <= 22 && m == 7))
    {
        printf("Su signo del zodiaco es: Cancer\n");
        printf("Su horoscopo del dia es:");
        printf("La sensibilidad y la empatoa son rasgos destacados de Cancer. Utilice estas cualidades para fortalecer sus relaciones y su conexion con los demas.\n ");
    }
    if ((d >= 23 && m == 7) || (d <= 22 && m == 8))
    {
        printf("Su signo del zodiaco es: Leo\n");
        printf("Su horoscopo del dia es:");
        printf("Leo es conocido por su carisma y confianza. Aproveche estas cualidades para liderar y destacar en sus esfuerzos.\n ");
    }
    if ((d >= 23 && m == 8) || (d <= 22 && m == 9))
    {
        printf("Su signo del zodiaco es: Virgo\n");
        printf("Su horoscopo del dia es:");
        printf("La atencion a los detalles es una habilidad clave de Virgo. Utilice su capacidad analitica para resolver problemas y mejorar su vida.\n ");
    }
    if ((d >= 23 && m == 9) || (d <= 22 && m == 10))
    {
        printf("Su signo del zodiaco es: Libra\n");
        printf("Su horoscopo del dia es:");
        printf("Libra tiende a buscar la armonia y el equilibrio. Este abierto a relaciones y situaciones pacificas que fomenten la tranquilidad en su vida.\n ");
    }
    if ((d >= 23 && m == 10) || (d <= 21 && m == 11))
    {
        printf("Su signo del zodiaco es: Escorpio\n");
        printf("Su horoscopo del dia es:");
        printf("Escorpio está asociado con la transformacion y la profundidad emocional. Aproveche esta influencia para crecer y sanar.\n ");
    }
    if ((d >= 22 && m == 11) || (d <= 21 && m == 12))
    {
        printf("Su signo del zodiaco es: Sagitario\n");
        printf("Su horoscopo del dia es:");
        printf("La aventura y la exploracion son fundamentales para Sagitario, asi que busque nuevas experiencias y aprendizaje.\n ");
    }
    system("PAUSE");
}
