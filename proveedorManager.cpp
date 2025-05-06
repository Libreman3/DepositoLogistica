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

    cout<< "Ingrese numero de Proveedor:";
    cin>>numeroProveedor;
    cout<< "Ingrese numero de CUIT: ";
    cin>>cuit;
    cout<< "Ingrese Razon Social:";
    cin.ignore();
    getline(cin,razonSocial);
    cout<< "Ingrese direccion:";
    getline(cin,direccion);
    cout<< "Ingrese mail:";
    getline(cin,mail);
    estado = true;

    proveedor = Proveedor(numeroProveedor,cuit, razonSocial, direccion, mail, estado);

    if(pArchivo.guardar(proveedor)){    // AL FINALIZAR LA CARGA TE MUESTRA SI ESTA TODO OK O SI HUBO ALGUN ERROR
        cout<<"Se guardo correctamente!"<<endl;
    }else{
        cout<< "error inesperado"<<endl;
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

    cout<< "INGRESE EL CUIT QUE DESEA BUSCAR: ";
    cin>>cuitBuscado;

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
        cout << "NO SE ENCONTRO PROVEEDOR CON EL NUMERO DE CUIT INGRESADO"<<endl;
    }
}

void ProveedorManager::modificar(){
    ProveedorArchivo pArchivo;
    Proveedor proveedor;

    int idProveedor;

    cout << "INGRESE EL ID DEL PROVEEDOR QUE DESEA MODIFICAR: ";
    cin >> idProveedor;

    int posicion = pArchivo.buscarId(idProveedor);

    if(posicion>=0){
        Proveedor registro = pArchivo.leer(posicion);
        int dato, cuit;
        string razonSocial, direccion, mail;

        system("cls");
        cout<< "INGRESE QUE DATO QUIERE MODIFICAR:"<<endl;
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
            cout << "INGRESE EL NUEVO NUMERO DE CUIT: ";
            cin >> cuit;
            registro.setCuit(cuit);
            if(pArchivo.modificar(registro,posicion)){
                cout<< "PROVEEDOR MODIFICADO"<<endl;
            } else{
                cout << "HUBO UN ERROR INESPERADO"<<endl;
            }
            return;
        case 2:
            system("cls");
            cout<< "INGRESE LA NUEVA RAZON SOCIAL: ";
            cin>> razonSocial;
            registro.setRazonSocial(razonSocial);
            if(pArchivo.modificar(registro,posicion)){
                cout << "PROVEEDOR MODIFICADO"<<endl;
            }else{
                cout << "HUBO UN ERROR INESPERADO"<<endl;
            }
            break;
        case 3:
            system("cls");
            cout << "INGRESE LA NUEVA DIRECCION: ";
            cin >> direccion;
            registro.setDireccion(direccion);
            if(pArchivo.modificar(registro,posicion)){
                cout << "PROVEEDOR MODIFICADO"<<endl;
            }else{
                cout << "HUBO UN ERROR INESPERADO"<<endl;
            }
            break;
        case 4:
            system("cls");
            cout << "INGRESE EL NUEVO MAIL: "<<endl;
            cin >> mail;
            registro.setMail(mail);
            if(pArchivo.modificar(registro,posicion)){
                cout << "PROVEEDOR MODIFICADO"<< endl;
            }else{
                cout << "HUBO UN ERROR INESPERADO"<<endl;
            }
            break;
        case 0:
            break;
        default:
            cout << "OPCION INCORRECTA" <<endl;
            break;
        }
    }else{
        cout << "NO EXISTE EL ID INGRESADO"<<endl;
    }
}

void ProveedorManager::eliminar(){
    ProveedorArchivo pArchivo;

    Proveedor proveedor; //VER SI ES OBLIGATORIO ESTE USO

    int cuitEliminar;

    cout << "INGRESE EL CUIT DEL PROVEEDOR QUE DESEA ELIMINAR: ";
    cin >> cuitEliminar;

    int posicion = pArchivo.buscarCuit(cuitEliminar);

    if(posicion>=0){
        Proveedor registro = pArchivo.leer(posicion);
        registro.setEstado(false);
        if(pArchivo.modificar(registro, posicion)){
            cout << "PROVEEDOR ELIMINADO"<< endl;
        }else{
            cout << "HUBO UN ERROR"<<endl;
        }

    }else{
        cout<< "NO EXISTE EL CUIT INGRESADO"<<endl;
    }
}

void ProveedorManager::restaurar(){
    ProveedorArchivo pArchivo;

    Proveedor proveedor;

    int cuitRestaurar;

    cout << "INGRESE EL CUIT DEL PROVEEDOR ELIMINADO QUE DESEA RESTAURAR: ";
    cin >> cuitRestaurar;

    int posicion = pArchivo.buscarCuit(cuitRestaurar);

    if(posicion>=0){
        Proveedor registro = pArchivo.leer(posicion);
        registro.setEstado(true);
        if(pArchivo.modificar(registro, posicion)){
            cout << "PROVEEDOR RESTAURADO"<< endl;
        }else{
            cout << "HUBO UN ERROR"<<endl;
        }

    }else{
        cout<< "NO EXISTE EL CUIT INGRESADO"<<endl;
    }
}
