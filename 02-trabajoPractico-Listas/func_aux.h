#ifndef FUNC_AUX_H
#define FUNC_AUX_H
#include "../libs/listas/headers/listas.h" 
#include <stdbool.h> 

// Funcion para rellenar una lista con valores aleatorios
Lista rellenarListaRandom();

// Funcion para cargar una lista manualmente con opcion de permitir o no el valor cero
// Recibe el tamanio deseado y un flag booleano (true para permitir 0, false para no permitir 0)
// Crea una nueva lista y la retorna.
Lista rellenarListaConOpcion(int tamanio, bool permitir_cero);

#endif // FUNC_AUX_H
