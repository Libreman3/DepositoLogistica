
#include <iostream>
#include <cstring>
#include <string>
#include "producto.h"

using namespace std;

// Getters y Setters

int Producto::get_IdProducto() {
    return _idProducto;
}
void Producto::set_IdProducto(int idProducto) {
    _idProducto = idProducto;
}

float Producto::get_precio() {
    return _precio;
}
void Producto::set_precio(float precio) {
    _precio = precio;
}

int Producto::get_cantidadStock() {
    return _cantidadStock;
}
void Producto::set_cantidadStock(int cantidadStock) {
    _cantidadStock = cantidadStock;
}

std::string Producto::get_descripcion() {
    return std::string(_descripcion);  // Convertir de char[] a std::string
}
void Producto::set_descripcion(std::string descripcion) {
    strcpy(_descripcion, descripcion.c_str());  // Copiar la cadena al arreglo de char[]
}


std::string Producto::get_Nombre() {
    return std::string(_nombre);  // Convertir de char[] a std::string
}
void Producto::set_Nombre(std::string nombre) {
    strcpy(_nombre, nombre.c_str());  // Copiar la cadena al arreglo de char[]
}

std::string Producto::get_Marca() {
    return std::string(_marca);  // Convertir de char[] a std::string
}
void Producto::set_Marca(std::string marca) {
    strcpy(_marca, marca.c_str());  // Copiar la cadena al arreglo de char[]
}

bool Producto::get_Estado() {
    return _estado;
}
void Producto::set_Estado(bool estado) {
    _estado = estado;
}

// Constructores

Producto::Producto() {
    _idProducto = 0;
    _precio = 0.0f;
    _cantidadStock = 0;
    strcpy(_descripcion, "");
    strcpy(_nombre, "");
    strcpy(_marca, "");
    _estado = true;
}

Producto::Producto(int idProducto, float precio, int cantidadStock, std::string descripcion,std::string nombre, std::string marca, bool estado) {
    set_IdProducto(idProducto);
    set_precio(precio);
    set_cantidadStock(cantidadStock);
    set_descripcion(descripcion);
    set_Nombre(nombre);
    set_Marca(marca);
    set_Estado(estado);
}

// Métodos adicionales

void Producto::cargarProducto() {
    cout << "===================" << endl;
    cout << "ID Producto: " << get_IdProducto() << endl;
    cout << "Nombre: " << get_Nombre() << endl;
    cout << "Marca: " << get_Marca() << endl;
    cout << "Estado: " << (get_Estado() ? "Activo" : "Inactivo") << endl;
    cout << endl;
}

void Producto::mostrarProducto() {
    cout << "ID Producto: " << _idProducto << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Marca: " << _marca << endl;
    cout << "Descripción: " << _descripcion << endl;
    cout << "Precio: " << _precio << endl;
    cout << "Cantidad en Stock: " << _cantidadStock << endl;
    cout << "Estado: " << (_estado ? "Activo" : "Inactivo") << endl;
}
