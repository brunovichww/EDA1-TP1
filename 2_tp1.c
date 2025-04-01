/***
 Dados dos números enteros m y n, construir una función recursiva que devuelva el
producto de ambos, calculando el mismo como sumas sucesivas. Esto es:
	m*n=m+m+...+m, n veces.
Ejemplos:
	producto(5, 3) => 15
	producto (10, 4) => 40
 ***/

#include <stdio.h>

int producto(int m, int n){
	//n es el número de veces que se tiene que sumar el número m
	
	//caso base
	if(n==1){return m;}
	if(n==-1){return 0-m;}
	if (n==0 || m==0){return 0;}
	
	//caso recursivo
	if(n>1){return m + producto(m,n-1);}
	else{return -m+producto(m,n+1);}
}
	
#include <assert.h>
#include <stdio.h> // Incluimos stdio.h para printf

int main() {
  // Pruebas básicas
  assert(producto(2, 3) == 6);
  printf("Test 1: Pasó\n");
  assert(producto(5, 0) == 0);
  printf("Test 1: Pasó\n");
  assert(producto(0, 8) == 0);
  printf("Test 1: Pasó\n");
  assert(producto(1, 1) == 1);
  printf("Test 1: Pasó\n");

  // Pruebas con números negativos
  assert(producto(-2, 4) == -8);
  printf("Test 1: Pasó\n");
  assert(producto(3, -5) == -15);
  printf("Test 2: Pasó\n");
  assert(producto(-1, -1) == 1);
  printf("Test 3: Pasó\n");

  // Prueba con números grandes (probando que no haya overflow)
  assert(producto(1000, 1000) == 1000000);
  printf("Test 4: Pasó\n");

  // Prueba con uno de los argumentos igual a 1
  assert(producto(7, 1) == 7);
  printf("Test 5: Pasó\n");
  assert(producto(1, 9) == 9);
  printf("Test 6: Pasó\n");

  return 0;
}
