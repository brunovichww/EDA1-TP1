#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

// funcion que elimina espacios en blanco de una cadena
void strtrim(char *cadena) {
    char *comienzoDeCadena = cadena;
    char *finalDeCadena = cadena + strlen(cadena) - 1;
    while (isspace(*comienzoDeCadena)) {
        comienzoDeCadena++;
    }
    while (isspace(*finalDeCadena) && finalDeCadena >= comienzoDeCadena) {
        finalDeCadena--;
    }
    *(finalDeCadena + 1) = '\0';
    memmove(cadena, comienzoDeCadena,   finalDeCadena - comienzoDeCadena + 2);
}

// funcion para leer un entero por teclado (validacion)
int leer_entero() {
    char entrada[100];
    long numero;
    char *finptr;
    int valido = 0;

    while (!valido) {
        printf("Ingrese un numero entero: ");
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strlen(entrada)-1] = '\0';
        strtrim(entrada);
        if (entrada[0] == '\0') {
            printf("Entrada invalida. Intentelo de nuevo.\n");
            continue;
        }
        errno = 0;
        numero = strtol(entrada, &finptr, 10);
        if (errno != 0 || *finptr != '\0' || numero > 100000 || numero < -100000) {
            printf("Entrada invalida. Intentelo de nuevo.\n");
        } else {
            valido = 1;
        }
    }
    return (int) numero;
}

// funcion para leer un entero por teclado que no sea cero
int leer_entero_sin_cero() {
    int numero;
    while (1) { 
        numero = leer_entero();
        if (numero == 0) {
            printf("Entrada invalida. El numero no puede ser cero. Intentelo de nuevo.\n");
        } else {
            return numero; 
        }
    }
}


// funcion para leer un flotante por teclado (validacion)
float leer_flotante() {
    char entrada[100];
    float numero;
    char *finptr;
    int valido = 0;

    while (!valido) {
        printf("Ingrese un numero flotante (-100k a 100k): ");
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strlen(entrada)-1] = '\0';
        strtrim(entrada);
        if (entrada[0] == '\0') {
            printf("Entrada invalida. Intentelo de nuevo.\n");
            continue;
        }
        errno = 0;
        numero = strtof(entrada, &finptr);
        if (errno != 0 || *finptr != '\0' || numero > 100000.0 || numero < -100000.0) {
            printf("Entrada invalida. Intentelo de nuevo.\n");
        } else {
            valido = 1;
        }
    }
    return numero;
}

// funcion para leer un entero por teclado limitado por el minimo y maximo grado disponible (validacion)
int leer_grado() {
    int grado = leer_entero(); 
    while ((grado < 0) || (grado > 9)) { 
        printf("El grado del polinomio no puede ser negativo o mayor a 9. Intentelo de nuevo.\n"); 
        grado = leer_entero(); 
    }
    return grado;
}

// funcion para leer un flotante por teclado que no pueda ser negativo o 0 (validacion)
float leer_intervalo() {
    float intervalo = -1.0; 
    while (intervalo <= 0.0 || intervalo > 500.0) { 
        intervalo = leer_flotante(); 
        if (intervalo <= 0.0 || intervalo > 500.0) { 
             printf("El intervalo debe ser mayor que 0 y menor o igual a 500. Intentelo de nuevo.\n"); 
        }
    }
    return intervalo;
}

