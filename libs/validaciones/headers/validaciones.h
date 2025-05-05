#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <stdbool.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <errno.h>
#include <ctype.h> 


// funcion que elimina los espacios de un string ingresado por teclado
void strtrim(char *cadena);

// funcion para leer un entero por teclado
int leer_entero();

// funcion para leer un entero por teclado que no sea cero
int leer_entero_sin_cero();

// funcion para leer un flotante por teclado
float leer_flotante();

// funcion para leer un entero por teclado limitado por el minimo y maximo grado disponible (validacion)
int leer_grado();

// funcion para leer un flotante por teclado que no pueda ser negativo o 0 (validacion)
float leer_intervalo();


#endif // VALIDACIONES_H

