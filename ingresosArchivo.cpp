#include "ingresosArchivo.h"
#include <cstdio>

IngresosArchivo::IngresosArchivo() {
    _nombreArchivo = "ingreso.dat";
}

IngresosArchivo::IngresosArchivo(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool IngresosArchivo::guardar(Ingresos registro) {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "ab");
    if (pFile == nullptr) {
        return false;
    }
    bool result = fwrite(&registro, sizeof(Ingresos), 1, pFile) == 1;
    fclose(pFile);
    return result;
}

int IngresosArchivo::getCantidadIngresos() {
    int total, cantidad;
    FILE *pFile;
    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) {
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    total   = ftell(pFile);
    cantidad = total / sizeof(Ingresos);
    fclose(pFile);
    return cantidad;
}

Ingresos IngresosArchivo::leer(int pos) {
    FILE *pFile;
    Ingresos reg;

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) {
        return reg;
    }

    fseek(pFile, sizeof(Ingresos) * pos, SEEK_SET);
    fread(&reg, sizeof(Ingresos), 1, pFile);
    fclose(pFile);
    return reg;
}

int IngresosArchivo::buscarProveedor(int idProveedor) {
    FILE *pFile;
    Ingresos reg;
    int posicion = 0;

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) {
        return -1;
    }

    while (fread(&reg, sizeof(Ingresos), 1, pFile) == 1) {
        if (reg.getIdProveedor() == idProveedor) {
            fclose(pFile);
            return posicion;
        }
        posicion++;
    }

    fclose(pFile);
    return -1;
}

int IngresosArchivo::buscarProducto(int idProducto) {
    FILE *pFile;
    Ingresos reg;
    int posicion = 0;

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) {
        return -1;
    }

    while (fread(&reg, sizeof(Ingresos), 1, pFile) == 1) {
        if (reg.getIdProducto() == idProducto) {
            fclose(pFile);
            return posicion;
        }
        posicion++;
    }

    fclose(pFile);
    return -1;
}

int IngresosArchivo::buscarPorIdIngreso(int idIngreso) {
    FILE *pFile;
    Ingresos reg;
    int posicion = 0;

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) {
        return -1;
    }

    while (fread(&reg, sizeof(Ingresos), 1, pFile) == 1) {
        if (reg.getIdIngreso() == idIngreso) {
            fclose(pFile);
            return posicion;
        }
        posicion++;
    }

    fclose(pFile);
    return -1;
}


bool IngresosArchivo::modificar(Ingresos registro, int posicion) {
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if (pFile == nullptr) {
        return false;
    }

    fseek(pFile, posicion * sizeof(Ingresos), SEEK_SET);
    result = (fwrite(&registro, sizeof(Ingresos), 1, pFile) == 1);
    fclose(pFile);
    return result;
}

