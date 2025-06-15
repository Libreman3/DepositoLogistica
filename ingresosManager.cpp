#include <iostream>
#include <string>
#include <cstring>
#include "ingresosManager.h"
#include "ingresos.h"
#include "ingresosArchivo.h"
#include "fecha.h"
#include "proveedorArchivo.h"
#include "productoArchivo.h"

using namespace std;

void IngresosManager::cargar() {
    int idProv = -1;
    int idProd = -1;
    int idIngreso = -1;
    bool estado;
    Fecha fecha;
    Ingresos ingreso;
    IngresosArchivo arc;
    ProveedorArchivo provArc;
    ProductoArchivo prodArc;

    cout << "------- CARGAR INGRESO -------" << endl;
    cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;

    while (true) {
        cout << "ID Proveedor: ";
        cin >> idProv;
        if (!cin || idProv < 0) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "  → Por favor ingresa un número válido.\n";
            continue;
        }
        if (idProv == 0) return;
        if (provArc.buscarId(idProv) < 0) {
            cout << "  No existe proveedor con ID " << idProv << "!\n";
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
        cout << "ID Ingreso  : ";
        cin >> idIngreso;
        if (!cin || idIngreso < 0) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "  → Por favor ingresa un numero válido.\n";
            continue;
        }
        if (idIngreso == 0) return;
        if (arc.buscarPorIdIngreso(idIngreso) >= 0) {
            cout << "  Ya existe un ingreso con ID " << idIngreso << "!\n";
            system("pause");
            continue;
        }
        break;
    }

    cout << "Fecha de ingreso:" << endl;
    fecha.Cargar();

    int pasillo, fila, columna, cantidad;
    auto pedir = [&](const char* etiqueta, int& var){
        while (true) {
            cout << etiqueta;
            cin >> var;
            if (cin && var > 0) break;
            cin.clear(); cin.ignore(1000,'\n');
            cout << "  → Debe ingresar un valor entero > 0\n";
        }
    };
    pedir("Ingrese pasillo   : ", pasillo);
    pedir("Ingrese fila       : ", fila);
    pedir("Ingrese columna    : ", columna);
    pedir("Ingrese cantidad   : ", cantidad);

    char almac[20][20];
    for (int i = 0; i < 20; ++i) almac[i][0] = '\0';
    snprintf(almac[0], 20, "%d", pasillo);
    snprintf(almac[1], 20, "%d", fila);
    snprintf(almac[2], 20, "%d", columna);
    snprintf(almac[3], 20, "%d", cantidad);

    ingreso = Ingresos(idProv, idProd, idIngreso, fecha, almac, true);
    if (arc.guardar(ingreso))
        cout << "\nIngreso guardado correctamente (ID Ingreso = " << idIngreso << ")\n\n";
    else
        cout << "\nError al guardar el ingreso!\n\n";
    system("pause");
}

void IngresosManager::mostrar() {
    IngresosArchivo arc;
    Ingresos reg;
    int total = arc.getCantidadIngresos();

    int activos = 0;
    for (int i = 0; i < total; ++i) {
        if (arc.leer(i).getEstado()) activos++;
    }

    cout << "------ LISTAR INGRESOS (Activos: " << activos << ") ------\n\n";

    int idxActivo = 0;
    for (int i = 0; i < total; ++i) {
        reg = arc.leer(i);
        if (!reg.getEstado()) continue;

        idxActivo++;
        cout << "Ingreso activo #" << idxActivo << ":\n";
        cout << "  ID Ingreso   : " << reg.getIdIngreso()    << '\n';
        cout << "  ID Proveedor : " << reg.getIdProveedor()  << '\n';
        cout << "  ID Producto  : " << reg.getIdProducto()   << '\n';
        cout << "  Fecha        : "; reg.getFechaIngreso().Mostrar();

        char buf[20];
        reg.getAlmacenamiento(0, buf); int pasillo  = atoi(buf);
        reg.getAlmacenamiento(1, buf); int fila      = atoi(buf);
        reg.getAlmacenamiento(2, buf); int columna   = atoi(buf);
        reg.getAlmacenamiento(3, buf); int cantidad  = atoi(buf);

        cout << "  Ubicación:\n"
             << "    Pasillo  : " << pasillo  << '\n'
             << "    Fila     : " << fila     << '\n'
             << "    Columna  : " << columna  << '\n'
             << "    Cantidad : " << cantidad << "\n\n";
    }

    system("pause");
}


void IngresosManager::buscar() {
    IngresosArchivo arc;
    Ingresos reg;

    cout << "------ BUSCAR INGRESO POR ID ------" << endl;
    cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;

    int idIngreso;
    cout << "ID Ingreso: ";
    cin >> idIngreso;
    if (idIngreso == 0) return;

    int pos = arc.buscarPorIdIngreso(idIngreso);
    if (pos < 0) {
        cout << "\nNo se encontró ingreso con ID " << idIngreso << ".\n\n";
    } else {
        reg = arc.leer(pos);
        if (reg.getEstado()) {
            reg.mostrar();
        } else {
            cout << "\nEl ingreso (ID " << idIngreso << ") está eliminado.\n\n";
        }
    }

    system("pause");
}


void IngresosManager::eliminar() {
    IngresosArchivo arc;
    Ingresos reg;

    cout << "------ ELIMINAR INGRESO ------" << endl;
    cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;

    int idIngreso;
    cout << "ID Ingreso a eliminar: ";
    cin >> idIngreso;
    if (idIngreso == 0) return;

    int pos = arc.buscarPorIdIngreso(idIngreso);
    if (pos < 0) {
        cout << "\nNo existe un ingreso con ID " << idIngreso << ".\n\n";
        system("pause");
        return;
    }

    reg = arc.leer(pos);
    if (!reg.getEstado()) {
        cout << "\nEl ingreso (ID " << idIngreso << ") ya está eliminado.\n\n";
    } else {
        reg.setEstado(false);
        if (arc.modificar(reg, pos))
            cout << "\nIngreso (ID " << idIngreso << ") marcado como eliminado.\n\n";
        else
            cout << "\nError al eliminar el ingreso!\n\n";
    }

    system("pause");
}

