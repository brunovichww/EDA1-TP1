#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "tp_1_recursividad.h"
#include "formulas_menu_tp1.h"


#define LIMITE_LONGITUD 15  // Longitud máxima permitida para el número

// Valida que la cadena:
// - Solo contenga dígitos
// - No tenga ceros a la izquierda (excepto "0")
// - No supere los 15 caracteres
bool esCadenaNumericaValida(const char *str) {
    int len = strlen(str);

    if (len == 0 || len > LIMITE_LONGITUD) return false;
    if (len > 1 && str[0] == '0') return false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) return false;
    }

    return true;
}

// Función recursiva para insertar separadores de miles
char *agregarSeparadorMiles(char numero[]) {
    int len = strlen(numero);

    // Caso base: si tiene 3 o menos dígitos, no se agrega punto
    if (len <= 3) {
        return strdup(numero);
    }

    // Dividir el número: copiar la parte izquierda (excepto los últimos 3)
    char parteIzquierda[100];
    strncpy(parteIzquierda, numero, len - 3);
    parteIzquierda[len - 3] = '\0';

    // Apuntar a los últimos 3 caracteres
    const char *ultimos = &numero[len - 3];

    // Llamada recursiva sobre la parte izquierda
    char *resultadoParcial = agregarSeparadorMiles(parteIzquierda);

    // Construir el resultado final concatenando el punto y los últimos 3 caracteres
    char *resultadoFinal = malloc(strlen(resultadoParcial) + 4);
    sprintf(resultadoFinal, "%s.%s", resultadoParcial, ultimos);

    free(resultadoParcial);
    return resultadoFinal;
}

void ejecutar_ejercicio_5 () {
    char entrada[100];
    char respuesta[10];
    int continuar = 1;

    while (continuar) {
        printf("\n--- EJERCICIO 5: Separador de miles ---\n");
        printf("Ingrese un numero (sin ceros a la izquierda, solo digitos, max %d): ", LIMITE_LONGITUD);

        // Leer el número desde teclado
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';  // Eliminar el salto de línea

        // Validar el número ingresado
        if (!esCadenaNumericaValida(entrada)) {
            printf("Entrada invalida. Solo se permiten numeros positivos, sin ceros a la izquierda, ni simbolos, y hasta %d cifras.\n", LIMITE_LONGITUD);
        } else {
            // Procesar y mostrar el resultado con separadores
            char *resultado = agregarSeparadorMiles(entrada);
            printf("Con separador de miles: %s\n", resultado);
            free(resultado);
        }

        // Preguntar si el usuario quiere ingresar otro número
        while (1) {
            printf("\n¿Desea consultar otro numero? (1 = Si, 0 = No): ");
            fgets(respuesta, sizeof(respuesta), stdin);
            respuesta[strcspn(respuesta, "\n")] = '\0';

            if (strcmp(respuesta, "1") == 0) {
                continuar = 1;
                break;
            } else if (strcmp(respuesta, "0") == 0) {
                continuar = 0;
                break;
            } else {
                printf("Entrada invalida. Solo se permite 1 o 0.\n");
            }
        }
    }

    printf("\nVolviendo al menu principal...\n");
    //system("pause");
    //return 0;
}