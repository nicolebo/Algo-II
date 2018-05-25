#include "strutil.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

char* armar_palabra(const char* texto, size_t inicio, size_t fin);

char** split(const char* str, char sep) {
   if(sep == '\0') return NULL;
   size_t contador_palabras = 1;
   int largo = 0;
   while(str[largo] != '\0') {
	if(sep == str[largo]) contador_palabras += 1;
	largo += 1;
   }

   char** arreglo = malloc(sizeof(char*) * contador_palabras);

   if (arreglo == NULL) return NULL;
   size_t posicion_separador_anterior = 0;
   size_t palabras_agregadas = 0;
   size_t posicion = 0;

   while(posicion <= largo) {
	if(sep == str[posicion] || posicion == largo) {
		char* palabra = armar_palabra(str, posicion_separador_anterior, posicion);
		arreglo[palabras_agregadas] = palabra;
		palabras_agregadas += 1;
		posicion_separador_anterior = posicion + 1;
	}
	posicion += 1;
   }
   arreglo[palabras_agregadas] = NULL;
   return arreglo;
}

char* armar_palabra(const char* texto, size_t inicio, size_t fin) {
	char* palabra = malloc(sizeof(char) * (fin - inicio + 1));
	if (palabra == NULL) return NULL;
	int posiciones = 0;
	for (size_t i = inicio; i < fin; ++i)
	{
		palabra[posiciones] = texto[i];
		posiciones += 1;
	};
	return palabra;
}

char* join(char** strv, char sep) {
	if(sep == '\0') return NULL;
   	int cant_palabras = 0;
	int largo_total = 0;

   	while(strv[cant_palabras] != NULL) {
		int largo = 0;
		while(strv[cant_palabras][largo] != '\0'){
			largo += 1;
   			largo_total += 1;
		}
   		cant_palabras += 1;
   	}

   	char* cadena = malloc(sizeof(char) * (cant_palabras + largo_total));
	int i = 0;
	int posicion_cadena = 0;

   	while(strv[i] != NULL) {
		int j = 0;
		while(strv[i][j] != '\0') {
			cadena[posicion_cadena] = strv[i][j];
			posicion_cadena += 1;
			j += 1;
		}
		if (posicion_cadena <= largo_total) {
			cadena[posicion_cadena] = sep;
			posicion_cadena += 1;
		}
		i += 1;
   }
   return cadena;
}
void free_strv(char* strv[]) {
	int i = 0;
	while(strv[i] != NULL) {
		free(strv[i]);
		i += 1;
	}
	free(strv);
}