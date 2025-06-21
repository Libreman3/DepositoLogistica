#pragma once
#include <string>
#include "egresos.h"

class EgresosArchivo {
private:
    std::string _nombreArchivo;

public:
    EgresosArchivo();
    EgresosArchivo(const std::string& nombreArchivo);

    bool guardar(const Egresos& registro);
    int  getCantidadEgresos();
    Egresos leer(int pos);

    int buscarPorIdEgreso(int idEgreso);

    bool modificar(const Egresos& registro, int posicion);
};
