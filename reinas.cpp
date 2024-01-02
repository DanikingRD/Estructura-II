#include <iostream>

const int n = 8; // Tamaño del tablero

// Función para imprimir el tablero
void printBoard(int board[n][n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << (board[i][j] ? "Q" : ".") << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Función para verificar si es seguro colocar una reina en la posición (row, col)
bool isSafe(int board[n][n], int row, int col) {
    // Verificar si hay una reina en la misma columna
    for (int i = 0; i < row; ++i) {
        if (board[i][col]) {
            return false;
        }
    }

    // Verificar la diagonal izquierda-arriba a derecha-abajo
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j]) {
            return false;
        }
    }

    // Verificar la diagonal izquierda-abajo a derecha-arriba
    for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Función de backtracking para resolver el problema de las ocho reinas
bool solveNQueens(int board[n][n], int row) {
    if (row == n) {
        // Se encontró una solución, imprimir el tablero
        printBoard(board);
        return true;
    }

    bool res = false;

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col)) {
            // Colocar una reina
            board[row][col] = 1;

            // Recursivamente resolver para la siguiente fila
            res = solveNQueens(board, row + 1) || res;

            // Backtrack, intentar la siguiente posición
            board[row][col] = 0;
        }
    }

    return res;
}

int main() {
    // Inicializar el tablero de 8x8
    int board[n][n] = {0};

    // Comenzar a resolver el problema de las ocho reinas
    if (!solveNQueens(board, 0)) {
        std::cout << "No existe solución." << std::endl;
    }

    return 0;
}