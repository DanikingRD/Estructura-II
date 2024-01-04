/*
 * ENUNCIADO: Jugadas de la loto
 * INTEGRANTES: 1113684 - Clay Manuel Gomera Arias
 *              1116614 - Luis Daniel de la Cruz García
 *              1114950 - Elian Gabriel Villegas Báez
 *              1115808 - Edward Diaz
 *              1113902 - Yu jhih Chen Yeh
 *              1116238 - I Chia Chen Wang
 * FECHA: 3/1/2023 <== Fecha de realización
 */

#include <iostream>
#include <time.h>

const int cantidadJugadas = 38;
const int cantidadGrupo = 6;

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void jugadaLoteria(int* posiblesJugadas, int jugadaMasAlta, int jugadaActual, int* jugada,
                   int indiceGrupo) {
    if (indiceGrupo >= cantidadGrupo) {
        printArray(jugada, cantidadGrupo);
        return;
    }
    if (jugadaActual >= jugadaMasAlta) {
        return;
    }
    jugada[indiceGrupo] = posiblesJugadas[jugadaActual];
    jugadaLoteria(posiblesJugadas, jugadaMasAlta, jugadaActual + 1, jugada, indiceGrupo + 1);
    jugadaLoteria(posiblesJugadas, jugadaMasAlta, jugadaActual + 1, jugada, indiceGrupo);
}

int main() {

    struct timespec start, finish;
    double elapsed;
    clock_gettime(CLOCK_MONOTONIC, &start);

    int arr[cantidadJugadas];
    for (int i = 0; i < cantidadJugadas; i++) {
        arr[i] = i + 1;
    }
    int result[cantidadGrupo];
    jugadaLoteria(arr, cantidadJugadas, 0, result, 0);

    clock_gettime(CLOCK_MONOTONIC, &finish);
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) * 1e-9;
    std::cout << "Tiempo de ejecución: " << elapsed << " segundos." << std::endl;

    return 0;
}
