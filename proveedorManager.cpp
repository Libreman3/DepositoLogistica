#include <iostream>
#include <string>
#include "proveedorManager.h"
#include "proveedor.h"
#include "proveedorArchivo.h"

using namespace std;

void ProveedorManager::cargar(){
    int numeroProveedor;
    string cuit, razonSocial, direccion, mail;
    bool estado;

    Proveedor proveedor;
    ProveedorArchivo pArchivo;

    cout<<"------- CARGAR PROVEEDOR -------"<<endl;
    cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;

    numeroProveedor = pArchivo.getCantidadProveedores() + 1;
    cout << "ID asignado autom�ticamente: " << numeroProveedor << endl;

    do{
        cout<< "Ingrese numero de CUIT:";
        cin.ignore();
        getline(cin,cuit);
        if(cuit=="0")return;
        if(cuit.empty()){
            cout<< "Por favor debe ingresar un numero de CUIT v�lido!"<<endl;
        }
    }while(cuit.empty());

    do{
        cout<< "Ingrese Razon Social:";
        getline(cin,razonSocial);
        if(razonSocial=="0")return;
        if(razonSocial.empty()){
            cout<< "POR FAVOR DEBE INGRESAR UNA RAZON SOCIAL V�LIDA!"<<endl;
        }
    }while(razonSocial.empty());

    do{
        cout<< "Ingrese direccion:";
        getline(cin,direccion);
        if(direccion=="0")return;
        if(direccion.empty()){
            cout<<endl<< "Por favor debe ingresar una direcci�n v�lida!"<<endl<<endl;
        }
    }while(direccion.empty());

    do{
        cout<< "Ingrese mail:";
        getline(cin,mail);
        if(mail=="0")return;
        if(mail.empty()){
            cout<<endl<< "POR FAVOR DEBE INGRESAR UN MAIL V�LIDO!"<<endl<<endl;
        }
    }while(mail.empty());

    estado = true;

    proveedor = Proveedor(numeroProveedor,cuit, razonSocial, direccion, mail, estado);

    if(pArchivo.guardar(proveedor)){
        cout<<endl<<"Se guardo correctamente!"<<endl<<endl;
        system("pause");
    }else{
        cout<<endl<< "Error inesperado!"<<endl<<endl;
        system("pause");
    }
}

void ProveedorManager::mostrar(){
    ProveedorArchivo pArchivo;
    Proveedor registro;

    int cantidadRegistros = pArchivo.getCantidadProveedores();

    for(int i=0; i<cantidadRegistros; i++){
        registro = pArchivo.leer(i);

        if(registro.getEstado()== true){
            registro.tarjetaProveedor();
        }
    }
}

void ProveedorManager::buscar(){
    ProveedorArchivo pArchivo;
    Proveedor registro;

    string cuitBuscado;
    bool encontrado = false;

    cout<<"------ BUSCAR PROVEEDOR ------"<<endl;
    cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
    cout<< "Ingrese el cuit del proveedor que desea buscar: ";
    cin>>cuitBuscado;
    if(cuitBuscado=="0"){
        return;
    }

    int cantidadRegistros = pArchivo.getCantidadProveedores();

    for(int i=0; i<cantidadRegistros;i++){
        registro = pArchivo.leer(i);

        if(registro.getCuit()== cuitBuscado && registro.getEstado()==true){
            registro.tarjetaProveedor();
            encontrado=true;
            break;
        }
    }
    if (encontrado == false){
        cout <<endl<< "NO SE ENCONTRO PROVEEDOR CON EL NUMERO DE CUIT INGRESADO!"<<endl<<endl;
    }
    system("pause");
}

void ProveedorManager::modificar(){
    ProveedorArchivo pArchivo;
    Proveedor proveedor;

    int idProveedor;

    cout<<"------ MODIFICAR PROVEEDOR ------"<<endl;
    cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
    cout << "Ingrese el ID del proveedor que desea modificar: ";
    cin >> idProveedor;
    if(idProveedor==0){
        return;
    }

    int posicion = pArchivo.buscarId(idProveedor);

    if(posicion>=0){
        Proveedor registro = pArchivo.leer(posicion);

        if(registro.getEstado()==true){

            int dato;
            string cuit, razonSocial, direccion, mail;

            system("cls");
            cout<<"------ MODIFICAR PROVEEDOR ------"<<endl<<endl;
            cout<< "INGRESE QUE DATO DESEA MODIFICAR:"<<endl;
            cout<< "1. Numero de CUIT"<<endl;
            cout<< "2. Razon Social"<<endl;
            cout<< "3. Direccion"<<endl;
            cout<< "4. Mail"<<endl;
            cout<< "0. Cancelar"<<endl;
            cout<< endl;
            cin >> dato;

            switch(dato){
            case 1:
                system("cls");
                cout<<"------ MODIFICAR PROVEEDOR ------"<<endl;
                cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
                cout << "Ingrese el nuevo numero de cuit: ";
                cin >> cuit;
                if(cuit=="0"){
                    return;
                }
                /*while(cuit<1000000 || cuit>100000000){
                    cout<< "El cuit ingresado es incorrecto, por favor intente nuevamente: ";
                    cin>>cuit;
                    if(cuit==0){
                        return;
                    }
                }*/
                registro.setCuit(cuit);
                if(pArchivo.modificar(registro,posicion)){
                    cout<<endl<< "PROVEEDOR MODIFICADO"<<endl<<endl;
                } else{
                    cout<<endl<< "HUBO UN ERROR INESPERADO"<<endl<<endl;
                }system("pause");
                return;
            case 2:
                system("cls");
                cout<<"------ MODIFICAR PROVEEDOR ------"<<endl;
                cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
                cout<< "Ingrese la nueva razon social: ";
                cin>> razonSocial;
                if(razonSocial=="0"){
                    return;
                }
                registro.setRazonSocial(razonSocial);
                if(pArchivo.modificar(registro,posicion)){
                    cout <<endl<< "PROVEEDOR MODIFICADO"<<endl<<endl;
                }else{
                    cout<<endl<< "HUBO UN ERROR INESPERADO"<<endl<<endl;
                }
                system("pause");
                break;
            case 3:
                system("cls");
                cout<<"------ MODIFICAR PROVEEDOR ------"<<endl;
                cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
                cout << "Ingrese la nueva direccion: ";
                cin >> direccion;
                if(direccion=="0"){
                    return;
                }
                registro.setDireccion(direccion);
                if(pArchivo.modificar(registro,posicion)){
                    cout <<endl<< "PROVEEDOR MODIFICADO"<<endl<<endl;
                }else{
                    cout <<endl<< "HUBO UN ERROR INESPERADO"<<endl<<endl;
                }
                system("pause");
                break;
            case 4:
                system("cls");
                cout<<"------ MODIFICAR PROVEEDOR ------"<<endl;
                cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
                cout << "Ingrese el nuevo mail: ";
                cin >> mail;
                if(mail=="0"){
                    return;
                }
                registro.setMail(mail);
                if(pArchivo.modificar(registro,posicion)){
                    cout <<endl<< "PROVEEDOR MODIFICADO"<< endl<<endl;
                }else{
                    cout <<endl<< "HUBO UN ERROR INESPERADO"<<endl<<endl;
                }
                system("pause");
                break;
            case 0:
                break;
            default:
                cout <<endl<< "OPCION INCORRECTA" <<endl<<endl;
                system("pause");
                break;
            }
        } else {
            cout<< endl<< "El ID ingresado se encuentra eliminado, debe darlo de alra para realizar modificaciones" <<endl<<endl;
            system("pause");
        }
    }else{
        cout <<endl<< "NO EXISTE EL ID INGRESADO"<<endl<<endl;
        system("pause");
    }
}

void ProveedorManager::eliminar(){
    ProveedorArchivo pArchivo;

    int idEliminar;

    cout<<"------ ELIMINAR PROVEEDOR ------"<<endl;
    cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
    cout <<"Ingrese el ID del proveedor que desea eliminar: ";
    cin >> idEliminar;
    if(idEliminar==0){
        return;
    }

    int posicion = pArchivo.buscarId(idEliminar);

    if(posicion>=0){
        Proveedor registro = pArchivo.leer(posicion);
        registro.setEstado(false);
        if(pArchivo.modificar(registro, posicion)){
            cout <<endl<< "PROVEEDOR ELIMINADO"<<endl<<endl;
        }else{
            cout <<endl<< "HUBO UN ERROR"<<endl<<endl;
        }

    }else{
        cout<<endl<< "NO EXISTE EL ID INGRESADO"<<endl<<endl;
    }
    system("pause");
}

void ProveedorManager::restaurar(){
    ProveedorArchivo pArchivo;

    int idRestaurar;

    cout<<"------ RESTAURAR PROVEEDOR ------"<<endl;
    cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
    cout << "Ingrese el ID del proveedor eliminado que desea restaurar :";
    cin >> idRestaurar;
    if(idRestaurar==0){
        return;
    }

    int posicion = pArchivo.buscarId(idRestaurar);

    if(posicion>=0){
        Proveedor registro = pArchivo.leer(posicion);
        registro.setEstado(true);
        if(pArchivo.modificar(registro, posicion)){
            cout <<endl<< "PROVEEDOR RESTAURADO"<< endl<<endl;
        }else{
            cout <<endl<< "HUBO UN ERROR"<<endl<<endl;
        }

    }else{
        cout<<endl<< "NO EXISTE EL ID INGRESADO"<<endl<<endl;
    }
    system("pause");
}
