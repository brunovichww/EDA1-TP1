#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp_1_recursividad.h"
#include "formulas_menu_tp1.h"

#define MAX 100
#define MAX_RESULTADOS 1000
#define MAX_LINEA 256

// Función recursiva auxiliar
void buscarSubconjuntosRec(int *conjunto, int n, int indice, int *subconjunto, int subTam, int sumaActual, int sumaObjetivo, char **output, int *count) {
    if (sumaActual == sumaObjetivo) {
        char buffer[MAX_LINEA] = "{ ";
        char num[16];
        for (int i = 0; i < subTam; i++) {
            sprintf(num, "%d ", subconjunto[i]);
            strcat(buffer, num);
        }
        strcat(buffer, "}");
        output[*count] = strdup(buffer);  // Guardamos la cadena en el array de resultados
        (*count)++;
        return;
    }

    if (indice >= n || sumaActual > sumaObjetivo)
        return;

    // Incluir el elemento actual
    subconjunto[subTam] = conjunto[indice];
    buscarSubconjuntosRec(conjunto, n, indice + 1, subconjunto, subTam + 1, sumaActual + conjunto[indice], sumaObjetivo, output, count);

    // No incluir el elemento actual
    buscarSubconjuntosRec(conjunto, n, indice + 1, subconjunto, subTam, sumaActual, sumaObjetivo, output, count);
}

// Función principal solicitada
void subconjuntosQueSumanN(int conjunto[], int tamano, int n, char **output) {
    int subconjunto[MAX];
    int count = 0;
    buscarSubconjuntosRec(conjunto, tamano, 0, subconjunto, 0, 0, n, output, &count);
    output[count] = NULL; // Marcamos fin de resultados
}

// Función del menú
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

        while (getchar() != '\n');  // Limpiar buffer

        // Reservamos espacio para resultados
        char *output[MAX_RESULTADOS];
        for (int i = 0; i < MAX_RESULTADOS; i++) output[i] = NULL;

        // Llamamos a la función principal
        subconjuntosQueSumanN(conjunto, n, objetivo, output);

        printf("\nSubconjuntos que suman %d:\n", objetivo);
        int i = 0;
        while (output[i] != NULL) {
            printf("%s\n", output[i]);
            free(output[i]);  // Liberamos memoria
            i++;
        }

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
