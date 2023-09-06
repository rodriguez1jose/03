// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creación: 5/09/2023

// Fecha modificación: 5/09/2023

// Número de ejericio: 11

// Problema planteado: Realizar el típico juego del 3 en raya, donde habrá dos jugadores que tengan que hacer el 3 en raya, los signos serán el X y el O, cuando haya una posición vacía....

#include <iostream>
using namespace std;
//Imprime el tablero
void imprimirTablero(char tablero[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout <<tablero[i][j];
            if (j < 2) cout <<" | ";
        }
        cout <<endl;
        if (i < 2) cout <<"---------" <<endl;
    }
    cout <<endl;
}
// Funcion para verificar si alguien gano
bool verificarGanador(char tablero[3][3], char jugador) {
	// comprueba las filas y las columnas
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador)
            return true;
        if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador)
            return true;
    }
    // Comprueba de diagonales
    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador)
        return true;
    if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)
        return true;
    return false;
}
int main() {
    char tablero[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
    char jugadorActual = 'X';
    int fila, columna;
    int movimientos = 0;

    cout <<"Bienvenido al juego del tres en raya!" <<endl;
    while (movimientos < 9) {
        cout <<"Turno del jugador " <<jugadorActual <<endl;
        imprimirTablero(tablero);
        cout <<"Ingrese la fila (0, 1, 2): ";
        cin>> fila;
        cout <<"Ingrese la columna (0, 1, 2): ";
        cin>> columna;
        // Verifica si la casilla esta ocupada
        if (tablero[fila][columna] == '-') {
            tablero[fila][columna] = jugadorActual;
            movimientos++;
            if (verificarGanador(tablero, jugadorActual)) {
                cout <<"¡Jugador " <<jugadorActual <<" gana!" <<endl;
                imprimirTablero(tablero);
                break;
            }
            jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
        } else {
            cout <<"Casilla ocupada. Intenta de nuevo." <<endl;
        }
    }
    if (movimientos == 9) {
        cout <<"Empate. El juego ha terminado sin ganador." <<endl;
        imprimirTablero(tablero);
    }
    return 0;
}

