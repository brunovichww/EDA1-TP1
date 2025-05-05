#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 
#include "../libs/listas/headers/listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "func_aux.h" 
#include "../libs/validaciones/headers/validaciones.h"


// Dada una 2 listas (L1 y L2) cargadas con valores, realizar los siguientes.

// a. Que retorne una lista con los valores de L1 que no estan en L2.
Lista valoresFaltantesL1(Lista lista1, Lista lista2) {
    Lista listaResultante = l_crear();
    Iterador iterL1 = iterador(lista1);
    bool estaEnLista;
    while (hay_siguiente(iterL1)) {
        TipoElemento elementoL1 = siguiente(iterL1);
        Iterador iterL2 = iterador(lista2);
        estaEnLista = false;
        if (elementoL1) {
            while (hay_siguiente(iterL2)) {
                TipoElemento elementoL2 = siguiente(iterL2);
                if (elementoL2 && elementoL1->clave == elementoL2->clave) {
                    estaEnLista = true;
                    break;
                }
            }
            if (!estaEnLista) {
                l_agregar(listaResultante, elementoL1);
            }
        }
    }
    return listaResultante;
}

// b. Que retorne una lista con los valores de L2 que no estan en L1.
Lista valoresFaltantesL2(Lista lista1, Lista lista2) {
    Lista listaResultante = l_crear();
    Iterador iterL2 = iterador(lista2);
    bool estaEnLista;
    while (hay_siguiente(iterL2)) {
        TipoElemento elementoL2 = siguiente(iterL2);
        Iterador iterL1 = iterador(lista1);
        estaEnLista = false;
        if (elementoL2) {
            while (hay_siguiente(iterL1)) {
                TipoElemento elementoL1 = siguiente(iterL1);
                if (elementoL1 && elementoL2->clave == elementoL1->clave) {
                    estaEnLista = true;
                    break;
                }
            }
            if (!estaEnLista) {
                l_agregar(listaResultante, elementoL2);
            }
        }
    }
    return listaResultante;
}

// c. Que retorne una lista con todos los valores comunes a ambas listas (L1 y L2).
Lista valoresComunes(Lista lista1, Lista lista2) {
    Lista listaResultante = l_crear();
    Iterador iterL1 = iterador(lista1);
    bool estaEnLista;
    while (hay_siguiente(iterL1)) {
        TipoElemento elementoL1 = siguiente(iterL1);
        estaEnLista = false;
        Iterador iterL2 = iterador(lista2);
        if (elementoL1) {
            while (hay_siguiente(iterL2)) {
                TipoElemento elementoL2 = siguiente(iterL2);
                if (elementoL2 && elementoL1->clave == elementoL2->clave) {
                    estaEnLista = true;
                    break;
                }
            }
            if (estaEnLista) {
                l_agregar(listaResultante, elementoL1);
            }
        }
    }
    return listaResultante;
}

// d. Que retorne los promedios de ambas listas.
char * promediosListas(Lista lista1, Lista lista2) {
    char *promedios = malloc(sizeof(char) * 200);
    if (promedios == NULL) {
        return NULL;
    }

    float sumaL1 = 0;
    int countL1 = 0;
    Iterador iterL1 = iterador(lista1);
    while (hay_siguiente(iterL1)) {
        TipoElemento elementoL1 = siguiente(iterL1);
        if (elementoL1) {
            sumaL1 += elementoL1->clave;
            countL1++;
        }
    }
    float promedioL1 = (countL1 > 0) ? sumaL1 / countL1 : 0;

    float sumaL2 = 0;
    int countL2 = 0;
    Iterador iterL2 = iterador(lista2);
    while (hay_siguiente(iterL2)) {
        TipoElemento elementoL2 = siguiente(iterL2);
        if (elementoL2) {
            sumaL2 += elementoL2->clave;
            countL2++;
        }
    }
    float promedioL2 = (countL2 > 0) ? sumaL2 / countL2 : 0;

    sprintf(promedios, "L1: %.4f, L2: %.4f", promedioL1, promedioL2);
    return promedios;
}

// e. Que retorne el valor maximo de ambas listas y su posicion ordinal.
char * maximoPosicionListas(Lista lista1, Lista lista2) {
    char * maxYPos = malloc(sizeof(char) * 200);
     if (maxYPos == NULL) {
        return NULL;
    }

    int maximoL1 = 0;
    int posOrdinalL1 = -1;

    if (!l_es_vacia(lista1)) {
        TipoElemento primer_elemL1 = l_recuperar(lista1, 1);
        if (primer_elemL1) {
            maximoL1 = primer_elemL1->clave;
            posOrdinalL1 = 1;
        }

        int i = 1;
        Iterador iterL1 = iterador(lista1);
        while (hay_siguiente(iterL1)) {
            TipoElemento elementoL1 = siguiente(iterL1);
            if (elementoL1) {
                 if (elementoL1->clave > maximoL1) {
                    maximoL1 = elementoL1->clave;
                    posOrdinalL1 = i;
                }
            }
            ++i;
        }
    }

    int maximoL2 = 0;
    int posOrdinalL2 = -1;

    if (!l_es_vacia(lista2)) {
         TipoElemento primer_elemL2 = l_recuperar(lista2, 1);
        if (primer_elemL2) {
            maximoL2 = primer_elemL2->clave;
            posOrdinalL2 = 1;
        }

        int i = 1;
        Iterador iterL2 = iterador(lista2);
        while (hay_siguiente(iterL2)) {
            TipoElemento elementoL2 = siguiente(iterL2);
             if (elementoL2) {
                 if (elementoL2->clave > maximoL2) {
                    maximoL2 = elementoL2->clave;
                    posOrdinalL2 = i;
                }
            }
            ++i;
        }
    }

    if (l_es_vacia(lista1) && l_es_vacia(lista2)) {
         sprintf(maxYPos, "[Ambas listas vacias]");
    } else if (l_es_vacia(lista1)) {
         sprintf(maxYPos, "[L1 vacia], [L2 Max: %d, pos %d]", maximoL2, posOrdinalL2);
    } else if (l_es_vacia(lista2)) {
         sprintf(maxYPos, "[L1 Max: %d, pos %d], [L2 vacia]", maximoL1, posOrdinalL1);
    }
    else {
        sprintf(maxYPos, "[L1 Max: %d, pos %d], [L2 Max: %d, pos %d]", maximoL1, posOrdinalL1, maximoL2, posOrdinalL2);
    }

    return maxYPos;
}

int run_ejercicio_2() {
    int opcion1, opcion2;
    Lista lista1 = NULL;
    Lista lista2 = NULL;
    int tamanio_manual;

    printf("========== CARGAR LISTA1 ==========\n");
    printf("Seleccione metodo de carga:\n");
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
        lista1 = rellenarListaConOpcion(tamanio_manual, true); // true = permitir cero
    }

    printf("\n========== CARGAR LISTA2 ==========\n");
    printf("Seleccione metodo de carga:\n");
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
        int tamanio_manual;
         printf("Ingrese el tamanio deseado para la LISTA 2 (entre 1 y 100):\n");
         tamanio_manual = leer_entero();
          while (tamanio_manual <= 0 || tamanio_manual > 100) {
            printf("Tamanio invalido. Por favor, ingrese un numero entre 1 y 100: ");
            tamanio_manual = leer_entero();
        }
        lista2 = rellenarListaConOpcion(tamanio_manual, true); // true = permitir cero
    }

    printf("\n=============================\n");
    printf("LISTA1 - ");
    l_mostrar(lista1);
    printf("LISTA2 - ");
    l_mostrar(lista2);

    printf("\na. VALORES DE L1 QUE NO ESTAN EN L2\n");
    Lista listaA = valoresFaltantesL1(lista1, lista2);
    if (listaA != NULL && l_es_vacia(listaA)) {
        printf("No hay valores que cumplan (lista vacia).\n");
    } else if (listaA != NULL) {
       l_mostrar(listaA);
    } else {
         printf("Error al crear la lista resultado para a).\n");
    }
  

    printf("\nb. VALORES DE L2 QUE NO ESTAN EN L1\n");
    Lista listaB = valoresFaltantesL2(lista1, lista2);
    if (listaB != NULL && l_es_vacia(listaB)) {
        printf("No hay valores que cumplan (lista vacia).\n");
    } else if (listaB != NULL) {
       l_mostrar(listaB);
    } else {
         printf("Error al crear la lista resultado para b).\n");
    }
 
    printf("\nc. VALORES COMUNES EN AMBAS LISTAS\n");
    Lista listaC = valoresComunes(lista1, lista2);
    if (listaC != NULL && l_es_vacia(listaC)) {
        printf("No hay valores que cumplan (lista vacia).\n");
    } else if (listaC != NULL) {
        l_mostrar(listaC);
    } else {
         printf("Error al crear la lista resultado para c).\n");
    }
  
    printf("\nd. PROMEDIOS DE AMBAS LISTAS\n");
    char *promedios = promediosListas(lista1, lista2);
    if (promedios != NULL) {
        printf("%s", promedios);
        printf("\n");
        free(promedios);
    } else {
         printf("Error al calcular los promedios.\n");
    }

    printf("\ne. POSICION MAXIMA DE CADA LISTA CON POSICION ORDINAL\n");
    char * maxYPos = maximoPosicionListas(lista1, lista2);
    if (maxYPos != NULL) {
        printf("%s", maxYPos);
        printf("\n");
        free(maxYPos);
    } else {
         printf("Error al calcular el maximo y posicion.\n");
    }

 
    return 0;
}
