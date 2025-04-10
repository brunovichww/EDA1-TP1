#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Se tiene una cadena que representa una onda digital de señales L (Low) y H (High). Se
pide obtener recursivamente la onda que representa utilizando “_” y “|”.

Ejemplos:
ondaDigital (“LHLHL”) =>
 “_ | ̄ |_| ̄ |_”
ondaDigital (“HHHHLLLLHHHHHLLHH”) => “ ̄  ̄  ̄  ̄ | _ _ _ _ | ̄  ̄  ̄  ̄  ̄ | _ _ |  ̄  ̄ ”
*/


// Función para limpiar pantalla según sistema operativo
void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

char* auxOndaDigital(char strsenial[], char stronda[], int pos){
	/*
	 * Leer la primera letra y ver si es H o L o \0, guardar el char _ o ¯ en
	 * un str y volver a llamar a la funcion con la posición que tiene que leer 
	 * (0 por defecto) así puede seguir leyendo el proximo caracter.
	 *  comparar el caracter actual i con el i-1, si son distintos incluir agregar
	 * al string el |.
	 * */
	 //caso base
	char buffer = strsenial[pos];
	if (buffer == '\0') {
		return stronda;
	 }else{
	 //caso recursivo
		if ( (buffer != strsenial[pos-1]) && (pos >= 1) ){
			strcat(stronda,"|");
		}
		if (buffer == 'H'){
			strcat(stronda,"¯");
		} else {if (buffer == 'L'){
					strcat(stronda,"_");
				}else{
					strcpy(stronda,"Error en la señal de entrada.\n");
					return "Error en la señal de entrada.\n";
				}
			}
		return auxOndaDigital(strsenial, stronda, pos+1);
	} 
}
	
	
/*	
int main() {
    char senial[100];
    char stronda[200];

    while (1) {
        limpiarPantalla();

        // Entrada de la señal
        printf("Ingrese la señal (solo H o L, Enter para salir): ");
        fgets(senial, sizeof(senial), stdin);

        // Quitar salto de línea
        senial[strcspn(senial, "\n")] = '\0';

        // Salir si solo se presionó Enter
        if (strlen(senial) == 0) {
            printf("Salida del programa.\n");
            break;
        }

        // Inicializar stronda vacío
        stronda[0] = '\0';

        // Llamar a la función recursiva
        auxOndaDigital(senial, stronda, 0);
        printf("Onda digital generada: %s\n", stronda);

        // Esperar antes de continuar
        printf("\nPresione Enter para continuar...");
        getchar();
    }

    return 0;
}
*/