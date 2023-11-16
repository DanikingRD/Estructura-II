/*
 * ENUNCIADO: Tic Tac Toe
 * INTEGRANTES: 1113684 - Clay Manuel Gomera Arias
 *              1116614 - Luis Daniel de la Cruz García
 *              1114950 - Elian Gabriel Villegas Báez
 *              1115808 - Edward Diaz
 *              1113902 - Yu jhih Chen Yeh
 *              1116238 - I Chia Chen Wang
 * FECHA: 13/11/2023 <== Fecha de realización
 */

#include <iostream>

using namespace std;

const int rows = 3;
const int cols = 3;

// clang-format off
char board[rows][cols] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};
// clang-format on

void printBoard(char board[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        cout << "-------------" << endl;
        for (int j = 0; j < cols; j++) {
            char c = board[i][j];
            if (c == 'X') {
                cout << "| \033[1;31m" << c << "\033[0m ";
            } else {
                cout << "| \033[1;34m" << c << "\033[0m ";
            }
        }
        cout << "|" << endl;
    }
    cout << "-------------" << endl;
}

int generateRange(int min, int max) {
    // - `rand` genera un entero aleatorio ej 12346567
    // - `min` y `max` se utilizan para 'convertir' el numero que devuelva al rango [min ,max]
    // - ej: [76312317, 56312310, 35678513, 17352184] -> [6, 5, 3, 1]
    return min + (rand() % max);
}

bool validMove(int row, int col) {
    bool outOfBounds = row <= 0 || row > rows || col <= 0 || col > cols;
    bool occupied = board[row - 1][col - 1] != ' ';
    return !outOfBounds && !occupied;
}

void readPosition(int& row, int& col) {
    cout << "Ingrese su jugada. (fila, columna): ";
    while (!(cin >> row >> col) || !validMove(row, col)) {
        cout << "\nEl movimiento no es válido. Ingrese su jugada nuevamente. (fila, columna): ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    cout << " -> " << row << ", " << col << endl;
}

void calculateNextMachineMove(int& row, int& col) {
    // generate random number
    int checkRow = generateRange(1, rows);
    int checkCol = generateRange(1, cols);

    // check if the position is valid
    while (!validMove(checkRow, checkCol)) {
        checkRow = generateRange(1, rows);
        checkCol = generateRange(1, cols);
    }

    row = checkRow;
    col = checkCol;
}

void gameLoop(string player1, string player2, bool againstPlayer) {
    int moves = 0;
    while (true) {

        if (moves == rows * cols) {
            cout << player1 << " y " << player2 << " empataron." << endl;
            break;
        }

        cout << "Turno de " << (moves % 2 == 0 ? player1 : player2) << endl;

        int row, col;

        // if this is turn of player1:
        if (moves % 2 == 0) {
            readPosition(row, col);
        } else {
            // if this is turn of player2:
            if (againstPlayer) {
                readPosition(row, col);
            } else {
                calculateNextMachineMove(row, col);
            }
        }
        board[row - 1][col - 1] = (moves % 2 == 0 ? 'X' : 'O');

        // anunciar jugada
        cout << " -> " << (moves % 2 == 0 ? player1 : player2) << " jugó en la posición " << row << ", " << col << endl;
        printBoard(board);

        bool winner = false;
        for (int i = 0; i < rows; i++) {
            // chequear filas
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                winner = true;
            }
            // chequear columnas
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                winner = true;
            }
            // chequear diagonal principal
            if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
                winner = true;
            }
            // chequear diagonal secundaria
            if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
                winner = true;
            }
        }
        if (winner) {
            cout << (moves % 2 == 0 ? player1 : player2) << " ha ganado!" << endl;
            break;
        }
        moves++;
    }
}

void play(int gameMode) {

    string player1, player2;

    if (gameMode == 1) {
        // Jugar contra un amigo
        cout << "Ingrese el nombre del jugador 1: ";
        cin >> player1;
        cout << "Ingrese el nombre del jugador 2: ";
        cin >> player2;
    }
    if (gameMode == 2) {
        // Jugar contra la maquina
        cout << "Ingrese su nombre: ";
        cin >> player1;
        player2 = "la máquina";
    }

    printBoard(board);

    cout << " -> " << player1 << " es X" << endl;
    cout << " -> " << player2 << " es O" << endl;
    gameLoop(player1, player2, gameMode == 1);

    // reset the table after the game is over
    // in case the user wants to play again
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = ' ';
        }
    }
}

int main(void) {

    cout << "Bienvenidos a Tic Tac Toe" << endl;

    while (true) {
        cout << "Presione:"
             << "\n0. Para salir"
             << "\n1. Para jugar contra un amigo"
             << "\n2. Para jugar contra la maquina" << endl;

        int option;
        while (!(cin >> option) || option < 0 || option > 2) {
            cout << "Opcion inválida. Intente de nuevo: ";
            cin.clear();
            cin.ignore(123, '\n');
        }

        if (option == 0) {
            cout << "Gracias por jugar!" << endl;
            break;
        }

        play(option);
    }
}