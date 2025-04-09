#include <stdio.h>
#include <stdlib.h>

/*
Dados los números enteros m y n, construir una función recursiva que devuelva el
cociente de ambos, calculando el mismo mediante restas sucesivas. Se deberá tener
en cuenta que en el caso de que la división no sea exacta, se devolverán hasta 5 cifras
decimales (si es necesario).
Ejemplos:
division (10,2) => 5
division (22,3) => 7,33333
*/

float pot(int dec){
	//calcula la potencia de 10 necesaria para desplazar los decimales
	float potenciaDeDiez = 1;
	for (int i = 0; i < dec; i++) {
		potenciaDeDiez *= 0.1f; // Multiplicar por 0.1 es equivalente a dividir por 10
    }
    return potenciaDeDiez;
}

void auxDivisionEntera(int a, int b, int *cociente, int *resto){
	//caso base
	if(a < b){
		*cociente += 0;
		*resto = a;
	}else{
		//caso recursivo
		a -= b;
		*cociente += 1;
		auxDivisionEntera(a, b, cociente, resto);
	}
}


float auxDivisionDecimal(int a, int b, float res, int dec){
	/*
	 toma los dos números a y b. tambien tiene que tomar una variable 
	 llamada res que almacene los resultados 
	 y otra variable llamada dec que indique la cantidad de digitos
	 decimales que se busca determinar (arranca en 0 y sube a 4).
	 creo cociente y resto para almacenar los resultados
	 divide con auxDivisionEntera
	 revisa si resto es cero, si es así corta
	 sino, revisa si la cantidad de decimales es 5, si es así corta
	 sino, vuelve premultiplica a por 10
	 y repite los pasos anteriores.
	 */
	//Creo e inicializo variables auxiliares
	int cociente = 0;
	int resto = 0;
	//realizo la división
	auxDivisionEntera(a, b, &cociente, &resto);
	//caso base
	if(resto == 0 || dec == 5){
		float potenciaDeDiez = pot(dec);
		res += cociente*potenciaDeDiez;
		return res;
	}else{
		//caso recursivo
		float potenciaDeDiez = pot(dec);
		//se multiplica por potencia de diez para desplazar el nuevo 
		//dígito calculado a la posición correcta en los decimales
		res += cociente*potenciaDeDiez;
		a = resto;
		return auxDivisionDecimal( 10*a, b, res, dec+1);
	}
}

float division(int a, int b){
	int signo = -1;
	if ((a > 0 && b > 0) || (a < 0 && b < 0)){signo = 1;};
	a = abs(a);
	b = abs(b);
	float resultado = auxDivisionDecimal(a, b, 0, 0);
	return signo*resultado;
	}
	
	
int main(){
    int a, b;

    do {
        printf("Ingrese el dividendo (a): ");
        scanf("%d", &a);

        printf("Ingrese el divisor (b) (ingrese 0 para salir): ");
        scanf("%d", &b);

        if (b != 0) {
            printf("%d dividido %d es:\n", a, b);
            float resultado = division(a, b);
            printf("%.5f\n", resultado);
        } else {
            printf("Saliendo del programa.\n");
        }
    } while (b != 0);

    return 0;
}

