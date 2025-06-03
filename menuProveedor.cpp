#include <iostream>
#include "menuProveedor.h"
#include "ProveedorManager.h"

using namespace std;

void MenuProveedor::mostrar(){
    ProveedorManager proveedorManager;
    int num;

    do{
        system("cls");
        cout << "  ---- PROVEEDORES ----" << endl<<endl;
        cout << "   1. CARGAR PROVEEDOR" << endl;
        cout << "   2. MOSTRAR PROVEEDORES" << endl;
        cout << "   3. BUSCAR PROVEEDOR" << endl;
        cout << "   4. MODIFICAR PROVEEDOR" << endl;
        cout << "   5. ELIMINAR PROVEEDOR" << endl;
        cout << "   6. RESTAURAR PROVEEDOR ELIMINADO" << endl;
        cout << "   0. VOLVER" << endl<<endl;
        cin>>num;

        switch(num){
            case 1:
                system("cls");
                proveedorManager.cargar();
                break;
            case 2:
                system("cls");
                proveedorManager.mostrar();
                system("pause");
                break;
            case 3:
                system("cls");
                proveedorManager.buscar();
                break;
            case 4:
                system("cls");
                proveedorManager.modificar();
                break;
            case 5:
                system("cls");
                proveedorManager.eliminar();
                break;
            case 6:
                system("cls");
                proveedorManager.restaurar();
                break;
            case 0:
                break;
            default:
                system("cls");
                cout<<"Opcion incorrecta, por favor intente nuevamente"<<endl;
                system("pause");
                break;
        }
    } while (num != 0);
}
