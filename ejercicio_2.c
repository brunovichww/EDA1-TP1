#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "tp_1_recursividad.h"
#include "formulas_menu_tp1.h"

// Validación estricta de número entero
bool esEnteroValido(const char *str)
{
    int i = 0;

    // No debe estar vacía
    if (str[0] == '\0')
        return false;

    // No debe contener espacios
    for (int j = 0; str[j] != '\0'; j++)
    {
        if (isspace(str[j]))
            return false;
    }

    // Aceptar signo al inicio
    if (str[0] == '-' || str[0] == '+')
    {
        if (str[1] == '\0')
            return false; // solo el signo no es válido
        i++;
    }

    // El resto deben ser dígitos
    for (; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
            return false;
    }

    return true;
}

// Función recursiva que calcula m * n como suma sucesiva
int producto(int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (n == 1)
        return m;
    if (n < 0)
        return -producto(m, -n);
    return m + producto(m, n - 1);
}

// Función principal del ejercicio 2
void ejecutar_ejercicio_2()
{
    char buffer[50];
    int m, n;
    char respuesta[10];
    int continuar = 1;

    while (continuar == 1)
    {
        // Leer m
        while (1)
        {
            printf("Ingrese el primer numero (m): ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';

            if (esEnteroValido(buffer))
            {
                m = atoi(buffer);
                break;
            }
            else
            {
                printf("Entrada invalida. Ingrese un numero entero sin espacios, letras ni comas.\n");
            }
        }

        // Leer n
        while (1)
        {
            printf("Ingrese el segundo numero (n): ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';

            if (esEnteroValido(buffer))
            {
                n = atoi(buffer);
                break;
            }
            else
            {
                printf("Entrada invalida. Ingrese un numero entero sin espacios, letras ni comas.\n");
            }
        }

        // Calcular producto y mostrar sumatoria real
        int resultado = producto(m, n);
        int repeticiones = abs(n);
        int valor = (n < 0) ? -m : m;

        printf("Calculo: ");
        if (m == 0 || n == 0)
        {
            printf("0");
        }
        else
        {
            for (int i = 0; i < repeticiones; i++)
            {
                printf("%d", valor);
                if (i < repeticiones - 1)
                    printf(" + ");
            }
        }

        printf(" = %d\n", resultado);

        // Preguntar si quiere repetir
        while (1)
        {
            printf("\nDesea calcular otro producto? (1 = Si, 0 = No): ");
            fgets(respuesta, sizeof(respuesta), stdin);
            respuesta[strcspn(respuesta, "\n")] = '\0';

            if (strcmp(respuesta, "1") == 0)
            {
                continuar = 1;
                break;
            }
            else if (strcmp(respuesta, "0") == 0)
            {
                continuar = 0;
                break;
            }
            else
            {
                printf("Entrada invalida. Solo se permite 1 (Si) o 0 (No).\n");
            }
        }
    }

    printf("\nVolviendo al menu principal...\n");
}