#include <iostream>
#include <string>
#include <cstring>
#include "stockManager.h"
#include "productoArchivo.h"
#include "producto.h"
#include "stock.h"

using namespace std;

void StockManager::mostrar(){
    ProductoArchivo pArchivo;
    Producto producto;
    Stock stock;

    int cantidadRegistros = pArchivo.getCantidadProductos();

    cout << "------ LISTA DE PRODUCTOS ACTIVOS ------" <<endl<<endl;

    for(int i=0; i<cantidadRegistros; i++){
        producto = pArchivo.leer(i);

        if(producto.getEstado()==true){
           int idProducto = producto.getIdProducto(); //ver si esto lo puedeo meter en el parentesis de abajo
           int cantidadStock = stock.calcularStock(idProducto);

        cout<<endl<< "Producto: "<<idProducto<<endl;
        cout<< "Sotck actual: "<<cantidadStock<<endl<<endl;
        cout<< "=============================" <<endl<<endl;

        }
    } system("pause");
}
