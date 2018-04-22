#include "lista.h"
#include <stdlib.h>

/* Definición del struct nodo*/
typedef struct nodo{
    void* dato;
    struct nodo* siguiente;
} nodo_t;


struct lista {
    nodo_t* primero;
    nodo_t* ultimo;
    size_t largo;
};

lista_t *lista_crear(void) {
    lista_t lista = malloc(sizeof(lista_t));
    if(lista == NULL) return NULL;
    lista->primero = NULL;
    lista->ultimo = NULL;
    lista.largo = 0;
}

bool lista_esta_vacia(const lista_t *lista) {
    return lista->largo == 0;
}

bool lista_insertar_primero(lista_t *lista, void *dato) {
    nodo_t nodo = malloc(sizeof(nodo_t));
    if (nodo == NULL) return false;
    nodo->dato = dato;
    if(lista_esta_vacia(lista)) {
        nodo->siguiente = NULL;
        lista->ultimo = nodo;
    } else {
        nodo->siguiente = lista->primero;
    }
    lista->primero = nodo;
    lista->largo += 1;
    return true;
}

bool lista_insertar_ultimo(lista_t *lista, void *dato) {
    nodo_t nodo = malloc(sizeof(nodo_t));
    if (nodo == NULL) return false;
    nodo->dato = dato;
    nodo->siguiente = NULL;
    if(lista_esta_vacia(lista)) {
        lista->primero = nodo;
    } else {
        lista->ultimo->siguiente = nodo;
    }
    lista->ultimo = nodo;
    lista->largo += 1;
    return true;
}

// borra el primer elemento de la lista y se devuelve su valor, si está vacía, devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el valor del elemento borrado de la lista
void *lista_borrar_primero(lista_t *lista) {
    if (lista_esta_vacia(lista)) return NULL;
    void* dato = lista->primero->dato;
    nodo_t proximo_primero = lista->primero->siguiente;
    free(lista->primero);
    lista->primero = proximo_primero;
    lista->largo -= 1;
    return dato;
}

void *lista_ver_primero(const lista_t *lista) {
    if (lista_esta_vacia(lista)) return NULL;
    return lista->primero->dato;
}

void *lista_ver_ultimo(const lista_t* lista) {
    if (lista_esta_vacia(lista)) return NULL;
    return lista->ultimo->dato;
}

size_t lista_largo(const lista_t *lista) {
    return lista->largo;
}

// Destruye la lista. Si se recibe la función destruir_dato por parámetro,
// para cada uno de los elementos de la lista llama a destruir_dato.
// Pre: la lista fue creada. destruir_dato es una función capaz de destruir
// los datos de la lista, o NULL en caso de que no se la utilice.
// Post: se eliminaron todos los elementos de la lista.
void lista_destruir(lista_t *lista, void destruir_dato(void *));