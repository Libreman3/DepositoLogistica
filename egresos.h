#pragma once
#include "fecha.h"

class Egresos {
private:
    int _idProveedor;
    int _idProducto;
    int _idEgreso;
    Fecha _fechaEgreso;
    char _almacenamiento[20][20];
    bool _estado;

public:
    Egresos();
    Egresos(int idProv,
            int idProd,
            int idEgreso,
            Fecha fecha,
            const char almac[20][20],
            bool estado = true);

    int getIdProveedor() const;
    void setIdProveedor(int idProv);

    int getIdProducto() const;
    void setIdProducto(int idProd);

    int getIdEgreso() const;
    void setIdEgreso(int idEgreso);

    Fecha getFechaEgreso() const;
    void setFechaEgreso(const Fecha &fecha);

    void getAlmacenamiento(int index, char out[20]) const;
    void setAlmacenamiento(int index, const char almac[20]);

    bool getEstado() const;
    void setEstado(bool estado);

    void mostrar() const;
};
