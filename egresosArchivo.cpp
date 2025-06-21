#include "egresosArchivo.h"
#include <cstdio>

EgresosArchivo::EgresosArchivo() {
    _nombreArchivo = "egreso.dat";
}

EgresosArchivo::EgresosArchivo(const std::string& nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool EgresosArchivo::guardar(const Egresos& registro) {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "ab");
    if (!pFile) return false;
    bool result = (fwrite(&registro, sizeof(Egresos), 1, pFile) == 1);
    fclose(pFile);
    return result;
}

int EgresosArchivo::getCantidadEgresos() {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (!pFile) return 0;
    fseek(pFile, 0, SEEK_END);
    long totalBytes = ftell(pFile);
    fclose(pFile);
    return static_cast<int>(totalBytes / sizeof(Egresos));
}

Egresos EgresosArchivo::leer(int pos) {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    Egresos reg;
    if (!pFile) return reg;
    fseek(pFile, sizeof(Egresos) * pos, SEEK_SET);
    fread(&reg, sizeof(Egresos), 1, pFile);
    fclose(pFile);
    return reg;
}

int EgresosArchivo::buscarPorIdEgreso(int idEgreso) {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (!pFile) return -1;
    Egresos reg;
    int posicion = 0;
    while (fread(&reg, sizeof(Egresos), 1, pFile) == 1) {
        if (reg.getIdEgreso() == idEgreso) {
            fclose(pFile);
            return posicion;
        }
        posicion++;
    }
    fclose(pFile);
    return -1;
}

bool EgresosArchivo::modificar(const Egresos& registro, int posicion) {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if (!pFile) return false;
    fseek(pFile, sizeof(Egresos) * posicion, SEEK_SET);
    bool result = (fwrite(&registro, sizeof(Egresos), 1, pFile) == 1);
    fclose(pFile);
    return result;
}
