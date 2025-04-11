#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "tp_1_recursividad.h"
#include "formulas_menu_tp1.h"

#define BUFFER 100

int ultimoDigito(int *bn) {
    int n = *bn;
    if (n < 0) {
        n = -n;
    }
    int buffer = n / 10;
    *bn = buffer;
    return (n - 10 * buffer);
}

bool divisiblePor7(int n) {
    if (n < 0) n = -n;

    // Caso base
    if (n <= 70) {
        return (n % 7 == 0);
    } else {
        int u = ultimoDigito(&n);
        return divisiblePor7(n - u * 2);
    }
}

int valIngresoNum() {
    char input[BUFFER];
    long num;
    char *endptr;

    while (1) {
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error al leer entrada. Intente de nuevo:\n");
            continue;
        }

        input[strcspn(input, "\n")] = '\0'; // Eliminamos el \n

        num = strtol(input, &endptr, 10);

        if (*endptr == '\0') {
            return (int)num;
        } else {
            printf("Debe ingresar un numero entero valido. Intentelo nuevamente:\n");
        }
    }
}

void ejecutar_ejercicio_9() {
    bool seguir = true;

    while (seguir) {
        printf("Ingresa un numero entero y te dire si es divisible por 7: ");
        int n = valIngresoNum();

        if (divisiblePor7(n)) {
            printf("%d es divisible por 7.\n", n);
        } else {
            printf("%d NO es divisible por 7.\n", n);
        }

        printf("¿Queres probar con otro numero? (No = 0, Si = 1): ");
        int respuesta = valIngresoNum();
        seguir = (respuesta != 0);
    }

    printf("\nVolviendo al menu principal...\n");
}
