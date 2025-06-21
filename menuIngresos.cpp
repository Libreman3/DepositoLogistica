#include <iostream>
#include <cstdlib>
#include <limits>
#include "menuIngresos.h"
#include "ingresosManager.h"

using namespace std;

void MenuIngresos::mostrar() {
    IngresosManager mgr;
    int opcion = -1;

    do {
        system("cls");
        cout << "==== MENU INGRESOS ====\n\n";
        cout << "1. Cargar ingreso\n";
        cout << "2. Mostrar ingresos\n";
        cout << "3. Buscar ingreso\n";
        cout << "4. Eliminar ingreso\n";
        cout << "0. Volver al menú principal\n\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        system("cls");
        switch (opcion) {
            case 1: mgr.cargar();    break;
            case 2: mgr.mostrar();   break;
            case 3: mgr.buscar();    break;
            case 4: mgr.eliminar();  break;
            case 0: /* Salir */      break;
            default:
                cout << "Opción invalida. Intente de nuevo.\n";
        }

    } while (opcion != 0);
}
