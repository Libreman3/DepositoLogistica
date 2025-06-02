#pragma once
#include "Ingresos.h"
#include "IngresosArchivo.h"

class IngresosManager {
public:
    void cargar();
    void mostrar();
    void buscar();
    void modificar();
    void eliminar();
    void restaurar();
};

