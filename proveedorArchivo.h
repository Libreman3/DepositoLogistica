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

    bool modificar(Proveedor registro, int posicion);

    int buscarId(int idProveedor);
    int buscarCuit(int cuitProveedor);
    //string buscar (string razonSocial);
};
