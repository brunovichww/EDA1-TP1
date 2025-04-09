#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "tp_1_recursividad.h"
#include "formulas_menu_tp1.h"

// Función que valida si una cadena representa un número entero positivo (incluye 0)
// No debe tener espacios, letras, ni símbolos
bool esEnteroPositivoValido(const char *str)
{
    int i = 0;

    if (str[0] == '\0')
        return false; // Cadena vacía no es válida

    // No debe contener espacios
    for (int j = 0; str[j] != '\0'; j++)
    {
        if (isspace(str[j]))
            return false;
    }

    // Todos los caracteres deben ser dígitos
    for (; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
            return false;
    }

    return true;
}

// Función recursiva que devuelve el k-ésimo término de la serie de Fibonacci
// Definición clásica: F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)
int terminoSeridFibonacci(int k)
{
    if (k == 0)
        return 0; // Caso base
    if (k == 1)
        return 1;                                                       // Caso base
    return terminoSeridFibonacci(k - 1) + terminoSeridFibonacci(k - 2); // Llamada recursiva
}

// Función principal del ejercicio 3, se llama desde el menú
void ejecutar_ejercicio_3()
{
    char buffer[50];    // Para leer la entrada como texto
    int k;              // Valor de entrada: la posición en la serie de Fibonacci
    char respuesta[10]; // Para validar si quiere continuar
    int continuar = 1;  // Controla el bucle principal

    while (continuar == 1)
    {
        // Leer y validar k
        while (1)
        {
            printf("Ingrese el valor de k (entero positivo, k >= 0): ");
            fgets(buffer, sizeof(buffer), stdin); // Leer línea completa
            buffer[strcspn(buffer, "\n")] = '\0'; // Eliminar salto de línea

            if (esEnteroPositivoValido(buffer))
            {
                k = atoi(buffer); // Convertir el texto a entero
                break;
            }
            else
            {
                printf("Entrada invalida. Ingrese un numero entero positivo sin espacios ni simbolos.\n");
            }
        }

        // Calcular el término de Fibonacci
        int resultado = terminoSeridFibonacci(k);
        printf("El termino %d de la serie de Fibonacci es: %d\n", k, resultado);

        // Preguntar si desea calcular otro
        while (1)
        {
            printf("\nDesea calcular otro termino? (1 = Si, 0 = No): ");
            fgets(respuesta, sizeof(respuesta), stdin); // Leer respuesta
            respuesta[strcspn(respuesta, "\n")] = '\0'; // Eliminar salto de línea

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

    // Mensaje final al volver al menú principal
    printf("\nVolviendo al menu principal...\n");
}
