#include <iostream>
#include <cstring>
#include "egresos.h"

using namespace std;

Egresos::Egresos()
    : _idProveedor(0)
    , _idProducto(0)
    , _idEgreso(0)
    , _fechaEgreso(0,0,0)
    , _estado(true)
{
    for(int i=0;i<20;++i)
        _almacenamiento[i][0] = '\0';
}

Egresos::Egresos(int idProv,
                 int idProd,
                 int idEgreso,
                 Fecha fecha,
                 const char almac[20][20],
                 bool estado)
    : _idProveedor(idProv)
    , _idProducto(idProd)
    , _idEgreso(idEgreso)
    , _fechaEgreso(fecha)
    , _estado(estado)
{
    for(int i=0;i<20;++i)
        setAlmacenamiento(i, almac[i]);
}

int Egresos::getIdProveedor() const { return _idProveedor; }
void Egresos::setIdProveedor(int idProv) { _idProveedor = idProv; }

int Egresos::getIdProducto() const { return _idProducto; }
void Egresos::setIdProducto(int idProd) { _idProducto = idProd; }

int Egresos::getIdEgreso() const { return _idEgreso; }
void Egresos::setIdEgreso(int idEgreso) { _idEgreso = idEgreso; }

Fecha Egresos::getFechaEgreso() const { return _fechaEgreso; }
void Egresos::setFechaEgreso(const Fecha &fecha) { _fechaEgreso = fecha; }

bool Egresos::getEstado() const { return _estado; }
void Egresos::setEstado(bool estado) { _estado = estado; }

void Egresos::getAlmacenamiento(int index, char out[20]) const {
    if(index<0||index>=20) { out[0]='\0'; return; }
    strncpy(out, _almacenamiento[index], 20);
}

void Egresos::setAlmacenamiento(int index, const char almac[20]) {
    if(index<0||index>=20) return;
    strncpy(_almacenamiento[index], almac, 20);
}

void Egresos::mostrar() const {
    char buf[20];
    cout << "==========================\n";
    cout << "ID Proveedor: " << getIdProveedor() << endl;
    cout << "ID Egreso   : " << getIdEgreso() << endl;
    cout << "ID Producto : " << getIdProducto() << endl;
    cout << "Fecha Egreso: ";
    _fechaEgreso.Mostrar();
    getAlmacenamiento(0, buf);
    cout << "Pasillo     : " << buf << endl;
    getAlmacenamiento(1, buf);
    cout << "Fila        : " << buf << endl;
    getAlmacenamiento(2, buf);
    cout << "Columna     : " << buf << endl;
    getAlmacenamiento(3, buf);
    cout << "Cantidad    : " << buf << endl;
    cout << "Estado      : " << (getEstado()?"Activo":"Eliminado") << endl;
    cout << "==========================\n\n";
}

