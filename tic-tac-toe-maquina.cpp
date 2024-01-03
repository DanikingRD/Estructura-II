/*
 * ENUNCIADO: Tic Tac Toe Contra la maquina
 * INTEGRANTES: 1113684 - Clay Manuel Gomera Arias
 *              1116614 - Luis Daniel de la Cruz García
 *              1114950 - Elian Gabriel Villegas Báez
 *              1115808 - Edward Diaz
 *              1113902 - Yu jhih Chen Yeh
 *              1116238 - I Chia Chen Wang
 * FECHA: 2/1/2024 <== Fecha de realización
 */

#include <iostream>

using namespace std;

const int rows = 3;
const int cols = 3;

int readInt(string message);

// clang-format off
char board[rows][cols] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};
// clang-format on

/*
 * Imprime el tablero
 */
void printBoard(char board[rows][cols]) {
    cout << "-------------" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "| ";
        for (int j = 0; j < cols; j++) {
            char c = board[i][j];
            if (c == 'X') {
                cout << "\033[1;31m" << c << "\033[0m | ";
            } else if (c == 'O') {
                cout << "\033[1;34m" << c << "\033[0m | ";
            } else {
                // imprimir el numero de la casilla a color
                cout << i * 3 + j + 1 << " | ";
            }
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

/*
 * Genera un numero aleatorio entre `min` y `max` inclusivos
 */
int genRange(int min, int max) { return min + (rand() % max); }

bool validPlay(int row, int col) {
    bool outOfBounds = row <= 0 || row > rows || col <= 0 || col > cols;
    bool occupied = board[row - 1][col - 1] != ' ';
    return !outOfBounds && !occupied;
}

int readPos() {
    int pos = readInt("Ingrese su jugada: ");
    while (pos < 1 || pos > 9) {
        cout << "La posicion ingresada no es valida. Ingrese nuevamente: ";
        pos = readInt("Ingrese su jugada: ");
    }


}

void play(char board[rows][cols], string player, string bot) {
    int moves = 0;

    while (moves < rows * cols) {
        cout << "Turno de " << (moves % 2 == 0 ? player : bot) << endl;

        int pos;
        if (moves % 2 == 0) {
            // turno del jugador

        } else {
            // turno de la maquina
        }
    }
}

void start() {

    // Ingresar nombres
    string player, bot;
    cout << "Ingrese su nombre: ";
    cin >> player;
    cout << "Ingrese el nombre de la maquina: ";
    cin >> bot;

    cout << " -> " << player << " es X" << endl;
    cout << " -> " << bot << " es O" << endl;

    // Imprimir tablero inicial
    printBoard(board);
    play(board, player, bot);
}

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

int main(void) {

    cout << "Bienvenidos a Tic Tac Toe contra la maquina." << endl;

    bool quit = false;
    while (!quit) {
        cout << "Presione:"
             << "\n0. Para salir"
             << "\n1. Para jugar contra la maquina" << endl;

        int option = readInt("Opcion: ");

        if (option == 0) {
            cout << "Gracias por jugar!" << endl;
            quit = true;
        } else if (option == 1) {
            start();
        } else {
            cout << "Ingrese una opcion valida." << endl;
        }
    }
}