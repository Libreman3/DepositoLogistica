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
        cout << "==== MENÚ INGRESOS ====\n\n";
        cout << "1. Cargar ingreso\n";
        cout << "2. Mostrar ingresos\n";
        cout << "3. Buscar ingreso\n";
        cout << "4. Modificar ingreso\n";
        cout << "5. Eliminar ingreso\n";
        cout << "6. Restaurar ingreso\n";
        cout << "0. Volver al menú principal\n\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        system("cls");
        switch (opcion) {
            case 1: mgr.cargar();    break;
            case 2: mgr.mostrar();   break;
            case 3: mgr.buscar();    break;
            case 4: mgr.modificar(); break;
            case 5: mgr.eliminar();  break;
            case 6: mgr.restaurar(); break;
            case 0: /* Salir */      break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
        }

        if (opcion != 0) {
            cout << "\nPresione ENTER para continuar...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
    } while (opcion != 0);
}
