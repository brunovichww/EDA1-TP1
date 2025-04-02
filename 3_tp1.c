
/***
Generar un algoritmo recursivo que calcule el k-ésimo número de la serie de Fibonacci.
	Ejemplos:
		terminoSeridFibonacci (1) => 1
		terminoSeridFibonacci (5) => 8
 * ***/
 
#include<stdio.h>

int terminoSeridFibonacci(int k){
	//caso base
	if(k==0 || k==1){return 1;};
	
	//caso recursivo
	return terminoSeridFibonacci(k-1)+ terminoSeridFibonacci(k-2);
	}
	
int main(){
	int kt = terminoSeridFibonacci(8);
	printf("%d",kt);
	}

