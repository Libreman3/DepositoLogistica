#include <iostream>
#include "proveedor.h"
#include "Menu.h"
#include "MenuProducto.h"
#include <cstdio>  // Para usar remove()
using namespace std;

int main(){

     Menu menu;

      menu.mostrar();

    //MenuProducto menuP;
    //menuP.mostrarMenuProducto();


    /*
    FILE *pFile = fopen("producto.dat", "wb");

    if (pFile == nullptr) {
        cout << "Error al intentar vaciar el archivo." << endl;
    } else {
        cout << "¡Todos los productos han sido eliminados!" << endl;
        fclose(pFile);  // Cerrar el archivo
    }

    */

    return 0;
}

