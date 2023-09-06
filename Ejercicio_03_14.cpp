// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creación: 5/09/2023

// Fecha modificación: 5/09/2023

// Número de ejericio: 14

// Problema planteado: Simule una elección de nuestro país Bolivia. En ello se mostrará las elecciones por departamento y existirá N candidatos.
// El programa debe pedir la cantidad de votos por departamento y candidato y almacenarlos en una matriz

#include <iostream>
using namespace std;

int main() {
    int numDepartamentos, numCandidatos;
    cout <<"Ingrese la cantidad de departamentos: ";
    cin>> numDepartamentos;
    cout <<"Ingrese la cantidad de candidatos: ";
    cin>> numCandidatos;

    int votosPorDepartamento[100][100]; // un limite de 100 departamentos y 100 candidatos
    int totalVotosPorCandidato[100] = {0}; // Inicia el arreglo a 0
    // para ingresar los votos por departamento y candidato
    for (int d = 0; d < numDepartamentos; d++) {
        cout << "Departamento " << d + 1 << ":" << endl;
        for (int c = 0; c < numCandidatos; c++) {
            cout <<"Ingrese los votos para el candidato " <<c + 1 <<": ";
            cin>> votosPorDepartamento[d][c];
            totalVotosPorCandidato[c] = totalVotosPorCandidato[c] + votosPorDepartamento[d][c];
        }
    }
    int totalVotos = 0;
    for (int c = 0; c < numCandidatos; c++) {
        totalVotos += totalVotosPorCandidato[c];
    }
    int candidatos[100]; // Almacena el numero de candidato
    int votosCandidatos[100]; // Almacena la cantidad de votos de cada candidato

    for (int c = 0; c < numCandidatos; c++) {
        candidatos[c] = c + 1;
        votosCandidatos[c] = totalVotosPorCandidato[c];
    }
    // Ordena la cantidad de candidatos por cantidad de votos en orden descendente usando burbuja
    for (int i = 0; i < numCandidatos - 1; i++) {
        for (int j = 0; j < numCandidatos - i - 1; j++) {
            if (votosCandidatos[j] < votosCandidatos[j + 1]) {
                // Intercambia los candidatos y sus votos manualmente
                int tempCandidato = candidatos[j];
                candidatos[j] = candidatos[j + 1];
                candidatos[j + 1] = tempCandidato;

                int tempVotos = votosCandidatos[j];
                votosCandidatos[j] = votosCandidatos[j + 1];
                votosCandidatos[j + 1] = tempVotos;
            }
        }
    }
    int ganadorAbsoluto = candidatos[0];
    int votosGanadorAbsoluto = votosCandidatos[0];
    if (votosGanadorAbsoluto > totalVotos / 2) {
        cout <<"El candidato " <<ganadorAbsoluto <<" es el ganador absoluto con " <<votosGanadorAbsoluto <<" votos." <<endl;
    } else {
        cout <<"No hay un ganador absoluto. Se requiere una segunda vuelta entre los dos candidatos más votados:" <<endl;
        cout <<"Candidato " <<candidatos[0] <<" con " <<votosCandidatos[0] <<" votos." <<endl;
        cout <<"Candidato " <<candidatos[1] <<" con " <<votosCandidatos[1] <<" votos." <<endl;
    }
    return 0;
}

