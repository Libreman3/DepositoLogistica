#include <iostream>
#include "clienteManager.h"
#include "cliente.h"
#include "clienteArchivo.h"
#include <limits>
using namespace std;

void ClienteManager::cargar(){
    string dni, nombre, apellido, direccion, mail;
    bool estado;

    Cliente cliente;
    ClienteArchivo cArchivo;
    Cliente registro;

    cout<<"------- CARGAR CLIENTE -------"<<endl;
    cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;

    int numeroCliente = cArchivo.getCantidadClientes()+1;
    cout<< "ID asignado autom�ticamente: "<< numeroCliente<<endl;

    cout<< "Ingrese n�mero de DNI: ";
    cin.ignore();
    getline(cin,dni);

    do{
        if(dni=="0"){
            return;
        }
        if(dni.empty()){
            cout << endl << "POR FAVOR DEBE INGRESAR UN N�MERO DE DNI V�LIDO!" <<endl <<endl;
            cout<< "Ingrese n�mero de DNI: ";
            getline(cin,dni);
            continue;
        }
        if(dni.length()<7||dni.length()>8){
            cout<< endl << "EL DNI DEBE TENER ENTRE 7 Y 8 CARACTERES!"<<endl<<endl;
            cout<< "Ingrese n�mero de DNI: ";
            getline(cin,dni);
            continue;
        }
        bool dniRepetido=false;
        for(int i =0; i<numeroCliente;i++){
            registro = cArchivo.leer(i);

            if(registro.getDni()==dni){
                cout<<endl<< "EL DNI INGRESADO YA SE ENCUENTRA REGISTRADO!"<<endl<<endl;
                cout<< "Ingrese numero de DNI: ";
                getline(cin,dni);
                dniRepetido=true;
                break;
            }
        }
        if(!dniRepetido){
            break;
        }
    }while(true);

    do{
        cout<< "Ingrese el nombre: ";
        getline(cin,nombre);
        if(nombre=="0")return;
        if(nombre.empty()){
            cout<<endl<<"POR FAVOR DEBE INGRESAR UN NOMBRE V�LIDO!"<<endl<<endl;
        }
    }while(nombre.empty());

    do{
        cout<< "Ingrese el apellido: ";
        getline(cin,apellido);
        if(apellido=="0")return;
        if(apellido.empty()){
            cout<<endl<<"POR FAVOR DEBE INGRESAR UN APELLIDO V�LIDO!"<<endl<<endl;
        }
    }while(apellido.empty());

    do{
        cout<< "Ingrese la direcci�n: ";
        getline(cin,direccion);
        if(direccion=="0")return;
        if(direccion.empty()){
            cout<<endl<<"POR FAVOR DEBE INGRESAR UNA DIRECCION  V�LIDA!"<<endl<<endl;
        }
    }while(direccion.empty());

    do{
        cout<< "Ingrese mail:";
        getline(cin,mail);
        if(mail=="0")return;
        if(mail.empty()){
            cout<<endl<< "POR FAVOR DEBE INGRESAR UN MAIL V�LIDO!"<<endl<<endl;
            continue;
        }
        bool mailRepetido=false;
        for(int i=0; i<numeroCliente;i++){
            registro = cArchivo.leer(i);

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

    cliente = Cliente(numeroCliente,dni, nombre, apellido, direccion, mail, estado);

    if(cArchivo.guardar(cliente)){
        cout<<endl<<"Se guard� correctamente!"<<endl<<endl;
        system("pause");
    }else{
        cout<<endl<< "Error inesperado!"<<endl<<endl;
        system("pause");
    }
}

void ClienteManager::mostrar(){
    ClienteArchivo cArchivo;
    Cliente registro;

    int cantidadRegistros = cArchivo.getCantidadClientes();

    cout<<"------- LISTA DE CLIENTES ACTIVOS -------"<<endl<<endl;

    for(int i=0; i<cantidadRegistros; i++){
        registro = cArchivo.leer(i);

        if(registro.getEstado()== true){
            registro.tarjetaCliente();
        }
    }
}

void ClienteManager::buscar() {
    ClienteArchivo cArchivo;
    Cliente registro;

    int opcion;
    bool encontrado = false;

    cout << "------ BUSCAR CLIENTE ------" << endl;
    cout << "-- PRESIONE 0 PARA CANCELAR --" << endl << endl;

    cout << "Seleccione el atributo por el cual desea buscar:" << endl;
    cout << "1. DNI" << endl;
    cout << "2. ID" << endl;
    cout << "3. Nombre" << endl;
    cout << "4. Mail" << endl;
    cout << "5. Direccion" << endl;
    cout << "6. Apellido" << endl;
    cout << "0. Cancelar" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    if (opcion == 0) {
        return;
    }

    string valorBuscado;
    int valorBuscadoInt = 0;

    int cantidadRegistros = cArchivo.getCantidadClientes();

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (opcion) {
        case 1:
            cout << "Ingrese el DNI a buscar: ";
            getline(cin, valorBuscado);
            break;
        case 2:
            cout << "Ingrese el ID a buscar: ";
            cin >> valorBuscadoInt;
            break;
        case 3:
            cout << "Ingrese el Nombre a buscar: ";
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
        case 6:
            cout << "Ingrese el Apellido a buscar: ";
            getline(cin, valorBuscado);
            break;
        default:
            cout << "Opcion invalida." << endl;
            system("pause");
            return;
    }

    for (int i = 0; i < cantidadRegistros; i++) {
        registro = cArchivo.leer(i);

        bool coincide = false;
        switch (opcion) {
            case 1:
                if (registro.getDni() == valorBuscado) {
                    coincide = true;
                }
                break;
            case 2:
                if (registro.getNumeroCliente() == valorBuscadoInt) {
                    coincide = true;
                }
                break;
            case 3:
                if (registro.getNombre().find(valorBuscado) != string::npos) {
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
            case 6:
                if (registro.getApellido().find(valorBuscado) != string::npos) {
                    coincide = true;
                }
                break;
        }

        if (coincide) {
            if (registro.getEstado()) {
                registro.tarjetaCliente(); // imprime todo ordenado
            } else {
                cout << "EL CLIENTE QUE ESTA BUSCANDO SE ENCUENTRA DADO DE BAJA!" << endl << endl;
            }
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "NO SE ENCONTR� CLIENTE CON EL VALOR INGRESADO!" << endl << endl;
    }

    system("pause");
}


void ClienteManager::modificar() {
    ClienteArchivo cArchivo;
    Cliente registro;
    bool encontrado = false;

    int opcionBusqueda;
    cout << "------ BUSCAR CLIENTE PARA MODIFICAR ------" << endl;
    cout << "-- PRESIONE 0 PARA CANCELAR --" << endl << endl;

    cout << "Seleccione el atributo por el cual desea buscar:" << endl;
    cout << "1. DNI" << endl;
    cout << "2. ID" << endl;
    cout << "3. Nombre" << endl;
    cout << "4. Mail" << endl;
    cout << "5. Direcci�n" << endl;
    cout << "6. Apellido" << endl;
    cout << "0. Cancelar" << endl;
    cout << "Opcion: ";
    cin >> opcionBusqueda;

    if (opcionBusqueda == 0) return;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpiar buffer

    string valorBuscado;
    int valorBuscadoInt;
    int posicion = -1;

    int cantidadRegistros = cArchivo.getCantidadClientes();

    // Pedir valor para buscar seg�n opci�n
    switch (opcionBusqueda) {
        case 1:
            cout << "Ingrese el DNI a buscar: ";
            getline(cin, valorBuscado);
            break;
        case 2:
            cout << "Ingrese el ID a buscar: ";
            cin >> valorBuscadoInt;
            cin.ignore();
            break;
        case 3:
            cout << "Ingrese el Nombre a buscar: ";
            getline(cin, valorBuscado);
            break;
        case 4:
            cout << "Ingrese el Mail a buscar: ";
            getline(cin, valorBuscado);
            break;
        case 5:
            cout << "Ingrese la Direcci�n a buscar: ";
            getline(cin, valorBuscado);
            break;
        case 6:
            cout << "Ingrese el Apellido a buscar: ";
            getline(cin, valorBuscado);
            break;
        default:
            cout << "Opci�n inv�lida." << endl;
            system("pause");
            return;
    }

    // Buscar cliente
    for (int i = 0; i < cantidadRegistros; i++) {
        registro = cArchivo.leer(i);
        bool coincide = false;

        switch (opcionBusqueda) {
            case 1:
                if (registro.getDni() == valorBuscado) coincide = true;
                break;
            case 2:
                if (registro.getNumeroCliente() == valorBuscadoInt) coincide = true;
                break;
            case 3:
                if (registro.getNombre() == valorBuscado) coincide = true;
                break;
            case 4:
                if (registro.getMail() == valorBuscado) coincide = true;
                break;
            case 5:
                if (registro.getDireccion() == valorBuscado) coincide = true;
                break;
            case 6:
                if (registro.getApellido() == valorBuscado) coincide = true;
                break;
        }

        if (coincide) {
            posicion = i;
            break;
        }
    }

    if (posicion == -1) {
        cout << "NO SE ENCONTR� CLIENTE CON EL VALOR INGRESADO!" << endl << endl;
        system("pause");
        return;
    }

    registro = cArchivo.leer(posicion);

    if (!registro.getEstado()) {
        cout << "EL CLIENTE SE ENCUENTRA DADO DE BAJA, NO SE PUEDE MODIFICAR." << endl << endl;
        system("pause");
        return;
    }

    // Mostrar cliente encontrado (asumiendo que ten�s m�todo para mostrar)
    cout << "\nCliente encontrado:" << endl;
    registro.tarjetaCliente();

    // Men� para modificar datos
    int dato;
    cout << "Seleccione el dato que desea modificar:" << endl;
    cout << "1. N�mero de DNI" << endl;
    cout << "2. Nombre" << endl;
    cout << "3. Apellido" << endl;
    cout << "4. Direcci�n" << endl;
    cout << "5. Mail" << endl;
    cout << "0. Cancelar" << endl;
    cout << "Opci�n: ";
    cin >> dato;
    cin.ignore();

    string nuevoValor;
    switch (dato) {
        case 1: {
            do {
                system("cls");
                cout << "------ MODIFICAR DNI CLIENTE ------" << endl;
                cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;
                cout << "Ingrese el nuevo n�mero de DNI: ";
                getline(cin, nuevoValor);

                if (nuevoValor == "0") return;
                if (nuevoValor.empty()) {
                    cout << "POR FAVOR DEBE INGRESAR UN N�MERO DE DNI V�LIDO!" << endl;
                    system("pause");
                    continue;
                }
                if (nuevoValor.length() < 7 || nuevoValor.length() > 8) {
                    cout << "EL DNI DEBE TENER ENTRE 7 Y 8 CARACTERES!" << endl;
                    system("pause");
                    continue;
                }
                bool dniRepetido = false;
                for (int i = 0; i < cantidadRegistros; i++) {
                    if (i == posicion) continue;
                    Cliente otro = cArchivo.leer(i);
                    if (otro.getDni() == nuevoValor) {
                        cout << "EL DNI INGRESADO YA SE ENCUENTRA REGISTRADO!" << endl;
                        system("pause");
                        dniRepetido = true;
                        break;
                    }
                }
                if (!dniRepetido) break;
            } while (true);
            registro.setDni(nuevoValor);
            break;
        }
        case 2: {
            do {
                system("cls");
                cout << "------ MODIFICAR NOMBRE CLIENTE ------" << endl;
                cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;
                cout << "Ingrese el nuevo nombre: ";
                getline(cin, nuevoValor);
                if (nuevoValor == "0") return;
                if (nuevoValor.empty()) {
                    cout << "POR FAVOR DEBE INGRESAR UN NOMBRE V�LIDO!" << endl;
                    system("pause");
                }
            } while (nuevoValor.empty());
            registro.setNombre(nuevoValor);
            break;
        }
        case 3: {
            do {
                system("cls");
                cout << "------ MODIFICAR APELLIDO CLIENTE ------" << endl;
                cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;
                cout << "Ingrese el nuevo apellido: ";
                getline(cin, nuevoValor);
                if (nuevoValor == "0") return;
                if (nuevoValor.empty()) {
                    cout << "POR FAVOR DEBE INGRESAR UN APELLIDO V�LIDO!" << endl;
                    system("pause");
                }
            } while (nuevoValor.empty());
            registro.setApellido(nuevoValor);
            break;
        }
        case 4: {
            do {
                system("cls");
                cout << "------ MODIFICAR DIRECCI�N CLIENTE ------" << endl;
                cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;
                cout << "Ingrese la nueva direcci�n: ";
                getline(cin, nuevoValor);
                if (nuevoValor == "0") return;
                if (nuevoValor.empty()) {
                    cout << "POR FAVOR DEBE INGRESAR UNA DIRECCI�N V�LIDA!" << endl;
                    system("pause");
                }
            } while (nuevoValor.empty());
            registro.setDireccion(nuevoValor);
            break;
        }
        case 5: {
            do {
                system("cls");
                cout << "------ MODIFICAR MAIL CLIENTE ------" << endl;
                cout << "-- PRESIONE '0' PARA CANCELAR --" << endl << endl;
                cout << "Ingrese el nuevo mail: ";
                getline(cin, nuevoValor);
                if (nuevoValor == "0") return;
                if (nuevoValor.empty()) {
                    cout << "POR FAVOR DEBE INGRESAR UN MAIL V�LIDO!" << endl;
                    system("pause");
                    continue;
                }
                bool mailRepetido = false;
                for (int i = 0; i < cantidadRegistros; i++) {
                    if (i == posicion) continue;
                    Cliente otro = cArchivo.leer(i);
                    if (otro.getMail() == nuevoValor) {
                        cout << "EL MAIL INGRESADO YA SE ENCUENTRA REGISTRADO!" << endl;
                        system("pause");
                        mailRepetido = true;
                        break;
                    }
                }
                if (!mailRepetido) break;
            } while (true);
            registro.setMail(nuevoValor);
            break;
        }
        case 0:
            return;
        default:
            cout << "Opci�n inv�lida." << endl;
            system("pause");
            return;
    }

    if (cArchivo.modificar(registro, posicion)) {
        cout << "CLIENTE MODIFICADO CON �XITO." << endl;
    } else {
        cout << "HUBO UN ERROR INESPERADO AL MODIFICAR." << endl;
    }
    system("pause");
}

void ClienteManager::eliminar(){
    ClienteArchivo cArchivo;

    int idEliminar;

    cout<<"------ ELIMINAR CLIENTE ------"<<endl;
    cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
    cout <<"Ingrese el ID del cliente que desea eliminar: ";
    cin >> idEliminar;
    if(idEliminar==0){
        return;
    }

    int posicion = cArchivo.buscarId(idEliminar);

    if(posicion>=0){
        Cliente registro = cArchivo.leer(posicion);
        if(registro.getEstado()==true){
            registro.setEstado(false);
            if(cArchivo.modificar(registro, posicion)){
                cout <<endl<< "CLIENTE ELIMINADO"<<endl<<endl;
            }else{
                cout <<endl<< "HUBO UN ERROR"<<endl<<endl;
            }
        }else{
            cout << endl << "NO SE PUDO ELIMINAR EL CLIENTE PORQUE YA SE ENCUENTRA DADO DE BAJA"<< endl << endl;
        }
    }else{
        cout<<endl<< "NO EXISTE EL ID INGRESADO"<<endl<<endl;
    }
    system("pause");
}

void ClienteManager::restaurar(){
    ClienteArchivo cArchivo;

    int idRestaurar;

    cout<<"------ RESTAURAR CLIENTE ------"<<endl;
    cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
    cout << "Ingrese el ID del cliente eliminado que desea restaurar :";
    cin >> idRestaurar;
    if(idRestaurar==0){
        return;
    }

    int posicion = cArchivo.buscarId(idRestaurar);

    if(posicion>=0){
        Cliente registro = cArchivo.leer(posicion);
        if(registro.getEstado()==false){
            registro.setEstado(true);
            if(cArchivo.modificar(registro, posicion)){
                cout <<endl<< "CLIENTE RESTAURADO"<< endl<<endl;
            }else{
                cout <<endl<< "HUBO UN ERROR"<<endl<<endl;
            }
        }else{
            cout<<endl<< "NO SE PUDO RESTAURAR EL CLIENTE PORQUE YA SE ENCUENTRA ACTIVO" <<endl <<endl;
        }

    }else{
        cout<<endl<< "NO EXISTE EL ID INGRESADO"<<endl<<endl;
    }
    system("pause");
}

