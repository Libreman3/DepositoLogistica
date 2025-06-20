#include <iostream>
#include "menu.h"
#include "menuProveedor.h"
#include "menuProducto.h"
#include "menuCliente.h"
#include "menuIngresos.h"
#include "menuEgresos.h"

using namespace std;

void Menu::mostrar(){
    MenuProveedor menuProveedor;
    MenuProducto menuProducto;
    MenuCliente menuCliente;
    MenuIngresos menuIngresos;
    MenuEgresos menuEgresos;

    int num;

    cout << " -----------------------------------------------" << endl;
    cout << "| BIENVENIDO AL SISTEMA GESTIÓN PARA LOGÍSTICAS |" << endl;
    cout << " -----------------------------------------------" <<endl<< endl;
    system("pause");

    while(true){

        system("cls");

        cout << "--- MENU PRINCIPAL ---" << endl<<endl;
        cout << "   1. PROVEEDORES" << endl;
        cout << "   2. PRODUCTOS" << endl;
        cout << "   3. CLIENTES" << endl;
        cout << "   4. MOVIMIENTOS" << endl;
        cout << "   0. SALIR" << endl<<endl;
        cin>>num;

        switch(num){
            case 1:
                system("cls");
                menuProveedor.mostrar();
                break;
            case 2:
                system("cls");
                menuProducto.mostrar();
                break;
            case 3:
                system("cls");
                menuCliente.mostrar();
                /**/
                break;
            case 4:
                while(true){
                    system("cls");
                    cout << "  ---- MOVIMIENTOS ----" << endl<<endl;
                    cout << "   1. INGRESOS" << endl;
                    cout << "   2. EGRESOS" << endl;
                    cout << "   0. VOLVER" << endl<<endl;
                    cin>>num;
                    switch(num){
                        case 1:
                            system("cls");
                            menuIngresos.mostrar();
                            break;
                         case 2:
                            system("cls");
                            menuEgresos.mostrar();
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
