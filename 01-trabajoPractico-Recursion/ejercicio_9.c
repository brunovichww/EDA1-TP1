#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "tp_1_recursividad.h"
#include "formulas_menu_tp1.h"
/*
Escribir una función recursiva que implemente el método que se describe para saber si
un número es divisible por 7. Se separa la primera cifra de la derecha, se la multiplica
por 2, y se resta este producto de lo que queda a la izquierda y así sucesivamente,
hasta que el resultado obtenido sea un número menor a 70. El número original será
múltiplo de 7 si el resultado da cero o múltiplo de 7.

Ejemplos:
32291 -> 1x2=2.
3229 - 2 =
3227 -> 7x2=14.
322 - 14 =
308 -> 8x2=16
30 - 16 =
14 -> Múltiplo de 7
divisiblePor7 (32291) => verdadero
110 -> 0 x 2 = 0
11 – 0 =
11 -> No múltiplo de 7
divisiblePor7 (110) => falso

*/


int ultimoDigito(int *bn){
	int n = *bn; //copia variable para operar dentro de la funcion
	if (n < 0){ //para poder trabajar con negativos
		n = -n;
		}
	int buffer = n/10; //ej: si es 123, devuelve 12
	*bn = buffer; //modifica el argumento de la función para que almacene
				  //los digitos de la izquierda
	return (n-10*buffer); //ej: 123 -> buffer = 12 -> 123 -12*10 = 123-120 = 3
	}




bool divisiblePor7(int n){
	//caso base
	if (n <= 70){
		if ( n%7 == 0){
				return true;
		}else{
			return false;
		}
	}else{
		int u = ultimoDigito(&n);
		return divisiblePor7(n-u*2);
	}
}

int valIngresoNum(){
			/*
			 * Función que valida el ingreso de solo números por teclado
			*/
			char snum[100]; //almacenará el string del usuario
			long int num; //almacenará el num convertido a entero
			char *pEnd; //almacenará lo que no sea entero en el str de entrada
			scanf("%s",snum);
			num = strtol(snum,&pEnd,10);
			while (strcmp(pEnd,"") != 0){
					printf("Debe ingresar un número entero. Intentelo nuevamente.\n");
					scanf("%s",snum);
					num = strtol(snum,&pEnd,10);
			}
			return num;
	}


void ejecutar_ejercicio_9(){
	bool seguir = true;
	while(seguir){
	printf("Ingresá un número entero y te diré si es divisible por 7:");
	int n = valIngresoNum();
	if (divisiblePor7(n)){
		printf("%d es divisible por 7.\n",n);
		}
	else{
		printf("%d NO es divisible por 7.\n",n);
		}
	printf("¿Querés probar con otro número?(No(0)  Si(1): ");
	n = valIngresoNum();
	if (n == 0){seguir = false;}else{seguir = true;};
	}
}
