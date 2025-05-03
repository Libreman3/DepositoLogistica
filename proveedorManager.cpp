#include <iostream>
#include <string>
#include "ProveedorManager.h"
#include "proveedor.h"
#include "proveedorArchivo.h"

using namespace std;

void ProveedorManager::cargar(){    //ACA SE CARGA CADA PERFIL DE PROVEEDOR
    int numeroProveedor, cuit;
    string razonSocial, direccion, mail;
    bool eliminado;

    Proveedor proveedor;
    ProveedorArchivo pArchivo;

    cout<< "Ingrese numero de Proveedor:";
    cin>>numeroProveedor;
    cout<< "Ingrese numero de CUIT: ";
    cin>>cuit;
    cout<< "Ingrese Razon Social:";
    cin>>razonSocial;
    cout<< "Ingrese direccion:";
    cin.ignore();
    getline(cin,direccion);
    cout<< "Ingrese mail:";
    getline(cin,mail);

    proveedor = Proveedor(numeroProveedor,cuit, razonSocial, direccion, mail, eliminado);

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

    cout << "HAY UN TOTAL DE " << cantidadRegistros << " PROVEEDORES:"<<endl;

    for(int i=0; i<cantidadRegistros; i++){     //MUESTRA LOS PROVEEDORES CARGADOS
        registro = pArchivo.leer(i);

        registro.tarjetaProveedor();
    }
}
