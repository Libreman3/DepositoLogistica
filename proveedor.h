#pragma once
#include <string>

class Proveedor{
private:
    int _numeroProveedor;
    char _cuit[15];
    char _razonSocial[50];
    char _direccion[50];
    char _mail[50];
    bool _estado;
public:
    int getNumeroProveedor();
    void setNumeroProveedor(int numeroProveedor);

    std::string getCuit();
    void setCuit(std::string cuit);

    std::string getRazonSocial();
    void setRazonSocial(std::string razonSocial);

    std::string getDireccion();
    void setDireccion(std::string direccion);

    std::string getMail();
    void setMail(std::string mail);

    bool getEstado();
    void setEstado(bool estado);

    Proveedor();
    Proveedor(int numeroProveedor,std::string cuit, std::string razonSocial,std::string direccion,std::string mail,bool estado);

    void tarjetaProveedor();

};
