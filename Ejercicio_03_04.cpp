// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creación: 5/09/2023

// Fecha modificación: 5/09/2023

// Número de ejericio: 4

// Problema planteado: En la segunda temporada de The Walking Dead, los personajes llegaron a una cárcel para refugiarse. La cárcel estaba rodeada de vallas por lo que los muertos
// vivientes no podían entrar en ella. . Sin embargo, dentro de las instalaciones aun existían muertos vivientes que amenazaban a los personajes. Por tanto, Rick y
// otros miembros del grupo decidieron ir a investigar las instalaciones con el fin de determinar cuáles eran los lugares seguros.....

#include <iostream>
using namespace std;

const int FILAS = 3;  // Tama~ne la matriz (filas)
const int COLUMNAS = 4;  // Tama~no de la matriz (columnas)
const int MAX_MUERTOS = FILAS * COLUMNAS;

// para mostrar la matriz
void mostrarMatriz(char matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout <<matriz[i][j] <<" ";
        }
        cout <<endl;
    }
}
//para contar las filas y columnas libres
void contarFilasColumnasLibres(char matriz[FILAS][COLUMNAS], int& filasLibres, int& columnasLibres) {
    for (int i = 0; i < FILAS; i++) {
        bool hayMuertoVivienteEnFila = false;
        for (int j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] == 'x') {
                hayMuertoVivienteEnFila = true;
                break;
            }
        }
        if (!hayMuertoVivienteEnFila) {
            filasLibres++;
        }
    }
    for (int j = 0; j < COLUMNAS; j++) {
        bool hayMuertoVivienteEnColumna = false;
        for (int i = 0; i < FILAS; i++) {
            if (matriz[i][j] == 'x') {
                hayMuertoVivienteEnColumna = true;
                break;
            }
        }
        if (!hayMuertoVivienteEnColumna) {
            columnasLibres++;
        }
    }
}
// para encontrar las coordenadas de los muertos vivientes
void encontrarCoordenadasMuertosVivientes(char matriz[FILAS][COLUMNAS], int filasMuertos[MAX_MUERTOS], int columnasMuertos[MAX_MUERTOS], int& totalMuertosVivientes) {
    totalMuertosVivientes = 0;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] == 'x') {
                filasMuertos[totalMuertosVivientes] = i;
                columnasMuertos[totalMuertosVivientes] = j;
                totalMuertosVivientes++;
            }
        }
    }
}
int main() {
    char matriz[FILAS][COLUMNAS] = {
        {'x', 'o', 'o', 'o'},
        {'o', 'o', 'o', 'o'},
        {'x', 'o', 'o', 'o'}
    };
    cout <<"a) Mostrar matriz:" <<endl;
    mostrarMatriz(matriz);

    int filasLibres = 0;
    int columnasLibres = 0;
    contarFilasColumnasLibres(matriz, filasLibres, columnasLibres);

    cout <<"b) Filas libres: " <<filasLibres <<endl;
    cout <<"   Columnas libres: " <<columnasLibres <<endl;

    int filasMuertos[MAX_MUERTOS];
    int columnasMuertos[MAX_MUERTOS];
    int totalMuertosVivientes;
    encontrarCoordenadasMuertosVivientes(matriz, filasMuertos, columnasMuertos, totalMuertosVivientes);
    
    cout <<"c) Posiciones de la matriz:" <<endl;
    for (int i = 0; i < totalMuertosVivientes; i++) {
        cout << filasMuertos[i] << " -- " <<columnasMuertos[i] <<endl;
    }
    cout <<"d) Total muertos vivientes: " <<totalMuertosVivientes <<endl;
    bool dosOMasMuertosPrimeraColumna = false;
    for (int i = 0; i < totalMuertosVivientes; i++) {
        if (columnasMuertos[i] == 0) {
            dosOMasMuertosPrimeraColumna = true;
            break;
        }
    }
    cout <<"e) ";
    if (dosOMasMuertosPrimeraColumna) {
        cout <<"No es posible entrar al complejo!" <<endl;
    } else {
        cout <<"Es posible entrar al complejo!" <<endl;
    }
    int espacioLibre = FILAS * COLUMNAS - totalMuertosVivientes;
    cout <<"f) Espacio libre: " <<espacioLibre <<endl;
    return 0;
}

