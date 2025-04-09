#include <stdio.h>
#include "tp_1_recursividad.h" // Declaraciones de todas las funciones ejecutar_ejercicio_X()
#include "formulas_menu_tp1.h"

// void ejecutar_ejercicio_1();
// void ejecutar_ejercicio_2();

int main()
{
    int opcion = -1;

    while (opcion != 0)
    {
        printf("\n========= MENU PRINCIPAL: Tp 1 - Recursividad=========\n");
        printf("1. Ejecutar ejercicio 1\n");
        printf("2. Ejecutar ejercicio 2\n");
        printf("3. Ejecutar ejercicio 3\n");
        printf("4. Ejecutar ejercicio 4\n");
        printf("5. Ejecutar ejercicio 5\n");
        printf("6. Ejecutar ejercicio 6\n");
        printf("7. Ejecutar ejercicio 7\n");
        printf("8. Ejecutar ejercicio 8\n");
        printf("9. Ejecutar ejercicio 9\n");
        printf("0. Salir del programa\n");
        printf("Seleccione una opcion (0-9): ");
        printf("\n");

        if (scanf("%d", &opcion) != 1 || opcion < 0 || opcion > 9)
        {
            printf("Opcion invalida. Ingrese un numero entre 0 y 9.\n");

            // Limpiar buffer
            while (getchar() != '\n')
                ;
            opcion = -1; // Resetear la opción
            continue;
        }

        // Limpiar buffer
        while (getchar() != '\n')
            ;

        switch (opcion)
        {
        case 1:
            ejecutar_ejercicio_1();
            break;
        case 2:
            ejecutar_ejercicio_2();
            break;
        case 3:
            ejecutar_ejercicio_3();
            break;
        /*case 4:
            ejecutar_ejercicio_4();
            break;
        case 5: ejecutar_ejercicio_5(); break;
        case 6: ejecutar_ejercicio_6(); break;
        case 7: ejecutar_ejercicio_7(); break;
        case 8: ejecutar_ejercicio_8(); break;
        case 9: ejecutar_ejercicio_9(); break;*/
        case 0:
            printf("Saliendo del programa.\n");
            break;
        }
    }

    system("pause");
    return 0;
}
