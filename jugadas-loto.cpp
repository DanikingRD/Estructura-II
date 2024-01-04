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
