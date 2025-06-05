#include <iostream>
#include "clienteArchivo.h"
using namespace std;

ClienteArchivo::ClienteArchivo(){
    _nombreArchivo = "cliente.dat";
}

ClienteArchivo::ClienteArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ClienteArchivo::guardar(Cliente registro){
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "ab");

    if(pFile==nullptr){
        return false;
    }

    result = fwrite(&registro, sizeof(Cliente),1,pFile);

    fclose(pFile);

    return result;
}

int ClienteArchivo::getCantidadClientes(){

    int total, cantidad;

    FILE *pFile;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile==nullptr){
       return 0;
    }

    fseek(pFile, 0, SEEK_END);

    total = ftell(pFile);

    cantidad = total / sizeof(Cliente);

    fclose(pFile);

    return cantidad;
}

Cliente ClienteArchivo::leer(int pos){
    FILE *pFile;
    Cliente reg;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile ==nullptr){
        return reg;
    }

    fseek(pFile, sizeof(Cliente)*pos, SEEK_SET);

    fread(&reg,sizeof(Cliente),1,pFile);

    fclose(pFile);

    return reg;
}

int ClienteArchivo::buscarId(int idCliente){
    FILE *pFile;
    Cliente reg;

    int posicion = 0;

    pFile=fopen(_nombreArchivo.c_str(),"rb");

    if(pFile == nullptr){
        return 0;
    }

    while(fread(&reg, sizeof(Cliente),1,pFile)==1){
        if(reg.getNumeroCliente()==idCliente){
            fclose(pFile);
            return posicion;
        }
        posicion ++;
    }
    fclose(pFile);
    return -1;
}

bool ClienteArchivo::modificar(Cliente registro, int posicion){
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "rb+");

    if(pFile == nullptr){
        return false;
    }

    fseek(pFile, posicion * sizeof(Cliente) , SEEK_SET);

    result = fwrite(&registro, sizeof(Cliente),1,pFile);

    fclose(pFile);

    return result;
}
