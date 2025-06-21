#pragma once
#include "fecha.h"

class Egresos {
private:
    int _idCliente;
    int _idProducto;
    int _idEgreso;
    Fecha _fechaEgreso;
    int _cantidad;
    bool _estado;

public:
    Egresos();
    Egresos(int idClien,
            int idProd,
            int idEgreso,
            Fecha fecha,
            int cantidad,
            bool estado = true);

    int getIdCliente() const;
    void setIdCliente(int idClien);

    int getIdProducto() const;
    void setIdProducto(int idProd);

    int getIdEgreso() const;
    void setIdEgreso(int idEgreso);

    Fecha getFechaEgreso() const;
    void setFechaEgreso(const Fecha &fecha);

    int getCantidad() const;
    void setCantidad(int cantidad);

    bool getEstado() const;
    void setEstado(bool estado);

    void mostrar() const;
};
