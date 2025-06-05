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

std::string Proveedor::getCuit(){
    return _cuit;
}
void Proveedor::setCuit(std::string cuit){
    strcpy(_cuit,cuit.c_str());
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
    strcpy(_cuit, "");
    strcpy(_razonSocial, "");
    strcpy(_direccion, "");
    strcpy(_mail, "");
    _estado= true;
}
Proveedor::Proveedor(int numeroProveedor,std::string cuit, std::string razonSocial,std::string direccion,std::string mail,bool estado){
    setNumeroProveedor(numeroProveedor);
    setCuit(cuit);
    setRazonSocial(razonSocial);
    setDireccion(direccion);
    setMail(mail);
    setEstado(estado);
}

void Proveedor::tarjetaProveedor(){

    cout<< "Número de Proveedor: "<< getNumeroProveedor() << endl;
    cout<< "Número de CUIT: "<< getCuit() <<endl;
    cout<< "Razón Social: "<< getRazonSocial() <<endl;
    cout<< "Dirección: "<< getDireccion() <<endl;
    cout<< "Mail: "<< getMail() <<endl<<endl;
    cout<< "===================" <<endl;
    cout<< endl;
}
