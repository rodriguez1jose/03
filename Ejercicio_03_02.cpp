// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creación: 4/09/2023

// Fecha modificación: 4/09/2023

// Número de ejericio: 2

// Problema planteado: Generar la matriz espiral para un orden n : Sea n=3: 1 2 3 / 8 9 4 / 7 6 5

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout <<"Ingrese el orden de la matriz espiral: ";
    cin>> n;
    if (n <= 0) {
        cout <<"El orden de la matriz debe ser un numero positivo." <<endl;
        return 1;
    }
	vector<vector<int> > matriz(n, vector<int>(n, 0));
    int valor = 1;
    int inicioFila = 0, finFila = n - 1;
    int inicioColumna = 0, finColumna = n - 1;

    while (valor <= n * n) {
        // Rellena la fila superior
        for (int i = inicioColumna; i <= finColumna; ++i) {
            matriz[inicioFila][i] = valor++;
        }
        inicioFila++;
        // Rellena la columna derecha
        for (int i = inicioFila; i <= finFila; ++i) {
            matriz[i][finColumna] = valor++;
        }
        finColumna--;
        // Rellena la fila inferior
        for (int i = finColumna; i >= inicioColumna; --i) {
            matriz[finFila][i] = valor++;
        }
        finFila--;
        // Rellena la columna izquierda
        for (int i = finFila; i >= inicioFila; --i) {
            matriz[i][inicioColumna] = valor++;
        }
        inicioColumna++;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout <<matriz[i][j] << " ";
        }
        cout <<endl;
    }
    return 0;
}

