#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
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

