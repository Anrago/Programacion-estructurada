#include <stdio.h>
#include <string.h>

int main() {
    char nombre[50]; // Declara una cadena para guardar el nombre
    char apellido[50]; // Declara una cadena para guardar el primer apellido
    char apellido_materno[50]; // Declara una cadena para guardar el apellido materno
    char codigo[7];  // Declara una cadena para guardar el código único

    // Supongamos que tienes un nombre, un primer apellido y un apellido materno
    strcpy(nombre, "Juan"); // Ejemplo de nombre
    strcpy(apellido, "Perez"); // Ejemplo de primer apellido
    strcpy(apellido_materno, "Lopez"); // Ejemplo de apellido materno

    // Copia los primeros 2 caracteres del nombre a la cadena "codigo"
    strncpy(codigo, nombre, 2);
    codigo[2] = '\0'; // Agrega el carácter nulo al final

    // Concatena los primeros 2 caracteres del primer apellido a la cadena "codigo"
    strncat(codigo, apellido, 2);

    // Concatena los primeros 2 caracteres del apellido materno a la cadena "codigo"
    strncat(codigo, apellido_materno, 2);

    // Imprime el código resultante
    printf("Código único: %s\n", codigo);

    return 0;
}