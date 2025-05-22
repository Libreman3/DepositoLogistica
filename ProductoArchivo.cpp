#include <iostream>
#include "ProductoArchivo.h"
#include "Producto.h"
using namespace std;

ProductoArchivo::ProductoArchivo(){
    _nombreArchivo = "producto.dat";
}

ProductoArchivo::ProductoArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ProductoArchivo::guardar(Producto registro){
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "ab");

    if(pFile == nullptr){
        return false;
    }

    result = fwrite(&registro, sizeof(Producto), 1, pFile);

    fclose(pFile);

    return result;
}

int ProductoArchivo::getCantidadProductos() {
    int total = 0;
    Producto producto;

    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");

    if (pFile == nullptr) {
        return 0;
    }

    while (fread(&producto, sizeof(Producto), 1, pFile)) {
        total++;  // Cuenta todos los productos, activos e inactivos
    }

    fclose(pFile);

    return total;
}

Producto ProductoArchivo::leer(int pos) {
    FILE *pFile;
    Producto reg;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == nullptr){
        return reg; // Devuelves un producto vac�o si el archivo no puede abrirse.
    }

    fseek(pFile, sizeof(Producto) * pos, SEEK_SET);

    if (fread(&reg, sizeof(Producto), 1, pFile) != 1) {
        fclose(pFile);
        return reg; // Si no se pudo leer correctamente, se devuelve un producto vac�o.
    }

    fclose(pFile);

    return reg;
}

int ProductoArchivo::buscarId(int idProducto) {
    FILE *pFile;
    Producto reg;

    int posicion = 0;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if (pFile == nullptr) {
        return -1;  // Retornar -1 si el archivo no se pudo abrir
    }

    while (fread(&reg, sizeof(Producto), 1, pFile) == 1) {
        if (reg.get_IdProducto() == idProducto) {  // Comparar el ID del producto
            fclose(pFile);
            return posicion;  // Si el producto se encuentra, devolver la posici�n
        }
        posicion++;
    }

    fclose(pFile);
    return -1;  // Si no se encuentra el producto, retornar -1
}

bool ProductoArchivo::modificar(Producto registro, int posicion){
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "rb+");

    if(pFile == nullptr){
        return false;
    }

    fseek(pFile, posicion * sizeof(Producto), SEEK_SET);

    result = fwrite(&registro, sizeof(Producto), 1, pFile);

    fclose(pFile);

    return result;
}
