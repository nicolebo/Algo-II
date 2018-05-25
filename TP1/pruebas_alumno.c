#include "strutil.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/
void prueba_separar_cadena(char* cadena, char separador, int tamanio)
{
	char** arreglo = split(cadena, separador);
	int i = 0;
	while ((char*)arreglo[i] != NULL) {
		i += 1;
	}
	print_test("Cantidad de palabras", i == tamanio);
	free_strv(arreglo);
}

void prueba_unir(char** arr, char unificador)
{
	char* nuevo_arreglo = join(arr, unificador);
	printf("Palabra es %s \n", nuevo_arreglo);
}

void pruebas_lista_alumno() {
	prueba_separar_cadena("", ',', 1);
	prueba_separar_cadena("hola que tal", ' ', 3);
 	prueba_separar_cadena("holaas, ,dsadasd",',', 3);
 	prueba_separar_cadena("abc,,def", ',', 3);
 	prueba_separar_cadena(",abc,def", ',', 3);
 	prueba_separar_cadena("abc,def,", ',', 3);
 	prueba_separar_cadena("", ',', 1);
 	prueba_separar_cadena(",", ',', 2);

//	char **palabras = split(",", ',');
//	prueba_unir(palabras,',');
	char* arr[] = {"cadena", "otra cadena", "123", NULL};
	prueba_unir(arr,',');
	char* arr2[] = {"", NULL};
 	prueba_unir(arr2,',');
 	char* arr3[] = {"abc", NULL};
 	prueba_unir(arr3,',');
	char* arr4[] = {" ", " ", " ", " ", " ", NULL};
	prueba_unir(arr4,',');
}
