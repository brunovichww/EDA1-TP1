#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tp_1_recursividad.h"
#include "formulas_menu_tp1.h"

// Función para calcular potencia negativa de 10
float pot(int dec) {
    float potenciaDeDiez = 1;
    for (int i = 0; i < dec; i++) {
        potenciaDeDiez *= 0.1f;
    }
    return potenciaDeDiez;
}

// División entera recursiva
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

// División decimal recursiva
float auxDivisionDecimal(int a, int b, float res, int dec) {
    int cociente = 0;
    int resto = 0;

    auxDivisionEntera(a, b, &cociente, &resto);

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

// División con signo
float division(int a, int b) {
    int signo = -1;
    if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
        signo = 1;
    }

    a = abs(a);
    b = abs(b);

    float resultado = auxDivisionDecimal(a, b, 0, 0);
    return signo * resultado;
}

// Validar si la cadena es un número entero (positivo o negativo)
bool esEnteroValido2(const char *str) {
    int i = 0;

    if (str[0] == '\0')
        return false;

    if (str[0] == '-' || str[0] == '+') {
        i++;
        if (str[i] == '\0') return false;  // Solo un signo no es válido
    }

    for (; str[i] != '\0'; i++) {
        if (!isdigit(str[i]))
            return false;
    }

    return true;
}

// Función principal del ejercicio 4
void ejecutar_ejercicio_4() {
    char buffer[50];
    char respuesta[10];
    int m, n;
    int continuar = 1;

    while (continuar == 1) {
        // Validar el dividendo
        while (1) {
            printf("Ingrese el valor de m (dividendo): ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';

            if (esEnteroValido2(buffer)) {
                m = atoi(buffer);
                break;
            } else {
                printf("Entrada invalida. Ingrese un numero entero (positivo o negativo) sin espacios ni simbolos.\n");
            }
        }

        // Validar el divisor
        while (1) {
            printf("Ingrese el valor de n (divisor): ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';

            if (!esEnteroValido2(buffer)) {
                printf("Entrada invalida. Ingrese un numero entero (positivo o negativo) sin espacios ni simbolos.\n");
            } else {
                n = atoi(buffer);
                if (n == 0) {
                    printf("Error: No se puede dividir por cero.\n");
                } else {
                    break;
                }
            }
        }

        float resultado = division(m, n);
        printf("El cociente de %d dividido por %d es: %.5f\n", m, n, resultado);

        // Preguntar si desea continuar
        while (1) {
            printf("\nDesea realizar otra division? (1 = Si, 0 = No): ");
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
