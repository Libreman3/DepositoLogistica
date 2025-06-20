#pragma once
#include <string>
#include "ingresos.h"

class IngresosArchivo {
private:
    std::string _nombreArchivo;

public:
    IngresosArchivo();
    IngresosArchivo(std::string nombreArchivo);
    bool    guardar(Ingresos registro);
    int     getCantidadIngresos();
    Ingresos leer(int pos);
    int     buscarPorIdIngreso(int idIngreso);
    bool    modificar(Ingresos registro, int posicion);
};

