
/***
Generar un algoritmo recursivo que calcule el k-ésimo número de la serie de Fibonacci.
	Ejemplos:
		terminoSeridFibonacci (1) => 1
		terminoSeridFibonacci (5) => 8
 * ***/
 
#include <stdio.h>
#include <stdlib.h>

int terminoSeridFibonacci(int k){
	//caso base
	if(k==0 || k==1){return 1;};
	
	//caso recursivo
	return terminoSeridFibonacci(k-1)+ terminoSeridFibonacci(k-2);
	}
	
/*
int main() {
    char str[10];
    printf("Ingrese un número: ");
    fgets(str, sizeof(str), stdin);
    
    char *endptr;
    long num = strtol(str, &endptr, 10);
	
    if (*endptr != '\0') {
        printf("Error: No se pudo convertir completamente. Parte inválida: %s\n", endptr);
    } else {
        printf("Número convertido: %ld\n", num);
    }

    return 0;
}	
*/	
	
//int main(){
	
	//int kt = terminoSeridFibonacci(8);
	//int a = 0;
	//char str[10];
	//char *endptr;
    //int num;
    
	//while(a==0){
	//printf("Ingrese un número: ");
    //fgets(str, sizeof(str), stdin);
	//num = strtol(str, &endptr, 10);
	
	//if (*endptr != '\0'){
		//printf("debe ingresar un valor numérico.\n");
		//}
	//}
//}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
int main() {
    char str[10];
    char *endptr;
    int num;
    
    while (1) {
        printf("Ingrese un número: ");
        fgets(str, sizeof(str), stdin);
        num = strtol(str, &endptr, 10);

        // Verificar si no se pudo convertir nada
        if (str == endptr) {
            printf("Debe ingresar un valor numérico.\n");
            continue;
        }

        // Verificar que después del número solo haya espacios o el fin de la línea
        while (*endptr != '\0' && *endptr != '\n') {
            if (!isspace((unsigned char)*endptr)) {
                printf("Debe ingresar solo números sin caracteres adicionales.\n");
                break;
            }
            endptr++;
        }

        // Si llegó aquí, la entrada es válida
        printf("Número ingresado: %d\n", num);
        break;
    }

    return 0;
}

*/


