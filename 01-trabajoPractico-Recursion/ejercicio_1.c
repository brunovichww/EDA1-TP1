#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h> // Para funciones como islower (verifica si es minúscula)
#include "tp_1_recursividad.h"
#include "formulas_menu_tp1.h"

//  Valida que la cadena tenga solo letras minusculas sin espacios ni numeros
bool esCadenaValida(char palabra[])
{
    for (int i = 0; palabra[i] != '\0'; i++)
    {
        if (isspace(palabra[i]) || isdigit(palabra[i]) || !islower(palabra[i]))
        {
            return false;
        }
    }
    return true;
}

// Funcion auxiliar recursiva
bool palindromoAux(char *cadena, int inicio, int fin)
{
    if (inicio >= fin)
        return true;
    if (cadena[inicio] != cadena[fin])
        return false;
    return palindromoAux(cadena, inicio + 1, fin - 1);
}

// Funcion principal
bool palindromo(char *cadena)
{
    int len = strlen(cadena);
    return palindromoAux(cadena, 0, len - 1);
}

void ejecutar_ejercicio_1()
{
    char palabra[100];
    char respuesta[10];
    int continuar = 1;

    while (continuar == 1)
    {
        // Solicitar palabra válida
        while (1)
        {
            printf("Ingrese una palabra (solo letras minusculas, sin espacios ni numeros): ");
            fgets(palabra, sizeof(palabra), stdin);
            palabra[strcspn(palabra, "\n")] = '\0'; // Eliminar salto de linea

            if (esCadenaValida(palabra))
            {
                break;
            }
            else
            {
                printf("Entrada invalida. No se permiten espacios, numeros ni mayusculas.\n");
            }
        }

        // Verificar si es palindromo
        if (palindromo(palabra))
        {
            printf("\"%s\" es palindromo\n", palabra);
        }
        else
        {
            printf("\"%s\" no es palindromo\n", palabra);
        }

        // Preguntar si desea continuar (solo acepta 1 o 0)
        while (1)
        {
            printf("\nDesea ingresar otra palabra? (1 = Si, 0 = No): ");
            fgets(respuesta, sizeof(respuesta), stdin);
            respuesta[strcspn(respuesta, "\n")] = '\0'; // Eliminar \n

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
