#define _POSIX_C_SOURCE 200809L //getline
#include <stdlib.h>
#include <stdio.h>


FILE* abrir_archivo(char* nombre){
   if(nombre == NULL) return NULL;
   FILE* archivo = fopen(nombre, "r");
   if(archivo == NULL) return NULL;
   return archivo;
}

int comparar(char* linea1, char* linea2) {
   int iguales = 1;
   int largo=0;

   while (linea1[largo] != '\0' && linea2[largo] != '\0') {
       if (linea1[largo] != linea2[largo]) iguales = 0;
       largo += 1;
   }

   if(linea1[largo] != '\0' || linea2[largo] != '\0') iguales = 0;
   return iguales;
}

int main(int argc, char *argv[]){
   if (argc != 3){
       fprintf(stderr, " Error, se ha ingresado mal la cantidad de parametros que recibe la funcion diff, requiere dos nombres de archivos \n");
       return 0;
   }
   char* linea1 = NULL;
   char* linea2 = NULL;
   size_t capacidad1 = 0;
   size_t capacidad2 = 0;
   FILE* primer_archivo = abrir_archivo(argv[1]);
   FILE* segundo_archivo = abrir_archivo(argv[2]);

   if (primer_archivo == NULL || segundo_archivo == NULL){
       fprintf(stderr, "Error, revice el nombre de los archivos");
       return 0;
   }

   ssize_t leidos1 = getline(&linea1, &capacidad1, primer_archivo);
   ssize_t leidos2 = getline(&linea2, &capacidad2, segundo_archivo);
   int contador_lineas = 0;

   while (leidos1 != -1 || leidos2 != -1) {
 
       if(leidos1 != -1 && leidos2 == -1) {
           fprintf(stdout, "Diferencia en linea %d, %s | %s", contador_lineas, linea1, "");
       } else if (leidos1 == -1 && leidos2 != -1) {
           fprintf(stdout, "Diferencia en linea %d, %s | %s", contador_lineas, "", linea2);
       } else {
           int iguales = comparar(linea1, linea2);
           if (iguales == 0) fprintf(stdout, " Diferencia en linea %d, %s | %s", contador_lineas, linea1, linea2);
       }
       contador_lineas += 1;
       leidos1 = getline(&linea1, &capacidad1, primer_archivo);
       leidos2 = getline(&linea2, &capacidad2, segundo_archivo);
   }
   free(linea1);
   free(linea2);
   fclose(primer_archivo);
   fclose(segundo_archivo);
   return 1;
}