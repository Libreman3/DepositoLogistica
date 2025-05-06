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

int ProveedorArchivo::buscarCuit(int cuitProveedor){
    FILE *pFile;
    Proveedor reg;

    int posicion=0;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == nullptr){
        return 0;
    }

    while(fread(&reg, sizeof(Proveedor),1,pFile)==1){
        if(reg.getCuit()==cuitProveedor){
            fclose(pFile);
            return posicion;
        }
        posicion++;
    }
    fclose(pFile);
    return -1;
}

int ProveedorArchivo::buscarId(int idProveedor){
    FILE *pFile;
    Proveedor reg;

    int posicion = 0;

    pFile=fopen(_nombreArchivo.c_str(),"rb");

    if(pFile == nullptr){
        return 0;
    }

    while(fread(&reg, sizeof(Proveedor),1,pFile)==1){
        if(reg.getNumeroProveedor()==idProveedor){
            fclose(pFile);
            return posicion;
        }
        posicion ++;
    }
    fclose(pFile);
    return -1;
}

bool ProveedorArchivo::modificar(Proveedor registro, int posicion){
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "rb+");

    if(pFile == nullptr){
        return false;
    }

    fseek(pFile, posicion * sizeof(Proveedor) , SEEK_SET);

    result = fwrite(&registro, sizeof(Proveedor),1,pFile);

    fclose(pFile);

    return result;
}

