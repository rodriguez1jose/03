// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creación: 5/09/2023

// Fecha modificación: 5/09/2023

// Número de ejericio: 12

// Problema planteado: Ingresa una matriz de NxN y a continuación: a. Elimine una fila ingresada por el usuario. b. Elimine una columna ingresada por el usuario.
// c. Inserte una fila por un valor determinado por el usuario. d. Inserte una columna por un valor determinado por el usuario.

#include <iostream>
using namespace std;

const int MAX_N = 100;  // Tama~no maximo de la matriz
//muestra la matriz
void mostrarMatriz(int matriz[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout <<matriz[i][j] <<" ";
        }
        cout <<endl;
    }
}
int main() {
    int n;
    cout <<"Ingrese el tama~no de la matriz (N): ";
    cin>> n;
    int matriz[MAX_N][MAX_N];
    cout <<"Ingrese los elementos de la matriz:" <<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>> matriz[i][j];
        }
    }
    cout <<"Matriz ingresada:" <<endl;
    mostrarMatriz(matriz, n);
    int opcion;
    cout <<"Elija una opcion:" <<endl;
    cout <<"1. Eliminar una fila" <<endl;
    cout <<"2. Eliminar una columna" <<endl;
    cout <<"3. Insertar una fila" <<endl;
    cout <<"4. Insertar una columna" <<endl;
    cin>> opcion;

    int fila, columna, valor;
    switch (opcion) {
        case 1:
            cout <<"Ingrese la fila a eliminar: ";
            cin>> fila;
            if (fila >= 0 && fila < n) {
                for (int i = fila; i < n - 1; i++) {
                    for (int j = 0; j < n; j++) {
                        matriz[i][j] = matriz[i + 1][j];
                    }
                }
                n--;  // Reduce el tama~no de la matriz
                cout <<"Fila eliminada." <<endl;
            } else {
                cout <<"Fila ingresada fuera de rango." <<endl;
            }
            break;
        case 2:
            cout <<"Ingrese la columna a eliminar: ";
            cin>> columna;
            if (columna >= 0 && columna < n) {
                for (int i = 0; i < n; i++) {
                    for (int j = columna; j < n - 1; j++) {
                        matriz[i][j] = matriz[i][j + 1];
                    }
                }
                n--;  // Reduce el tama~no de la matriz
                cout <<"Columna eliminada." <<endl;
            } else {
                cout <<"Columna ingresada fuera de rango." <<endl;
            }
            break;
        case 3:
            cout <<"Ingrese la fila a insertar: ";
            cin>> fila;
            cout <<"Ingrese el valor para la fila: ";
            cin>> valor;
            if (fila >= 0 && fila <= n) {
                for (int i = n; i > fila; i--) {
                    for (int j = 0; j < n; j++) {
                        matriz[i][j] = matriz[i - 1][j];
                    }
                }
                for (int j = 0; j < n; j++) {
                    matriz[fila][j] = valor;
                }
                n++;  // Aumenta el tama~no de la matriz
                cout << "Fila insertada." << endl;
            } else {
                cout << "Fila ingresada fuera de rango." << endl;
            }
            break;
        case 4:
            cout << "Ingrese la columna a insertar: ";
            cin >> columna;
            cout << "Ingrese el valor para la columna: ";
            cin >> valor;
            if (columna >= 0 && columna <= n) {
                for (int i = 0; i < n; i++) {
                    for (int j = n; j > columna; j--) {
                        matriz[i][j] = matriz[i][j - 1];
                    }
                }
                for (int i = 0; i < n; i++) {
                    matriz[i][columna] = valor;
                }
                n++;  // Aumentar el tama~no de la matriz
                cout << "Columna insertada." << endl;
            } else {
                cout <<"Columna ingresada fuera de rango." <<endl;
            }
            break;
        default:
            cout <<"Opcion no valida." <<endl;
            break;
    }
    cout <<"Matriz resultante:" <<endl;
    mostrarMatriz(matriz, n);
    return 0;
}


