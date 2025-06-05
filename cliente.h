#pragma once
#include <string>

class Cliente{
private:
    int _numeroCliente;
    char _dni[10];
    char _nombre[50];
    char _apellido[50];
    char _direccion[50];
    char _mail[50];
    bool _estado;
public:
    int getNumeroCliente();
    void setNumeroCliente(int numeroCliente);

    std::string getDni();
    void setDni(std::string dni);

    std::string getNombre();
    void setNombre(std::string nombre);

    std::string getApellido();
    void setApellido(std::string apellido);

    std::string getDireccion();
    void setDireccion(std::string direccion);

    std::string getMail();
    void setMail(std::string mail);

    bool getEstado();
    void setEstado(bool estado);

    Cliente();
    Cliente(int numeroCliente,std::string dni, std::string nombre, std::string apellido, std::string direccion,std::string mail,bool estado);

    void tarjetaCliente();

};
