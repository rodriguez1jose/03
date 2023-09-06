// Materia: Programación I, Paralelo 1

// Autor: Jose Joaquin Rodriguez Ojeda

// Fecha creación: 5/09/2023

// Fecha modificación: 5/09/2023

// Número de ejericio: 10

// Problema planteado: Queremos realizar una encuesta a 10 personas, en esta encuesta indicaremos el sexo (1=masculino, 2=femenino), si trabaja (1=si trabaja, 2= no trabaja) y su
// sueldo (si tiene un trabajo, sino sera un cero) estará entre 600 y 2000 (valor entero). Los valores pueden ser generados aleatoriamente. Calcula y muestra lo siguiente:
// Porcentaje de hombres (tengan o no trabajo), Porcentaje de mujeres (tengan o no trabajo), Porcentaje de hombres que trabajan, Porcentaje de mujeres que trabajan.
// El sueldo promedio de las hombres que trabajan, EL sueldo promedio de las mujeres que trabajan

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // Inicia la "semilla" para numeros aleatorios con el tiempo actual
    int hombres = 0, mujeres = 0, hombresTrabajan = 0, mujeresTrabajan = 0;
    int sueldoHombres = 0, sueldoMujeres = 0;
    for (int i = 0; i < 10; i++) {
        int sexo = rand() % 2 + 1; // 1=masculino, 2=femenino
        int trabaja = rand() % 2 + 1; // 1=trabaja, 2=no trabaja
        int sueldo = 0;

        if (trabaja == 1) {
            sueldo = rand() % 1401 + 600; // Sueldo entre 600 y 2000
        }

        if (sexo == 1) { // Hombre
            hombres++;
            sueldoHombres += sueldo;
            if (trabaja == 1) {
                hombresTrabajan++;
            }
        } else { // Mujer
            mujeres++;
            sueldoMujeres += sueldo;
            if (trabaja == 1) {
                mujeresTrabajan++;
            }
        }
    }
    // Calculos para los porcentajes y promedios
    float porcentajeHombres = (float)hombres / 10 * 100;
    float porcentajeMujeres = (float)mujeres / 10 * 100;
    float porcentajeHombresTrabajan = (float)hombresTrabajan / hombres * 100;
    float porcentajeMujeresTrabajan = (float)mujeresTrabajan / mujeres * 100;
    float sueldoPromedioHombresTrabajan = (float)sueldoHombres / hombresTrabajan;
    float sueldoPromedioMujeresTrabajan = (float)sueldoMujeres / mujeresTrabajan;
    
    cout <<"Porcentaje de hombres: " <<porcentajeHombres <<"%" <<endl;
    cout <<"Porcentaje de mujeres: " <<porcentajeMujeres <<"%" <<endl;
    cout <<"Porcentaje de hombres que trabajan: " <<porcentajeHombresTrabajan <<"%" <<endl;
    cout <<"Porcentaje de mujeres que trabajan: " <<porcentajeMujeresTrabajan <<"%" <<endl;
    cout <<"Sueldo promedio de hombres que trabajan: " <<sueldoPromedioHombresTrabajan <<endl;
    cout <<"Sueldo promedio de mujeres que trabajan: " <<sueldoPromedioMujeresTrabajan <<endl;
    return 0;
}

