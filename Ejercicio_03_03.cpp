// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creación: 4/09/2023

// Fecha modificación: 4/09/2023

// Número de ejericio: 3

// Problema planteado: Generar una matriz de N x N con números al azar entre A y B, y determinar:
//La suma de la última columna
//El producto total de la última fila
//Obtener el mayor valor y su posición
//Obtener la desviación estándar de todos los elementos de la matriz

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
    int n;
    int A, B;
    cout <<"Ingrese el tama~no de la matriz NxN: ";
    cin>> n;
    cout <<"Ingrese el valor de A: ";
    cin>> A;
    cout <<"Ingrese el valor de B: ";
    cin>> B;

    vector<vector<int> > matriz(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = rand() % (B - A + 1) + A;
        }
    }
    cout <<"Matriz generada:" <<endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout <<matriz[i][j] << "\t";
        }
        cout <<endl;
    }
    // Calcula la suma de la ultima columna
    int sumaUltimaColumna = 0;
    for (int i = 0; i < n; ++i) {
        sumaUltimaColumna = sumaUltimaColumna + matriz[i][n - 1];
    }
    // Calcula el producto total de la ultima fila
    int productoUltimaFila = 1;
    for (int j = 0; j < n; ++j) {
        productoUltimaFila = productoUltimaFila * matriz[n - 1][j];
    }
    // Encuentra el mayor valor y su posicin
    int mayorValor = matriz[0][0];
    int filaMayor, columnaMayor;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matriz[i][j] > mayorValor) {
                mayorValor = matriz[i][j];
                filaMayor = i;
                columnaMayor = j;
            }
        }
    }
    // Calcula la desviacion estandar
    double suma = 0.0;
    double media = 0.0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            suma = suma + matriz[i][j];
        }
    }
    media = suma / (n * n);
    double sumaDiferencias = 0.0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sumaDiferencias = sumaDiferencias + pow(matriz[i][j] - media, 2);
        }
    }
    double desviacionEstandar = sqrt(sumaDiferencias / (n * n));
    cout <<"Suma de la ultima columna: " <<sumaUltimaColumna <<endl;
    cout <<"Producto total de la ultima fila: " <<productoUltimaFila <<endl;
    cout <<"Mayor valor: " <<mayorValor <<" (fila " <<filaMayor <<", columna " <<columnaMayor <<")" <<endl;
    cout <<"Desviacion estandar: " <<desviacionEstandar <<endl;
    return 0;
}

