#include <stdio.h>
#include <stdlib.h>
#include "../libs/listas/headers/listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"

//---------------------------------------------------
// Encabezados
//---------------------------------------------------
Lista MultiplosDe(Lista L, int m);


//---------------------------------------------------
// MAIN PRINCIPAL
//---------------------------------------------------
void main()
{
    int i = 0;
    TipoElemento X;
    Lista L = l_crear();

    printf("---------- Ejercicio 2 de Listas ----------------!\n");

    // Leno la lista
    while (l_es_llena(L) != true) {
        i++;
        X = te_crear(i);
        l_agregar(L, X);
    }

    // Muestro la lista
    l_mostrar(L);

    // Muestro los multiplos de 3
    Lista lm3 = MultiplosDe(L, 3);
    printf("Multiplos de 3 ..... \n");
    l_mostrar(lm3);

    // Muestro la lista
    printf("\n");
    l_mostrar(L);

    system("pause");
    return;
}


//---------------------------------------------------------------------------------
// Funciones del Ejercicio 2
//---------------------------------------------------------------------------------
Lista MultiplosDe(Lista l, int m){
    TipoElemento x, x1;
    Lista lm = l_crear();
    Iterador ite = iterador(l);
    // Ahora la recorro
    while (hay_siguiente(ite)) {
        x = siguiente(ite);
        if ((x->clave % m) == 0) {
            x1 = te_crear(x->clave);
            l_agregar(lm, x1);
        }
    }
    return lm;
};
