// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creación: 4/09/2023

// Fecha modificación: 4/09/2023

// Número de ejericio: 7

// Problema planteado: Efectuar la suma de una matriz tridimensional de orden n x n x n

#include <iostream>
using namespace std;

int main() {
    int n;
    cout <<"Ingrese el valor de N para la matriz tridimensional: ";
    cin>> n;
    int matriz[n][n][n];
    int valor = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                matriz[i][j][k] = valor++;
            }
        }
    }
    // Calcula la suma de todos los elementos de la matriz
    int suma = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                suma = suma + matriz[i][j][k];
            }
        }
    }
    cout <<"La suma de todos los elementos de la matriz tridimensional es: " <<suma <<endl;
    return 0;
}

