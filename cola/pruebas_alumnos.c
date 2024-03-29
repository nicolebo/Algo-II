#include "cola.h"
#include "testing.h"
#include <stddef.h>
#define CANT_ELEMENTOS 10000



/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void prueba_crear_cola()
{
    cola_t* cola = cola_crear();
    print_test("Creacion de la cola", cola == NULL ? false : true);
    cola_destruir(cola, NULL);

}
void prueba_encolar()
{
    int variable = 1;
    cola_t* cola = cola_crear();
    bool encolo = cola_encolar(cola, &variable);
    print_test("encolo un elemento", encolo);
    cola_destruir(cola, NULL);

}
void prueba_desencolar()
{
    int variable = 1;
    cola_t* cola = cola_crear();
    cola_encolar(cola, &variable);
    cola_desencolar(cola);
    print_test("desencolar un elemento", cola_esta_vacia(cola));
    cola_destruir(cola, NULL);
}
void prueba_encolo_y_desencolo_x_elementos(int cantidad_elementos)
{
    cola_t* cola = cola_crear();

    int array_posiciones[cantidad_elementos];
    bool ok = true;

    for (int i = 0; i < cantidad_elementos; ++i) {
        array_posiciones[i] = i;
    }

    for (int i = 0; i < cantidad_elementos; ++i) {
        ok = cola_encolar(cola, &array_posiciones[i]);
    }

    print_test("se apilaron correctacmente?", ok);

    print_test("El primero es correcto?", cola_ver_primero(cola) == &array_posiciones[0]);

    for (int j = 0; j < cantidad_elementos; ++j) {
        cola_desencolar(cola);
    }
    print_test("se desencolaron correctacmente?", cola_esta_vacia(cola));

    cola_destruir(cola, NULL);

}

void prueba_encolo_elemento_nulo()
{
    cola_t* cola = cola_crear();
    cola_encolar(cola, NULL);
    print_test("Deberia tener un elemento", !cola_esta_vacia(cola));
    cola_destruir(cola, NULL);


}
void pruebo_desencolar_en_cola_vacia()
{
    cola_t* cola = cola_crear();
    print_test("la cola estaba vacia", cola_desencolar(cola) == NULL ? true : false);
    cola_destruir(cola, NULL);

}
void pruebo_ver_primer_elemento_en_cola_vacia()
{
    cola_t* cola = cola_crear();
    print_test("primer elemento de la cola estaba vacia", cola_ver_primero(cola) == NULL);
    cola_destruir(cola, NULL);
}
void pruebo_cola_creada_esta_vacia()
{
    cola_t* cola = cola_crear();
    print_test("cola esta vacia", cola_esta_vacia(cola));
    cola_destruir(cola, NULL);
}

void pruebas_caso_encolo_y_desencolo_para_ver_cola()
{
    int variable = 1;
    cola_t* cola = cola_crear();
    cola_encolar(cola, &variable);
    cola_desencolar(cola);
    print_test("desencolar", cola_desencolar(cola) == NULL ? true : false);
    print_test("ver primero", cola_ver_primero(cola) == NULL ? true : false);
    cola_destruir(cola, NULL);
}

void pruebas_cola_alumno() {
    prueba_crear_cola();
    prueba_encolar();
    prueba_desencolar();
    prueba_encolo_y_desencolo_x_elementos(CANT_ELEMENTOS);
    prueba_encolo_elemento_nulo();
    pruebo_desencolar_en_cola_vacia();
    pruebo_ver_primer_elemento_en_cola_vacia();
    pruebo_cola_creada_esta_vacia();
    pruebas_caso_encolo_y_desencolo_para_ver_cola();
}
