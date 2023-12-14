/*
 * ENUNCIADO: Crear un programa en c++ que permita barajar las 52 cartas
 * de un casino, en donde una carta del mismo tipo este separada de otra
 * almenos 6 cartas de distancia.
 * INTEGRANTES: 1113684 - Clay Manuel Gomera Arias
 *              1116614 - Luis Daniel de la Cruz García
 *              1114950 - Elian Gabriel Villegas Báez
 *              1115808 - Edward Diaz
 *              1113902 - Yu jhih Chen Yeh
 *              1116238 - I Chia Chen Wang
 * FECHA: 12/12/2023 <== Fecha de realización
 */

#include <iostream>

using namespace std;

const int MAX = 52;
string symbols[] = {"♠️", "♥️", "♦️", "♣️"};

struct Card {
    string symbol;
    int number;
};

Card cards[MAX];
int readInt();

void poblarCartas() {
    int i = 0;
    // asignar cada simbolo a 13 cartas
    for (int j = 0; j < 4; j++) {
        for (int k = 1; k <= 13; k++) {
            cards[i].symbol = symbols[j];
            cards[i].number = k;
            i++;
        }
    }
}

void printCardArray(Card* arr) {
    // imprimir las 52 unidades, didividas en 4 grupos de 13
    for (int i = 0; i < MAX; i++) {
        cout << arr[i].symbol << arr[i].number << " ";
        if ((i + 1) % 13 == 0) {
            cout << endl;
        }
    }
}

bool arrayContains(int* arr, int size, int n) {
    for (int i = 0; i < 6; i++) {
        if (arr[i] == n) {
            return true;
        }
    }
    return false;
}

void shuffle(Card* arr) {
    Card output[MAX] = {};
    bool inserted[MAX] = {};
    int aux[6] = {};

    for (int i = 0; i < MAX; i++) {
        int j;
        Card randomCard;
        // do {
        //     j = rand() % MAX;
        //     randomCard = cards[j];
        //     if (i == 50) {
        //         break;
        //     }
        // } while (arrayContains(aux, 6, randomCard.number) || inserted[j]);

        while (true) {
            j = rand() % MAX;
            randomCard = cards[j];
            if (!arrayContains(aux, 6, randomCard.number) && !inserted[j]) {
                break;
            }
        }

        output[i] = randomCard;
        inserted[j] = true;
        aux[i % 6] = randomCard.number;
    }

    for (int i = 0; i < MAX; i++) {
        arr[i] = output[i];
    }
}
void makeShuffle() {
    cout << endl << "Cartas antes de barajar:" << endl;
    printCardArray(cards);
    shuffle(cards);
    cout << endl << "Cartas despues de barajar:" << endl;
    printCardArray(cards);
}

int readInt() {
    int n;
    while (!(cin >> n)) {
        cout << "Intente de nuevo: " << endl;
        cin.clear();
        cin.ignore(123, '\n');
    }
    return n;
}

int main() {
    cout << "Bienvenido al programa cartas" << endl;
    poblarCartas();
    srand(time(NULL));

    bool quit = false;
    while (!quit) {
        cout << "Ingrese: " << endl;
        cout << "0. Para salir." << endl;
        cout << "1. Para mostrar las cartas." << endl;
        cout << "2. Para barajar las cartas." << endl;
        cout << "Opcion: ";
        int option = readInt();
        switch (option) {
        case 0:
            quit = true;
            break;
        case 1:
            printCardArray(cards);
            break;
        case 2:
            makeShuffle();
            break;
        }
    }
    cout << "Saliendo del programa..." << endl;
    return 0;
}