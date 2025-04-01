#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

bool es_palindromo(char palabra[],int i, int f){
	if(i>=f){return true;} //caso base
	if(palabra[i]==palabra[f]){ //caso recursivo
		return es_palindromo(palabra,i+1,f-1);
	}else{
		return false;}
	}

int main() {
  // Casos base
  assert(es_palindromo("", 0, -1) == true);
  assert(es_palindromo("a", 0, 0) == true);

  // Palíndromos
  assert(es_palindromo("abba", 0, 3) == true);
  assert(es_palindromo("radar", 0, 4) == true);
  //assert(es_palindromo("anita lava la tina", 0, 16) == true); // Este caso no se cumple si no se ignoran los espacios

  // No palíndromos
  assert(es_palindromo("hello", 0, 4) == false);
  assert(es_palindromo("abda", 0, 3) == false);

  // Casos con mayúsculas y minúsculas (sensible a mayúsculas y minúsculas)
  assert(es_palindromo("Madam", 0, 4) == false);
  assert(es_palindromo("madam", 0, 4) == true);

  // Casos con caracteres especiales
  assert(es_palindromo("12321", 0, 4) == true);
  assert(es_palindromo("!@#$%", 0, 4) == false);

  // Casos de prueba adicionales
  assert(es_palindromo("a", 0, 0) == true);
  assert(es_palindromo("aa", 0, 1) == true);
  assert(es_palindromo("aba", 0, 2) == true);
  assert(es_palindromo("abc", 0, 2) == false);
  assert(es_palindromo("abcd", 0, 3) == false);

  //prueba de git con este comentario

  
  printf("Todas las pruebas pasaron correctamente.\n");
  return 0;
}
