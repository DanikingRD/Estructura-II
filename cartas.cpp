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
 * FECHA: 11/11/2023 <== Fecha de realización
 */

#include <iostream>

using namespace std;

const int MAX = 52;
string symbols[] = {"♠️", "♥️", "♦️", "♣️"};

struct Card {
    string symbol;
    int number;
};

Card cartas[MAX];

void poblarCartas() {
    int i = 0;
    // asignar cada simbolo a 13 cartas
    for (int j = 0; j < 4; j++) {
        for (int k = 1; k <= 13; k++) {
            cartas[i].symbol = symbols[j];
            cartas[i].number = k;
            i++;
        }
    }
}

void printCardArray() {
    // imprimir las 52 unidades, didividas en 4 grupos de 13
    for (int i = 0; i < MAX; i++) {
        cout << cartas[i].symbol << cartas[i].number << " ";
        if ((i + 1) % 13 == 0) {
            cout << endl;
        }
    }
}

bool containsCard(Card* arr, int arrSize, Card card) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i].symbol == card.symbol && arr[i].number == card.number) {
            return true;
        }
    }
    return false;
}

bool containsValue(int* arr, int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

void shuffle(Card* cards, int n) {

    Card output[MAX];
    int aux[n];

    for (int i = 0; i < MAX; i++) {
        Card randomCard = cards[rand() % MAX];
        while (containsCard(output, i, randomCard) || containsValue(aux, n, randomCard.number)) {
            randomCard = cards[rand() % MAX];
        }

        output[i] = randomCard;
        aux[i % n] = randomCard.number;
    }

    for (int i = 0; i < MAX; i++) {
        cards[i] = output[i];
    }
}

int getInt() {
    int n;
    while (!(cin >> n)) {
        cout << "Intente de nuevo: " << endl;
        cin.clear();
        cin.ignore(123, '\n');
    }
    return n;
}

void makeShuffle() {
    cout << "Ingrese la distancia de separacion: ";
    int n = getInt();
    while (n < 0) {
        cout << "La distancia de separacion debe ser mayor o igual a 6" << endl;
        cout << "Ingrese la distancia de separacion: ";
        n = getInt();
    }
    cout << endl << "Cartas antes de barajar:" << endl;
    printCardArray();
    shuffle(cartas, n);
    cout << endl << "Cartas despues de barajar:" << endl;
    printCardArray();
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
        int option = getInt();
        switch (option) {
        case 0:
            quit = true;
            break;
        case 1:
            printCardArray();
            break;
        case 2:
            makeShuffle();
            break;
        }
    }
    cout << "Saliendo del programa..." << endl;
    return 0;
}
