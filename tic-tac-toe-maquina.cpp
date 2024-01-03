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

bool isOcuppied(int pos) {
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;
    return board[row][col] != ' ';
}

int readPos() {
    int pos = readInt("Ingrese su jugada: ");
    while (pos < 1 || pos > 9 || isOcuppied(pos)) {
        cout << "La posicion ingresada no es valida. Ingrese nuevamente: ";
        pos = readInt("Ingrese su jugada: ");
    }
    return pos;
}

int generatePos() {
    int pos = genRange(1, 9);
    while (isOcuppied(pos)) {
        pos = genRange(1, 9);
    }
    return pos;
}

void setPlay(string name, int pos, char player) {
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;
    board[row][col] = player;
    // anunciar jugada
    cout << " -> " << name << " jugó en la casilla " << pos << endl;
}

void play(char board[rows][cols], string player, string bot) {
    int moves = 0;
    bool isOver = false;
    while (!isOver) {

        bool playerTurn = moves % 2 == 0;
        cout << "Turno de " << (playerTurn ? player : bot) << endl;

        int pos;
        if (playerTurn) {
            pos = readPos();
        } else {
            // turno de la maquina
            pos = generatePos();
        }

        setPlay(playerTurn ? player : bot, pos, playerTurn ? 'X' : 'O');

        for (int i = 0; i < rows; i++) {
            // chequear filas
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                isOver = true;
            }
            // chequear columnas
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                isOver = true;
            }
            // chequear diagonal principal
            if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
                isOver = true;
            }
            // chequear diagonal secundaria
            if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
                isOver = true;
            }
        }

        if (isOver) {
            cout << (playerTurn ? player : bot) << " ha ganado!" << endl;
            break;
        } else if (moves == rows * cols - 1) {
            cout << player << " y " << bot << " empataron." << endl;
            isOver = true;
        }

        printBoard(board);
        moves++;
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

    // clear
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; ++j) {
            board[i][j] = ' ';
        }
    }
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