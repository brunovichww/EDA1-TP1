#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp_1_recursividad.h"
#include "formulas_menu_tp1.h"

// Funcion recursiva que genera la representación del grupo
char* reunionMafia(int nivel) {
    if (nivel == 1) {
        char* base = malloc(6 * sizeof(char)); // "(-.-)" + '\0'
        if (base == NULL) {
            printf("Error al asignar memoria.\n");
            exit(1);
        }
        strcpy(base, "(-.-)");
        return base;
    } else {
        char* anterior = reunionMafia(nivel - 1);
        size_t tamaño = strlen(anterior) + 5 + 1; // "(-" + contenido + "-)" + '\0'

        char* resultado = malloc(tamaño * sizeof(char));
        if (resultado == NULL) {
            printf("Error al asignar memoria.\n");
            exit(1);
        }

        strcpy(resultado, "(-.");
        strcat(resultado, anterior);
        strcat(resultado, ".-)");

        free(anterior);
        return resultado;
    }
}

// Función principal para ejecutar el ejercicio
void ejecutar_ejercicio_7() {
    int nivel;
    char respuesta[10];
    int continuar = 1;

    while (continuar == 1) {
        printf("Ingrese el nivel de la reunion (mayor o igual a 1): ");
        scanf("%d", &nivel);
        while (getchar() != '\n'); // Limpiar buffer

        if (nivel < 1) {
            printf("Nivel inválido. Debe ser mayor o igual a 1.\n");
            continue;
        }

        char* vista = reunionMafia(nivel);
        printf("Vista frontal del grupo de nivel %d: %s\n", nivel, vista);
        free(vista);

        printf("\n¿Desea continuar? (si/no): ");
        fgets(respuesta, sizeof(respuesta), stdin);
        respuesta[strcspn(respuesta, "\n")] = '\0'; // Eliminar salto de línea

        if (strcmp(respuesta, "no") == 0) {
            continuar = 0;
        }
    }
}