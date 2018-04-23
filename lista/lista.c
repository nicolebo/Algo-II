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


struct lista_iter {
    nodo_t* actual;
    nodo_t* anterior;
    lista_t* lista;
};

lista_t* lista_crear(void) {
    lista_t* lista = malloc(sizeof(lista_t));
    if(lista == NULL) return NULL;
    lista->primero = NULL;
    lista->ultimo = NULL;
    lista->largo = 0;
    return lista;
}

bool lista_esta_vacia(const lista_t *lista) {
    return lista->largo == 0;
}

bool lista_insertar_primero(lista_t *lista, void *dato) {
    nodo_t* nodo = malloc(sizeof(nodo_t));
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
    nodo_t* nodo = malloc(sizeof(nodo_t));
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

void* lista_borrar_primero(lista_t *lista) {
    if (lista_esta_vacia(lista)) return NULL;
    void* dato = lista->primero->dato;
    nodo_t* proximo_primero = lista->primero->siguiente;
    free(lista->primero);
    lista->primero = proximo_primero;
    lista->largo -= 1;
    return dato;
}

void* lista_ver_primero(const lista_t* lista) {
    if (lista_esta_vacia(lista)) return NULL;
    return lista->primero->dato;
}

void* lista_ver_ultimo(const lista_t* lista) {
    if (lista_esta_vacia(lista)) return NULL;
    return lista->ultimo->dato;
}

size_t lista_largo(const lista_t* lista) {
    return lista->largo;
}

void lista_destruir(lista_t* lista, void destruir_dato(void*)) {
    while (lista->primero != NULL)
    {
        void* dato = lista->primero->dato;
        if(destruir_dato != NULL)
        {
            destruir_dato(dato);
        }
        nodo_t* siguiente = lista->primero->siguiente;
        free(lista->primero);
        lista->primero = siguiente;
    }
    free(lista);
}

/* ******************************************************************
 *                    ITERADOR
 * *****************************************************************/


void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra) {
    if(lista_esta_vacia(lista)) return;
    nodo_t* actual = lista->primero;
    while(actual){
        if(!visitar(actual->dato, extra)){
            return;
        }
        actual = actual->siguiente;
    }
}

lista_iter_t* lista_iter_crear(lista_t* lista) {
    lista_iter_t* iterador = malloc(sizeof(lista_iter_t));
    if(iterador == NULL) return NULL;
    iterador->lista = lista;
    iterador->actual = lista->primero;
    iterador->anterior = NULL;
    return iterador;
}

bool lista_iter_avanzar(lista_iter_t* iter) {
    if (iter->actual == NULL) return false;
    iter->anterior = iter->actual;
    iter->actual = iter->actual->siguiente;
    return true;
}

void* lista_iter_ver_actual(const lista_iter_t* iter) {
    if (iter->actual == NULL) return NULL;
    return iter->actual->dato;
}

bool lista_iter_al_final(const lista_iter_t* iter) {
    return(iter->actual == NULL);
}

void lista_iter_destruir(lista_iter_t* iter) {
    free(iter);
}

bool lista_iter_insertar(lista_iter_t* iter, void* dato) {
    if (iter== NULL) return false;
    nodo_t* nodo = malloc(sizeof(nodo_t));
    if (nodo == NULL) return false;

    nodo->siguiente = iter->actual;
    nodo->dato = dato;

    if(lista_esta_vacia(iter->lista))
    {
        iter->lista->primero = nodo;
        iter->lista->ultimo = nodo;
    } else if (lista_iter_al_final(iter)) {
        iter->lista->ultimo = nodo;
        iter->anterior->siguiente = nodo;
    } else if (iter->anterior == NULL) {
        iter->lista->primero = nodo;
    } else {
        iter->anterior->siguiente = nodo;
        nodo->siguiente = iter->actual;
    }
    iter->actual =  nodo;
    iter->lista->largo += 1;
    return true;
}

void* lista_iter_borrar(lista_iter_t* iter) {
    if (iter->actual == NULL) return NULL;
    void* dato = iter->actual->dato;
    nodo_t* proximo_actual = iter->actual->siguiente;

    if (iter->anterior == NULL) {
        iter->lista->primero = proximo_actual;
    } else if (proximo_actual == NULL) {
        iter->anterior->siguiente = NULL;
        iter->lista->ultimo = iter->anterior;
        proximo_actual = iter->anterior;
    } else {
        iter->anterior->siguiente = proximo_actual;
    }
    free(iter->actual);
    iter->actual = proximo_actual;
    iter->lista->largo -= 1;
    return dato;
}
