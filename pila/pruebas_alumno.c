#include "pila.h"
#include "testing.h"
#include <stddef.h>


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void prueba_crear_pila()
{
    pila_t* pila = pila_crear();
    print_test("Creacion de la pila", pila == NULL ? false : true);
    pila_destruir(pila);

}
void prueba_apilar()
{
    int variable = 1;
    pila_t* pila = pila_crear();
    bool apilo = pila_apilar(pila, &variable);
    print_test("Apilar un elemento", apilo);
    pila_destruir(pila);

}
void prueba_desapilar()
{
    int variable = 1;
    pila_t* pila = pila_crear();
    pila_apilar(pila, &variable);
    pila_desapilar(pila);
    print_test("desapilar un elemento", pila_esta_vacia(pila) ? true : false);
    pila_destruir(pila);
}
void prueba_apilo_y_desapilo_x_elementos()
{
    int elementos = 100;
    int variable = 87;
    pila_t* pila = pila_crear();

    for (int i = 0; i < elementos; ++i) {
        pila_apilar(pila, &variable);
    }
    print_test("se apilaron correctacmente?", pila_esta_vacia(pila) ? false : true);

    for (int j = 0; j < elementos; ++j) {
        pila_desapilar(pila);
    }
    print_test("se desapilaron correctacmente?", pila_esta_vacia(pila) ? true : false);

    pila_destruir(pila);

}

void prueba_apilo_elemento_nulo()
{
    pila_t* pila = pila_crear();
    pila_apilar(pila, NULL);
    print_test("El tope deberia ser null", pila_ver_tope(pila) == NULL ? true : false);
    pila_destruir(pila);


}
void pruebo_desapilar_en_pila_vacia()
{
    pila_t* pila = pila_crear();
    print_test("la pila estaba vacia", pila_desapilar(pila) == NULL ? true : false);
    pila_destruir(pila);


}
void pruebo_vet_topo_en_pila_vacia()
{
    pila_t* pila = pila_crear();
    print_test("tope de pila estaba vacia", pila_ver_tope(pila) == NULL ? true : false);
    pila_destruir(pila);
}
void pruebo_pila_creada_esta_vacia()
{
    pila_t* pila = pila_crear();
    print_test("pila esta vacia", pila_esta_vacia(pila) ? true : false);
    pila_destruir(pila);
}


void pruebas_caso_apilar_y_desapilar_para_ver_pila()
{
    int variable = 1;
    pila_t* pila = pila_crear();
    pila_apilar(pila, &variable);
    pila_desapilar(pila);
    print_test("desapilar", pila_desapilar(pila) == NULL ? true : false);
    print_test("ver tope", pila_ver_tope(pila) == NULL ? true : false);
    pila_destruir(pila);
}

void pruebas_pila_alumno() {
    pila_t* ejemplo = NULL;

    print_test("Puntero inicializado a NULL", ejemplo == NULL);
    prueba_crear_pila();
    prueba_apilar();
    prueba_desapilar();
    prueba_apilo_elemento_nulo();
    prueba_apilo_y_desapilo_x_elementos();
    pruebo_desapilar_en_pila_vacia();
    pruebo_vet_topo_en_pila_vacia();
    pruebo_pila_creada_esta_vacia();
    pruebas_caso_apilar_y_desapilar_para_ver_pila();
}
