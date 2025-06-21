#include <iostream>
#include <cstring>
#include "egresos.h"

using namespace std;

Egresos::Egresos()
    : _idCliente(0)
    , _idProducto(0)
    , _idEgreso(0)
    , _fechaEgreso(0,0,0)
    , _cantidad(0)
    , _estado(true)
{}

Egresos::Egresos(int idClien,
                 int idProd,
                 int idEgreso,
                 Fecha fecha,
                 int cantidad,
                 bool estado)
    : _idCliente(idClien)
    , _idProducto(idProd)
    , _idEgreso(idEgreso)
    , _fechaEgreso(fecha)
    , _cantidad(cantidad)
    , _estado(estado)
{}

int Egresos::getIdCliente() const { return _idCliente; }
void Egresos::setIdCliente(int idClien) { _idCliente = idClien; }

int Egresos::getIdProducto() const { return _idProducto; }
void Egresos::setIdProducto(int idProd) { _idProducto = idProd; }

int Egresos::getIdEgreso() const { return _idEgreso; }
void Egresos::setIdEgreso(int idEgreso) { _idEgreso = idEgreso; }

Fecha Egresos::getFechaEgreso() const { return _fechaEgreso; }
void Egresos::setFechaEgreso(const Fecha &fecha) { _fechaEgreso = fecha; }

int Egresos::getCantidad() const { return _cantidad; }
void Egresos::setCantidad(int cantidad) { _cantidad = cantidad; }

bool Egresos::getEstado() const { return _estado; }
void Egresos::setEstado(bool estado) { _estado = estado; }

void Egresos::mostrar() const {
    //char buf[20];
    cout << "==========================\n";
    cout << "ID Cliente: " << getIdCliente() << endl;
    cout << "ID Egreso   : " << getIdEgreso() << endl;
    cout << "ID Producto : " << getIdProducto() << endl;
    cout << "Fecha Egreso: ";
    _fechaEgreso.Mostrar();
    cout << "Cantidad    : " << getCantidad() << endl;
    //cout << "Estado      : " << (getEstado()?"Activo":"Eliminado") << endl;
    cout << "==========================\n\n";
}
