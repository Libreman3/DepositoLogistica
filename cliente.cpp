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

int Cliente::getDni(){
    return _dni;
}
void Cliente::setDni(int dni){
    _dni=dni;
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
    _dni=0;
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_direccion, "");
    strcpy(_mail, "");
    _estado= true;
}
Cliente::Cliente(int numeroCliente,int dni, std::string nombre,std::string apellido,std::string direccion,std::string mail,bool estado){
    setNumeroCliente(numeroCliente);
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setDireccion(direccion);
    setMail(mail);
    setEstado(estado);
}

void Cliente::tarjetaCliente(){

    cout<< "===================" <<endl;
    cout<< "Numero de Cliente: "<< getNumeroCliente() << endl;
    cout<< "Numero de DNI: "<< getDni() <<endl;
    cout<< "Nombre: "<< getNombre() <<endl;
    cout<< "Apellido: "<< getApellido() <<endl;
    cout<< "Direccion: "<< getDireccion() <<endl;
    cout<< "Mail: "<< getMail() <<endl;
    cout<< endl;
}
