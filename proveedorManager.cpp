#include <iostream>
#include <string>
#include "proveedorManager.h"
#include "proveedor.h"
#include "proveedorArchivo.h"
#include <limits>

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
        cout<< "Ingrese Razón Social: ";
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
            continue;
        }
        bool mailRepetido=false;
        for(int i=0; i<numeroProveedor;i++){
            registro = pArchivo.leer(i);

            if(registro.getMail()== mail){
                cout<<endl<< "EL MAIL INGRESADO YA SE ENCUENTRA REGISTRADO!"<<endl<<endl;
                mailRepetido=true;
                break;
            }
        }
        if(!mailRepetido){
            break;
        }
    }while(true);

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

void ProveedorManager::buscar() {
    ProveedorArchivo pArchivo;
    Proveedor registro;

    int opcion;
    bool encontrado = false;

    cout << "------ BUSCAR PROVEEDOR ------" << endl;
    cout << "-- PRESIONE 0 PARA CANCELAR --" << endl << endl;

    cout << "Seleccione el atributo por el cual desea buscar:" << endl;
    cout << "1. Razon Social" << endl;
    cout << "2. ID" << endl;
    cout << "3. CUIT" << endl;
    cout << "4. Mail" << endl;
    cout << "5. Direccion" << endl; // Nueva opción agregada
    cout << "0. Cancelar" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    if (opcion == 0) {
        return;
    }

    string valorBuscado;
    int valorBuscadoInt = 0;

    int cantidadRegistros = pArchivo.getCantidadProveedores();

    // Limpiar buffer de entrada para usar getline después de cin >>
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (opcion) {
        case 1:
            cout << "Ingrese la Razon Social a buscar: ";
            getline(cin, valorBuscado);
            break;
        case 2:
            cout << "Ingrese el ID a buscar: ";
            cin >> valorBuscadoInt;
            break;
        case 3:
            cout << "Ingrese el CUIT a buscar: ";
            getline(cin, valorBuscado);
            break;
        case 4:
            cout << "Ingrese el Mail a buscar: ";
            getline(cin, valorBuscado);
            break;
        case 5:
            cout << "Ingrese la Direccion a buscar: ";
            getline(cin, valorBuscado);
            break;
        default:
            cout << "Opcion invalida." << endl;
            system("pause");
            return;
    }

    for (int i = 0; i < cantidadRegistros; i++) {
        registro = pArchivo.leer(i);

        bool coincide = false;
        switch (opcion) {
            case 1:
                if (registro.getRazonSocial().find(valorBuscado) != string::npos) {
                    coincide = true;
                }
                break;
            case 2:
                if (registro.getNumeroProveedor() == valorBuscadoInt) {
                    coincide = true;
                }
                break;
            case 3:
                if (registro.getCuit() == valorBuscado) {
                    coincide = true;
                }
                break;
            case 4:
                if (registro.getMail().find(valorBuscado) != string::npos) {
                    coincide = true;
                }
                break;
            case 5:
                if (registro.getDireccion().find(valorBuscado) != string::npos) {
                    coincide = true;
                }
                break;
        }

        if (coincide) {
            if (registro.getEstado() == true) {
                registro.tarjetaProveedor();
                encontrado = true;
                break;
            }
            encontrado = true;
            cout << "EL PROVEEDOR QUE ESTA BUSCANDO SE ENCUENTRA DADO DE BAJA!" << endl << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "NO SE ENCONTRÓ PROVEEDOR CON EL VALOR INGRESADO!" << endl << endl;
    }

    system("pause");
}

void ProveedorManager::modificar() {
    ProveedorArchivo pArchivo;
    Proveedor registro;
    bool encontrado = false;

    int opcionBusqueda;
    cout << "------ BUSCAR PROVEEDOR PARA MODIFICAR ------" << endl;
    cout << "-- PRESIONE 0 PARA CANCELAR --" << endl << endl;

    cout << "Seleccione el atributo por el cual desea buscar:" << endl;
    cout << "1. Razon Social" << endl;
    cout << "2. ID" << endl;
    cout << "3. CUIT" << endl;
    cout << "4. Mail" << endl;
    cout << "5. Dirección" << endl;
    cout << "0. Cancelar" << endl;
    cout << "Opcion: ";
    cin >> opcionBusqueda;

    if (opcionBusqueda == 0) return;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpiar buffer

    string valorBuscado;
    int valorBuscadoInt;
    int posicion = -1;

    int cantidadRegistros = pArchivo.getCantidadProveedores();

    // Pedir valor para buscar según opción
    switch (opcionBusqueda) {
        case 1:
            cout << "Ingrese la Razon Social a buscar: ";
            getline(cin, valorBuscado);
            break;
        case 2:
            cout << "Ingrese el ID a buscar: ";
            cin >> valorBuscadoInt;
            cin.ignore();
            break;
        case 3:
            cout << "Ingrese el CUIT a buscar: ";
            getline(cin, valorBuscado);
            break;
        case 4:
            cout << "Ingrese el Mail a buscar: ";
            getline(cin, valorBuscado);
            break;
        case 5:
            cout << "Ingrese la Dirección a buscar: ";
            getline(cin, valorBuscado);
            break;
        default:
            cout << "Opción inválida." << endl;
            system("pause");
            return;
    }

    // Buscar proveedor
    for (int i = 0; i < cantidadRegistros; i++) {
        registro = pArchivo.leer(i);
        bool coincide = false;

        switch (opcionBusqueda) {
            case 1:
                if (registro.getRazonSocial() == valorBuscado) coincide = true;
                break;
            case 2:
                if (registro.getNumeroProveedor() == valorBuscadoInt) coincide = true;
                break;
            case 3:
                if (registro.getCuit() == valorBuscado) coincide = true;
                break;
            case 4:
                if (registro.getMail() == valorBuscado) coincide = true;
                break;
            case 5:
                if (registro.getDireccion() == valorBuscado) coincide = true;
                break;
        }

        if (coincide) {
            posicion = i;
            break;
        }
    }

    if (posicion == -1) {
        cout << "NO SE ENCONTRÓ PROVEEDOR CON EL VALOR INGRESADO!" << endl << endl;
        system("pause");
        return;
    }

    registro = pArchivo.leer(posicion);

    if (!registro.getEstado()) {
        cout << "EL PROVEEDOR SE ENCUENTRA DADO DE BAJA, NO SE PUEDE MODIFICAR." << endl << endl;
        system("pause");
        return;
    }

    // Mostrar proveedor encontrado (puedes crear un método para mostrarlo más claro)
    cout << "\nProveedor encontrado:";
    registro.tarjetaProveedor();
    cout << endl;

    // Menú para modificar datos
    int dato;
    cout << "Seleccione el dato que desea modificar:" << endl;
    cout << "1. Número de CUIT" << endl;
    cout << "2. Razón Social" << endl;
    cout << "3. Dirección" << endl;
    cout << "4. Mail" << endl;
    cout << "0. Cancelar" << endl;
    cout << "Opción: ";
    cin >> dato;
    cin.ignore();

    switch (dato) {
        case 1: {
            string cuit;
            do {
                system("cls");
                cout << "------ MODIFICAR CUIT PROVEEDOR ------" << endl;
                cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;
                cout << "Ingrese número de CUIT: ";
                getline(cin, cuit);

                if (cuit == "0") return;
                if (cuit.empty()) {
                    cout << "POR FAVOR DEBE INGRESAR UN NÚMERO DE CUIT VÁLIDO!";
                    system("pause");
                    continue;
                }
                if (cuit.length() != 11) {
                    cout << "EL CUIT DEBE TENER EXACTAMENTE 11 CARACTERES!";
                    system("pause");
                    continue;
                }

                bool cuitRepetido = false;
                for (int i = 0; i < cantidadRegistros; i++) {
                    if (i == posicion) continue;
                    Proveedor otro = pArchivo.leer(i);
                    if (otro.getCuit() == cuit) {
                        cout << "EL CUIT INGRESADO YA SE ENCUENTRA REGISTRADO!\n\n";
                        system("pause");
                        cuitRepetido = true;
                        break;
                    }
                }
                if (!cuitRepetido) break;
            } while (true);

            registro.setCuit(cuit);
            break;
        }
        case 2: {
            string razonSocial;
            do {
                system("cls");
                cout << "------ MODIFICAR RAZÓN SOCIAL PROVEEDOR ------" << endl;
                cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;
                cout << "Ingrese la nueva razón social: ";
                getline(cin, razonSocial);

                if (razonSocial == "0") return;
                if (razonSocial.empty()) {
                    cout << "POR FAVOR DEBE INGRESAR UNA RAZÓN SOCIAL VÁLIDA!";
                    system("pause");
                    continue;
                }

                bool razonRepetida = false;
                for (int i = 0; i < cantidadRegistros; i++) {
                    if (i == posicion) continue;
                    Proveedor otro = pArchivo.leer(i);
                    if (otro.getRazonSocial() == razonSocial) {
                        cout << "LA RAZÓN SOCIAL INGRESADA YA SE ENCUENTRA REGISTRADA!";
                        system("pause");
                        razonRepetida = true;
                        break;
                    }
                }
                if (!razonRepetida) break;
            } while (true);

            registro.setRazonSocial(razonSocial);
            break;
        }
        case 3: {
            string direccion;
            do {
                system("cls");
                cout << "------ MODIFICAR DIRECCIÓN PROVEEDOR ------" << endl;
                cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;
                cout << "Ingrese la nueva dirección: ";
                getline(cin, direccion);

                if (direccion == "0") return;
                if (direccion.empty()) {
                    cout << "POR FAVOR DEBE INGRESAR UNA DIRECCIÓN VÁLIDA!";
                    system("pause");
                    continue;
                }
                break;
            } while (true);

            registro.setDireccion(direccion);
            break;
        }
        case 4: {
            string mail;
            do {
                system("cls");
                cout << "------ MODIFICAR MAIL PROVEEDOR ------" << endl;
                cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;
                cout << "Ingrese el nuevo mail: ";
                getline(cin, mail);

                if (mail == "0") return;
                if (mail.empty()) {
                    cout << "POR FAVOR DEBE INGRESAR UN MAIL VÁLIDO!";
                    system("pause");
                    continue;
                }

                bool mailRepetido = false;
                for (int i = 0; i < cantidadRegistros; i++) {
                    if (i == posicion) continue;
                    Proveedor otro = pArchivo.leer(i);
                    if (otro.getMail() == mail) {
                        cout << "EL MAIL INGRESADO YA SE ENCUENTRA REGISTRADO!";
                        system("pause");
                        mailRepetido = true;
                        break;
                    }
                }
                if (!mailRepetido) break;
            } while (true);

            registro.setMail(mail);
            break;
        }
        case 0:
            return;
        default:
            cout << "Opción inválida." << endl;
            system("pause");
            return;
    }

    if (pArchivo.modificar(registro, posicion)) {
        cout << "PROVEEDOR MODIFICADO CON ÉXITO.";
    } else {
        cout << "HUBO UN ERROR INESPERADO AL MODIFICAR.";
    }
    system("pause");
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
            cout << endl << "NO SE PUDO RESTAURAR EL PROVEEDOR PORQUE YA SE ENCUENTRA ACTIVO" << endl << endl;
        }
    }else{
        cout<<endl<< "NO EXISTE EL ID INGRESADO"<<endl<<endl;
    }
    system("pause");
}
