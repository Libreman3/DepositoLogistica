#pragma once
#include <string>

class Cliente{
private:
    int _numeroCliente;
    int _dni;
    char _nombre[50];
    char _apellido[50];
    char _direccion[50];
    char _mail[50];
    bool _estado;
public:
    int getNumeroCliente();
    void setNumeroCliente(int numeroCliente);

    int getDni();
    void setDni(int dni);

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
    Cliente(int numeroCliente,int dni, std::string nombre, std::string apellido, std::string direccion,std::string mail,bool estado);

    void tarjetaCliente();

};
