// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creación: 5/09/2023

// Fecha modificación: 5/09/2023

// Número de ejericio: 11.2

// Problema planteado: Realizar el típico juego del 3 en raya, donde habrá dos jugadores que tengan que hacer el 3 en raya, los signos serán el X y el O, cuando haya una posición vacía....
// este programa es contra la computadora.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Funcion para que imprima el tablero
void imprimirTablero(char tablero[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout <<tablero[i][j];
            if (j < 2) cout <<" | ";
        }
        cout <<endl;
        if (i < 2) cout <<"---------" <<endl;
    }
    cout << endl;
}
// Funcion que verifica si alguien gano
bool verificarGanador(char tablero[3][3], char jugador) {
    // Comprueba las filas y columnas
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador)
            return true;
        if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador)
            return true;
    }
    // Comprueba las diagonales diagonales
    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador)
        return true;
    if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)
        return true;
    return false;
}
// Funcion para que la computadora realice un movimiento
void moverComputadora(char tablero[3][3], char jugador) {
    // Intenta ganar en el siguiente movimiento
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == '-') {
                tablero[i][j] = jugador;
                if (verificarGanador(tablero, jugador)) {
                    return;
                }
                tablero[i][j] = '-';
            }
        }
    }
    // Si no puede ganar, bloquea al jugador
    char jugadorContrario = (jugador == 'X') ? 'O' : 'X';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == '-') {
                tablero[i][j] = jugadorContrario;
                if (verificarGanador(tablero, jugadorContrario)) {
                    tablero[i][j] = jugador;
                    return;
                }
                tablero[i][j] = '-';
            }
        }
    }
    // Si no puede ganar ni bloquear, realiza un movimiento aleatorio
    srand(time(0));
    int fila, columna;
    do {
        fila = rand() % 3;
        columna = rand() % 3;
    } while (tablero[fila][columna] != '-');
    tablero[fila][columna] = jugador;
}
int main() {
    char tablero[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
    char jugadorActual = 'X';
    int fila, columna;
    int movimientos = 0;

    cout <<"Bienvenido al juego del tres en raya!" <<endl;
    cout <<"Eres el jugador X y la computadora es el jugador O." <<endl;
    while (movimientos < 9) {
        if (jugadorActual == 'X') {
            cout << "Tu turno" << endl;
            imprimirTablero(tablero);
            cout << "Ingrese la fila (0, 1, 2): ";
            cin >> fila;
            cout << "Ingrese la columna (0, 1, 2): ";
            cin >> columna;
            if (tablero[fila][columna] == '-') {
                tablero[fila][columna] = jugadorActual;
                movimientos++;
                if (verificarGanador(tablero, jugadorActual)) {
                    cout <<"Ganaste! Felicidades." <<endl;
                    imprimirTablero(tablero);
                    break;
                }
                jugadorActual = 'O';
            } else {
                cout <<"Casilla ocupada. Intenta de nuevo." <<endl;
            }
        } else {
            cout <<"Turno de la computadora" <<endl;
            moverComputadora(tablero, jugadorActual);
            movimientos++;
            imprimirTablero(tablero);
            if (verificarGanador(tablero, jugadorActual)) {
                cout <<"La computadora gana!" <<endl;
                break;
            }
            jugadorActual = 'X';
        }
    }
    if (movimientos == 9) {
        cout <<"Empate. El juego ha terminado sin ganador." <<endl;
        imprimirTablero(tablero);
    }
    return 0;
}

