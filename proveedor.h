#pragma once
#include <string>

class Proveedor{
private:
    int _numeroProveedor;
    int _cuit;
    char _razonSocial[50];
    char _direccion[50];
    char _mail[50];
    bool _estado;
public:
    int getNumeroProveedor();
    void setNumeroProveedor(int numeroProveedor);

    int getCuit();
    void setCuit(int cuit);

    std::string getRazonSocial();
    void setRazonSocial(std::string razonSocial);

    std::string getDireccion();
    void setDireccion(std::string direccion);

    std::string getMail();
    void setMail(std::string mail);

    bool getEstado();
    void setEstado(bool estado);

    Proveedor();
    Proveedor(int numeroProveedor,int cuit, std::string razonSocial,std::string direccion,std::string mail,bool estado);

    void tarjetaProveedor();

};
