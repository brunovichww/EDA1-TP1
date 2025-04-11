#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "tp_1_recursividad.h"
#include "formulas_menu_tp1.h"

#define LIMITE_NIVEL 1000

bool esEnteroPositivoValido(const char *str)
{
    if (str[0] == '\0')
        return false;

    for (int j = 0; str[j] != '\0'; j++)
    {
        if (isspace(str[j]) || !isdigit(str[j]))
            return false;
    }

    return true;
}

void limpiarBuffer()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}

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
        size_t tamaño = strlen(anterior) + strlen("(-.") + strlen(".-)") + 1;

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

void ejecutar_ejercicio_7()
{
    char buffer[50];
    char respuesta[10];

    while (true)
    {
        while (1)
        {
            printf("Ingrese el nivel de la reunion (entero positivo, nivel >= 1): ");
            if (fgets(buffer, sizeof(buffer), stdin) == NULL)
                continue;

            if (strchr(buffer, '\n') == NULL) // Limpiar buffer si es necesario
                limpiarBuffer();

            buffer[strcspn(buffer, "\n")] = '\0';

            if (esEnteroPositivoValido(buffer))
            {
                int nivel = atoi(buffer);
                if (nivel >= 1 && nivel <= LIMITE_NIVEL)
                {
                    char *vista = reunionMafia(nivel);
                    printf("Vista frontal del grupo de nivel %d: %s\n", nivel, vista);
                    free(vista);
                    break;
                }
                else if (nivel > LIMITE_NIVEL)
                {
                    printf("Nivel demasiado alto. Por favor, ingrese un número menor o igual a %d.\n", LIMITE_NIVEL);
                }
                else
                {
                    printf("Nivel inválido. Debe ser mayor o igual a 1.\n");
                }
            }
            else
            {
                printf("Entrada invalida. Ingrese un número entero positivo sin espacios ni símbolos.\n");
            }
        }

        while (1)
        {
            printf("\n¿Desea continuar? (1 = Si, 0 = No): ");
            if (fgets(respuesta, sizeof(respuesta), stdin) == NULL)
                continue;

            if (strchr(respuesta, '\n') == NULL)
                limpiarBuffer();

            respuesta[strcspn(respuesta, "\n")] = '\0';

            if (strcmp(respuesta, "1") == 0)
            {
                break;
            }
            else if (strcmp(respuesta, "0") == 0)
            {
                printf("\nVolviendo al menu principal...\n");
                return;
            }
            else
            {
                printf("Entrada inválida. Solo se permite 1 (Si) o 0 (No).\n");
            }
        }
    }
}