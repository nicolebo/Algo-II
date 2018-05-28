//#define _POSIX_C_SOURCE 200809L //getline
//#include "cola.h"
//#include <stdlib.h>
//#include <stdio.h>
//
//int main(int argc, char *argv[]) {
//    if (argc != 2){
//        fprintf(stderr, "Cantidad de parametros erronea \n");
//        return 0;
//    }
//
//    long int n_posiciones = atoi(argv[1]);
//
//    if (n_posiciones == 0){
//        fprintf(stderr, "Tipo de parametro incorrecto \n");
//        return 0;
//    }
//
//    cola_t* cola = cola_crear();
//    size_t capacidad = 0;
//    ssize_t leidos;
//    char* linea = NULL;
//    int contador = 0;
//
//    while ((leidos = getline(&linea, &capacidad, stdin)) > 0) {
//        cola_encolar(cola, linea);
//
//        if (contador == n_posiciones) {
//            free(cola_desencolar(cola));
//        }else {
//            contador += 1;
//        }
//        linea = NULL;
//    }
//    free(linea);
//
//    while (!cola_esta_vacia(cola)) {
//        char* variable = cola_desencolar(cola);
//        fprintf(stdout, "%s", variable);
//        free(variable);
//    }
//    cola_destruir(cola, NULL);
//}