#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp_1_recursividad.h"
#include "formulas_menu_tp1.h"

// Función recursiva auxiliar
char* auxOndaDigital(char seniales[], char onda[], int pos) {
    char actual = seniales[pos];

    if (actual == '\0') {
        return onda;
    } else {
        if (pos >= 1 && actual != seniales[pos - 1]) {
            strcat(onda, "|");
        }

        if (actual == 'H') {
            strcat(onda, "^");
        } else if (actual == 'L') {
            strcat(onda, "_");
        } else {
            strcpy(onda, "Error en la señal de entrada.");
            return onda;
        }

        return auxOndaDigital(seniales, onda, pos + 1);
    }
}

// Función principal del ejercicio
void ejecutar_ejercicio_6() {
    char senial[100];
    char respuesta[10];
    int continuar = 1;

    while (continuar == 1) {
        printf("Ingrese la señal (solo H o L, sin espacios): ");
        fgets(senial, sizeof(senial), stdin);
        senial[strcspn(senial, "\n")] = '\0'; // Eliminar salto de línea

        if (strlen(senial) == 0) {
            printf("Señal vacía. Intente nuevamente.\n");
            continue;
        }

        char onda[200] = ""; // Inicializar string vacío

        char* resultado = auxOndaDigital(senial, onda, 0);
        printf("Onda digital: %s\n", resultado);

        printf("\n¿Desea ingresar otra señal? (1 = sí / 0 = no): ");
        fgets(respuesta, sizeof(respuesta), stdin);
        respuesta[strcspn(respuesta, "\n")] = '\0';

        if (strcmp(respuesta, "0") == 0) {
            continuar = 0;
        }
    }
}