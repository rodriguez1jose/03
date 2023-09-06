// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creación: 4/09/2023

// Fecha modificación: 5/09/2023

// Número de ejericio: 8

// Problema planteado: Multiplique dos matrices una de N x M y la otra de M x N

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M; // Tama~no de la primera matriz NxM
    int M2; // Tama~no de la segunda matriz (M2xN)
    cout <<"Ingrese el valor de N para la primera matriz: ";
    cin>> N;
    cout <<"Ingrese el valor de M (y M2) para la primera y segunda matriz: ";
    cin>> M>> M2;
    // Verifica que las dimensiones sean compatibles para la multiplicacion
    if (M != M2) {
        cout << "Las dimensiones de las matrices no son compatibles para la multiplicación." << endl;
        return 1;
    }
    // Crea la primera matriz (NxM)
    vector<vector<int> > matriz1(N, vector<int>(M));
    cout <<"Ingrese los valores de la primera matriz (" <<N <<"x" <<M <<"):" <<endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matriz1[i][j];
        }
    }
    // Crea la segunda matriz (MxN)
    vector<vector<int> > matriz2(M, vector<int>(N));
    cout <<"Ingrese los valores de la segunda matriz (" <<M <<"x" <<N <<"):" <<endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matriz2[i][j];
        }
    }
    // Crea la matriz resultante (NxN)
    vector<vector<int> > resultado(N, vector<int>(N, 0));
    // Realizar la multiplicacion de las matrices
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                resultado[i][j] = resultado[i][j] + matriz1[i][k] * matriz2[k][j];
            }
        }
    }
    cout <<"Resultado de la multiplicacion:" <<endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout <<resultado[i][j] <<" ";
        }
        cout <<endl;
    }
    return 0;
}

