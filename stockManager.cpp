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
           int cantidadStock = stock.calcularStock(producto.getIdProducto());

           if(cantidadStock>0){
               cout<<endl<< "Producto: "<<producto.getNombre()<<endl;
               cout<< "Marca: "<<producto.getMarca()<<endl;
               cout<< "Sotck actual: "<<cantidadStock<<endl<<endl;
               cout<< "=============================" <<endl<<endl;
           }
        }
    } system("pause");
}
