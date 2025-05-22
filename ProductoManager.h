#ifndef PRODUCTOMANAGER_H_INCLUDED
#define PRODUCTOMANAGER_H_INCLUDED
#pragma once

class ProductoManager {
public:
    void cargar();
    void cargarProducto();
    void mostrarProductos();
    void buscarProducto();
    void modificarProducto();
    void eliminarProducto();
    void restaurarProducto();

private:
    // Aqu� podr�as declarar variables privadas si necesit�s
};

#endif // PRODUCTOMANAGER_H_INCLUDED
