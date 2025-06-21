#include "egresosManager.h"
#include "egresosArchivo.h"
#include "egresos.h"
#include "fecha.h"
#include "clienteArchivo.h"
#include "productoArchivo.h"
#include "stock.h"
#include "stockManager.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void EgresosManager::cargar() {

    int idClien = -1;
    int idProd = -1;
    int idEgreso = -1;
    int cantidad = -1;
    bool estado;
    Fecha fecha;
    Egresos egresos;
    EgresosArchivo arc;
    ClienteArchivo clienArc;
    ProductoArchivo prodArc;

    cout << "------- CARGAR EGRESO -------" << endl;
    cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;

    while (true) {
        cout << "ID Cliente: ";
        cin >> idClien;
        if (!cin || idClien < 0) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "  → Por favor ingresa un número válido.\n";
            continue;
        }
        if (idClien == 0) return;
        if (clienArc.buscarId(idClien) < 0) {
            cout << "  No existe cliente con ID " << idClien << "!\n";
            system("pause");
            continue;
        }
        break;
    }

    while (true) {
        cout << "ID Producto : ";
        cin >> idProd;
        if (!cin || idProd < 0) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "  → Por favor ingresa un número valido.\n";
            continue;
        }
        if (idProd == 0) return;
        if (prodArc.buscarId(idProd) < 0) {
            cout << "  No existe producto con ID " << idProd << "!\n";
            system("pause");
            continue;
        }
        break;
    }

    while (true) {
        cout << "ID Egreso  : ";
        cin >> idEgreso;
        if (!cin || idEgreso < 0) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "  → Por favor ingresa un número válido.\n";
            continue;
        }
        if (idEgreso == 0) return;
        if (arc.buscarPorIdEgreso(idEgreso) >= 0) {
            cout << "  Ya existe un egreso con ID " << idEgreso << "!\n";
            system("pause");
            continue;
        }
        break;
    }

    cout << "Fecha de Egreso:" << endl;
    fecha.Cargar();

    while (true) {
        cout << "Cantidad  : ";
        cin >> cantidad;
        if (!cin || cantidad < 0) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "  → Por favor ingresa un número válido.\n";
            continue;
        }
        if (cantidad == 0) return;
        break;
    }

    // --- VALIDACIÓN DE STOCK DISPONIBLE ---
    Stock stockManager;
    int stockDisponible = stockManager.calcularStock(idProd);
    if (cantidad > stockDisponible) {
        cout << "No hay suficiente stock disponible. Stock actual: " << stockDisponible << endl;
        system("pause");
        return;
    }
    // ----------------------------------------

    egresos = Egresos(idClien, idProd, idEgreso, fecha, cantidad, true);
    if (arc.guardar(egresos))
        cout << "\nEgreso guardado correctamente (ID Egreso = " << idEgreso << ")\n\n";
    else
        cout << "\nError al guardar el egreso!\n\n";
    system("pause");
}

void EgresosManager::mostrar() {
EgresosArchivo _archivo;
int cantidad = _archivo.getCantidadEgresos();
    for (int i = 0; i < cantidad; i++) {
        Egresos reg = _archivo.leer(i);
        if (reg.getEstado()) {  // Solo mostramos los egresos activos
            reg.mostrar();
        }
    }
}

void EgresosManager::buscar() {
EgresosArchivo _archivos;
int id;
    std::cout << "Ingrese el ID del egreso a buscar: ";
    std::cin >> id;

    int pos = _archivos.buscarPorIdEgreso(id);
    if (pos == -1) {
        std::cout << "No se encontró un egreso con ese ID.\n";
        return;
    }

    Egresos reg = _archivos.leer(pos);
    if (reg.getEstado()) {
        reg.mostrar();
    } else {
        std::cout << "El egreso fue eliminado (baja lógica).\n";
    }
}

void EgresosManager::eliminar() {
 EgresosArchivo  _archivos;
 int id;
    std::cout << "Ingrese el ID del egreso a eliminar: ";
    std::cin >> id;

    int pos = _archivos.buscarPorIdEgreso(id);
    if (pos == -1) {
        std::cout << "Egreso no encontrado.\n";
        return;
    }

    Egresos reg = _archivos.leer(pos);
    if (!reg.getEstado()) {
        std::cout << "Ese egreso ya fue eliminado.\n";
        return;
    }

    char confirma;
    std::cout << "¿Esta seguro que desea eliminar el egreso? (S/N): ";
    std::cin >> confirma;
    if (confirma == 'S' || confirma == 's') {
        reg.setEstado(false);
        if (_archivos.modificar(reg, pos)) {
            std::cout << "Egreso eliminado correctamente.\n";
        } else {
            std::cout << "No se pudo eliminar el egreso.\n";
        }
    } else {
        std::cout << "Operación cancelada.\n";
    }
}
