//#define _POSIX_C_SOURCE 200809L //getline
//#include "pila.h"
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//
//int main(void) {
//    size_t capacidad = 0;
//    ssize_t leidos;
//    char* linea = NULL;
//
//    while ((leidos = getline(&linea, &capacidad, stdin)) > 0) {
//        bool comilla_simple = false;
//        int contador = 0;
//        int syntax = 1;
//        pila_t* pila = pila_crear();
//
//        while (linea[contador] != '\0') {
//            void* dato = NULL;
//            if (linea[contador] == '\'') comilla_simple = !comilla_simple;
//            if(comilla_simple){
//                contador += 1;
//                continue;
//            }
//            switch(linea[contador]) {
//                case '(':
//                    pila_apilar(pila, &"(");
//                    break;
//                case '[':
//                    pila_apilar(pila, &"[");
//                    break;
//                case '{':
//                    pila_apilar(pila, &"{");
//                    break;
//                case ')':
//                    dato = pila_desapilar(pila);
//                    if(strcmp(dato, "(" ) != 0) syntax=0;
//                    break;
//                case ']':
//                    dato = pila_desapilar(pila);
//                    if(strcmp(dato, "[" ) != 0) syntax = 0;
//                    break;
//                case '}':
//                    dato = pila_desapilar(pila);
//                    if(strcmp(dato, "{" ) != 0) syntax = 0;
//                    break;
//            }
//            contador += 1;
//        }
//
//        if (!pila_esta_vacia(pila) || comilla_simple) syntax = 0;
//        pila_destruir(pila);
//        syntax == 1 ? fprintf(stdout, "OK ") : fprintf(stdout, "Error ");
//        linea = NULL;
//    }
//    free(linea);
//    return 1;
//}