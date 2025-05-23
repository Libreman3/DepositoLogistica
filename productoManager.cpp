#include <iostream>
#include <string>
#include "producto.h"
#include "productoArchivo.h"
#include "productoManager.h"
#include <cstring>
using namespace std;

void ProductoManager::cargar() {
    int idProducto;
    string nombre, marca;
    bool estado;

    Producto producto;
    ProductoArchivo pArchivo;

    cout << "------- CARGAR PRODUCTO -------" << endl;
    cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;

    // ID automático

    idProducto = pArchivo.getCantidadProductos() + 1;
    cout << "ID asignado automáticamente: " << idProducto << endl;

    /*cout<< "Ingrese numero de Producto:";    //ESTO EN REALIDAD NO LO DEBERIA PREGUNTAR
    cin>>idProducto;*/

    //cout << " Los Id que no se muestran es por que estan en baja logica " << endl;

     // Limpiar el buffer antes de getline

    // Ingreso de nombre con validación
    do {
        cout << "Ingrese nombre del producto: ";
        cin.ignore();
        getline(cin,nombre);

        if (nombre== "0") return;
        if(nombre.empty()){
            cout << "Debe ingresar un nombre válido." << endl;
        }
    } while (nombre.empty());

    // Ingreso de marca con validación
    do {
        cout << "Ingrese marca del producto: ";
        getline(cin,marca);
        if(marca== "0") return;
        if(marca.empty()){
            cout << "Debe ingresar una marca válida." << endl;
        }
    } while (marca.empty());

    estado = true;

    // Crear el producto
    producto = Producto(idProducto, nombre, marca, estado);

    // Guardar en archivo
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

    //int totalRegistros = 0;
    //int productosMostrados = 0;
    int cantidadRegistros = pArchivo.getCantidadProductos();

    cout << "------ LISTA DE PRODUCTOS ------" << endl;

    for(int i=0; i<cantidadRegistros; i++){
        producto = pArchivo.leer(i);

        if(producto.getEstado()==true){
            producto.tarjetaProducto();
        }
    }

    // Recorremos hasta que falle la lectura
    /*while (true) {
        producto = pArchivo.leer(totalRegistros); // leer por índice
        if (producto.get_IdProducto() == 0) {
            break; // Producto inválido, salimos
        }

        if (producto.get_Estado()) {
            producto.mostrarProducto();
            productosMostrados++;
        }

        totalRegistros++;
    }*/

    if (cantidadRegistros == 0) {
        cout << "No hay productos activos para mostrar." << endl;
    }

    cout << "Presione una tecla para continuar . . ." << endl;
    cin.ignore();
    cin.get();
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

    if (idBuscado == 0) {
        return;
    }

    int cantidadRegistros = pArchivo.getCantidadProductos();

    if (cantidadRegistros == 0) {
        cout << "El archivo está vacío. No se pueden buscar productos." << endl;
        return;
    }

    for (int i = 0; i < cantidadRegistros; i++) {
        registro = pArchivo.leer(i);

        if (registro.getIdProducto() == idBuscado && registro.getEstado() == true) {
            //cout << "Producto encontrado:" << endl;
            registro.tarjetaProducto();  // Mostrar producto solo si está activo
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << endl << "¡NO SE ENCONTRÓ PRODUCTO CON EL ID INGRESADO!" << endl << endl;
    }

    system("pause");
}

void ProductoManager::modificar() {
    ProductoArchivo pArchivo;
    Producto producto;

    int idProducto;

    cout << "------ MODIFICAR PRODUCTO ------" << endl;
    cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;
    cout << "Ingrese el ID del producto que desea modificar: ";
    cin >> idProducto;

    if (idProducto == 0) return;

    int posicion = pArchivo.buscarId(idProducto);

    if (posicion >= 0) {
        Producto registro = pArchivo.leer(posicion);
        int dato;
        string nombre, marca;

        cin.ignore(); // Limpiar el buffer de entrada

        system("cls");
        cout << "------ MODIFICAR PRODUCTO ------" << endl << endl;
        cout << "¿QUÉ DATO DESEA MODIFICAR?" << endl;
        cout << "1. Nombre" << endl;
        cout << "2. Marca" << endl;
        cout << "0. Cancelar" << endl << endl;
        cin >> dato;
        cin.ignore(); // Limpiar el buffer

        switch (dato) {
        case 1:
            do {
                system("cls");
                cout<<"------ MODIFICAR PRODUCTO ------"<<endl;
                cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
                cout << "Ingrese el nuevo nombre: ";
                cin>>nombre;
                if (nombre == "0") return;
                if (nombre.empty()) {
                    cout << "Debe ingresar un nombre válido.\n" << endl;
                }
            } while (nombre.empty());
            registro.setNombre(nombre);

            break;

        case 2:
            do {
                system("cls");
                cout<<"------ MODIFICAR PRODUCTO ------"<<endl;
                cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
                cout << "Ingrese la nueva marca: ";
                cin>>marca;
                if (marca == "0") return;
                if (marca.empty()) {
                    cout << "Debe ingresar una marca valida." << endl;
                }
            } while (marca.empty());
            registro.setMarca(marca);
            break;

        case 0:
            break;

        default:
            cout << "OPCIÓN INCORRECTA" << endl;
            return;
        }

        if (pArchivo.modificar(registro, posicion)) {
            cout << endl << "PRODUCTO MODIFICADO" << endl << endl;
        } else {
            cout << endl << "HUBO UN ERROR INESPERADO" << endl << endl;
        }

    } else {
        cout << endl << "NO EXISTE EL ID INGRESADO" << endl << endl;
    }

    system("pause");
}

void ProductoManager::eliminar() {
    ProductoArchivo pArchivo;

    Producto producto;  // Este puede ser opcional si no es necesario usarlo en este caso.

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
        registro.setEstado(false);  // Cambiar el estado a 'false' para indicar que el producto está eliminado.

        if (pArchivo.modificar(registro, posicion)) {
            cout << endl << "PRODUCTO ELIMINADO" << endl << endl;
        } else {
            cout << endl << "HUBO UN ERROR AL ELIMINAR EL PRODUCTO" << endl << endl;
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

        if (registro.getEstado()) {
            cout << endl << "El producto ya está activo." << endl << endl;
        } else {
            registro.setEstado(true);
            if (pArchivo.modificar(registro, posicion)) {
                cout << endl << "PRODUCTO RESTAURADO" << endl << endl;
            } else {
                cout << endl << "HUBO UN ERROR" << endl << endl;
            }
        }
    } else {
        cout << endl << "NO EXISTE EL ID INGRESADO" << endl << endl;
    }

    system("pause");
}
