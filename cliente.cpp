#include <iostream>
#include <cstring>
#include <string>
#include "cliente.h"

using namespace std;

int Cliente::getNumeroCliente(){
    return _numeroCliente;
}
void Cliente::setNumeroCliente(int numeroCliente){
    _numeroCliente=numeroCliente;
}

std::string Cliente::getDni(){
    return _dni;
}
void Cliente::setDni(std::string dni){
    strcpy(_dni,dni.c_str());
}

std::string Cliente::getNombre(){
    return _nombre;
}
void Cliente::setNombre(std::string nombre){
    strcpy(_nombre,nombre.c_str());
}

std::string Cliente::getApellido(){
    return _apellido;
}
void Cliente::setApellido(std::string apellido){
    strcpy(_apellido,apellido.c_str());
}

std::string Cliente::getDireccion(){
    return _direccion;
}
void Cliente::setDireccion(std::string direccion){
    strcpy(_direccion,direccion.c_str());
}

std::string Cliente::getMail(){
    return _mail;
}
void Cliente::setMail(std::string mail){
    strcpy(_mail,mail.c_str());
}

bool Cliente::getEstado(){
    return _estado;
}
void Cliente::setEstado(bool estado){
    _estado=estado;
}

Cliente::Cliente(){
    _numeroCliente = 0;
    strcpy(_dni, "");
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_direccion, "");
    strcpy(_mail, "");
    _estado= true;
}
Cliente::Cliente(int numeroCliente,std::string dni, std::string nombre,std::string apellido,std::string direccion,std::string mail,bool estado){
    setNumeroCliente(numeroCliente);
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setDireccion(direccion);
    setMail(mail);
    setEstado(estado);
}

void Cliente::tarjetaCliente(){

    cout<< "Número de Cliente: "<< getNumeroCliente() << endl;
    cout<< "Número de DNI: "<< getDni() <<endl;
    cout<< "Nombre: "<< getNombre() <<endl;
    cout<< "Apellido: "<< getApellido() <<endl;
    cout<< "Dirección: "<< getDireccion() <<endl;
    cout<< "Mail: "<< getMail() <<endl<<endl;
    cout<< "===================" <<endl;
    cout<< endl;
}
