#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Incluir esta librería para usar strcspn y strcmp
#include <ctype.h> // Para funciones como islower (verifica si es minúscula)
#include "tp_1_recursividad.h"
#include "formulas_menu_tp1.h"

// Calcular la potencia de 10 necesaria para los decimales
float pot(int dec) {
    float potenciaDeDiez = 1;
    for (int i = 0; i < dec; i++) {
        potenciaDeDiez *= 0.1f; // Multiplicar por 0.1 es equivalente a dividir por 10
    }
    return potenciaDeDiez;
}

// Función auxiliar recursiva para la división entera (restas sucesivas)
void auxDivisionEntera(int a, int b, int *cociente, int *resto) {
    if (a < b) {
        *cociente += 0;
        *resto = a;
    } else {
        a -= b;
        *cociente += 1;
        auxDivisionEntera(a, b, cociente, resto);
    }
}

// Función auxiliar recursiva para la división con decimales
float auxDivisionDecimal(int a, int b, float res, int dec) {
    int cociente = 0;
    int resto = 0;
    
    // Realizar la división entera usando la función auxiliar
    auxDivisionEntera(a, b, &cociente, &resto);
    
    // Caso base: cuando el resto es 0 o cuando hemos alcanzado 5 decimales
    if (resto == 0 || dec == 5) {
        float potenciaDeDiez = pot(dec);
        res += cociente * potenciaDeDiez;
        return res;
    } else {
        float potenciaDeDiez = pot(dec);
        res += cociente * potenciaDeDiez;
        a = resto;
        return auxDivisionDecimal(10 * a, b, res, dec + 1);
    }
}

// Función principal que maneja la división, considerando el signo
float division(int a, int b) {
    int signo = -1;
    if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
        signo = 1;
    }
    
    // Convertir a valores absolutos
    a = abs(a);
    b = abs(b);
    
    // Realizar la división recursiva con decimales
    float resultado = auxDivisionDecimal(a, b, 0, 0);
    
    // Devolver el resultado con el signo adecuado
    return signo * resultado;
}

// Función que maneja la interacción con el usuario y el menú
void ejecutar_ejercicio_4() {
    int m, n;
    char respuesta[10];
    int continuar = 1;

    while (continuar == 1) {
        // Solicitar valores de m y n (dividendo y divisor)
        printf("Ingrese el valor de m (dividendo): ");
        scanf("%d", &m);
        printf("Ingrese el valor de n (divisor): ");
        scanf("%d", &n);

        // Verificar si n es diferente de cero para evitar división por cero
        if (n == 0) {
            printf("Error: No se puede dividir por cero.\n");
        } else {
            // Realizar la división recursiva
            float resultado = division(m, n);
            printf("El cociente de %d dividido por %d es: %.5f\n", m, n, resultado);
        }

        // Preguntar si desea continuar (solo acepta 1 o 0)
        while (1) {
            printf("\nDesea realizar otra división? (1 = Si, 0 = No): ");
            fgets(respuesta, sizeof(respuesta), stdin);
            respuesta[strcspn(respuesta, "\n")] = '\0'; // Eliminar salto de línea

            if (strcmp(respuesta, "1") == 0) {
                continuar = 1;
                break;
            } else if (strcmp(respuesta, "0") == 0) {
                continuar = 0;
                break;
            } else {
                printf("Entrada inválida. Solo se permite 1 (Sí) o 0 (No).\n");
            }
        }
    }

    printf("\nVolviendo al menú principal...\n");
}