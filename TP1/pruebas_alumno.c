#include "strutil.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>



/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/
void prueba_separar_cadena(char* cadena, char separador, int tamanio)
{
	char** fafa;
	fafa = split(cadena, separador);
	int i = 0;
	while ((char*)fafa[i] != NULL) {
		printf("%d Palabra es %s \n", i + 1, (char*)fafa[i]);
		i += 1;
	}		
		print_test("Cantidad de palabras", i == tamanio);
}

void pruebas_lista_alumno() {
	prueba_separar_cadena("hola que tal", ' ', 3);
	prueba_separar_cadena("holaas, ,dsadasd",',', 3);
	prueba_separar_cadena("", ' ', 0);
}
