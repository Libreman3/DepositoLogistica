#include <iostream>
#include "menu.h"
#include "ProveedorManager.h"

using namespace std;

void Menu::mostrar(){
    ProveedorManager proveedorManager;

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
                    cout << "   0. VOLVER" << endl<<endl;
                    cin>>num;

                    switch(num){
                        case 1:
                            system("cls");
                            proveedorManager.cargar();
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            proveedorManager.mostrar();
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            cout << "funcion de buscar proveedor" << endl;
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            cout << "funcion de modificar proveedor" << endl;
                            system("pause");
                            break;
                        case 5:
                            system("cls");
                            cout << "funcion de eliminar proveedor" << endl;
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
                    if(num==0){
                        break;
                    }
                }
                break;
            case 2:
                while(true){
                    system("cls");
                    cout << "  ---- PRODUCTOS ----" << endl<<endl;
                    cout << "   1. CARGAR PRODUCTO" << endl;
                    cout << "   2. CONSULTAR PRODUCTO" << endl;
                    cout << "   3. MODIFICAR PRODUCTO" << endl;
                    cout << "   4. ELIMINAR PRODUCTO" << endl;
                    cout << "   0. VOLVER" << endl<<endl;
                    cin>>num;
                    switch(num){
                        case 1:
                            system("cls");
                            cout << "funcion de cargar producto" << endl;
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            cout << "funcion de consultar producto" << endl;
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            cout << "funcion de modificar producto" << endl;
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            cout << "funcion de eliminar producto" << endl;
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
            case 3:
                while(true){
                    system("cls");
                    cout << "  ---- CLIENTES ----" << endl<<endl;
                    cout << "   1. CARGAR CLIENTE" << endl;
                    cout << "   2. CONSULTAR CLIENTE" << endl;
                    cout << "   3. MODIFICAR CLIENTE" << endl;
                    cout << "   4. ELIMINAR CLIENTER" << endl;
                    cout << "   0. VOLVER" << endl<<endl;
                    cin>>num;
                    switch(num){
                        case 1:
                            system("cls");
                            cout << "funcion de cargar cliente" << endl;
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            cout << "funcion de consultar cliente" << endl;
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            cout << "funcion de modificar cliente" << endl;
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            cout << "funcion de eliminar cliente" << endl;
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
