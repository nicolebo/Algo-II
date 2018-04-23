#include "lista.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#define CANT_ELEMENTOS 10000
#define VARIABLE 10



/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void prueba_crear_lista()
{
    lista_t* lista = lista_crear();
    print_test("Creacion de la lista", lista == NULL ? false : true);
    lista_destruir(lista, NULL);

}
void prueba_inserto_primero_lista(int variable)
{
    lista_t* lista = lista_crear();
    lista_insertar_primero(lista, &variable);
    print_test("enlisto correctamente el primer elemento", lista_ver_primero(lista) == &variable);
    lista_destruir(lista, NULL);
}
void prueba_inserto_ultimo_lista(int variable) {
    lista_t *lista = lista_crear();
    lista_insertar_ultimo(lista, &variable);
    print_test("enlisto correctamente el ultimo elemento", lista_ver_ultimo(lista) == &variable);
    lista_destruir(lista, NULL);
}
void prueba_desenlisto_primer_elemento(int variable)
{
    lista_t* lista = lista_crear();
    lista_insertar_primero(lista, &variable);
    print_test("desenlisto el primer elemento", lista_borrar_primero(lista) == &variable);
    lista_destruir(lista, NULL);
}
void prueba_enlisto_primer_elementos_y_desenlisto_primer_elementos_x_elementos(int cantidad_elementos)
{
    lista_t* lista = lista_crear();

    int array_posiciones[cantidad_elementos];
    bool ok = true;

    for (int i = 0; i < cantidad_elementos; ++i) {
        array_posiciones[i] = i;
    }

    for (int i = 0; i < cantidad_elementos; ++i) {
        ok = lista_insertar_primero(lista, &array_posiciones[i]);
    }

    print_test("se enlisto correctacmente?", ok);

    print_test("El primer elemento es correcto?", lista_ver_primero(lista) == &array_posiciones[cantidad_elementos-1]);
    print_test("El ultimo elemento es correcto?", lista_ver_ultimo(lista) == &array_posiciones[0]);

    for (int j = 0; j < cantidad_elementos; ++j) {
        lista_borrar_primero(lista);
    }
    print_test("se desenlistaron correctacmente?", lista_esta_vacia(lista));

    lista_destruir(lista, NULL);
}

void prueba_enlisto_ultimo_elementos_y_desenlisto_ultimo_elementos_x_elementos(int cantidad_elementos)
{
    lista_t* lista = lista_crear();

    int array_posiciones[cantidad_elementos];
    bool ok = true;

    for (int i = 0; i < cantidad_elementos; ++i) {
        array_posiciones[i] = i;
    }

    for (int i = 0; i < cantidad_elementos; ++i) {
        ok = lista_insertar_ultimo(lista, &array_posiciones[i]);
    }

    print_test("se enlisto correctacmente?", ok);

    print_test("El primer elemento es correcto?", lista_ver_primero(lista) == &array_posiciones[0]);
    print_test("El ultimo elemento es correcto?", lista_ver_ultimo(lista) == &array_posiciones[cantidad_elementos-1]);

    for (int j = 0; j < cantidad_elementos; ++j) {
        lista_borrar_primero(lista);
    }
    print_test("se desenlistaron correctacmente?", lista_esta_vacia(lista));

    lista_destruir(lista, NULL);
}

void prueba_primer_elemento_nulo()
{
    lista_t* lista = lista_crear();
    lista_insertar_ultimo(lista, NULL);
    print_test("Deberia tener un elemento", !lista_esta_vacia(lista));
    lista_destruir(lista, NULL);
}

void pruebo_desenlisto_en_lista_vacia()
{
    lista_t* lista = lista_crear();
    print_test("la lista estaba vacia", lista_borrar_primero(lista) == NULL);
    lista_destruir(lista, NULL);

}

void pruebo_ver_primer_elemento_en_lista_vacia()
{
    lista_t* lista = lista_crear();
    print_test("primer elemento de la lista estaba vacia", lista_ver_primero(lista) == NULL);
    lista_destruir(lista, NULL);
}

void pruebo_ver_ultimo_elemento_en_lista_vacia()
{
    lista_t* lista = lista_crear();
    print_test("ultimo elemento de la lista estaba vacia", lista_ver_ultimo(lista) == NULL);
    lista_destruir(lista, NULL);
}

void prueba_enlisto_y_desenlisto_para_ver_lista(int variable)
{
    lista_t* lista = lista_crear();
    lista_insertar_primero(lista, &variable);
    lista_borrar_primero(lista);
    print_test("desenlisto", lista_borrar_primero(lista) == NULL);
    print_test("ver primero", lista_ver_primero(lista) == NULL);
    lista_destruir(lista, NULL);
}

//Pruebas del iterador
void prueba_inserto_elemento_con_iterador(int variable) {
    lista_t* lista = lista_crear();
    bool ok = true;
    lista_iter_t* iter = lista_iter_crear(lista);
    ok = lista_iter_insertar(iter, &variable);
    print_test("se enlisto correctacmente?", ok);
    print_test("se inserto un elemento en el actual del iterador y de la lista", lista_iter_ver_actual(iter) == &variable);
    lista_iter_destruir(iter);
    lista_destruir(lista, NULL);
}

void prueba_inserto_elemento_al_final_con_iterador(int variable) {
    lista_t* lista = lista_crear();
    bool ok = true;
    lista_iter_t* iter = lista_iter_crear(lista);
    for (int i = 0; i < variable; ++i) {
        ok = lista_iter_insertar(iter, &variable);
    }
    print_test("se enlisto correctacmente?", ok);

    print_test("se inserto un elemento en el actual del iterador y de la lista", lista_iter_ver_actual(iter) == &variable);

    for (int i = 0; i < variable; ++i) {
        lista_iter_avanzar(iter);
    }

    ok = lista_iter_insertar(iter, &variable);
    print_test("se enlisto correctacmente?", ok);

    print_test("se inserto un elemento en el ultimo del iterador y de la lista", lista_iter_ver_actual(iter) == lista_ver_ultimo(lista));


    size_t largo_antes_eliminar = lista_largo(lista);
    lista_iter_borrar(iter);
    print_test("se elimino el elemento del final?", lista_largo(lista) == largo_antes_eliminar-1);

    lista_iter_destruir(iter);
    lista_destruir(lista, NULL);
}
void prueba_inserto_elemento_en_medio_con_iterador(int variable) {
    lista_t* lista = lista_crear();
    bool ok = true;
    lista_iter_t* iter = lista_iter_crear(lista);
    for (int i = 0; i < variable; ++i) {
        ok = lista_iter_insertar(iter, &variable);
    }
    print_test("se enlisto correctacmente?", ok);

    print_test("se inserto un elemento en el actual del iterador y de la lista", lista_iter_ver_actual(iter) == &variable);
    size_t largo_anterior = lista_largo(lista);
    for (int i = 0; i < variable/2; ++i) {
        lista_iter_avanzar(iter);
    }

    ok = lista_iter_insertar(iter, &variable);
    print_test("se enlisto correctacmente?", ok);

    print_test("se inserto un elemento en el medio del iterador y de la lista", lista_largo(lista) == largo_anterior+1);

    lista_iter_borrar(iter);
    print_test("se elimino un elemento en el medio del iterador y de la lista", lista_largo(lista) == largo_anterior);

    lista_iter_destruir(iter);
    lista_destruir(lista, NULL);
}
void prueba_remover_elemento_iterador_creado(int variable) {
    lista_t* lista = lista_crear();
    lista_iter_t* iter = lista_iter_crear(lista);
    lista_iter_insertar(iter, &variable);
    print_test("se enlisto correctacmente?", lista_largo(lista) != 0);
    lista_iter_borrar(iter);
    print_test("se inserto un elemento en el medio del iterador y de la lista", lista_largo(lista) == 0);
    lista_iter_destruir(iter);
    lista_destruir(lista, NULL);
}
void pruebas_lista_alumno() {
    prueba_crear_lista();
    prueba_inserto_primero_lista(VARIABLE);
    prueba_inserto_ultimo_lista(VARIABLE);
    prueba_desenlisto_primer_elemento(VARIABLE);
    prueba_enlisto_primer_elementos_y_desenlisto_primer_elementos_x_elementos(CANT_ELEMENTOS);
    prueba_enlisto_ultimo_elementos_y_desenlisto_ultimo_elementos_x_elementos(CANT_ELEMENTOS);
    prueba_primer_elemento_nulo();
    pruebo_desenlisto_en_lista_vacia();
    pruebo_ver_primer_elemento_en_lista_vacia();
    pruebo_ver_ultimo_elemento_en_lista_vacia();
    prueba_enlisto_y_desenlisto_para_ver_lista(VARIABLE);
    prueba_inserto_elemento_con_iterador(VARIABLE);
    prueba_inserto_elemento_al_final_con_iterador(VARIABLE);
    prueba_inserto_elemento_en_medio_con_iterador(VARIABLE);
    prueba_remover_elemento_iterador_creado(VARIABLE);
}
