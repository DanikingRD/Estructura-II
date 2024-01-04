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

// given a position,
// checks if it wins
bool wins(int pos) {
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;
    // check row
    if (board[row][0] != ' ' && board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
        return true;
    }
    // check col
    if (board[0][col] != ' ' && board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
        return true;
    }
    // check diagonal
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    // check diagonal
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}

void setPlay(string name, int pos, char character) {
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;
    board[row][col] = character;
    cout << " -> " << name << " jugo en la posicion " << pos << endl;
}

int generatePos() {
    // check if its possible to win
    for (int i = 0; i < 9; i++) {

        int row = i / 3;
        int col = i % 3;

        if (board[row][col] == ' ') {
            board[row][col] = 'O';
            if (wins(i + 1)) {
                board[row][col] = ' ';
                return i + 1;
            }
            board[row][col] = ' ';
        }

        // check if its possible to block a player that will win
        if (board[row][col] == ' ') {
            board[row][col] = 'X';
            if (wins(i + 1)) {
                board[row][col] = 'O';
                return i + 1;
            }
            board[row][col] = ' ';
        }
    }
    // generate a random pos that is not ocuppied
    int pos = genRange(1, 9);
    while (isOcuppied(pos)) {
        pos = genRange(1, 9);
    }
    return pos;
}

void play(string player, string bot) {

    // preguntar quien empieza
    cout << "Quien empieza?" << endl;
    cout << "0. " << player << endl;
    cout << "1. " << bot << endl;

    int option = readInt("Opcion: ");
    while (option != 0 && option != 1) {
        cout << "Ingrese una opcion valida." << endl;
        option = readInt("Opcion: ");
    }

    int moves = 0;
    bool isOver = false;
    bool playerTurn = option == 0;

    while (!isOver) {

        // anunciar turno
        cout << "Turno de " << (playerTurn ? player : bot) << endl;

        int pos;
        if (playerTurn) {
            pos = readPos();
        } else {
            // turno de la maquina
            pos = generatePos();
        }

        setPlay(playerTurn ? player : bot, pos, playerTurn ? 'X' : 'O');
        isOver = wins(pos);

        if (isOver) {
            cout << (playerTurn ? player : bot) << " ha ganado!" << endl;
            isOver = true;
        } else if (moves == rows * cols - 1) {
            cout << player << " y " << bot << " empataron." << endl;
            isOver = true;
        }

        printBoard(board);
        moves++;
        playerTurn = !playerTurn;
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
    play(player, bot);

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
    srand(time(NULL));
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