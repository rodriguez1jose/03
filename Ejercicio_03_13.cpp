// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creación: 5/09/2023

// Fecha modificación: 5/09/2023

// Número de ejericio: 13

// Problema planteado: La farmacia FARMACARP tiene N sucursales, leer sus ventas por mes de un año entero de cada sucursal y calcule:
// a. Total, de ventas b. Total, de ventas por sucursal. c. Sucursal que más ha vendido. d. Sucursal que menos ha vendido.

#include <iostream>
using namespace std;

int main() {
    int n;
    cout <<"Ingresa el numero de sucursales: ";
    cin>> n;

    int totalVentas = 0;
    int ventasMax = -1;
    int ventasMin = 1000000; // Valor grande como limite superior inicial.
    int sucursalMax = -1;
    int sucursalMin = -1;

    for (int i = 1; i <= n; i++) {
        int ventasAnuales = 0;
        cout <<"Sucursal " <<i <<":" <<endl;
        for (int mes = 1; mes <= 12; mes++) {
            int ventasMes;
            cout <<"Ingresa las ventas para el mes " <<mes <<": ";
            cin>> ventasMes;
            ventasAnuales = ventasAnuales + ventasMes;
        }
        totalVentas = totalVentas + ventasAnuales;
        if (ventasAnuales > ventasMax) {
            ventasMax = ventasAnuales;
            sucursalMax = i;
        }
        if (ventasAnuales < ventasMin || sucursalMin == -1) {
            ventasMin = ventasAnuales;
            sucursalMin = i;
        }
        cout <<"   Total: " <<ventasAnuales <<endl;
    }
    cout <<"TOTAL DE VENTAS: " <<totalVentas <<endl;
    cout <<"TOTAL DE VENTAS POR SUCURSAL:" <<endl;
    for (int i = 1; i <= n; i++) {
        cout <<"Sucursal " <<i <<": " <<endl;
    }
    cout <<"Sucursal que mas ha vendido: Sucursal " <<sucursalMax <<" con " <<ventasMax <<" ventas." <<endl;
    cout <<"Sucursal que menos ha vendido: Sucursal " <<sucursalMin <<" con " <<ventasMin <<" ventas." <<endl;
    return 0;
}

