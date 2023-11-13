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

void readPosition(int& row, int& col) {
    cout << "Ingrese su jugada. (fila, columna): ";
    while (!(cin >> row >> col) || row <= 0 || row > rows || col <= 0 || col > cols) {
        cout << "\nEntrada inválida. Ingrese su jugada. (fila, columna): ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    cout << " -> " << row << ", " << col << endl;
}

int main(void) {

    cout << "Bienvenidos a Tic Tac Toe" << endl;

    string player1, player2;

    cout << "Ingrese el nombre del jugador 1: ";
    cin >> player1;

    cout << "Ingrese el nombre del jugador 2: ";
    cin >> player2;

    cout << " -> " << player1 << " es X" << endl;
    cout << " -> " << player2 << " es O" << endl;
    printBoard(board);

    int moves = 0;

    while (true) {

        if (moves == rows * cols) {
            cout << player1 << " y " << player2 << " empataron." << endl;
            return 0;
        }

        cout << "Turno de " << (moves % 2 == 0 ? player1 : player2) << endl;

        int row, col;
        readPosition(row, col);

        if (board[row - 1][col - 1] != ' ') {
            cout << "Posicion (" << row << ", " << col << ") ocupada" << endl;
            continue;
        }

        board[row - 1][col - 1] = (moves % 2 == 0 ? 'X' : 'O');
        printBoard(board);

        for (int i = 0; i < rows; i++) {

            // chequear filas
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                cout << "Ganó " << (moves % 2 == 0 ? player1 : player2) << endl;
                return 0;
            }
            // chequear columnas
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                cout << "Ganó " << (moves % 2 == 0 ? player1 : player2) << endl;
                return 0;
            }
            // chequear diagonal principal
            if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
                cout << "Ganó " << (moves % 2 == 0 ? player1 : player2) << endl;
                return 0;
            }
            // chequear diagonal secundaria
            if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
                cout << "Ganó " << (moves % 2 == 0 ? player1 : player2) << endl;
                return 0;
            }
        }
        moves++;
    }
}