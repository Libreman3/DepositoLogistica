#include <iostream>
#include <string>
#include "ProveedorManager.h"
#include "proveedor.h"
#include "proveedorArchivo.h"

using namespace std;

void ProveedorManager::cargar(){    //ACA SE CARGA CADA PERFIL DE PROVEEDOR
    int numeroProveedor, cuit;
    string razonSocial, direccion, mail;
    bool estado;

    Proveedor proveedor;
    ProveedorArchivo pArchivo;

    cout<<"------- CARGAR PROVEEDOR -------"<<endl;
    cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
    cout<< "Ingrese numero de Proveedor:";    //ESTO EN REALIDAD NO LO DEBERIA PREGUNTAR
    cin>>numeroProveedor;                     //SEDEBERIA CARGAR AUTOMATICAMENTE
    cout<< "Ingrese numero de CUIT: ";
    cin>>cuit;
    if(cuit==0){
        return;
    }
    while(cuit<1000000 || cuit>100000000){
        cout<< "El cuit ingresado es incorrecto, por favor intente nuevamente: ";
        cin>>cuit;
        if(cuit==0){
            return;
        }
    }
    cout<< "Ingrese Razon Social:";
    cin.ignore();
    getline(cin,razonSocial);
    if(razonSocial=="0"){
        return;
    }
    cout<< "Ingrese direccion:";
    getline(cin,direccion);
    if(direccion=="0"){
        return;
    }
    cout<< "Ingrese mail:";
    getline(cin,mail);
    if(mail=="0"){
        return;
    }
    estado = true;

    proveedor = Proveedor(numeroProveedor,cuit, razonSocial, direccion, mail, estado);

    if(pArchivo.guardar(proveedor)){    // AL FINALIZAR LA CARGA TE MUESTRA SI ESTA TODO OK O SI HUBO ALGUN ERROR
        cout<<endl<<"Se guardo correctamente!"<<endl<<endl;
        system("pause");
    }else{
        cout<<endl<< "Error inesperado!"<<endl<<endl;
        system("pause");
    }
}

void ProveedorManager::mostrar(){  //EN ESTE PROCESO BUSCA PRIMERO LA CANTIDAD DE PROVEEDORES CARGADOS,
    ProveedorArchivo pArchivo;     //PARA QUE FUNCIONE EL BUCLE DE MOSTRARLOS A TODOS
    Proveedor registro;

    int cantidadRegistros = pArchivo.getCantidadProveedores();  //CALCULA LA CANTIDAD DE PROVEEDORES CARGADOS

    for(int i=0; i<cantidadRegistros; i++){     //MUESTRA LOS PROVEEDORES CARGADOS
        registro = pArchivo.leer(i);

        if(registro.getEstado()== true){
            registro.tarjetaProveedor();
        }
    }
}

void ProveedorManager::buscar(){
    ProveedorArchivo pArchivo;
    Proveedor registro;

    int cuitBuscado;
    bool encontrado = false;

    cout<<"------ BUSCAR PROVEEDOR ------"<<endl;
    cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
    cout<< "Ingrese el cuit del proveedor que desea buscar: ";
    cin>>cuitBuscado;
    if(cuitBuscado==0){
        return;
    }

    int cantidadRegistros = pArchivo.getCantidadProveedores();

    for(int i=0; i<cantidadRegistros;i++){
        registro = pArchivo.leer(i);

        if(registro.getCuit()== cuitBuscado){
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
        int dato, cuit;
        string razonSocial, direccion, mail;

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
            if(cuit==0){
                return;
            }
            while(cuit<1000000 || cuit>100000000){
                cout<< "El cuit ingresado es incorrecto, por favor intente nuevamente: ";
                cin>>cuit;
                if(cuit==0){
                    return;
                }
            }
            registro.setCuit(cuit);
            if(pArchivo.modificar(registro,posicion)){
                cout<<endl<< "PROVEEDOR MODIFICADO"<<endl<<endl;
            } else{
                cout<<endl<< "HUBO UN ERROR INESPERADO"<<endl<<endl;
            }
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
            break;
        case 4:
            system("cls");
            cout<<"------ MODIFICAR PROVEEDOR ------"<<endl;
            cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
            cout << "Ingrese el nuevo mail: "<<endl;
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
            break;
        case 0:
            break;
        default:
            cout <<endl<< "OPCION INCORRECTA" <<endl<<endl;
            break;
        }
    }else{
        cout <<endl<< "NO EXISTE EL ID INGRESADO"<<endl<<endl;
    }
    system("pause");
}

void ProveedorManager::eliminar(){
    ProveedorArchivo pArchivo;

    Proveedor proveedor; //VER SI ES OBLIGATORIO ESTE USO

    int cuitEliminar;

    cout<<"------ ELIMINAR PROVEEDOR ------"<<endl;
    cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
    cout <<"Ingrese el cuit del proveedor que desea eliminar: ";
    cin >> cuitEliminar;
    if(cuitEliminar==0){
        return;
    }

    int posicion = pArchivo.buscarCuit(cuitEliminar);

    if(posicion>=0){
        Proveedor registro = pArchivo.leer(posicion);
        registro.setEstado(false);
        if(pArchivo.modificar(registro, posicion)){
            cout <<endl<< "PROVEEDOR ELIMINADO"<<endl<<endl;
        }else{
            cout <<endl<< "HUBO UN ERROR"<<endl<<endl;
        }

    }else{
        cout<<endl<< "NO EXISTE EL CUIT INGRESADO"<<endl<<endl;
    }
    system("pause");
}

void ProveedorManager::restaurar(){
    ProveedorArchivo pArchivo;

    Proveedor proveedor;

    int cuitRestaurar;

    cout<<"------ RESTAURAR PROVEEDOR ------"<<endl;
    cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
    cout << "Ingrese el cuit del proveedor eliminado que desea restaurar :";
    cin >> cuitRestaurar;
    if(cuitRestaurar==0){
        return;
    }

    int posicion = pArchivo.buscarCuit(cuitRestaurar);

    if(posicion>=0){
        Proveedor registro = pArchivo.leer(posicion);
        registro.setEstado(true);
        if(pArchivo.modificar(registro, posicion)){
            cout <<endl<< "PROVEEDOR RESTAURADO"<< endl<<endl;
        }else{
            cout <<endl<< "HUBO UN ERROR"<<endl<<endl;
        }

    }else{
        cout<<endl<< "NO EXISTE EL CUIT INGRESADO"<<endl<<endl;
    }
    system("pause");
}
