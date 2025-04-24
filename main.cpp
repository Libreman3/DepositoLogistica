#include <iostream>

using namespace std;

int main()
{
    int menu, num;
    Proveedor proveedor;

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
        cin>>menu;

        switch(menu){
            case 1:
                while(true){
                    system("cls");
                    cout << "  ---- PROVEEDORES ----" << endl<<endl;
                    cout << "   1. CARGAR PROVEEDOR" << endl;
                    cout << "   2. CONSULTAR PROVEEDOR" << endl;
                    cout << "   3. MODIFICAR PROVEEDOR" << endl;
                    cout << "   4. ELIMINAR PROVEEDOR" << endl;
                    cout << "   0. VOLVER" << endl<<endl;
                    cin>>num;

                    switch(num){
                        case 1:
                            system("cls");
                            cout << "funcion de cargar proveedor" << endl;
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            cout << "funcion de consultar proveedor" << endl;
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            cout << "funcion de modificar proveedor" << endl;
                            system("pause");
                            break;
                        case 4:
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
                return 0;
            default:
                system("cls");
                cout<<"Opcion incorrecta, por favor intente nuevamente"<<endl;
                system("pause");
                break;
        }
    }
}

