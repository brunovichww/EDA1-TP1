#include <math.h> 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 
#include "tp_2_listas.h" 
#include "../libs/listas/headers/listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h" 
#include "../libs/validaciones/headers/validaciones.h" 


void mostrar_polinomio(Lista lista);

// funcion que recibe una lista vacia y la carga con los terminos del polinomio
// Los elementos se agregan con el grado en 'clave' y el coeficiente real
// apuntado por "valor" (como string).
void hacerPolinomio(Lista list) {
    int grado = 0;
    float entrada = 0;
    printf("========== CARGAR POLINOMIO ==========\n");
    printf("Ingrese el grado del polinomio (rango de 0 a 9): ");
    grado = leer_grado();

    while ((grado < 0) || (grado > 9)) {
        printf("El grado del polinomio no puede ser negativo o mayor a 9. Intentelo de nuevo.\n");
        grado = leer_grado();
    }

    for (int i = grado; i >= 0; i--) {
        if (i == 0) {
            printf("Ingrese el coeficiente del polinomio para el termino independiente (grado 0). ");
        } else {
            printf("Ingrese el coeficiente del polinomio para el grado %d. ", i);
        }
        entrada = leer_flotante();

        char *str_valor = (char*) malloc(sizeof(char) * 20);
        if (str_valor == NULL) {
             printf("Error: No se pudo asignar memoria para el coeficiente.\n");
             continue;
        }
        sprintf(str_valor, "%f", entrada);

        TipoElemento elemento = te_crear_con_valor(i, str_valor);
        if (elemento == NULL) {
             printf("Error: No se pudo crear el elemento de la lista.\n");
             free(str_valor);
             continue;
        }

        l_agregar(list, elemento);
    }
}


float evaluarPoliomio(Lista list, float x) {
    int clave = 0;
    float resultado = 0;
    float valor = 0;
    Iterador iter = iterador(list);
    while (hay_siguiente(iter)) {
        TipoElemento elemento = siguiente(iter);
        if (!elemento) continue;

        valor = atof(elemento->valor);
        clave = elemento->clave;
        resultado += valor * pow(x, clave);
    }
    return resultado;
}

// funcion para chequear si se supera el limite de tamanio de la lista resultado del rango
static bool supera_limite_lista_rango(double minX, double maxX, double intervaloI) {
    if (intervaloI <= 0.0) {
        printf("Error: El intervalo debe ser mayor que cero.\n");
        return true;
    }

    int contadorElementos = 0;
    double tolerancia = 1e-9;

    for (double currentX = minX; currentX <= maxX + tolerancia; currentX += intervaloI) {
        contadorElementos++;
        if (contadorElementos > 100) {
            return true;
        }
        if (contadorElementos < 0) {
             printf("Error: El numero de elementos excede el rango de un entero.\n");
             return true;
        }
    }
    return false;
}

// funcion que dado un rango de valores de 'x' y un valor de intervalo 'I',
// retorne una lista con los valores de 'y' o 'F(x)'.
Lista calcularRango(Lista list, double x, double y, double sumando) {
    if (l_es_vacia(list)) {
         printf("El polinomio esta vacio. No se puede calcular el rango.\n");
         return l_crear();
    }

    double minX = x;
    double maxX = y;
    double intervaloI = sumando;

    if (!supera_limite_lista_rango(minX, maxX, intervaloI)) {
        Lista listaResultado = l_crear();
        int claveNuevaLista = 1;
        double tolerancia = 1e-9;

        for (double currentX = minX; currentX <= maxX + tolerancia; currentX += intervaloI) {
            if (l_es_llena(listaResultado)) {
                printf("La lista resultado ha alcanzado su limite maximo. No se pueden agregar mas elementos.\n");
                break;
            }

            float resultado_float = evaluarPoliomio(list, (float)currentX);

            char *str_valor = (char*) malloc(sizeof(char) * 20);
            if (str_valor == NULL) {
                 printf("Error: No se pudo asignar memoria para el resultado del rango.\n");
                 break;
            }
            sprintf(str_valor, "%f", resultado_float);

            TipoElemento elemento = te_crear_con_valor(claveNuevaLista, str_valor);
             if (elemento == NULL) {
                 printf("Error: No se pudo crear el elemento de la lista resultado.\n");
                 free(str_valor);
                 break;
            }

            l_agregar(listaResultado, elemento);
            claveNuevaLista++;
        }
         printf("Calculo de rango completado.\n");
        return listaResultado;
    } else {
        printf("Debido a que la cantidad de elementos supera al tamanio maximo de la lista resultado, no se puede completar la accion.\n");
        return l_crear();
    }
}

// funcion que muestra un polinomio basado en la lista ingresada
void mostrar_polinomio(Lista lista) {
    printf("------------------\n");
    if (l_es_vacia(lista)) {
        printf("El polinomio esta vacio.\n");
        return;
    } else {
        float valor = 0;
        Iterador iter = iterador(lista);
        printf("El polinomio ingresado es: ");
        bool primer_termino_impreso = false;

        while (hay_siguiente(iter)) {
            TipoElemento elemento = siguiente(iter);
            if (!elemento) continue;

            valor = atof(elemento->valor);
            int grado = elemento->clave;

            if (valor == 0.0 && l_longitud(lista) > 1) {
                continue;
            }

            if (valor > 0 && primer_termino_impreso) {
                printf(" + ");
            } else if (valor < 0) {
                 printf(" - ");
                 valor = -valor;
            } else if (primer_termino_impreso && valor == 0.0) {
                 continue;
            }

            if (valor != 1.0 || grado == 0) {
                 if (!(primer_termino_impreso == false && valor == 1.0 && grado > 0)) {
                     printf("%.2f", valor);
                 }
            }

            if (grado > 1) {
                 if (valor != 0.0 || l_longitud(lista) == 1) {
                     printf("X^%d", grado);
                 }
            } else if (grado == 1) {
                 if (valor != 0.0 || l_longitud(lista) == 1) {
                     printf("X");
                 }
            }

            primer_termino_impreso = true;
        }

        if (l_longitud(lista) == 1) {
             TipoElemento unico_elemento = l_recuperar(lista, 1);
             if (unico_elemento && atof(unico_elemento->valor) == 0.0) {
                 printf("0.00");
             }
        }

        printf("\n------------------\n");
    }
}

int run_ejercicio_5() {
    Lista lista_polinomio = l_crear();
    hacerPolinomio(lista_polinomio);
    mostrar_polinomio(lista_polinomio);

    double minX_rango = 0;
    double maxX_rango = 0;
    double intervaloI_rango = 0;
    printf("\n========== CALCULAR POLINOMIO EN UN RANGO ==========\n");

    while (minX_rango >= maxX_rango) {
        printf("Recuerde que el valor minimo de X debe ser menor al valor maximo de X.\n");
        printf("Ingrese el valor MINIMO de X para el rango: ");
        minX_rango = (double)leer_flotante();
        printf("Ingrese el valor MAXIMO de X para el rango: ");
        maxX_rango = (double)leer_flotante();
    }

    printf("Ingrese el valor del intervalo I (mayor que 0 y menor o igual a 500): ");
    intervaloI_rango = (double)leer_intervalo();
    printf("\nCalculando valores del polinomio en el rango [%.2f, %.2f] con intervalo %.2f...\n", minX_rango, maxX_rango, intervaloI_rango);
    Lista listaResultadoRango = calcularRango(lista_polinomio, minX_rango, maxX_rango, intervaloI_rango);

    printf("------------------ \n");
    if (listaResultadoRango != NULL && !l_es_vacia(listaResultadoRango)) {
        printf("Valores de F(x) en el rango:\n");
        printf("|     x     |     y     |\n");
        printf("|-----------|-----------|\n");

        Iterador iterResultado = iterador(listaResultadoRango);
        double currentX_display = minX_rango;

        while(hay_siguiente(iterResultado)) {
            TipoElemento elemResultado = siguiente(iterResultado);
             if (elemResultado) {
                 printf("| %9.2f | %9.2f |\n", currentX_display, atof(elemResultado->valor));
             }
             currentX_display += intervaloI_rango;
        }
         printf("|-----------|-----------|\n");

    } else if (listaResultadoRango != NULL && l_es_vacia(listaResultadoRango)){
         printf("La lista de resultados del rango esta vacia (posiblemente por tamanio invalido o error).\n");
    }

    return 0;
}
