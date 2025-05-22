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
    // Aquí podrías declarar variables privadas si necesitás
};

#endif // PRODUCTOMANAGER_H_INCLUDED
