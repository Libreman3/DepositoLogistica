#pragma once
#include "fecha.h"

class Ingresos {
private:
    int     _idProveedor;
    int     _idProducto;
    int     _idIngreso;
    Fecha   _fechaIngreso;
    char    _almacenamiento[20][20];
    bool    _estado;

public:
    Ingresos();
    Ingresos(int idProv,
             int idProd,
             int idIngreso,
             Fecha fecha,
             const char almac[20][20],
             bool estado = true);

    int     getIdProveedor();
    void    setIdProveedor(int idProv);

    int     getIdProducto();
    void    setIdProducto(int idProd);

    int     getIdIngreso();
    void    setIdIngreso(int idIngreso);

    Fecha   getFechaIngreso();
    void    setFechaIngreso(Fecha fecha);

    void    getAlmacenamiento(int fila, char out[20]);
    void    setAlmacenamiento(int fila, const char almac[20]);

    bool    getEstado();
    void    setEstado(bool estado);

    void    mostrar();
};
