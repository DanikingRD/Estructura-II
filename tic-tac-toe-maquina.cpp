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

void printBoard(int* board) {
    cout << "-------------" << endl;
    int aux = 0;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            if (board[aux] == -1) {
                cout << "\033[1;31m" << 'X' << "\033[0m | ";
            } else if (board[aux] == 1) {
                cout << "\033[1;34m" << 'O' << "\033[0m | ";
            } else {
                cout << aux + 1 << " | ";
            }
            aux++;
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

/*
 * Determina si un jugador ha ganado.
 * Retorna 0 si no hay ganador, 1 si gana la maquina, -1 si gana el jugador.
 */
int checkWin(int* board) {
    // clang-format off
    const int POSSIBLE_WIN_MOVES[8][3] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
                                            {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
                                            {0, 4, 8}, {2, 4, 6}};
    // clang-format on

    for (int i = 0; i < 8; i++) {
        int row = POSSIBLE_WIN_MOVES[i][0];
        int column = POSSIBLE_WIN_MOVES[i][1];
        int diagonal = POSSIBLE_WIN_MOVES[i][2];
        // Si el valor de una casilla es 0, entonces esta vacia
        // Si el valor en la misma casilla de fila, columna y diagonal es igual, entonces hay un
        // ganador
        if (board[row] != 0 && board[row] == board[column] && board[column] == board[diagonal]) {
            return board[diagonal];
        }
    }
    return 0;
}

/*
 * El algoritmo minimax es un algoritmo recursivo que se utiliza para elegir un movimiento óptimo
 * para un jugador, suponiendo que el oponente tambien está jugando óptimamente.
 * Evaluacion:
 *  - -1 gana min (jugador)
 *  - 0 empate
 *  - 1 gana max (maquina)
 */
int minimax(int* board, int player) {
    int winner = checkWin(board);

    if (winner != 0) return winner * player;

    int move = -1;
    int score = -2;

    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) {
            // Simular jugadas de este jugador
            board[i] = player;
            int thisScore = -minimax(board, player * -1);
            if (thisScore > score) {
                score = thisScore;
                move = i;
            }
            board[i] = 0;
        }
    }
    if (move == -1) return 0;

    return score;
}

/*
 * Selecciona el mejor movimiento para la maquina.
 *
 * Esto se hace simulando todos los posibles siguientes movimientos de la maquina
 * y revisando con cual de ellos el oponente tiene la menor probabilidad de ganar
 * haciendo uso del algoritmo minimax para evaluar las jugadas del oponente.
 */
int findBestMove(int* board) {
    int move = -1;
    int score = -2; // Lowest possible score.
    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) { // Casilla vacia
            // Simular jugadas
            board[i] = 1;
            int tempScore = -minimax(board, -1);
            board[i] = 0;
            if (tempScore > score) {
                score = tempScore;
                move = i;
            }
        }
    }
    return move;
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

/*
 * Evaluacion del ganador:
 * -1 -> Gana el jugador
 * 0 -> Empate
 * 1 -> Gana la maquina
 */
void play(int* board) {
    cout << "Eligen quien inicia el juego: \n"
         << "0. Tu\n"
         << "1. La maquina\n";

    int option = readInt("Ingrese su opcion: ");

    int moves = 0;
    switch (option) {
    case 0:
        cout << "Inicia el jugador." << endl;
        break;
    case 1:
        cout << "Inicia la maquina." << endl;
        board[findBestMove(board)] = 1;
        moves++;
        cout << "\nTablero despues del movimiento de la maquina:\n";
        printBoard(board);
        break;

    default:
        cout << "Opcion invalida. Inicia el jugador." << endl;
        break;
    }

    bool quit = false;
    while (!quit) {
        int move = readInt("Ingrese su movimiento: ");
        // La casilla no esta ocupada
        if (board[move - 1] == 0) {
            // turno del jugador
            if (!quit) {
                board[move - 1] = -1; // La casilla ahora esta ocupada por el jugador
                moves++;
                cout << "\nTablero despues de su movimiento:\n";
                printBoard(board);
            }
            quit = checkWin(board) != 0 || moves == 9;
            if (!quit) {
                // turno de la maquina
                board[findBestMove(board)] = 1;
                cout << "\nTablero despues del movimiento de la maquina:\n";
                printBoard(board);
                moves++;
            }
            quit = checkWin(board) != 0 || moves == 9;
        } else {
            cout << "Movimiento invalido. Intente de nuevo." << endl;
        }
    }
}

int main(void) {
    cout << "Bienvenidos a Tic Tac Toe contra la maquina." << endl;
    int board[9] = {0};
    printBoard(board);
    play(board);

    switch (checkWin(board)) {
    case 0:
        cout << "Empate." << endl;
        break;
    case 1:
        cout << "Perdiste." << endl;
        break;
    case -1:
        cout << "Felicidades, lograste lo imposible o (encontraste un bug)." << endl;
        break;
    }
}
