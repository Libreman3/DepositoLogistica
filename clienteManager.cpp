#include <iostream>
#include "clienteManager.h"
#include "cliente.h"
#include "clienteArchivo.h"

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
    cout<< "ID asignado automáticamente: "<< numeroCliente<<endl;

    cout<< "Ingrese número de DNI: ";
    cin.ignore();
    getline(cin,dni);

    do{
        if(dni=="0"){
            return;
        }
        if(dni.empty()){
            cout << endl << "POR FAVOR DEBE INGRESAR UN NÚMERO DE DNI VÁLIDO!" <<endl <<endl;
            cout<< "Ingrese número de DNI: ";
            getline(cin,dni);
            continue;
        }
        if(dni.length()<7||dni.length()>8){
            cout<< endl << "EL DNI DEBE TENER ENTRE 7 Y 8 CARACTERES!"<<endl<<endl;
            cout<< "Ingrese número de DNI: ";
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
            cout<<endl<<"POR FAVOR DEBE INGRESAR UN NOMBRE VÁLIDO!"<<endl<<endl;
        }
    }while(nombre.empty());

    do{
        cout<< "Ingrese el apellido: ";
        getline(cin,apellido);
        if(apellido=="0")return;
        if(apellido.empty()){
            cout<<endl<<"POR FAVOR DEBE INGRESAR UN APELLIDO VÁLIDO!"<<endl<<endl;
        }
    }while(apellido.empty());

    do{
        cout<< "Ingrese la dirección: ";
        getline(cin,direccion);
        if(direccion=="0")return;
        if(direccion.empty()){
            cout<<endl<<"POR FAVOR DEBE INGRESAR UNA DIRECCION  VÁLIDA!"<<endl<<endl;
        }
    }while(direccion.empty());

    do{
        cout<< "Ingrese mail:";
        getline(cin,mail);
        if(mail=="0")return;
        if(mail.empty()){
            cout<<endl<< "POR FAVOR DEBE INGRESAR UN MAIL VÁLIDO!"<<endl<<endl;
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
        cout<<endl<<"Se guardó correctamente!"<<endl<<endl;
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

void ClienteManager::buscar(){
    ClienteArchivo cArchivo;
    Cliente registro;

    string dniBuscado;
    bool encontrado = false;

    cout<<"------ BUSCAR CLIENTE ------"<<endl;
    cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
    cout<< "Ingrese el DNI del cliente que desea buscar: ";
    cin>>dniBuscado;
    cout<<endl;
    if(dniBuscado=="0"){
        return;
    }

    int cantidadRegistros = cArchivo.getCantidadClientes();

    for(int i=0; i<cantidadRegistros;i++){
        registro = cArchivo.leer(i);

        if(registro.getDni()== dniBuscado){
            if(registro.getEstado()==true){
                registro.tarjetaCliente();
                encontrado=true;
                break;
            }
            encontrado=true;
            cout << "EL CLIENTE QUE ESTA BUSCANDO SE ENCUENTRA DADO DE BAJA!"<<endl<<endl;
            break;
        }
    }
    if (encontrado == false){
        cout << "NO SE ENCONTRÓ CLIENTE CON EL NÚMERO DE DNI INGRESADO!"<<endl<<endl;
    }
    system("pause");
}

void ClienteManager::modificar(){
    ClienteArchivo cArchivo;
    Cliente cliente;

    int idCliente;

    cout<<"------ MODIFICAR CLIENTE ------"<<endl;
    cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
    cout << "Ingrese el ID del cliente que desea modificar: ";
    cin >> idCliente;
    if(idCliente==0){
        return;
    }

    int posicion = cArchivo.buscarId(idCliente);

    if(posicion>=0){
        Cliente registro = cArchivo.leer(posicion);

        if(registro.getEstado()==true){
            int dato;
            string dni, nombre, apellido, direccion, mail;
            int cantidadRegistros = cArchivo.getCantidadClientes();

            system("cls");
            cout<<"------ MODIFICAR CLIENTE ------"<<endl<<endl;
            cout<< "INGRESE QUE DATO DESEA MODIFICAR:"<<endl;
            cout<< "1. Número de DNI"<<endl;
            cout<< "2. Nombre"<<endl;
            cout<< "3. Apellido"<<endl;
            cout<< "4. Dirección"<<endl;
            cout<< "5. Mail"<<endl;
            cout<< "0. Cancelar"<<endl;
            cout<< endl;
            cin >> dato;
            cin.ignore();

            switch(dato){
            case 1:
                system("cls");
                cout<<"------ MODIFICAR DNI CLIENTE ------"<<endl;
                cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
                cout << "Ingrese el nuevo número de DNI: ";
                getline(cin,dni);

                do{
                    if(dni=="0"){
                        return;
                    }
                    if(dni.empty()){
                        cout << endl << "POR FAVOR DEBE INGRESAR UN NÚMERO DE DNI VÁLIDO!" <<endl <<endl;
                        cout<< "Ingrese número de DNI: ";
                        getline(cin,dni);
                        continue;
                    }
                    if(dni.length()<7||dni.length()>8){
                        cout<< endl << "EL DNI DEBE TENER ENTRE 7 Y 8 CARACTERES!"<<endl<<endl;
                        cout<< "Ingrese número de DNI: ";
                        getline(cin,dni);
                        continue;
                    }
                    bool dniRepetido=false;
                    for(int i; i<cantidadRegistros;i++){

                        Cliente registroSecundario = cArchivo.leer(i);

                        if(registroSecundario.getDni()==dni){
                            cout<<endl<< "EL DNI INGRESADO YA SE ENCUENTRA REGISTRADO!"<<endl<<endl;
                            cout<< "Ingrese número de DNI: ";
                            getline(cin,dni);
                            dniRepetido=true;
                            break;
                        }
                    }
                    if(!dniRepetido){
                        break;
                    }
                }while(true);

                registro.setDni(dni);
                if(cArchivo.modificar(registro,posicion)){
                    cout<<endl<< "CLIENTE MODIFICADO"<<endl<<endl;
                } else{
                    cout<<endl<< "HUBO UN ERROR INESPERADO"<<endl<<endl;
                }system("pause");
                return;
            case 2:
                system("cls");
                cout<<"------ MODIFICAR NOMBRE CLIENTE ------"<<endl;
                cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
                do{
                    cout<< "Ingrese el nuevo nombre: ";
                    getline(cin,nombre);
                    if(nombre=="0")return;
                    if(nombre.empty()){
                        cout<<endl<<"POR FAVOR DEBE INGRESAR UN NOMBRE VÁLIDO!"<<endl<<endl;
                    }
                }while(nombre.empty());
                registro.setNombre(nombre);
                if(cArchivo.modificar(registro,posicion)){
                    cout <<endl<< "CLIENTE MODIFICADO"<<endl<<endl;
                }else{
                    cout<<endl<< "HUBO UN ERROR INESPERADO"<<endl<<endl;
                }system("pause");
                break;
            case 3:
                system("cls");
                cout<<"------ MODIFICAR APELLIDO CLIENTE ------"<<endl;
                cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
                do{
                    cout<< "Ingrese el nuevo apellido: ";
                    getline(cin,apellido);
                    if(apellido=="0")return;
                    if(apellido.empty()){
                        cout<<endl<<"POR FAVOR DEBE INGRESAR UN APELLIDO VÁLIDO!"<<endl<<endl;
                    }
                }while(apellido.empty());
                registro.setApellido(apellido);
                if(cArchivo.modificar(registro,posicion)){
                    cout <<endl<< "CLIENTE MODIFICADO"<<endl<<endl;
                }else{
                    cout<<endl<< "HUBO UN ERROR INESPERADO"<<endl<<endl;
                }system("pause");
                break;
            case 4:
                system("cls");
                cout<<"------ MODIFICAR DIRECCIÓN CLIENTE ------"<<endl;
                cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
                do{
                    cout<< "Ingrese la nueva dirección: ";
                    getline(cin,direccion);
                    if(direccion=="0")return;
                    if(direccion.empty()){
                        cout<<endl<<"POR FAVOR DEBE INGRESAR UNA DIRECCIÓN VÁLIDA!"<<endl<<endl;
                    }
                }while(direccion.empty());
                registro.setDireccion(direccion);
                if(cArchivo.modificar(registro,posicion)){
                    cout <<endl<< "CLIENTE MODIFICADO"<<endl<<endl;
                }else{
                    cout <<endl<< "HUBO UN ERROR INESPERADO"<<endl<<endl;
                }system("pause");
                break;
            case 5:
                system("cls");
                cout<<"------ MODIFICAR MAIL CLIENTE ------"<<endl;
                cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
                do{
                    cout << "Ingrese el nuevo mail: ";
                    getline(cin,mail);
                    if(mail=="0")return;
                    if(mail.empty()){
                        cout<<endl<< "POR FAVOR DEBE INGRESAR UN MAIL VÁLIDO!"<<endl<<endl;
                        continue;
                    }
                    bool mailRepetido=false;
                    for(int i=0; i<cantidadRegistros;i++){
                        Cliente registroSecundario = cArchivo.leer(i);

                        if(registroSecundario.getMail()== mail){
                            cout<<endl<< "EL MAIL INGRESADO YA SE ENCUENTRA REGISTRADO!"<<endl<<endl;
                            mailRepetido=true;
                            break;
                        }
                    }
                    if(!mailRepetido){
                        break;
                    }
                }while(true);
                registro.setMail(mail);
                if(cArchivo.modificar(registro,posicion)){
                    cout <<endl<< "CLIENTE MODIFICADO"<< endl<<endl;
                }else{
                    cout <<endl<< "HUBO UN ERROR INESPERADO"<<endl<<endl;
                }system("pause");
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

