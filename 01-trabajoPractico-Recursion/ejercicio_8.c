#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp_1_recursividad.h"

#define MAX 100

// Función recursiva para encontrar subconjuntos que suman el total
void encontrarSubconjuntos(int *conjunto, int n, int indice, int *subconjunto, int subTam, int sumaActual, int sumaObjetivo) {
    if (sumaActual == sumaObjetivo) {
        printf("{ ");
        for (int i = 0; i < subTam; i++) {
            printf("%d ", subconjunto[i]);
        }
        printf("}\n");
        return;
    }

    if (indice >= n || sumaActual > sumaObjetivo) {
        return;
    }

    // Opción 1: incluir el elemento actual
    subconjunto[subTam] = conjunto[indice];
    encontrarSubconjuntos(conjunto, n, indice + 1, subconjunto, subTam + 1, sumaActual + conjunto[indice], sumaObjetivo);

    // Opción 2: NO incluir el elemento actual
    encontrarSubconjuntos(conjunto, n, indice + 1, subconjunto, subTam, sumaActual, sumaObjetivo);
}

void ejecutar_ejercicio_8() {
    int conjunto[MAX], n, objetivo;
    char respuesta[10];
    int continuar = 1;

    while (continuar == 1) {
        printf("Ingrese la cantidad de elementos del conjunto: ");
        scanf("%d", &n);

        if (n <= 0 || n > MAX) {
            printf("Cantidad invalida. Intente nuevamente.\n");
            continue;
        }

        printf("Ingrese los %d elementos:\n", n);
        for (int i = 0; i < n; i++) {
            printf("Elemento %d: ", i + 1);
            scanf("%d", &conjunto[i]);
        }

        printf("Ingrese la suma objetivo: ");
        scanf("%d", &objetivo);

        // Limpiar buffer
        while (getchar() != '\n');

        printf("\nSubconjuntos que suman %d:\n", objetivo);
        int subconjunto[MAX];
        encontrarSubconjuntos(conjunto, n, 0, subconjunto, 0, 0, objetivo);

        // Preguntar si desea continuar
        while (1) {
            printf("\nDesea probar con otro conjunto? (1 = Si, 0 = No): ");
            fgets(respuesta, sizeof(respuesta), stdin);
            respuesta[strcspn(respuesta, "\n")] = '\0';

            if (strcmp(respuesta, "1") == 0) {
                continuar = 1;
                break;
            } else if (strcmp(respuesta, "0") == 0) {
                continuar = 0;
                break;
            } else {
                printf("Entrada invalida. Solo se permite 1 (Si) o 0 (No).\n");
            }
        }
    }

    printf("\nVolviendo al menu principal...\n");
}
