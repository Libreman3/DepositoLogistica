#include <iostream>
#include <string>
#include "clienteManager.h"
#include "cliente.h"
#include "clienteArchivo.h"

using namespace std;

void ClienteManager::cargar(){    //ACA SE CARGA CADA PERFIL DE CLIENTE
    int numeroCliente, dni;
    string nombre, apellido, direccion, mail;
    bool estado;

    Cliente cliente;
    ClienteArchivo cArchivo;

    cout<<"------- CARGAR CLIENTE -------"<<endl;
    cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
    cout<< "Ingrese numero de Cliente:";    //ESTO EN REALIDAD NO LO DEBERIA PREGUNTAR
    cin>>numeroCliente;                     //SEDEBERIA CARGAR AUTOMATICAMENTE
    cout<< "Ingrese numero de DNI: ";
    cin>>dni;
    if(dni==0){
        return;
    }
    while(dni<1000000 || dni>100000000){
        cout<< "El dni ingresado es incorrecto, por favor intente nuevamente: ";
        cin>>dni;
        if(dni==0){
            return;
        }
    }
    cout<< "Ingrese el nombre: ";
    cin.ignore();
    getline(cin,nombre);
    if(nombre=="0"){
        return;
    }
    cout<< "Ingrese apellido: ";
    getline(cin,apellido);
    if(apellido=="0"){
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

    cliente = Cliente(numeroCliente,dni, nombre, apellido, direccion, mail, estado);

    if(cArchivo.guardar(cliente)){    // AL FINALIZAR LA CARGA TE MUESTRA SI ESTA TODO OK O SI HUBO ALGUN ERROR
        cout<<endl<<"Se guardo correctamente!"<<endl<<endl;
        system("pause");
    }else{
        cout<<endl<< "Error inesperado!"<<endl<<endl;
        system("pause");
    }
}

void ClienteManager::mostrar(){  //EN ESTE PROCESO BUSCA PRIMERO LA CANTIDAD DE ClienteES CARGADOS,
    ClienteArchivo cArchivo;     //PARA QUE FUNCIONE EL BUCLE DE MOSTRARLOS A TODOS
    Cliente registro;

    int cantidadRegistros = cArchivo.getCantidadClientes();  //CALCULA LA CANTIDAD DE ClienteES CARGADOS

    for(int i=0; i<cantidadRegistros; i++){     //MUESTRA LOS ClienteES CARGADOS
        registro = cArchivo.leer(i);

        if(registro.getEstado()== true){
            registro.tarjetaCliente();
        }
    }
}

void ClienteManager::buscar(){
    ClienteArchivo cArchivo;
    Cliente registro;

    int dniBuscado;
    bool encontrado = false;

    cout<<"------ BUSCAR CLIENTE ------"<<endl;
    cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
    cout<< "Ingrese el dni del cliente que desea buscar: ";
    cin>>dniBuscado;
    if(dniBuscado==0){
        return;
    }

    int cantidadRegistros = cArchivo.getCantidadClientes();

    for(int i=0; i<cantidadRegistros;i++){
        registro = cArchivo.leer(i);

        if(registro.getDni()== dniBuscado){
            registro.tarjetaCliente();
            encontrado=true;
            break;
        }
    }
    if (encontrado == false){
        cout <<endl<< "NO SE ENCONTRO CLIENTE CON EL NUMERO DE DNI INGRESADO!"<<endl<<endl;
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
        int dato, dni;
        string nombre, apellido, direccion, mail;

        system("cls");
        cout<<"------ MODIFICAR CLIENTE ------"<<endl<<endl;
        cout<< "INGRESE QUE DATO DESEA MODIFICAR:"<<endl;
        cout<< "1. Numero de DNI"<<endl;
        cout<< "2. Nombre"<<endl;
        cout<< "3. Apellido"<<endl;
        cout<< "4. Direccion"<<endl;
        cout<< "5. Mail"<<endl;
        cout<< "0. Cancelar"<<endl;
        cout<< endl;
        cin >> dato;

        switch(dato){
        case 1:
            system("cls");
            cout<<"------ MODIFICAR CLIENTE ------"<<endl;
            cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
            cout << "Ingrese el nuevo numero de DNI: ";
            cin >> dni;
            if(dni==0){
                return;
            }
            while(dni<1000000 || dni>100000000){
                cout<< "El dni ingresado es incorrecto, por favor intente nuevamente: ";
                cin>>dni;
                if(dni==0){
                    return;
                }
            }
            registro.setDni(dni);
            if(cArchivo.modificar(registro,posicion)){
                cout<<endl<< "CLIENTE MODIFICADO"<<endl<<endl;
            } else{
                cout<<endl<< "HUBO UN ERROR INESPERADO"<<endl<<endl;
            }
            return;
        case 2:
            system("cls");
            cout<<"------ MODIFICAR CLIENTE ------"<<endl;
            cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
            cout<< "Ingrese el nuevo nombre: ";
            cin>> nombre;
            if(nombre=="0"){
                return;
            }
            registro.setNombre(nombre);
            if(cArchivo.modificar(registro,posicion)){
                cout <<endl<< "CLIENTE MODIFICADO"<<endl<<endl;
            }else{
                cout<<endl<< "HUBO UN ERROR INESPERADO"<<endl<<endl;
            }
            break;
        case 3:
            system("cls");
            cout<<"------ MODIFICAR CLIENTE ------"<<endl;
            cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
            cout<< "Ingrese el nuevo apellido: ";
            cin>> apellido;
            if(apellido=="0"){
                return;
            }
            registro.setApellido(apellido);
            if(cArchivo.modificar(registro,posicion)){
                cout <<endl<< "CLIENTE MODIFICADO"<<endl<<endl;
            }else{
                cout<<endl<< "HUBO UN ERROR INESPERADO"<<endl<<endl;
            }
            break;
        case 4:
            system("cls");
            cout<<"------ MODIFICAR CLIENTE ------"<<endl;
            cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
            cout << "Ingrese la nueva direccion: ";
            cin >> direccion;
            if(direccion=="0"){
                return;
            }
            registro.setDireccion(direccion);
            if(cArchivo.modificar(registro,posicion)){
                cout <<endl<< "CLIENTE MODIFICADO"<<endl<<endl;
            }else{
                cout <<endl<< "HUBO UN ERROR INESPERADO"<<endl<<endl;
            }
            break;
        case 5:
            system("cls");
            cout<<"------ MODIFICAR CLIENTE ------"<<endl;
            cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
            cout << "Ingrese el nuevo mail: "<<endl;
            cin >> mail;
            if(mail=="0"){
                return;
            }
            registro.setMail(mail);
            if(cArchivo.modificar(registro,posicion)){
                cout <<endl<< "CLIENTE MODIFICADO"<< endl<<endl;
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

void ClienteManager::eliminar(){
    ClienteArchivo cArchivo;

    Cliente cliente; //VER SI ES OBLIGATORIO ESTE USO

    int dniEliminar;

    cout<<"------ ELIMINAR CLIENTE ------"<<endl;
    cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
    cout <<"Ingrese el dni del cliente que desea eliminar: ";
    cin >> dniEliminar;
    if(dniEliminar==0){
        return;
    }

    int posicion = cArchivo.buscarDni(dniEliminar);

    if(posicion>=0){
        Cliente registro = cArchivo.leer(posicion);
        registro.setEstado(false);
        if(cArchivo.modificar(registro, posicion)){
            cout <<endl<< "CLIENTE ELIMINADO"<<endl<<endl;
        }else{
            cout <<endl<< "HUBO UN ERROR"<<endl<<endl;
        }

    }else{
        cout<<endl<< "NO EXISTE EL DNI INGRESADO"<<endl<<endl;
    }
    system("pause");
}

void ClienteManager::restaurar(){
    ClienteArchivo cArchivo;

    Cliente cliente;

    int dniRestaurar;

    cout<<"------ RESTAURAR CLIENTE ------"<<endl;
    cout<<"-- PRESIONE '0' PARA CANCELAR --"<<endl<<endl;
    cout << "Ingrese el dni del cliente eliminado que desea restaurar :";
    cin >> dniRestaurar;
    if(dniRestaurar==0){
        return;
    }

    int posicion = cArchivo.buscarDni(dniRestaurar);

    if(posicion>=0){
        Cliente registro = cArchivo.leer(posicion);
        registro.setEstado(true);
        if(cArchivo.modificar(registro, posicion)){
            cout <<endl<< "CLIENTE RESTAURADO"<< endl<<endl;
        }else{
            cout <<endl<< "HUBO UN ERROR"<<endl<<endl;
        }

    }else{
        cout<<endl<< "NO EXISTE EL DNI INGRESADO"<<endl<<endl;
    }
    system("pause");
}

