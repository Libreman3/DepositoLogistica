#include "Fecha.h"

void Fecha::Cargar() {
    do {
        std::cout << "DIA (1-31): ";
        std::cin  >> dia;
        if (dia < 1 || dia > 31)
            std::cout << "  Valor invalido.  Por favor reingresa dia.\n";
    } while (dia < 1 || dia > 31);

    do {
        std::cout << "MES (1-12): ";
        std::cin  >> mes;
        if (mes < 1 || mes > 12)
            std::cout << "  Valor invalido. Por favor reingresa mes.\n";
    } while (mes < 1 || mes > 12);

    do {
        std::cout << "ANIO (>=2025): ";
        std::cin  >> anio;
        if (anio < 2025)
            std::cout << "  No se admiten anios anteriores a 2025. Por favor reingresa año.\n";
    } while (anio < 2025);
}

void Fecha::Mostrar() const {
    if (dia < 10)  std::cout << '0';
    std::cout << dia << '/';
    if (mes < 10)  std::cout << '0';
    std::cout << mes << '/';
    std::cout << anio << '\n';
}
