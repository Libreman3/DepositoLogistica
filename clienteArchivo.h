#pragma once
#include <string>
#include "cliente.h"

class ClienteArchivo{
private:
    std::string _nombreArchivo;
public:
    ClienteArchivo();
    ClienteArchivo(std::string nombreArchivo);

    bool guardar(Cliente registro);
    int getCantidadClientes();
    Cliente leer(int pos);
    bool modificar(Cliente registro, int posicion);
    int buscarId(int idCliente);
    int buscarDni(int dniCliente);
    //string buscar (string nombre);
};
