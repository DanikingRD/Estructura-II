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

const int n = 38;
const int k = 6;

void generateCombinations(int numbers[], int start, int remaining, int result[], int resultIndex) {
    if (remaining == 0) {
        for (int i = 0; i < k; ++i) {
            std::cout << result[i] << " ";
        }
        std::cout << std::endl;
        return;
    }

    for (int i = start; i < n; ++i) {
        result[resultIndex] = numbers[i];
        generateCombinations(numbers, i + 1, remaining - 1, result, resultIndex + 1);
    }
}

int main() {
    int numbers[n];
    for (int i = 0; i < n; ++i) {
        numbers[i] = i + 1;
    }

    int result[k];
    generateCombinations(numbers, 0, k, result, 0);

    return 0;
}
