#pragma once
#include <string>
#include "proveedor.h"

class ProveedorArchivo{
private:
    std::string _nombreArchivo;
public:
    ProveedorArchivo();
    ProveedorArchivo(std::string nombreArchivo);
    bool guardar(Proveedor registro);
    int getCantidadProveedores();

    Proveedor leer(int pos);
};
