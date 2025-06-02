#include <iostream>
#include <cstring>
#include <string>
#include "ingresos.h"

using namespace std;

int Ingresos::getIdProveedor() {
    return _idProveedor;
}
void Ingresos::setIdProveedor(int idProv) {
    _idProveedor = idProv;
}

int Ingresos::getIdProducto() {
    return _idProducto;
}
void Ingresos::setIdProducto(int idProd) {
    _idProducto = idProd;
}

int Ingresos::getIdIngreso() {
     return _idIngreso;
}
void Ingresos::setIdIngreso(int idIngreso) {
    _idIngreso = idIngreso;
}

Fecha Ingresos::getFechaIngreso() {
    return _fechaIngreso;
}
void Ingresos::setFechaIngreso(Fecha fecha) {
    _fechaIngreso = fecha;
}

bool Ingresos::getEstado() {
    return _estado;
}
void Ingresos::setEstado(bool estado) {
    _estado = estado;
}

void Ingresos::getAlmacenamiento(int fila, char out[20]) {
    if (fila < 0 || fila >= 20) {
        out[0] = '\0';
        return;
    }
    strncpy(out, _almacenamiento[fila], 20);
}
void Ingresos::setAlmacenamiento(int fila, const char almac[20]) {
    if (fila < 0 || fila >= 20) return;
    strncpy(_almacenamiento[fila], almac, 20);
}

Ingresos::Ingresos() {
    _idProveedor    = 0;
    _idProducto     = 0;
    _idIngreso      = 0;
    _fechaIngreso   = Fecha(0,0,0);
    _estado         = true;
    for (int i = 0; i < 20; ++i) {
        _almacenamiento[i][0] = '\0';
    }
}

Ingresos::Ingresos(int idProv,
                   int idProd,
                   int idIngreso,
                   Fecha fecha,
                   const char almac[20][20],
                   bool estado) {
    setIdProveedor(idProv);
    setIdProducto(idProd);
    setIdIngreso(idIngreso);
    setFechaIngreso(fecha);
    setEstado(estado);
    for (int i = 0; i < 20; ++i) {
        setAlmacenamiento(i, almac[i]);
    }
}

void Ingresos::mostrar() {
    char buf[20];
    cout << "==========================\n";
    cout << "ID Proveedor: " << getIdProveedor() << endl;
    cout << "ID INGESO:    " << getIdIngreso() << endl;
    cout << "ID Producto : " << getIdProducto()  << endl;
    cout << "Fecha Ingreso: ";
    _fechaIngreso.Mostrar();              // imprime DD/MM/AAAA
    getAlmacenamiento(0, buf);
    cout << "Almac[0]     : " << buf << endl;
    cout << "Estado       : " << (getEstado() ? "Activo" : "Eliminado") << endl;
    cout << "==========================\n\n";
}

