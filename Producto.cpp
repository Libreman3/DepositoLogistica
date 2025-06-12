#include <iostream>
#include <cstring>
#include <string>
#include "producto.h"

using namespace std;

int Producto::getIdProducto() {
    return _idProducto;
}
void Producto::setIdProducto(int idProducto) {
    _idProducto = idProducto;
}

std::string Producto::getNombre() {
    return _nombre;
}
void Producto::setNombre(std::string nombre) {
    strcpy(_nombre,nombre.c_str());
}

std::string Producto::getMarca() {
    return _marca;
}
void Producto::setMarca(std::string marca) {
    strcpy(_marca, marca.c_str());
}

bool Producto::getEstado() {
    return _estado;
}
void Producto::setEstado(bool estado) {
    _estado = estado;
}


Producto::Producto() {
    _idProducto = 0;
    strcpy(_nombre, "");
    strcpy(_marca, "");
    _estado = true;
}

Producto::Producto(int idProducto,std::string nombre, std::string marca, bool estado) {
    setIdProducto(idProducto);
    setNombre(nombre);
    setMarca(marca);
    setEstado(estado);
}

// Métodos adicionales

/*void Producto::cargarProducto() {
    cout << "===================" << endl;
    cout << "ID Producto: " << get_IdProducto() << endl;
    cout << "Nombre: " << get_Nombre() << endl;
    cout << "Marca: " << get_Marca() << endl;
    cout << "Estado: " << (get_Estado() ? "Activo" : "Inactivo") << endl;
    cout << endl;
}*/

void Producto::tarjetaProducto() {

    cout << "ID Producto: " << getIdProducto() << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Marca: " << getMarca() << endl<<endl;
    cout<< "===================" <<endl;
    cout << endl;
}
