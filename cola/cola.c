#include "cola.h"
#include <stdlib.h>

/* Definición del struct nodo*/
typedef struct nodo{
    void* dato;
    struct nodo* siguiente;
} nodo_t;

/* Definición del struct cola*/
struct cola {
    nodo_t* primero;
    nodo_t* ultimo;
};

nodo_t* crear_nodo(void *dato);

// Crea una cola.
// Post: devuelve una nueva cola vacía.
cola_t* cola_crear(void) {
    cola_t* cola = malloc(sizeof(cola_t));
    if(cola == NULL) return NULL;
    cola->primero = NULL;
    return cola;
}

// Destruye la cola. Si se recibe la función destruir_dato por parámetro,
// para cada uno de los elementos de la cola llama a destruir_dato.
// Pre: la cola fue creada. destruir_dato es una función capaz de destruir
// los datos de la cola, o NULL en caso de que no se la utilice.
// Post: se eliminaron todos los elementos de la cola.
void cola_destruir(cola_t *cola, void destruir_dato(void*)){
    while (!cola_esta_vacia(cola))
    {
        void* dato = cola_desencolar(cola);
        if(destruir_dato != NULL)
        {
            destruir_dato(dato);
        }
    }
    free(cola);
}

// Devuelve verdadero o falso, según si la cola tiene o no elementos encolados.
// Pre: la cola fue creada.
bool cola_esta_vacia(const cola_t *cola){
    return cola->primero == NULL;
}

// Agrega un nuevo elemento a la cola. Devuelve falso en caso de error.
// Pre: la cola fue creada.
// Post: se agregó un nuevo elemento a la cola, valor se encuentra al final
// de la cola.
bool cola_encolar(cola_t *cola, void* valor){
    nodo_t* nuevo_nodo = crear_nodo(valor);
    if (cola_esta_vacia(cola)) {
        cola->primero = nuevo_nodo;
    } else {
        cola->ultimo->siguiente = nuevo_nodo;
    }
    cola->ultimo = nuevo_nodo;
    return true;
}

// Obtiene el valor del primer elemento de la cola. Si la cola tiene
// elementos, se devuelve el valor del primero, si está vacía devuelve NULL.
// Pre: la cola fue creada.
// Post: se devolvió el primer elemento de la cola, cuando no está vacía.
void* cola_ver_primero(const cola_t *cola){
    return (cola_esta_vacia(cola) ? NULL : cola->primero->dato);
}

// Saca el primer elemento de la cola. Si la cola tiene elementos, se quita el
// primero de la cola, y se devuelve su valor, si está vacía, devuelve NULL.
// Pre: la cola fue creada.
// Post: se devolvió el valor del primer elemento anterior, la cola
// contiene un elemento menos, si la cola no estaba vacía.
void* cola_desencolar(cola_t *cola){
    if (cola_esta_vacia(cola)) return NULL;
    if(cola->primero ==  cola->ultimo) cola->ultimo = NULL;
    nodo_t* viejo_primero = cola->primero;
    void * dato = viejo_primero->dato;
    cola->primero = cola->primero->siguiente;
    free(viejo_primero);

    return dato;
}

nodo_t* crear_nodo(void *dato) {
    nodo_t* nodo = malloc(sizeof(nodo_t));
    if (nodo == NULL) return NULL;
    nodo->siguiente = NULL;
    nodo->dato = dato;
    return nodo;
}