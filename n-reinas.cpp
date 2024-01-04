/*
 * ENUNCIADO: N Reinas
 * INTEGRANTES: 1113684 - Clay Manuel Gomera Arias
 *              1116614 - Luis Daniel de la Cruz García
 *              1114950 - Elian Gabriel Villegas Báez
 *              1115808 - Edward Diaz
 *              1113902 - Yu jhih Chen Yeh
 *              1116238 - I Chia Chen Wang
 * FECHA: 29/12/2023 <== Fecha de realización
 */
#include <iostream>

using namespace std;

/*
 * Imprime un tablero de NxN
 */
void printBoard(int** board, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j]) {
                printf("\033[1;34mQ\033[0m "); // Imprimir 'Q' en azul si hay una reina
            } else {
                printf(". "); // Imprimir '.' si la casilla está vacía
            }
        }
        printf("\n");
    }
    printf("\n");
}

/*
 * Verifica si es seguro colocar una reina en la posición dada.
 */
bool isSafe(int** board, int n, int row, int col) {
    // Verificar si hay una reina en la misma columna
    int i, j;
    // Comprobar esta fila en el lado izquierdo
    for (i = 0; i < col; i++)
        if (board[row][i]) return false;

    // Comprobar la diagonal superior en el lado izquierdo
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    // Comprobar la diagonal inferior en el lado izquierdo
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j]) return false;

    return true;
}

// Función de backtracking para resolver el problema de las N reinas
int solveNQueens(int** board, int n, int nextCol) {
    int solutionCount = 0; // Contador de soluciones

    if (nextCol >= n) {
        // Se encontró una solución, imprimir el tablero
        // cout << "Solución #" << ++solutionCount << ":\n";
        printBoard(board, n);
        return solutionCount;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(board, n, row, nextCol)) {
            // Colocar una reina
            board[row][nextCol] = 1;
            // Recursivamente resolver para la siguiente fila
            solveNQueens(board, n, nextCol + 1);
            // Backtrack, intentar la siguiente posición
            board[row][nextCol] = 0;
        }
    }

    return solutionCount;
}

// Función para leer un entero desde la entrada estándar con manejo de errores
int readInt(string message) {
    int value;
    cout << message;
    while (!(cin >> value)) {
        cout << "\nEl valor ingresado no es válido. Ingrese nuevamente: ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    return value;
}

// Función principal para iniciar el programa
void start() {
    int n = readInt("Ingrese el valor de N: ");
    int** board = new int*[n];
    for (int i = 0; i < n; ++i) {
        board[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            board[i][j] = 0; // Inicializar el tablero con ceros
        }
    }

    int totalSolutions = solveNQueens(board, n, 0);

    if (totalSolutions == 0) {
        cout << "No se encontró ninguna solución.\n";
    } else {
        cout << "Se encontraron " << totalSolutions << " soluciones.\n";
    }
}

// Función principal
int main() {
    cout << "Bienvenido al programa de N Reinas\n";

    bool quit = false;

    while (!quit) {
        cout << "Ingrese: \n"
             << "0. Para salir\n"
             << "1. Para resolver el problema de N Reinas\n";

        int option = readInt("Ingrese su opcion: ");

        if (option == 0) {
            quit = true;
        } else if (option == 1) {
            start();
        } else {
            cout << "Ingrese una opcion valida.\n";
        }
    }
    cout << "Saliendo del programa...\n";
    return 0;
}