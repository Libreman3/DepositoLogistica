#include <iostream>
#include "menuCliente.h"
#include "clienteManager.h"

using namespace std;

void MenuCliente::mostrar(){
    ClienteManager clienteManager;
    int num;

    do{
        system("cls");
        cout << "  ---- CLIENTES ----" << endl<<endl;
        cout << "   1. CARGAR CLIENTE" << endl;
        cout << "   2. MOSTRAR CLIENTES" << endl;
        cout << "   3. BUSCAR CLIENTE" << endl;
        cout << "   4. MODIFICAR CLIENTE" << endl;
        cout << "   5. ELIMINAR CLIENTE" << endl;
        cout << "   6. RESTAURAR CLIENTE ELIMINADO" << endl;
        cout << "   0. VOLVER" << endl<<endl;
        cin>>num;
        switch(num){
            case 1:
                system("cls");
                clienteManager.cargar();
                break;
            case 2:
                system("cls");
                clienteManager.mostrar();
                system("pause");
                break;
            case 3:
                system("cls");
                clienteManager.buscar();
                break;
            case 4:
                system("cls");
                clienteManager.modificar();
                break;
            case 5:
                system("cls");
                clienteManager.eliminar();
                break;
            case 6:
                system("cls");
                clienteManager.restaurar();
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
