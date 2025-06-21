#pragma once
#include "egresos.h"
#include "egresosArchivo.h"

class EgresosManager {
public:
    void cargar();
    void mostrar();
    void buscar();
    void eliminar();
};
