// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creación: 4/09/2023

// Fecha modificación: 4/09/2023

// Número de ejericio: 1

// Problema planteado: Elabore un programa que lea una matriz de orden n x n y la cambie la fila 1 por la fina n. Por ejemplo, si la matriz que da el usuario es:...

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout <<"Ingrese el orden de la matriz (n x n): ";
    cin>> n;
    // Crea la matriz n x n
	vector<vector<int> > matriz(n, vector<int>(n));
    cout <<"Ingrese los elementos de la matriz:" <<endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>> matriz[i][j];
        }
    }
    // Intercambia la primera fila con la ultima fila
    vector<int> temp = matriz[0];
    matriz[0] = matriz[n - 1];
    matriz[n - 1] = temp;

    cout <<"Matriz con la primera fila intercambiada por la ultima fila:" <<endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout <<matriz[i][j] << " ";
        }
        cout <<endl;
    }
    return 0;
}

