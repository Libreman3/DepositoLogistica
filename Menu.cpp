#include <iostream>
#include "menu.h"
#include "ProveedorManager.h"
#include "clienteManager.h"
#include "menuProducto.h"

using namespace std;

void Menu::mostrar(){
    ProveedorManager proveedorManager;
    MenuProducto menuProducto;
    ClienteManager clienteManager;

    int num;

    cout << " -----------------------------------------------" << endl;
    cout << "| BIENVENIDO AL SISTEMA GESTION PARA LOGISTICAS |" << endl;
    cout << " -----------------------------------------------" <<endl<< endl;
    system("pause");

    while(true){

        system("cls");

        cout << "--- MENU PRINCIPAL ---" << endl<<endl;
        cout << "   1. PROVEEDORES" << endl;
        cout << "   2. PRODUCTOS" << endl;
        cout << "   3. CLIENTES" << endl;
        cout << "   4. MOVIMIENTOS" << endl;
        cout << "   0. SALIR" << endl;
        cin>>num;

        switch(num){
            case 1:
                while(true){
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
                            system("cls");
                            break;
                        default:
                            system("cls");
                            cout<<"Opcion incorrecta, por favor intente nuevamente"<<endl;
                            system("pause");
                            break;
                    }

                    break;
                }
                break;
            case 2:
                system("cls");
                menuProducto.mostrar();
                break;
            case 3:
                while(true){
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
                           system("cls");
                            break;
                        default:
                            system("cls");
                            cout<<"Opcion incorrecta, por favor intente nuevamente"<<endl;
                            system("pause");
                            break;
                    }
                    if (num==0){
                        break;
                    }
                }
                break;
            case 4:
                while(true){
                    system("cls");
                    cout << "  ---- MOVIMIENTOS ----" << endl<<endl;
                    cout << "   1. CARGAR INGRESO" << endl;
                    cout << "   2. CARGAR EGRESO" << endl;
                    cout << "   0. VOLVER" << endl<<endl;
                    cin>>num;
                    switch(num){
                        case 1:
                            system("cls");
                            cout << "funcion de cargar ingreso" << endl;
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            cout << "funcion de cargar egreso" << endl;
                            system("pause");
                            break;
                        case 0:
                            system("cls");
                            break;
                        default:
                            system("cls");
                            cout<<"Opcion incorrecta, por favor intente nuevamente"<<endl;
                            system("pause");
                            break;
                    }
                    if (num==0){
                        break;
                    }
                }
                break;
            case 0:
                system("cls");
                return;
            default:
                system("cls");
                cout<<"Opcion incorrecta, por favor intente nuevamente"<<endl;
                system("pause");
                break;
        }
    }
}
