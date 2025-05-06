#include <iostream>
#include <cstring>
#include <string>
#include "proveedor.h"

using namespace std;

int Proveedor::getNumeroProveedor(){
    return _numeroProveedor;
}
void Proveedor::setNumeroProveedor(int numeroProveedor){
    _numeroProveedor=numeroProveedor;
}

int Proveedor::getCuit(){
    return _cuit;
}
void Proveedor::setCuit(int cuit){
    _cuit=cuit;
}

std::string Proveedor::getRazonSocial(){
    return _razonSocial;
}
void Proveedor::setRazonSocial(std::string razonSocial){
    strcpy(_razonSocial,razonSocial.c_str());
}

std::string Proveedor::getDireccion(){
    return _direccion;
}
void Proveedor::setDireccion(std::string direccion){
    strcpy(_direccion,direccion.c_str());
}

std::string Proveedor::getMail(){
    return _mail;
}
void Proveedor::setMail(std::string mail){
    strcpy(_mail,mail.c_str());
}

bool Proveedor::getEstado(){
    return _estado;
}
void Proveedor::setEstado(bool estado){
    _estado=estado;
}

Proveedor::Proveedor(){
    _numeroProveedor = 0;
    _cuit=0;
    strcpy(_razonSocial, "");
    strcpy(_direccion, "");
    strcpy(_mail, "");
    _estado= true;
}
Proveedor::Proveedor(int numeroProveedor,int cuit, std::string razonSocial,std::string direccion,std::string mail,bool estado){
    setNumeroProveedor(numeroProveedor);
    setCuit(cuit);
    setRazonSocial(razonSocial);
    setDireccion(direccion);
    setMail(mail);
    setEstado(estado);
}

void Proveedor::tarjetaProveedor(){

    cout<< "===================" <<endl;
    cout<< "Numero de Proveedor: "<< getNumeroProveedor() << endl;
    cout<< "Numero de CUIT: "<< getCuit() <<endl;
    cout<< "Razon Social: "<< getRazonSocial() <<endl;
    cout<< "Direccion: "<< getDireccion() <<endl;
    cout<< "Mail: "<< getMail() <<endl;
    cout<< endl;
}


