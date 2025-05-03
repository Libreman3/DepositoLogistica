#include <iostream>
#include "proveedorArchivo.h"
using namespace std;

ProveedorArchivo::ProveedorArchivo(){
    _nombreArchivo = "proveedor.dat";
}
ProveedorArchivo::ProveedorArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}
bool ProveedorArchivo::guardar(Proveedor registro){
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "ab");

    if(pFile==nullptr){
        return false;
    }

    result = fwrite(&registro, sizeof(Proveedor),1,pFile);

    fclose(pFile);

    return result;
}

int ProveedorArchivo::getCantidadProveedores(){

    int total, cantidad;

    FILE *pFile;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile==nullptr){
       return 0;
    }

    fseek(pFile, 0, SEEK_END);

    total = ftell(pFile);

    cantidad = total / sizeof(Proveedor);

    fclose(pFile);

    return cantidad;
}

Proveedor ProveedorArchivo::leer(int pos){
    FILE *pFile;
    Proveedor reg;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile ==nullptr){
        return reg;
    }

    fseek(pFile, sizeof(Proveedor)*pos, SEEK_SET);

    fread(&reg,sizeof(Proveedor),1,pFile);

    fclose(pFile);

    return reg;
}
