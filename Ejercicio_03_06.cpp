// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creación: 4/09/2023

// Fecha modificación: 5/09/2023

// Número de ejericio: 6

// Problema planteado: Generar la matriz para un orden NxN

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout <<"Ingrese el valor de N para la matriz: ";
    cin>> n;
    // Crea una matriz de NxN
    vector<vector<int> > matriz(n, vector<int>(n));
    // Llena la matriz con valores
    int valor = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = valor++;
        }
    }
    cout <<"Matriz de orden " <<n <<"x" <<n <<":" <<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout <<matriz[i][j] <<"\t";
        }
        cout <<endl;
    }
    return 0;
}

