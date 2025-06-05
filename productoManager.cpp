#include <iostream>
#include "productoManager.h"
#include "producto.h"
#include "productoArchivo.h"

using namespace std;

void ProductoManager::cargar() {
    int idProducto;
    string nombre, marca;
    bool estado;

    Producto producto;
    ProductoArchivo pArchivo;
    Producto registro;

    cout << "-------- CARGAR PRODUCTO -------" << endl;
    cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;

    idProducto = pArchivo.getCantidadProductos() + 1;
    cout << "ID asignado automáticamente: " << idProducto << endl;

    cout << "Ingrese nombre del producto: ";
    cin.ignore();
    getline(cin,nombre);

    do {
        if(nombre== "0") return;
        if(nombre.empty()){
            cout << endl<<"POR FAVOR INGRESE UN NOMBRE VÁLIDO!" << endl<< endl;
            cout << "Ingrese nombre del producto: ";
            getline(cin,nombre);
            continue;
        }
    } while (nombre.empty());


    do {
        cout << "Ingrese marca del producto: ";
        getline(cin,marca);
        if(marca== "0") return;
        if(marca.empty()){
            cout << endl<<"POR FAVOR INGRESE UNA MARCA VÁLIDA!" << endl<<endl;
            continue;
        }
        bool productoMarcaRepetido = false;
        for(int i=0;i<idProducto;i++){
            registro = pArchivo.leer(i);

            if(registro.getNombre()==nombre && registro.getMarca()==marca){
                cout<<endl<< "LA MARCA INGRESADA YA POSEE ESTE PRODUCTO REGISTRADO!"<<endl<<endl;
                productoMarcaRepetido = true;
                break;
            }
        }
        if(!productoMarcaRepetido){
            break;
        }
    } while (true);

    estado = true;

    producto = Producto(idProducto, nombre, marca, estado);

    if (pArchivo.guardar(producto)) {
        cout <<endl<< "¡Producto guardado correctamente!" << endl<<endl;
    } else {
        cout <<endl<< "Error al guardar el producto." << endl<<endl;
    }

    system("pause");
}

void ProductoManager::mostrar() {
    ProductoArchivo pArchivo;
    Producto producto;

    int cantidadRegistros = pArchivo.getCantidadProductos();

    cout << "------ LISTA DE PRODUCTOS ACTIVOS ------" <<endl<<endl;

    for(int i=0; i<cantidadRegistros; i++){
        producto = pArchivo.leer(i);

        if(producto.getEstado()==true){
            producto.tarjetaProducto();
        }
    }
}

void ProductoManager::buscar() {
    ProductoArchivo pArchivo;
    Producto registro;

    int idBuscado;
    bool encontrado = false;

    cout << "------ BUSCAR PRODUCTO ------" << endl;
    cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;
    cout << "Ingrese el ID del producto que desea buscar: ";
    cin >> idBuscado;
    cout << endl;

    if (idBuscado == 0) {
        return;
    }

    int cantidadRegistros = pArchivo.getCantidadProductos();

    for (int i = 0; i < cantidadRegistros; i++) {
        registro = pArchivo.leer(i);

        if (registro.getIdProducto() == idBuscado){
                if(registro.getEstado() == true){
                    registro.tarjetaProducto();
                    encontrado = true;
                    break;
                }
                encontrado=true;
                cout<< "EL PRODUCTO QUE ESTA BUSCANDO SE ENCUENTRA DADO DE BAJA!" <<endl<<endl;
        }
    }
    if (encontrado==false){
        cout << endl << "NO SE ENCONTRÓ PRODUCTO CON EL ID INGRESADO!" << endl << endl;
    }
    system("pause");
}

void ProductoManager::modificar() {
    ProductoArchivo pArchivo;
    Producto producto;

    int idProducto;
    int cantidadRegistros = pArchivo.getCantidadProductos();

    cout << "------ MODIFICAR PRODUCTO ------" << endl;
    cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;
    cout << "Ingrese el ID del producto que desea modificar: ";
    cin >> idProducto;

    if (idProducto == 0) return;

    int posicion = pArchivo.buscarId(idProducto);

    if (posicion >= 0) {
        Producto registro = pArchivo.leer(posicion);

        if(registro.getEstado()==true){
            int dato;
            string nombre, marca;

            system("cls");
            cout << "------ MODIFICAR PRODUCTO ------" << endl << endl;
            cout << "¿QUÉ DATO DESEA MODIFICAR?" << endl;
            cout << "1. Nombre" << endl;
            cout << "2. Marca" << endl;
            cout << "0. Cancelar" << endl << endl;
            cin >> dato;
            cin.ignore();

            switch (dato) {
            case 1:
                system("cls");
                cout<<"------ MODIFICAR NOMBRE PRODUCTO ------"<<endl;
                cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;

                cout << "Ingrese el nuevo nombre: ";
                getline(cin,nombre);
                do {
                    if (nombre == "0") return;
                    if (nombre.empty()) {
                        cout << endl<<"POR FAVOR DEBE INGRESAR UN NOMBRE VÁLIDO!" << endl<<endl;
                        cout << "Ingrese nombre del producto: ";
                        getline(cin,nombre);
                        continue;
                    }
                } while (nombre.empty());

                registro.setNombre(nombre);
                if(pArchivo.modificar(registro,posicion)){
                    cout<<endl<< "PRODUCTO MODIFICADO"<<endl<<endl;
                } else{
                    cout<<endl<< "HUBO UN ERROR INESPERADO"<<endl<<endl;
                }system("pause");
                return;

            case 2:
                system("cls");
                cout<<"----- MODIFICAR MARCA PRODUCTO -----"<<endl;
                cout<<"---- PRESIONE '0' PARA CANCELAR ----"<<endl<<endl;
                do {
                    cout << "Ingrese marca del producto: ";
                    getline(cin,marca);
                    if(marca== "0") return;
                    if(marca.empty()){
                        cout << endl<<"POR FAVOR INGRESE UNA MARCA VÁLIDA!" << endl<<endl;
                        continue;
                    }
                    bool productoMarcaRepetido = false;
                    for(int i=0;i<cantidadRegistros;i++){

                        Producto registroSecundario = pArchivo.leer(i);

                        if(registroSecundario.getNombre()==nombre && registroSecundario.getMarca()==marca){
                            cout<<endl<< "LA MARCA INGRESADA YA POSEE ESTE PRODUCTO REGISTRADO!"<<endl<<endl;
                            productoMarcaRepetido = true;
                            break;
                        }
                    }
                    if(!productoMarcaRepetido){
                        break;
                    }
                } while (true);

                registro.setMarca(marca);
                if(pArchivo.modificar(registro,posicion)){
                    cout <<endl<< "PRODUCTO MODIFICADO"<<endl<<endl;
                }else{
                    cout<<endl<< "HUBO UN ERROR INESPERADO"<<endl<<endl;
                }
                system("pause");
                break;
            case 0:
                break;
            default:
                cout << "OPCIÓN INCORRECTA" << endl;
                system("pause");
                return;
            }
        }else{
            cout << endl << "EL ID INGRESADO SE ENCUENTRA ELIMINADO, DEBE DARLO DE ALTA PARA REALIZAR MODIFICACIONES!"<<endl<<endl;
            system("pause");
        }
    } else {
        cout << endl << "NO EXISTE EL ID INGRESADO" << endl << endl;
        system("pause");
    }
}

void ProductoManager::eliminar() {
    ProductoArchivo pArchivo;

    int idProductoEliminar;

    cout << "------ ELIMINAR PRODUCTO ------" << endl;
    cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;
    cout << "Ingrese el ID del producto que desea eliminar: ";
    cin >> idProductoEliminar;

    if (idProductoEliminar == 0) {
        return;
    }

    int posicion = pArchivo.buscarId(idProductoEliminar);

    if (posicion >= 0) {
        Producto registro = pArchivo.leer(posicion);
        if(registro.getEstado()==true){
            registro.setEstado(false);
            if (pArchivo.modificar(registro, posicion)) {
                cout << endl << "PRODUCTO ELIMINADO" << endl << endl;
            } else {
                cout << endl << "HUBO UN ERROR AL ELIMINAR EL PRODUCTO" << endl << endl;
            }
        }else{
            cout << endl << "NO SE PUDO ELIMINAR EL PRODUCTO PORQUE YA SE ENCUENTRA DADO DE BAJA!"<<endl<<endl;
        }
    } else {
        cout << endl << "NO EXISTE EL ID INGRESADO" << endl << endl;
    }
    system("pause");
}

void ProductoManager::restaurar() {
    ProductoArchivo pArchivo;
    Producto producto;

    int idRestaurar;

    cout << "------ RESTAURAR PRODUCTO ------" << endl;
    cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;
    cout << "Ingrese el ID del producto eliminado que desea restaurar: ";
    cin >> idRestaurar;

    if (idRestaurar == 0) {
        return;
    }

    int posicion = pArchivo.buscarId(idRestaurar);

    if (posicion >= 0) {
        Producto registro = pArchivo.leer(posicion);
        if(registro.getEstado()==false){
            registro.setEstado(true);
            if (pArchivo.modificar(registro, posicion)) {
                cout << endl << "PRODUCTO RESTAURADO" << endl << endl;
            } else {
                cout << endl << "HUBO UN ERROR" << endl << endl;
            }
        }else{
            cout << endl << "NO SE PUDO RESTAURAR EL PRODUCTO PORQUE YA SE ENCUENTRA ACTIVO" <<endl<<endl;
        }
    } else {
        cout << endl << "NO EXISTE EL ID INGRESADO" << endl << endl;
    }
    system("pause");
}
