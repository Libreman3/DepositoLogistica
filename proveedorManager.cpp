#include <iostream>
#include <string>
#include "proveedorManager.h"
#include "proveedor.h"
#include "proveedorArchivo.h"

using namespace std;

void ProveedorManager::cargar(){
    string cuit, razonSocial, direccion, mail;
    bool estado;


    Proveedor proveedor;
    ProveedorArchivo pArchivo;
    Proveedor registro;

    cout<<"------- CARGAR PROVEEDOR -------"<<endl;
    cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;

    int numeroProveedor = pArchivo.getCantidadProveedores() + 1;
    cout << "ID asignado automáticamente: " << numeroProveedor << endl;

    cout<< "Ingrese número de CUIT: ";
    cin.ignore();
    getline(cin,cuit);

    do{
        if(cuit=="0"){
            return;
        }
        if(cuit.empty()){
            cout<<endl<< "POR FAVOR DEBE INGRESAR UN NÚMERO DE CUIT VÁLIDO!"<<endl<<endl;
            cout<< "Ingrese número de CUIT: ";
            getline(cin,cuit);
            continue;
        }
        if(cuit.length()!=11){
            cout << endl<< "EL CUIT DEBE TENER EXACTAMENTE 11 CARACTERES!" << endl <<endl;
            cout<< "Ingrese número de CUIT: ";
            getline(cin,cuit);
            continue;
        }
        bool cuitRepetido=false;
        for(int i=0; i<numeroProveedor;i++){
            registro = pArchivo.leer(i);

            if(registro.getCuit()== cuit){
                cout<<endl<< "EL CUIT INGRESADO YA SE ENCUENTRA REGISTRADO!"<<endl<<endl;
                cout<< "Ingrese número de CUIT: ";
                getline(cin,cuit);
                cuitRepetido=true;
                break;
            }
        }
        if(!cuitRepetido){
            break;
        }

    }while(true);

    do{
        cout<< "Ingrese Razón Social:";
        getline(cin,razonSocial);
        if(razonSocial=="0")return;
        if(razonSocial.empty()){
            cout<<endl<< "POR FAVOR DEBE INGRESAR UNA RAZÓN SOCIAL VÁLIDA!"<<endl<<endl;
            continue;
        }
        bool razonRepetida=false;
        for(int i=0; i<numeroProveedor;i++){
            registro = pArchivo.leer(i);

            if(registro.getRazonSocial()== razonSocial){
                cout<<endl<< "LA RAZÓN SOCIAL INGRESADA YA SE ENCUENTRA REGISTRADA!"<<endl<<endl;
                razonRepetida=true;
                break;
            }
        }
        if(!razonRepetida){
            break;
        }
    }while(true);

    do{
        cout<< "Ingrese dirección: ";
        getline(cin,direccion);
        if(direccion=="0")return;
        if(direccion.empty()){
            cout<<endl<< "POR FAVOR DEBE INGRESAR UNA DIRECCIÓN VÁLIDA!"<<endl<<endl;
        }
    }while(direccion.empty());

    do{
        cout<< "Ingrese mail: ";
        getline(cin,mail);
        if(mail=="0")return;
        if(mail.empty()){
            cout<<endl<< "POR FAVOR DEBE INGRESAR UN MAIL VÁLIDO!"<<endl<<endl;
        }
    }while(mail.empty());

    estado = true;

    proveedor = Proveedor(numeroProveedor,cuit, razonSocial, direccion, mail, estado);

    if(pArchivo.guardar(proveedor)){
        cout<<endl<<"Se guardó correctamente!"<<endl<<endl;
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

    cout<<"------- LISTA DE PROVEEDORES ACTIVOS -------"<<endl<<endl;

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

        if(registro.getCuit()== cuitBuscado){
            if(registro.getEstado()==true){
                registro.tarjetaProveedor();
                encontrado=true;
                break;
            }
            encontrado=true;
            cout << endl << "EL PROVEEDOR QUE ESTA BUSCANDO SE ENCUENTRA DADO DE BAJA!"<< endl<<endl;
            break;
        }
    }
    if (encontrado == false){
        cout <<endl<< "NO SE ENCONTRÓ PROVEEDOR CON EL NÚMERO DE CUIT INGRESADO!"<<endl<<endl;
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
            int cantidadRegistros = pArchivo.getCantidadProveedores();

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

                cout<< "Ingrese número de CUIT: ";
                cin.ignore();
                getline(cin,cuit);

                do{
                    if(cuit=="0"){
                        return;
                    }
                    if(cuit.empty()){
                        cout<<endl<< "POR FAVOR DEBE INGRESAR UN NÚMERO DE CUIT VÁLIDO!"<<endl<<endl;
                        cout<< "Ingrese número de CUIT: ";
                        getline(cin,cuit);
                        continue;
                    }
                    if(cuit.length()!=11){
                        cout << endl<< "EL CUIT DEBE TENER EXACTAMENTE 11 CARACTERES!" << endl <<endl;
                        cout<< "Ingrese numero de CUIT: ";
                        getline(cin,cuit);
                        continue;
                    }
                    bool cuitRepetido=false;
                    for(int i=0; i<cantidadRegistros;i++){

                        Proveedor registroSecundario = pArchivo.leer(i);

                        if(registroSecundario.getCuit()== cuit){
                            cout<<endl<< "EL CUIT INGRESADO YA SE ENCUENTRA REGISTRADO!"<<endl<<endl;
                            cout<< "Ingrese número de CUIT: ";
                            getline(cin,cuit);
                            cuitRepetido=true;
                            break;
                        }
                    }
                    if(!cuitRepetido){
                        break;
                    }
                }while(true);

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
                do{
                    cout<< "Ingrese la nueva razón social: ";
                    getline(cin,razonSocial);
                    if(razonSocial=="0")return;
                    if(razonSocial.empty()){
                        cout<<endl<< "POR FAVOR DEBE INGRESAR UNA RAZÓN SOCIAL VÁLIDA!"<<endl<<endl;
                        continue;
                    }
                    bool razonRepetida=false;
                    for(int i=0; i<cantidadRegistros;i++){
                        Proveedor registroSecundario = pArchivo.leer(i);

                        if(registroSecundario.getRazonSocial()== razonSocial){
                            cout<<endl<< "LA RAZÓN SOCIAL INGRESADA YA SE ENCUENTRA REGISTRADA!"<<endl<<endl;
                            razonRepetida=true;
                            break;
                        }
                    }
                    if(!razonRepetida){
                        break;
                    }
                }while(true);
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
                do{
                    cout << "Ingrese la nueva dirección: ";
                    getline(cin,direccion);
                    if(direccion=="0")return;
                    if(direccion.empty()){
                        cout<<endl<< "POR FAVOR DEBE INGRESAR UNA DIRECCIÓN VÁLIDA!"<<endl<<endl;
                    }
                }while(direccion.empty());
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
                do{
                    cout << "Ingrese el nuevo mail: ";
                    getline(cin,mail);
                    if(mail=="0")return;
                    if(mail.empty()){
                        cout<<endl<< "POR FAVOR DEBE INGRESAR UN MAIL VÁLIDO!"<<endl<<endl;
                    }
                }while(mail.empty());
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
                cout <<endl<< "OPCIÓN INCORRECTA" <<endl<<endl;
                system("pause");
                break;
            }
        } else {
            cout<< endl<< "El ID ingresado se encuentra eliminado, debe darlo de alta para realizar modificaciones" <<endl<<endl;
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
        if(registro.getEstado()==true){
            registro.setEstado(false);
            if(pArchivo.modificar(registro, posicion)){
                cout <<endl<< "PROVEEDOR ELIMINADO"<<endl<<endl;
            }else{
                cout <<endl<< "HUBO UN ERROR"<<endl<<endl;
            }
        }else{
            cout << endl << "NO SE PUDO ELIMINAR EL PROVEEDOR PORQUE YA SE ENCUENTRA DADO DE BAJA"<< endl << endl;
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
        if(registro.getEstado()==false){
            registro.setEstado(true);
            if(pArchivo.modificar(registro, posicion)){
                cout <<endl<< "PROVEEDOR RESTAURADO"<< endl<<endl;
            }else{
                cout <<endl<< "HUBO UN ERROR"<<endl<<endl;
            }
        }else{
            cout << endl << "NO SE PUSO RESTAURAR EL PROVEEDOR PORQUE YA SE ENCUENTRA ACTIVO" << endl << endl;
        }
    }else{
        cout<<endl<< "NO EXISTE EL ID INGRESADO"<<endl<<endl;
    }
    system("pause");
}
