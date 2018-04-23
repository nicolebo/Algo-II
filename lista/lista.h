#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdbool.h>


/* ******************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/

typedef struct lista lista_t;

typedef struct lista_iter lista_iter_t;

/* ******************************************************************
 *                    PRIMITIVAS DE LA LISTA
 * *****************************************************************/

// Crea una lista.
// Post: devuelve una nueva lista vacía.
lista_t *lista_crear(void);

// Devuelve verdadero o falso, según si la lista tiene o no elementos enlistados.
// Pre: la lista fue creada.
bool lista_esta_vacia(const lista_t *lista);

// Agrega un nuevo primer elemento a la lista. Devuelve falso en caso de error.
// Pre: la lista fue creada.
// Post: se agregó un el primer elemento a la lista
bool lista_insertar_primero(lista_t *lista, void *dato);

// Agrega un nuevo elemento a la lista. Devuelve falso en caso de error.
// Pre: la lista fue creada.
// Post: se agregó un elemento a la lista valor se encuentra al final de la lista.
bool lista_insertar_ultimo(lista_t *lista, void *dato);

// borra el primer elemento de la lista y se devuelve su valor, si está vacía, devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el valor del elemento borrado de la lista
void *lista_borrar_primero(lista_t *lista);

// Obtiene el valor del primer elemento de la lista. Si la lista tiene
// elementos, se devuelve el valor del primero, si está vacía devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el primer elemento de la lista, cuando no está vacía.
void *lista_ver_primero(const lista_t *lista);

// Obtiene el valor del ultimo elemento de la lista. Si la lista tiene
// elementos, se devuelve el valor del ultimo, si está vacía devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el ultimo elemento de la lista, cuando no está vacía.
void *lista_ver_ultimo(const lista_t* lista);

// Obtiene el largo de la lista.
// Pre: la lista fue creada.
// Post: se devolvió el largo de la lista.
size_t lista_largo(const lista_t *lista);

// Destruye la lista. Si se recibe la función destruir_dato por parámetro,
// para cada uno de los elementos de la lista llama a destruir_dato.
// Pre: la lista fue creada. destruir_dato es una función capaz de destruir
// los datos de la lista, o NULL en caso de que no se la utilice.
// Post: se eliminaron todos los elementos de la lista.
void lista_destruir(lista_t *lista, void destruir_dato(void *));


/* ******************************************************************
 *                    PRIMITIVAS DEL ITERADOR INTERNO
 * *****************************************************************/

// Itera toda la lista de una.
// Pre: la lista fue creada.
// Post: Itera toda la lista o hasta que la funcion visitar lo detenga.
void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra);


/* ******************************************************************
 *                    PRIMITIVAS DEL ITERADOR EXTERNO
 * *****************************************************************/

// Crea un iterador de la lista.
// Post: devuelve un nuevo iterador de la lista.
lista_iter_t *lista_iter_crear(lista_t *lista);

//Avanza a la siguiente nodo de la lista.
// Pre: el iterador de la lista fue creada.
// Post: Devuelve verdadero o falso, según si la lista avanza o o no un elemento enlistados.
bool lista_iter_avanzar(lista_iter_t *iter);

// Obtiene el valor del elemento actual del iterador de la lista. Si la lista tiene
// un elemento, se devuelve el valor del actual, si está vacía devuelve NULL.
// Pre: el iterador de la lista fue creada.
// Post: se devolvió el elemento actual del iterador de la lista, cuando no está vacía.
void *lista_iter_ver_actual(const lista_iter_t *iter);

// Se fija si la el iterador esta en el final de la lista
// Pre: el iterador de la lista fue creada.
// Post: se devolvera true si el iterador esta al final de la lista, en caso contrario se devuelve false.
bool lista_iter_al_final(const lista_iter_t *iter);

// Destruye la lista.
// Pre: la lista fue creada.
// Post: se eliminaron todos los elementos de la lista.
void lista_iter_destruir(lista_iter_t *iter);


// Inserta un elemento en la posicion actual del iterador, si no tiene elementos, devuelve false
// Pre: el iterador de la lista fue creada.
// Post: inserta un nuevo elemento en la posicion actual del iterador y devuelve el true en caso de exito
bool lista_iter_insertar(lista_iter_t *iter, void *dato);

// Borra el elemento actual del iterador, si no tiene elementos, devuelve null
// Pre: el iterador de la lista fue creada.
// Post: Borra el elemento actual del iterador y devuelve el dato del elemento.
void *lista_iter_borrar(lista_iter_t *iter);

#endif // LISTA_H