#pragma once
#include <iostream>

class Fecha {
private:
    int dia, mes, anio;

public:
    Fecha(int dia = 0, int mes = 0, int anio = 0)
        : dia(dia), mes(mes), anio(anio) {}

    void Cargar();
    void Mostrar() const;
};
