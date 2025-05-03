#include <stdio.h>
#include <stdlib.h>
// #include "listas.h"
// #include "tipo_elemento.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"

//---------------------------------------------------
// Encabezados
//---------------------------------------------------
bool ListasIguales(Lista L1, Lista L2);


//---------------------------------------------------
// MAIN PRINCIPAL
//---------------------------------------------------
void main()
{
    int i = 0;
    TipoElemento X;
    Lista L1 = l_crear();
    Lista L2 = l_crear();

    printf("---------- Ejercicio 2 de Listas ----------------!\n");

    // Leno la lista 1
    while (i <= 10) {
        i++;
        X = te_crear(i);
        l_agregar(L1, X);
    }


    // Leno la lista 2
    i=0;
    while (i <= 10) {
        i++;
        X = te_crear(i);
        l_agregar(L2, X);
    }

    X = te_crear(i);
    l_insertar(L1, X, 1);

    i++;
    X = te_crear(i);
    l_insertar(L2, X, 1);

    // Muestro la lista
    l_mostrar(L1);
    l_mostrar(L2);


    // Muestro la lista
    printf("\n");
    printf("%s\n", (ListasIguales(L1, L2)) ? "Listas iguales." : "Listas distintas");

    system("pause");

}


//---------------------------------------------------------------------------------
// Funciones del Ejercicio 2
//---------------------------------------------------------------------------------
bool ListasIguales(Lista L1, Lista L2){
    bool resultado = true;
    Iterador I1 = iterador(L1);
    Iterador I2 = iterador(L2);
    TipoElemento x1, x2;
    if (l_longitud(L1)==l_longitud(L2)){
        while (resultado && hay_siguiente(I1))
        {
            x1 = siguiente(I1);
            x2 = siguiente(I2);
            resultado = (x1->clave == x2->clave);
        }
        
    }else{resultado = false;}

    return resultado;
};
