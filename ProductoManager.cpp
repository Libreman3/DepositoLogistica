#include <iostream>
#include <string>
#include "Producto.h"
#include "ProductoArchivo.h"
#include "ProductoManager.h"
#include <cstring>
using namespace std;

void ProductoManager::cargar() {
    int idProducto;
    char nombre[50], marca[50], descripcion[100];
    bool estado = true;
    float precio;
    int cantidadStock;

    Producto producto;
    ProductoArchivo pArchivo;

    cout << "------- CARGAR PRODUCTO -------" << endl;
    cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;

    // ID automático
    idProducto = pArchivo.getCantidadProductos() + 1;
    cout << "ID asignado automáticamente: " << idProducto << endl;

    cout << " Los Id que no se muestran es por que estan en baja logica " << endl;

    cin.ignore(); // Limpiar el buffer antes de getline

    // Ingreso de nombre con validación
    do {
        cout << "Ingrese nombre del producto: ";
        cin.getline(nombre, 50);
        if (strlen(nombre) == 0 || strcmp(nombre, "0") == 0) {
            if (strcmp(nombre, "0") == 0) return;
            cout << "Debe ingresar un nombre válido." << endl;
        }
    } while (strlen(nombre) == 0);

    // Ingreso de marca con validación
    do {
        cout << "Ingrese marca del producto: ";
        cin.getline(marca, 50);
        if (strlen(marca) == 0 || strcmp(marca, "0") == 0) {
            if (strcmp(marca, "0") == 0) return;
            cout << "Debe ingresar una marca válida." << endl;
        }
    } while (strlen(marca) == 0);

    // Ingreso de descripción con validación
    do {
        cout << "Ingrese descripción del producto: ";
        cin.getline(descripcion, 100);
        if (strlen(descripcion) == 0 || strcmp(descripcion, "0") == 0) {
            if (strcmp(descripcion, "0") == 0) return;
            cout << "Debe ingresar una descripción válida." << endl;
        }
    } while (strlen(descripcion) == 0);

    // Ingreso de precio con validación
    do {
        cout << "Ingrese precio del producto: ";
        cin >> precio;
        if (precio <= 0) {
            cout << "¡El precio debe ser un número positivo!" << endl;
        }
    } while (precio <= 0);

    // Ingreso de stock con validación
    do {
        cout << "Ingrese cantidad de stock: ";
        cin >> cantidadStock;
        if (cantidadStock < 0) {
            cout << "¡El stock no puede ser negativo!" << endl;
        }
    } while (cantidadStock < 0);

    // Crear el producto
    producto = Producto(idProducto, precio, cantidadStock, descripcion, nombre, marca, estado);

    // Guardar en archivo
    if (pArchivo.guardar(producto)) {
        cout << "¡Producto guardado correctamente!" << endl;
    } else {
        cout << "Error al guardar el producto." << endl;
    }

    system("pause");
}

void ProductoManager::mostrarProductos() {
    ProductoArchivo pArchivo;
    Producto producto;
    int totalRegistros = 0;
    int productosMostrados = 0;

    cout << "------ LISTA DE PRODUCTOS ------" << endl;

    // Recorremos hasta que falle la lectura
    while (true) {
        producto = pArchivo.leer(totalRegistros); // leer por índice
        if (producto.get_IdProducto() == 0) {
            break; // Producto inválido, salimos
        }

        if (producto.get_Estado()) {
            producto.mostrarProducto();
            productosMostrados++;
        }

        totalRegistros++;
    }

    if (productosMostrados == 0) {
        cout << "No hay productos activos para mostrar." << endl;
    }

    cout << "Presione una tecla para continuar . . ." << endl;
    cin.ignore();
    cin.get();
}

void ProductoManager::buscarProducto() {
    ProductoArchivo pArchivo;
    Producto producto;

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
        producto = pArchivo.leer(i);

        if (producto.get_IdProducto() == idBuscado && producto.get_Estado() == true) {
            cout << "Producto encontrado:" << endl;
            producto.mostrarProducto();  // Mostrar producto solo si está activo
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << endl << "¡NO SE ENCONTRÓ PRODUCTO CON EL ID INGRESADO!" << endl << endl;
    }

    system("pause");
}

void ProductoManager::modificarProducto() {
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
        string entrada;
        float precio;
        int stock;
        bool estado;

        cin.ignore(); // Limpiar el buffer de entrada

        system("cls");
        cout << "------ MODIFICAR PRODUCTO ------" << endl << endl;
        cout << "¿QUÉ DATO DESEA MODIFICAR?" << endl;
        cout << "1. Nombre" << endl;
        cout << "2. Marca" << endl;
        cout << "3. Estado (Activo/Inactivo)" << endl;
        cout << "4. Precio" << endl;
        cout << "5. Stock" << endl;
        cout << "6. Descripción" << endl;
        cout << "0. Cancelar" << endl << endl;

        cin >> dato;
        cin.ignore(); // Limpiar el buffer

        switch (dato) {
        case 1:
            do {
                system("cls");
                cout << "Ingrese el nuevo nombre: ";
                getline(cin, entrada);
                if (entrada == "0") return;
                if (entrada.empty()) {
                    cout << "Debe ingresar un nombre válido.\n" << endl;
                }
            } while (entrada.empty());
            registro.set_Nombre(entrada);
            break;

        case 2:
            do {
                system("cls");
                cout << "Ingrese la nueva marca: ";
                getline(cin, entrada);
                if (entrada == "0") return;
                if (entrada.empty()) {
                    cout << "Debe ingresar una marca valida." << endl;
                }
            } while (entrada.empty());
            registro.set_Marca(entrada);
            break;

        case 3:
            system("cls");
            cout << "Ingrese el nuevo estado (1 = Activo, 0 = Inactivo): ";
            cin >> estado;
            if (estado != 0 && estado != 1) {
                cout << "Estado invalido." << endl;
                return;
            }
            registro.set_Estado(estado);
            break;

        case 4:
            do {
                system("cls");
                cout << "Ingrese el nuevo precio: ";
                cin >> precio;
                if (precio <= 0) {
                    cout << "Precio inválido. Debe ser mayor a 0." << endl;
                }
            } while (precio <= 0);
            registro.set_precio(precio);
            break;

        case 5:
            do {
                system("cls");
                cout << "Ingrese el nuevo stock: ";
                cin >> stock;
                if (stock < 0) {
                    cout << "Stock inválido. No puede ser negativo." << endl;
                }
            } while (stock < 0);
            registro.set_cantidadStock(stock);
            break;

        case 6:
            do {
                system("cls");
                cout << "Ingrese la nueva descripcion: ";
                getline(cin, entrada);
                if (entrada == "0") return;
                if (entrada.empty()) {
                    cout << "Debe ingresar una descripcion valida." << endl;
                }
            } while (entrada.empty());
            registro.set_descripcion(entrada);
            break;

        case 0:
            return;

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

void ProductoManager::eliminarProducto() {
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
        registro.set_Estado(false);  // Cambiar el estado a 'false' para indicar que el producto está eliminado.

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

void ProductoManager::restaurarProducto() {
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

        if (registro.get_Estado()) {
            cout << endl << "El producto ya está activo." << endl << endl;
        } else {
            registro.set_Estado(true);
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
