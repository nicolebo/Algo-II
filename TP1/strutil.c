//#define _POSIX_C_SOURCE 200809L
//#include "strutil.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//char* armar_palabra(const char* texto, size_t inicio, size_t fin);
//
//char** split(const char* str, char sep) {
//    if(sep == '\0') return NULL;
//
//	size_t contador_palabras = 1;
//	int largo = 0;
//
//    char* s = strdup(str);
//
//	while(s[largo] != '\0') {
//		if(sep == s[largo]) contador_palabras += 1;
//		largo += 1;
//	}
//
//    char** arreglo = malloc(sizeof(char*) * (contador_palabras+1));
//
//	if (arreglo == NULL) return NULL;
//
//	size_t posicion_separador_anterior = 0, palabras_agregadas = 0, posicion = 0;
//
//	while(palabras_agregadas != contador_palabras) {
//        if(sep == str[posicion] || posicion == largo) {
//            arreglo[palabras_agregadas] = armar_palabra(str, posicion_separador_anterior, posicion);
//            palabras_agregadas += 1;
//            posicion_separador_anterior = posicion + 1;
//        }
//        posicion += 1;
//    }
//	free(s);
//	arreglo[palabras_agregadas] = NULL;
//	return arreglo;
//}
//
//char* armar_palabra(const char* texto, size_t inicio, size_t fin) {
//    char* palabra = malloc(sizeof(char) * (fin - inicio + 1));
//    if (palabra == NULL) return NULL;
//    int posiciones = 0;
//    for (size_t i = inicio; i < fin; ++i)
//    {
//        palabra[posiciones] = texto[i];
//        posiciones += 1;
//    }
//    palabra[posiciones] = '\0';
//    return palabra;
//}
//
//char* join(char** strv, char sep) {
//	if(sep == '\0') return NULL;
//
//	int cant_palabras = 0, largo_total = 0;
//
//	while(strv[cant_palabras] != NULL) {
//		int largo = 0;
//
//		while(strv[cant_palabras][largo] != '\0') {
//			largo += 1;
//			largo_total += 1;
//		}
//		cant_palabras += 1;
//	}
//
//	char* cadena = malloc(sizeof(char) * (largo_total + cant_palabras + 1));
//    if (cadena == NULL) return NULL;
//	cadena[0] = '\0';
//
//    int i = 0, posiciones_nueva_cadena = 0;
//
//    while(strv[i] != NULL) {
//        int j = 0;
//        while(strv[i][j] != '\0') {
//            cadena[posiciones_nueva_cadena] = strv[i][j];
//            posiciones_nueva_cadena += 1;
//            j += 1;
//        }
//        cadena[posiciones_nueva_cadena] = sep;
//        posiciones_nueva_cadena += 1;
//        i += 1;
//	}
//    if(i == 0) {
//        cadena[posiciones_nueva_cadena] = '\0';
//    }else {
//        cadena[posiciones_nueva_cadena - 1] = '\0';
//    }
//	return cadena;
//}
//
//
//void free_strv(char* strv[]) {
//	int i = 0;
//	while(strv[i] != NULL) {
//		free(strv[i]);
//		i += 1;
//	}
//	free(strv);
//}