#include <iostream>
#include <string>
#include <cstring>
#include "stockManager.h"
#include "productoArchivo.h"
#include "producto.h"
#include "stock.h"
#include "ingresosArchivo.h"
#include "egresosArchivo.h"


int Stock::calcularStock(int idProducto){
    int stock = 0;

    IngresosArchivo ingresosArchivo;
    EgresosArchivo egresosArchivo;

    int totalIngresos = ingresosArchivo.getCantidadIngresos();
    int totalEgresos = egresosArchivo.getCantidadEgresos();

    for (int i = 0; i < totalIngresos; i++) {
        Ingresos ingreso = ingresosArchivo.leer(i);
        if (ingreso.getIdProducto() == idProducto && ingreso.getEstado()) {
            char buffer[20];
            ingreso.getAlmacenamiento(3, buffer);
            stock += atoi(buffer);
        }
    }

    for (int i = 0; i < totalEgresos; i++) {
        Egresos egreso = egresosArchivo.leer(i);
        if (egreso.getIdProducto() == idProducto && egreso.getEstado()) {
            stock -= egreso.getCantidad();
        }
    }

    return stock;

}
