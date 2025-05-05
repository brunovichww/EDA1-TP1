#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../libs/listas/headers/listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/validaciones.h"
#include "func_aux.h" 

// funcion para chequear lo que pasa si una de las listas (o ambas) es vacia
bool revisar_listas_vacias (Lista lista1, Lista lista2) {
    if (l_es_vacia(lista1) && l_es_vacia(lista2)) {
        printf("Ambas listas son sublista de la otra, ya que las dos estan vacias (e iguales).\n");
        return true;
    } else if (l_es_vacia(lista1)) {
        printf("L1 es sublista de L2.\n");
        return true;
    } else if (l_es_vacia(lista2)) {
        printf("L2 es sublista de L1.\n");
        return true;
    } else {
        return false;
    }
}

// funcion que indica si una lista es sublista de la otra
bool es_sublista (Lista principal, Lista secundaria) {
    if (l_es_vacia(secundaria)) {
        return true;
    }
    if (l_es_vacia(principal)) {
        return false;
    }

    Iterador iterSecundaria = iterador(secundaria);
    while (hay_siguiente(iterSecundaria)) {
        TipoElemento elementoS = siguiente(iterSecundaria);
        bool encontrado = false;

        if (!elementoS) continue;

        Iterador iterPrincipal = iterador(principal);
        while (hay_siguiente(iterPrincipal)) {
            TipoElemento elementoP = siguiente(iterPrincipal);
             if (elementoP && elementoP->clave == elementoS->clave) {
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            return false;
        }
    }
    return true;
}

int run_ejercicio_6() {
    Lista lista1 = NULL;
    Lista lista2 = NULL;
    int opcion1, opcion2;
    int tamanio_manual;

    printf("========== CARGAR LISTA 1 ==========\n");
    printf("Seleccione metodo de carga para LISTA 1:\n");
    printf("1. Carga aleatoria\n");
    printf("2. Carga manual\n");
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

    printf("\n========== CARGAR LISTA 2 ==========\n");
    printf("Seleccione metodo de carga para LISTA 2:\n");
    printf("1. Carga aleatoria\n");
    printf("2. Carga manual\n");
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

    printf("\n-----------------------\n");
    printf("LISTA 1 - ");
    l_mostrar(lista1);
    printf("\n");
    printf("LISTA 2 - ");
    l_mostrar(lista2);
    printf("\n");
    printf("-----------------------\n");

    if (revisar_listas_vacias(lista1, lista2)) {
        return 0;
    } else {
        printf("SON SUBLISTA? \n");
        printf("\n");

        if (es_sublista(lista1, lista2)) {
            printf("L2 es sublista de L1\n");
        } else {
            printf("L2 no es sublista de L1\n");
        }

        if (es_sublista(lista2, lista1)) {
            printf("L1 es sublista de L2\n");
        } else {
            printf("L1 no es sublista de L2\n");
        }
        printf("\n");
    }

   return 0;
}
