#pragma once
#include <string>
#include "proveedor.h"
class Producto{
private:
    int _idProducto;
    float _precio;
    int _cantidadStock;
    char _descripcion[50];
    char _nombre[50];
    char _marca[50];
    bool _estado;

public:
    // Getters y Setters
    int get_IdProducto();
    void set_IdProducto(int idProducto);

    float get_precio();
    void set_precio(float precio);

    int get_cantidadStock();
    void set_cantidadStock(int cantidadStock);

    std::string get_descripcion();
    void set_descripcion(std::string descripcion);


    std::string get_Nombre();
    void set_Nombre(std::string nombre);

    std::string get_Marca();
    void set_Marca(std::string marca);

    bool get_Estado();
    void set_Estado(bool estado);

    // Constructores
    Producto();
    Producto(int idProducto, float precio, int cantidadStock, std::string descripcion, std::string nombre, std::string marca, bool estado);

    // Métodos adicionales
    void cargarProducto();
    void mostrarProducto();
};


