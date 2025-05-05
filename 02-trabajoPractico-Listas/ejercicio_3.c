#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tp_2_listas.h" 
#include "../libs/listas/headers/listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/validaciones.h" 
#include "func_aux.h" 

// funcion que pide dos listas y dice si una es multiplo de la otra
bool multiploLista (Lista l1, Lista l2) {
    bool res = true;
    bool es_escalar = true;
    int escala_inicial = 0;

    if (l_es_vacia(l1) || l_es_vacia(l2) || l_longitud(l1) != l_longitud(l2)) {
        printf("Listas con longitud diferente o vacias (por ende L2 no es multiplo de L1)!\n");
        return false;
    }

    TipoElemento primer_elem1 = l_recuperar(l1, 1);
    TipoElemento primer_elem2 = l_recuperar(l2, 1);

    if (!primer_elem1 || !primer_elem2 || primer_elem1->clave == 0) {
         printf("No se puede determinar el multiplo debido a elementos invalidos o cero en la primera posicion de L1.\n");
         return false;
    }

    escala_inicial = primer_elem2->clave / primer_elem1->clave;

    Iterador iter1 = iterador(l1);
    Iterador iter2 = iterador(l2);
    TipoElemento elemento1;
    TipoElemento elemento2;

    bool es_primer_elemento_en_bucle = true;

    while (hay_siguiente(iter1)) {
        elemento1 = siguiente(iter1);
        elemento2 = siguiente(iter2);

        if (!elemento1 || !elemento2) {
            res = false;
            break;
        }

        if (elemento1->clave == 0) {
            printf("Elemento cero encontrado en L1, no se puede determinar el multiplo.\n");
            res = false;
            break;
        }

        if (elemento2->clave % elemento1->clave != 0 ) {
            res = false;
        }

        if (!es_primer_elemento_en_bucle) {
            int escala_actual = elemento2->clave / elemento1->clave;
            if (escala_actual != escala_inicial) {
                es_escalar = false;
            }
        }

        es_primer_elemento_en_bucle = false;
    }

    if (res == true) {
        printf("L2 es multiplo de L1\n");
        if (es_escalar) {
            printf("Es un escalar con valor %d.\n", escala_inicial);
        }
    } else {
        printf("L2 no es multiplo de L1\n");
    }

    return res;
}

int run_ejercicio_3() {
    int opcion1, opcion2;
    Lista lista1 = NULL;
    Lista lista2 = NULL;
    int tamanio_manual;

    printf("========== CARGAR LISTA 1 ==========\n");
    printf("Seleccione metodo de carga para LISTA 1:\n");
    printf("1. Carga aleatoria\n");
    printf("2. Carga manual (sin ceros)\n");
    printf("Ingrese su opcion (1 o 2): ");
    opcion1 = leer_entero();

    while (opcion1 != 1 && opcion1 != 2) {
        printf("Opcion invalida. Ingrese 1 para carga aleatoria o 2 para carga manual: ");
        opcion1 = leer_entero();
    }

    if (opcion1 == 1) {
        lista1 = rellenarListaRandom();
    } else {
        printf("Ingrese el tamanio de la LISTA 1 (entre 1 y 100): \n");
        tamanio_manual = leer_entero();
        while (tamanio_manual <= 0 || tamanio_manual > 100) {
            printf("Tamanio invalido. Ingrese un numero entre 1 y 100 para el tamanio de la LISTA 1: ");
            tamanio_manual = leer_entero();
        }
        lista1 = rellenarListaConOpcion(tamanio_manual, false); 
    }

    printf("LISTA 1 - ");
    l_mostrar(lista1);
    printf("\n");

    printf("\n========== CARGAR LISTA 2 ==========\n");
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
         printf("Ingrese el tamanio de la LISTA 2 (entre 1 y 100): \n");
         tamanio_manual = leer_entero();
          while (tamanio_manual <= 0 || tamanio_manual > 100) {
            printf("Tamanio invalido. Por favor, ingrese un numero entre 1 y 100: ");
            tamanio_manual = leer_entero();
        }
         lista2 = rellenarListaConOpcion(tamanio_manual, true); 
    }

    printf("LISTA 2 - ");
    l_mostrar(lista2);
    printf("\n");

    multiploLista(lista1, lista2);
    return 0;
}
