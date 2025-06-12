#pragma once
#include <string>

class Producto{
private:
    int _idProducto;
    char _nombre[50];
    char _marca[50];
    bool _estado;

public:
    int getIdProducto();
    void setIdProducto(int idProducto);

    std::string getNombre();
    void setNombre(std::string nombre);

    std::string getMarca();
    void setMarca(std::string marca);

    bool getEstado();
    void setEstado(bool estado);

    Producto();
    Producto(int idProducto, std::string nombre, std::string marca, bool estado);

    //Métodos adicionales
    //void cargarProducto();
    //void mostrarProducto();
    void tarjetaProducto();
};
