#include "strutil.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>


//funcion que recibe un texto, la posicion de inicio en donde toma la palabra y la posicion de fin.
char* armar_palabra(const char* texto, size_t inicio, size_t fin);

char** split(const char* str, char sep) {
    if(sep == '\0') return NULL;
    //Quiero saber la cantidad de palabras para poder crear el arreglo dinamico
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
 	while(posicion < largo) {
 		if(sep == str[posicion]) {
 			char* palabra = armar_palabra(str, posicion_separador_anterior, posicion);
 			arreglo[palabras_agregadas] = palabra;
 			palabras_agregadas += 1;
 			posicion_separador_anterior = posicion + 1;
 		}
 		posicion += 1;
 		if(posicion == largo){
 			char* palabra = armar_palabra(str, posicion_separador_anterior, posicion);
 			arreglo[palabras_agregadas] = palabra;
 			palabras_agregadas += 1;
 		}
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


//  * Devuelve una cadena, allocada dinámicamente, resultado de unir todas las
//  * cadenas del arreglo terminado en NULL ‘strv’.
//  *
//  * Quien llama a la función toma responsabilidad de la memoria dinámica de la
//  * cadena devuelta. La función devuelve NULL si no se pudo allocar memoria.
 
// char* join(char** strv, char sep) {

// }

// /*
//  * Libera un arreglo dinámico de cadenas, y todas las cadenas que contiene.
//  */
// void free_strv(char* strv[]) {

// }
