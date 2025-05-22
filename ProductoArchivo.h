#ifndef PRODUCTOARCHIVO_H_INCLUDED
#define PRODUCTOARCHIVO_H_INCLUDED
#include <iostream>
#include <string>
#include "producto.h"
using namespace std;

class ProductoArchivo
{
private:
    std::string _nombreArchivo;

public:
    // Constructores
    ProductoArchivo();
    ProductoArchivo(std::string nombreArchivo);

    // Métodos
    bool guardar(Producto registro);
    int getCantidadProductos();
    Producto leer(int pos);
    bool modificar(Producto registro, int posicion);
    int buscarId(int idProducto);
};


#endif // PRODUCTOARCHIVO_H_INCLUDED
