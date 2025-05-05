#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../libs/listas/headers/listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/validaciones.h"
#include "func_aux.h" 

// funcion que compara dos listas y se fija si una es mayor, menor o igual a la otra
// Si las longitudes son diferentes, se informa al usuario y se retorna un valor especifico.
int comparar(Lista L1, Lista L2) {
    int MAYOR = 0;
    int MENOR = 1;
    int IGUAL = 2;

    if (l_longitud(L1) != l_longitud(L2)) {
        printf("Las listas tienen longitud diferente y no pueden ser comparadas elemento a elemento.\n");
        return -1;
    }

    if (l_es_vacia(L1) && l_es_vacia(L2)) {
        return IGUAL;
    }

    Iterador iter1 = iterador(L1);
    Iterador iter2 = iterador(L2);

    int contL1_mayor = 0;
    int contL2_mayor = 0;

    while (hay_siguiente(iter1)) {
        TipoElemento elemento1 = siguiente(iter1);
        TipoElemento elemento2 = siguiente(iter2);

        if (!elemento1 || !elemento2) {
             printf("Error: Elemento inesperado NULL durante la comparacion.\n");
             return -2;
        }

        if (elemento1->clave > elemento2->clave) {
            contL1_mayor++;
        } else if (elemento2->clave > elemento1->clave) {
            contL2_mayor++;
        }
    }

    if (contL1_mayor > contL2_mayor) {
        return MAYOR;
    } else if (contL2_mayor > contL1_mayor) {
        return MENOR;
    } else {
        return IGUAL;
    }
}

int run_ejercicio_4() {
    Lista lista1 = NULL;
    Lista lista2 = NULL;
    int opcion1, opcion2;
    int tamanio_manual;

    printf("========== CARGAR Y COMPARAR LISTAS ==========\n");

    printf("\n--- Cargar LISTA 1 ---\n");
    printf("Seleccione metodo de carga para LISTA 1:\n");
    printf("1. Carga aleatoria\n");
    printf("2. Carga manual (permite ceros)\n");
    printf("Ingrese su opcion (1 o 2): ");
    opcion1 = leer_entero();

    while (opcion1 != 1 && opcion1 != 2) {
        printf("Opcion invalida. Ingrese 1 para carga aleatoria o 2 para carga manual: ");
        opcion1 = leer_entero();
    }

    if (opcion1 == 1) {
        lista1 = rellenarListaRandom();
    } else {
        printf("Ingrese el tamanio deseado para la LISTA 1 (entre 1 y 100):\n");
        tamanio_manual = leer_entero();
         while (tamanio_manual <= 0 || tamanio_manual > 100) {
            printf("Tamanio invalido. Por favor, ingrese un numero entre 1 y 100: ");
            tamanio_manual = leer_entero();
        }
        lista1 = rellenarListaConOpcion(tamanio_manual, true);
    }

    printf("LISTA 1 - ");
    l_mostrar(lista1);
    printf("\n");

    printf("\n--- Cargar LISTA 2 ---\n");
    printf("Seleccione metodo de carga para LISTA 2:\n");
    printf("1. Carga aleatoria\n");
    printf("2. Carga manual (permite ceros)\n");
    printf("Ingrese su opcion (1 o 2): ");
    opcion2 = leer_entero();

     while (opcion2 != 1 && opcion2 != 2) {
        printf("Opcion invalida. Ingrese 1 para carga aleatoria o 2 para carga manual: ");
        opcion2 = leer_entero();
    }

    if (opcion2 == 1) {
        lista2 = rellenarListaRandom();
    } else {
         printf("Ingrese el tamanio deseado para la LISTA 2 (entre 1 y 100):\n");
         tamanio_manual = leer_entero();
          while (tamanio_manual <= 0 || tamanio_manual > 100) {
            printf("Tamanio invalido. Por favor, ingrese un numero entre 1 y 100: ");
            tamanio_manual = leer_entero();
        }
        lista2 = rellenarListaConOpcion(tamanio_manual, true);
    }

    printf("\n");
    printf("LISTA 1 - ");
    l_mostrar(lista1);
    printf("LISTA 2 - ");
    l_mostrar(lista2);
    printf("\n");

    int resultado_comparacion = comparar(lista1, lista2);

    if (resultado_comparacion == 0) {
        printf("La lista 1 es MAYOR a la lista 2\n");
    } else if(resultado_comparacion == 1) {
        printf("La lista 1 es MENOR a la lista 2\n");
    } else if(resultado_comparacion == 2) {
         printf("La lista 1 es IGUAL a la lista 2\n");
    } else {
      
    }


    return 0;
}
