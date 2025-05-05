#include <stdio.h>
#include <stdlib.h>
#include "../libs/validaciones/headers/validaciones.h" // Necesario para leer_entero

// Incluir el header unificado para todos los ejercicios
#include "ejercicios.h"


int main() {
    int opcion = 0;

    do {
        // Mostrar menu de opciones
        printf("\n========== MENU PRINCIPAL ==========\n");
        printf("Seleccione un ejercicio para ejecutar:\n");
        printf("2. Ejercicio 2 (Listas: Faltantes y Comunes, Promedios, Maximo)\n");
        printf("3. Ejercicio 3 (Multiplo de Lista)\n");
        printf("4. Ejercicio 4 (Comparar Listas)\n");
        printf("5. Ejercicio 5 (Polinomio)\n");
        printf("6. Ejercicio 6 (Sublista)\n");
        printf("0. Salir\n");
        printf("====================================\n");
        printf("Ingrese su opcion: ");

        // Leer la opcion del usuario usando la funcion de validaciones
        opcion = leer_entero();

        // Ejecutar el ejercicio seleccionado
        switch (opcion) {
            case 2:
                printf("\n--- Ejecutando Ejercicio 2 ---\n");
                run_ejercicio_2(); // Llama a la funcion del ejercicio 2
                break;
            case 3:
                printf("\n--- Ejecutando Ejercicio 3 ---\n");
                run_ejercicio_3(); // Llama a la funcion del ejercicio 3
                break;
            case 4:
                printf("\n--- Ejecutando Ejercicio 4 ---\n");
                run_ejercicio_4(); // Llama a la funcion del ejercicio 4
                break;
            case 5:
                printf("\n--- Ejecutando Ejercicio 5 ---\n");
                run_ejercicio_5(); // Llama a la funcion del ejercicio 5
                break;
            case 6:
                printf("\n--- Ejecutando Ejercicio 6 ---\n");
                run_ejercicio_6(); // Llama a la funcion del ejercicio 6
                break;
            case 0:
                printf("\nSaliendo del programa.\n");
                break;
            default:
                printf("\nOpcion invalida. Por favor, ingrese un numero entre 0 y 6.\n");
                break;
        }

        // Opcional: esperar a que el usuario presione Enter antes de mostrar el menu de nuevo
        if (opcion != 0) {
            printf("\nPresione Enter para continuar...");
            // Consume el '\n' restante de la entrada anterior y espera a que el usuario presione Enter
            while (getchar() != '\n'); // Limpia el buffer de entrada
            getchar(); // Espera la nueva pulsacion de Enter
        }

    } while (opcion != 0); // Continuar mientras la opcion no sea Salir

    return 0; // Indicar salida exitosa
}
