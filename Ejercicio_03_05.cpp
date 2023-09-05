// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creación: 4/09/2023

// Fecha modificación: 4/09/2023

// Número de ejericio: 5

// Problema planteado: Generar la matriz para un orden NxN Sea n=5  1 2 3 4 5 / 3 4 5 6 7 / 5 6 7 8 9 / 7 8 9 10 11 / 9 10 11 12 13

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout <<"Ingrese el tamaño de la matriz NxN: ";
    cin>> n;
    // Crea una matriz de NxN para el patron dado
    vector<vector<int> > matriz(n, vector<int>(n));
    int valor = 1;

    for (int i = 0; i < n; ++i) {
        int inicio = valor;
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = inicio;
            inicio++;
        }
        valor += 2;
    }
    cout <<"Matriz generada:" <<endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout <<matriz[i][j] << " ";
        }
        cout <<endl;
    }
    return 0;
}

