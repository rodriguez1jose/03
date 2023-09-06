// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creación: 5/09/2023

// Fecha modificación: 5/09/2023

// Número de ejericio: 9

// Problema planteado: Traspones una matriz de N x M 

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cout << "Ingrese el numero de filas (N) de la matriz: ";
    cin >> N;
    cout << "Ingrese el numero de columnas (M) de la matriz: ";
    cin >> M;
    // Crea la matriz original (NxM)
    vector<vector<int> > matriz(N, vector<int>(M));
    cout <<"Ingrese los valores de la matriz (" <<N <<"x" <<M <<"):" <<endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin>> matriz[i][j];
        }
    }
    // Muestra la matriz transpuesta directamente
    cout <<"Matriz transpuesta (" <<M <<"x" <<N <<"):" <<endl;
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            cout <<matriz[i][j] << " ";
        }
        cout <<endl;
    }
    return 0;
}

