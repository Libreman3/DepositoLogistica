#include <iostream>
#include <limits>
#include "menuEgresos.h"
#include "egresosManager.h"

using namespace std;

void MenuEgresos::mostrar() {
    EgresosManager mgr;
    int opcion = -1;

    do {
        system("cls");
        cout << "==== MENU EGRESOS ====\n\n";
        cout << "1. Cargar egreso\n";
        cout << "2. Mostrar egresos\n";
        cout << "3. Buscar egreso\n";
        cout << "4. Eliminar egreso\n";
        cout << "0. Volver al menu principal\n\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        system("cls");
        switch (opcion) {
            case 1: mgr.cargar();    break;
            case 2: mgr.mostrar();   break;
            case 3: mgr.buscar();    break;
            case 4: mgr.eliminar();  break;
            case 0:                  break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }

        if (opcion != 0) {
            cout << "\nPresione ENTER para continuar...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
    } while (opcion != 0);
}
