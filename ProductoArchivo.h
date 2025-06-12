#include <iostream>
#include <string>
#include "producto.h"

class ProductoArchivo{
private:
    std::string _nombreArchivo;

public:
    ProductoArchivo();
    ProductoArchivo(std::string nombreArchivo);

    bool guardar(Producto registro);
    int getCantidadProductos();
    Producto leer(int pos);
    bool modificar(Producto registro, int posicion);
    int buscarId(int idProducto);
};
