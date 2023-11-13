/*
 * ENUNCIADO: Reina vs Torres Enemigas
 * INTEGRANTES: 1113684 - Clay Manuel Gomera Arias
 *              1116614 - Luis Daniel de la Cruz García
 *              1114950 - Elian Gabriel Villegas Báez
 * FECHA: 11/11/2023 <== Fecha de realización
 */

#include <cmath>
#include <iostream>

using namespace std;

// Realizar un programa C++ que lea un número real (correspondiente a un monto)
// y convertir este monto a palabra.

const float LIMIT = 999999999.99F;

const string base[] = {"", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
const string especiales[] = {"diez",   "once",      "doce",       "trece",     "catorce",
                             "quince", "dieciseis", "diecisiete", "dieciocho", "diecinueve"};
const string decenas[] = {"",        "",        "veinti",  "treinta", "cuarenta", "cicuenta",
                          "sesenta", "setenta", "ochenta", "noventa", "cien"};

const string centenas[] = {"",           "ciento",      "doscientos",  "trescientos", "cuatrocientos",
                           "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"};

string findNameForNumber(int n) {
    if (n == 0)
        return "cero";
    if (n == 20)
        return "veinte";
    if (n == 100)
        return "cien";
    if (n == 1000)
        return "mil";

    if (n < 10) {
        // cubre del 1 al 10
        return base[n];
    } else if (n < 20) {
        // cubre del 10 al 19
        return especiales[n - 10];
    } else if (n < 100) {
        // cubre del 20 al 99
        string separador = (n % 10 == 0 || n < 30) ? "" : " y ";
        return decenas[n / 10] + separador + base[n % 10];
    } else if (n < 1000) {
        // cubre del 100 al 999
        string decena = (n % 100 == 0 ? "" : findNameForNumber(n % 100));
        return centenas[n / 100] + ' ' + decena;
    } else if (n < LIMIT) {
        string unidad = (n % 1000 == 0 ? "" : findNameForNumber(n % 1000));
        // para los numeros entre 1000 y 1999, no se usa la palabra "uno" al
        // principio. e.g 1001 => mil uno, no uno mil
        return (n < 2000 ? "" : findNameForNumber(n / 1000)) + " mil " + unidad;
    }
    return "Número fuera de rango";
}

double readInput() {
    double input;
    printf("Entrada: ");
    while (!(cin >> input) || input < 0 || input > LIMIT) {
        cin.clear();
        cin.ignore(1000, '\n');
        printf("\nIngrese un número entre 0 y %.2f: ", LIMIT - 0.01);
    }
    return input;
}

int main(void) {
    printf("Bienvenido al programa un número a palabra\n");

    while (true) {
        printf("Ingrese un número entre 0 y %.2f: \n", LIMIT - 0.01);

        double input = readInput();
        double decimal = (input - floor(input)) * 100;

        string output = findNameForNumber((int)input);
        output[0] = toupper(output[0]);

        if (decimal == 0.0) {
            cout << " * " << output << endl;
        } else {
            cout << " * " << output << " con " << decimal << " centavos" << endl;
        }
    }
    return 0;
}
