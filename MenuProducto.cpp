#include <iostream>
#include <cstring>
#include <string>
#include "producto.h"
#include "ProductoArchivo.h"
#include "ProductoManager.h"
#include "MenuProducto.h"

void MenuProducto::mostrarMenuProducto(){
     int opcion;
    ProductoManager manager;

    do {
        system("cls");
        cout << "===== MENU PRODUCTO =====" << endl;
        cout << "1. Cargar producto" << endl;
        cout << "2. Mostrar productos" << endl;
        cout << "3. Buscar producto por ID" << endl;
        cout << "4. Modificar producto" << endl;
        cout << "5. Eliminar producto" << endl;
        cout << "6. Restaurar producto" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "==========================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            manager.cargar();
            break;
        case 2:
            manager.mostrarProductos();
            break;
        case 3:
            manager.buscarProducto();
            break;
        case 4:
            manager.modificarProducto();
            break;
        case 5:
            manager.eliminarProducto();
            break;
        case 6:
            manager.restaurarProducto();
            break;
        case 0:
            cout << "Volviendo al menu principal..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
            system("pause");
            break;
        }

    } while (opcion != 0);

}



