#include <stdlib.h>
#include <stdio.h>
#include "../libs/listas/headers/listas.h"

Lista Factorizacion(int n);

int main(void){
    int numero;
    Lista f;
    do{
        printf("Ingrese el número a factorizar: ");
        scanf("%d", &numero);
        f = Factorizacion(numero);
        if(!l_es_vacia(f)){
            printf("Factorización en primos de %d: \n", numero);
            l_mostrar(f);
        }else printf("Error al factorizar el numero.\n");
    }while(numero != 0);

    system("pause");
    return 0;
}




Lista Factorizacion(int n){
    Lista l = l_crear();
    bool blAg = true;
    TipoElemento X;
    int factor = 2;
    while (n > 1){
        while ((n % factor) == 0) {
            X = te_crear(factor);
            blAg = blAg && l_agregar(l, X);
            n = n / factor;    
        }   
        factor += 1;
    }
    if(!blAg) l = l_crear();
    return l;
}


