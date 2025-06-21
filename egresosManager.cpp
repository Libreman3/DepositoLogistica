#include "egresosManager.h"
#include "egresosArchivo.h"
#include "egresos.h"
#include "fecha.h"
#include "clienteArchivo.h"
#include "productoArchivo.h"
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
            cout << "  → Por favor ingresa un numero válido.\n";
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
            cout << "  → Por favor ingresa un numero válido.\n";
            continue;
        }
        if (cantidad == 0) return;
        break;
    }

    egresos = Egresos(idClien, idProd, idEgreso, fecha, cantidad, true);
    if (arc.guardar(egresos))
        cout << "\nEgreso guardado correctamente (ID Egreso = " << idEgreso << ")\n\n";
    else
        cout << "\nError al guardar el egreso!\n\n";
    system("pause");

}

void EgresosManager::mostrar() {

}

void EgresosManager::buscar() {

}

void EgresosManager::eliminar() {

}
