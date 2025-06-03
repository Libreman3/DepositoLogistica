#include <iostream>
#include "menuProducto.h"
#include "productoManager.h"

using namespace std;

void MenuProducto::mostrar(){
    ProductoManager productoManager;
    int opcion;

    do {
        system("cls");
        cout << "  ---- PRODUCTOS ----" << endl<< endl;
        cout << "   1. CARGAR PRODUCTO" << endl;
        cout << "   2. MOSTRAR PRODUCTOS" << endl;
        cout << "   3. BUSCAR PRODUCTO" << endl;
        cout << "   4. MODIFICAR PRODUCTO" << endl;
        cout << "   5. ELIMINAR PRODUCTO" << endl;
        cout << "   6. RESTAURAR PRODUCTO" << endl;
        cout << "   0. VOLVER AL MENU PRINCIPAL" << endl<< endl;
        cin >> opcion;

        switch (opcion) {
        case 1:
            system("cls");
            productoManager.cargar();
            break;
        case 2:
            system("cls");
            productoManager.mostrar();
            break;
        case 3:
            system("cls");
            productoManager.buscar();
            break;
        case 4:
            system("cls");
            productoManager.modificar();
            break;
        case 5:
            system("cls");
            productoManager.eliminar();
            break;
        case 6:
            system("cls");
            productoManager.restaurar();
            break;
        case 0:
            break;
        default:
            system("cls");
            cout<<"Opcion incorrecta, por favor intente nuevamente"<<endl;
            system("pause");
            break;
        }
    } while (opcion != 0);
}
