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
const int SEPARATION = 6;

// Estructura para representar una carta
struct Card {
    string symbol;
    int number;
};

// Arreglo para almacenar las cartas
Card cards[MAX];

// Función para leer un entero desde la entrada estándar
int readInt();

// Función para poblar el arreglo de cartas con todas las combinaciones posibles
void poblarCartas() {
    int i = 0;
    for (int j = 0; j < 4; j++) {
        for (int k = 1; k <= 13; k++) {
            cards[i].symbol = symbols[j];
            cards[i].number = k;
            i++;
        }
    }
}

// Función para imprimir un arreglo de cartas
void printCardArray(const Card* arr) {
    for (int i = 0; i < MAX; i++) {
        cout << arr[i].symbol;
        if (arr[i].number >= 2 && arr[i].number <= 10) {
            cout << arr[i].number;
        } else {
            switch (arr[i].number) {
            case 1:
                cout << "A";
                break;
            case 11:
                cout << "J";
                break;
            case 12:
                cout << "Q";
                break;
            case 13:
                cout << "K";
                break;
            }
        }
        cout << " ";

        if ((i + 1) % 13 == 0) {
            cout << endl;
        }
    }
}

// Función para verificar si un número está contenido en un arreglo
bool arrayContains(int* arr, int size, int n) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == n) {
            return true;
        }
    }
    return false;
}

// Función para barajar las cartas
void shuffle(Card* arr) {
    Card output[MAX] = {};
    int aux[SEPARATION] = {};

    for (int i = 0; i < MAX; i++) {
        int j = rand() % MAX;
        Card randomCard = cards[j];

        while (cards[j].number == 0 || arrayContains(aux, SEPARATION, randomCard.number)) {
            j = rand() % MAX;
            randomCard = cards[j];
        }

        output[i] = randomCard;
        aux[i % SEPARATION] = randomCard.number;
        cards[j].number = 0;
    }

    for (int i = 0; i < MAX; i++) {
        arr[i] = output[i];
    }
}

// Función para mostrar el estado de las cartas antes y después de barajar
void makeShuffle() {
    cout << endl << "Cartas antes de barajar:" << endl;
    printCardArray(cards);
    shuffle(cards);
    cout << endl << "Cartas después de barajar:" << endl;
    printCardArray(cards);
}

// Función para leer un entero de la entrada estándar con manejo de errores
int readInt() {
    int n;
    while (!(cin >> n)) {
        cout << "Intente de nuevo: " << endl;
        cin.clear();
        cin.ignore(123, '\n');
    }
    return n;
}

// Función principal
int main() {
    srand((unsigned int)clock());
    cout << "Bienvenido al programa de cartas" << endl;
    poblarCartas();

    bool quit = false;
    while (!quit) {
        cout << "Ingrese: " << endl;
        cout << "0. Para salir." << endl;
        cout << "1. Para mostrar las cartas." << endl;
        cout << "2. Para barajar las cartas." << endl;
        cout << "Opción: ";
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
