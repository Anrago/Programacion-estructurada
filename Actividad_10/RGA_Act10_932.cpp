// Antonio Ramos Gonzalez Mt: 372576
// 9/12/2023 || 9/24/2023
// Cadenas parte 1
// RGA_Act10_Pt1_932
#include "Babilonia.h"

typedef struct _alumn
{
    char name[30];
    char lasP[30]; // apellido paterno
    char lasM[30]; // apellido materno
    int mt;        // matricula
    int age;       // edad
    int sex;       // sexo
    int status;    // dado de baja o no
} Talum;

int msg();
void nombAl(char nombre[], int sex);
void apellidoAl(char apellido[]);
void menu();

int sear(Talum alumn[], int n, int mt);

Talum genAl();

Talum llenarManual();

Talum eliminar(Talum alumn);

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

int msg()
{
    system("CLS");
    printf("MENU\n");
    printf("1.-Agalumnar(AUTOM 10 alumnISTROS)\n");
    printf("2.-Agalumnar manual\n");
    printf("3.-Eliminar alumnistro(logico)\n");
    printf("4.-Buscar\n");
    printf("5.-Ordenar\n");
    printf("6.-Imprimir\n");
    printf("0.-Salir\n");
    return valid("Elije una opcion: ", 0, 6);
}

void menu()
{
    Talum reg[500];
    int opc,el, i=0,j;
    int bus;
    do
    {
        opc = msg();
        switch (opc)
        {
        case 1:
            for (j = 0; j < 10; j++)
            {
                reg[i++]=genAl();   
            }
            break;

        case 2:
            reg[i++]=llenarManual();
            printf("%s",reg[0].name);
            
            break;

        case 3:
            el=valid("Que registro desea eliminar?",0,i);
            reg[el]=eliminar(reg[el]);
            break;
        case 4:
            bus=sear(reg,5,372576);
            if(bus!=-1)
            {
                printf("El aulmno se encuentra en el registro %d",bus);
            }
            else
            {
                printf("El aulmno no encontrado ");   
            }
            system("PAUSE");
            break;








        default:
            break;
        }
    } while (opc != 0);
}

void nombAl(char nombre[], int sex)
{
    int fil;
    char nombM[10][10] =
        {
            "Ana",
            "Julieta",
            "Josefina",
            "Dianna",
            "Carmen",
            "Sofia",
            "Laura",
            "Andrea",
            "Elena",
            "Isabel"};

    char nombH[10][10] =
        {
            "Juan",
            "Carlos",
            "Roberto",
            "Damian",
            "Andres",
            "David",
            "Alejandro",
            "Miguel",
            "Pedro",
            "Fernando"};

    if (sex == 1)
    {
        fil = rand() % 10;
        strcpy(nombre, nombH[fil]);
    }
    if (sex == 2)
    {
        fil = rand() % 10;
        strcpy(nombre, nombM[fil]);
    }
}

void apellidoAl(char apellido[])
{
    int fil;
    char ap[10][15] =
        {
            "García",
            "Rodríguez",
            "Pérez",
            "López",
            "Martínez",
            "González",
            "Sánchez",
            "Romero",
            "Fernández",
            "Torres"};

    fil = rand() % 10;
    strcpy(apellido, ap[fil]);
}

Talum genAl()
{
    Talum alumn;
    char nombre[10], apellido[15];
    
    alumn.sex = rand() % 2 + 1;

    nombAl(nombre, alumn.sex);
    strcpy(alumn.name, nombre);

    apellidoAl(apellido);
    strcpy(alumn.lasP, apellido);

    apellidoAl(apellido);
    strcpy(alumn.lasM, apellido);

    alumn.age = rand() % 13 + 18;

    alumn.status = rand() % 2;

    alumn.mt=rand()%100000+300000;
    return alumn;
}

Talum llenarManual()
{
    Talum alumn;
    fflush(stdin);
    gets(alumn.name);
    gets(alumn.lasP);
    gets(alumn.lasM);
    
    scanf("%d",&alumn.mt);
    scanf("%d",&alumn.age);
    scanf("%d",&alumn.sex);
    scanf("%d",&alumn.status);

    return alumn;
}

Talum eliminar(Talum alumn)
{
    strcpy(alumn.name,"");
    strcpy(alumn.lasP,"");
    strcpy(alumn.lasM,"");
    
    alumn.mt=0;
    alumn.age=0;
    alumn.sex=0;
    alumn.status=0;
}

int sear(Talum alumn[], int n, int mt)
{
    int i;// define contador
    for ( i = 0; i < n; i++)//
    {
        if(alumn[i].mt==mt)//Busca en el vector el numero buscado
        {
            return i; //si encuentra el valor, retorna el valor del indice
        }
    }
    return -1; //si no encuentra el valor, retorna -1
}








































































