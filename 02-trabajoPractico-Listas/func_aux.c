#include "func_aux.h"
#include <stdlib.h>
#include <stdio.h>
#include "../libs/listas/headers/listas.h"
#include "../libs/validaciones/headers/validaciones.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"

// Funcion para rellenar una lista con valores aleatorios
Lista rellenarListaRandom() {
    Lista lista = l_crear();
    printf("========== CARGAR LISTA ALEATORIA ==========\n"); 
    printf("Ingrese el tamanio deseado para la lista (entre 1 y 100):\n"); 

    int tamano = leer_entero();
    while (tamano <= 0 || tamano > 100) { 
        printf("Tamanio invalido. Por favor, ingrese un numero entre 1 y 100: ");
        tamano = leer_entero();
    }

    printf("\n[INGRESO - RANGO DE VALORES ALEATORIOS]\n"); 
    printf("Ingrese el valor minimo para los elementos (-100.000 a 100.000): "); 
    int randomMin = leer_entero();

    printf("Ingrese el valor maximo para los elementos (-100.000 a 100.000): "); 
    int randomMax = leer_entero();

    while (randomMax < randomMin) {
        printf("El valor maximo no puede ser menor que el minimo. Ingrese de vuelta: ");
        randomMax = leer_entero();
    }

    printf("\nCargando lista con %d elementos aleatorios...\n", tamano);

    int clave = 0;
    for (int i = 0; i < tamano; i++) {
        if (randomMax >= randomMin) {
             clave = randomMin + rand() % (randomMax - randomMin + 1);
        } else {
             clave = randomMin;
        }
        TipoElemento elemento = te_crear(clave);
        l_agregar(lista, elemento);
    }

    printf("Lista cargada.\n");
    return lista;
}

// Funcion para cargar una lista manualmente con opcion de permitir o no el valor cero
// Recibe el tamanio deseado y un flag booleano (true para permitir 0, false para no permitir 0)
// Crea una nueva lista y la retorna.

Lista rellenarListaConOpcion(int tamanio, bool permitir_cero) {
    Lista lista = l_crear();
    printf("========== CARGAR LISTA MANUAL ==========\n"); 
    printf("Ingrese el tamanio deseado para la lista (entre 1 y 100):\n");

  
    int elementos_a_cargar = tamanio;
    if (elementos_a_cargar > 100) { 
        printf("El tamanio ingresado (%d) excede el tamanio maximo de la lista (100). Se cargaran 100 elementos.\n", tamanio);
        elementos_a_cargar = 100;
    }
     if (elementos_a_cargar <= 0) {
        printf("Tamanio invalido para cargar la lista (%d).\n", tamanio);
        return lista; 
    }

    printf("\nIngrese los %d elementos de la lista:\n", elementos_a_cargar);

    for (int i = 0; i < elementos_a_cargar; i++) {
        int valorLista;
        if (permitir_cero) {
            printf("Elemento %d: ", i + 1);
            valorLista = leer_entero(); 
        } else {
            printf("Elemento %d (no cero): ", i + 1);
            valorLista = leer_entero_sin_cero(); 
        }
        TipoElemento elemento = te_crear(valorLista);
        l_agregar(lista, elemento);
    }

    printf("Lista cargada manualmente.\n");
    return lista;
}
