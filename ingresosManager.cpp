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
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "  → Por favor ingresa un numero valido.\n\n";
            continue;
        }
        if (idProv == 0) {
            return;
        }
        int posProv = provArc.buscarId(idProv);
        if (posProv < 0) {
            cout << "    No existe ningun proveedor con ID " << idProv << "."
                 << "    Por favor carga primero ese proveedor o ingresa otro ID.";
            system("pause");
            continue;
        }

        break;
    }

    while (true) {
        cout << "ID Producto : ";
        cin >> idProd;
        if (!cin || idProd < 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "    Por favor ingresa un numero valido.";
            continue;
        }
        if (idProd == 0) {
            return;
        }
        int posProd = prodArc.buscarId(idProd);
        if (posProd < 0) {
            cout << "    No existe ningun producto con ID " << idProd << "."
                 << "    Por favor carga primero ese producto o ingresa otro ID.";
            system("pause");
            continue;
        }
        break;
    }

    while (true) {
        cout << "ID Ingreso  : ";
        cin >> idIngreso;
        if (!cin || idIngreso < 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "   Por favor ingresa un numero valido.";
            continue;
        }
        if (idIngreso == 0) {
            return;
        }
        int posExistente = arc.buscarPorIdIngreso(idIngreso);
        if (posExistente >= 0) {
            cout << "    Ya existe un ingreso con ID " << idIngreso << ".\n"
                 << "    Por favor elige otro ID.";
            system("pause");
            continue;
        }
        break;
    }

    cout << "Fecha de ingreso:" << endl;
    fecha.Cargar();

    int fila = -1, estante = -1, contenedor = -1;


    while (true) {
        cout << "Ingrese fila      : ";
        cin >> fila;
        if (!cin || fila < 1) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "  → Por favor ingresa un valor válido para fila (>=1).\n\n";
            continue;
        }
        break;
    }

    while (true) {
        cout << "Ingrese estante   : ";
        cin >> estante;
        if (!cin || estante < 1) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "  → Por favor ingresa un valor válido para estante (>=1).\n\n";
            continue;
        }
        break;
    }

    while (true) {
        cout << "Ingrese contenedor: ";
        cin >> contenedor;
        if (!cin || contenedor < 1) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "  → Por favor ingresa un valor válido para contenedor (>=1).\n\n";
            continue;
        }
        break;
    }

    char almac[20][20];
    for (int i = 0; i < 20; ++i) {
        almac[i][0] = '\0';
    }

    snprintf(almac[0], 20, "%d", fila);
    snprintf(almac[1], 20, "%d", estante);
    snprintf(almac[2], 20, "%d", contenedor);

    estado = true;
    ingreso = Ingresos(idProv, idProd, idIngreso, fecha, almac, estado);

    if (arc.guardar(ingreso))
        cout << "Ingreso guardado correctamente (ID Ingreso = " << idIngreso << ")\n\n";
    else
        cout << "Error al guardar el ingreso";

    system("pause");
}


void IngresosManager::mostrar() {
    IngresosArchivo arc;
    Ingresos reg;
    int total = arc.getCantidadIngresos();

    int activos = 0;
    for (int i = 0; i < total; ++i) {
        reg = arc.leer(i);
        if (reg.getEstado()) activos++;
    }

    cout << "------ LISTAR INGRESOS (Activos: " << activos << ") ------\n\n";

    int contadorActivos = 0;
    for (int i = 0; i < total; ++i) {
        reg = arc.leer(i);
        if (!reg.getEstado()) continue;

        contadorActivos++;
        cout << "Ingreso activo #" << contadorActivos << ":\n";
        cout << "  ID Ingreso   : " << reg.getIdIngreso()    << '\n';
        cout << "  ID Proveedor : " << reg.getIdProveedor()  << '\n';
        cout << "  ID Producto  : " << reg.getIdProducto()   << '\n';

        cout << "  Fecha        : ";
        reg.getFechaIngreso().Mostrar();

        char buf[20];
        reg.getAlmacenamiento(0, buf);
        int fila = atoi(buf);
        reg.getAlmacenamiento(1, buf);
        int estante = atoi(buf);
        reg.getAlmacenamiento(2, buf);
        int contenedor = atoi(buf);

        cout << "  Ubicación:\n"
             << "    Fila      : " << fila       << '\n'
             << "    Estante   : " << estante    << '\n'
             << "    Contenedor: " << contenedor << "\n\n";
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

void IngresosManager::modificar() {
    IngresosArchivo arc;
    Ingresos reg;

    cout << "------ MODIFICAR INGRESO ------" << endl;
    cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;

    int idIngreso;
    cout << "ID Ingreso a modificar: ";
    cin >> idIngreso;
    if (idIngreso == 0) return;

    int pos = arc.buscarPorIdIngreso(idIngreso);
    if (pos < 0) {
        cout << "\nNo existe un ingreso con ID " << idIngreso << ".\n\n";
        system("pause");
        return;
    }

    reg = arc.leer(pos);
    cout << "\nDatos actuales del Ingreso ID " << idIngreso << ":\n";
    reg.mostrar();

    cout << "\n--- NUEVOS DATOS ---\n";

    int nuevoProd;
    cout << "Nuevo ID Producto  : ";
    cin >> nuevoProd;
    reg.setIdProducto(nuevoProd);

    cout << "Nueva Fecha:\n";
    Fecha f;
    f.Cargar();
    reg.setFechaIngreso(f);

    int fila, estante, contenedor;
    cout << "Nueva fila      : ";    cin >> fila;
    cout << "Nuevo estante   : ";    cin >> estante;
    cout << "Nuevo contenedor: ";    cin >> contenedor;

    char buf[20][20];
    for (int i = 0; i < 20; ++i)
        buf[i][0] = '\0';
    snprintf(buf[0], 20, "%d", fila);
    snprintf(buf[1], 20, "%d", estante);
    snprintf(buf[2], 20, "%d", contenedor);

    for (int i = 0; i < 3; ++i) {
        reg.setAlmacenamiento(i, buf[i]);
    }

    if (arc.modificar(reg, pos))
        cout << "\nIngreso (ID " << idIngreso << ") modificado correctamente!\n\n";
    else
        cout << "\nError al modificar el ingreso!\n\n";

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

void IngresosManager::restaurar() {
    IngresosArchivo arc;
    Ingresos reg;

    cout << "------ RESTAURAR INGRESO ------" << endl;
    cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;

    int idIngreso;
    cout << "ID Ingreso a restaurar: ";
    cin >> idIngreso;
    if (idIngreso == 0) return;

    int pos = arc.buscarPorIdIngreso(idIngreso);
    if (pos < 0) {
        cout << "\nNo existe un ingreso con ID " << idIngreso << ".\n\n";
    } else {
        reg = arc.leer(pos);
        if (reg.getEstado()) {
            cout << "\nEl ingreso (ID " << idIngreso << ") ya está activo.\n\n";
        } else {
            reg.setEstado(true);
            if (arc.modificar(reg, pos))
                cout << "\nIngreso (ID " << idIngreso << ") restaurado correctamente!\n\n";
            else
                cout << "\nError al restaurar el ingreso!\n\n";
        }
    }
    system("pause");
}
