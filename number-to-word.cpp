/*
 * ENUNCIADO: Numero a palabra
 * INTEGRANTES: 1113684 - Clay Manuel Gomera Arias
 *              1116614 - Luis Daniel de la Cruz García
 *              1114950 - Elian Gabriel Villegas Báez
 *              1115808 - Edward Diaz
 *              1113902 - Yu jhih Chen Yeh
 *              1116238 - I Chia Chen Wang
 * FECHA: 11/11/2023 <== Fecha de realización
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const float MAX = 999999999.99F;
const string base[] = {"", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
const string especiales[] = {"diez",   "once",      "doce",       "trece",     "catorce",
                             "quince", "dieciseis", "diecisiete", "dieciocho", "diecinueve"};
const string decenas[] = {"",        "",        "veinti",  "treinta", "cuarenta", "cicuenta",
                          "sesenta", "setenta", "ochenta", "noventa", "cien"};
const string centenas[] = {"",           "ciento",      "doscientos",  "trescientos", "cuatrocientos",
                           "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"};

string findNameForNumber(int n) {
    if (n == 0) return "cero";
    if (n == 20) return "veinte";
    if (n == 100) return "cien";
    if (n == 1000) return "mil";
    if (n == 1000000) return "un millón";

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
        // omite el cero al final
        string decena = (n % 100 == 0 ? "" : findNameForNumber(n % 100));
        return centenas[n / 100] + ' ' + decena;
    } else if (n < 1000000) {
        // cubre del 1,000 al 999,999
        string miles = n < 2000 ? "" : findNameForNumber(n / 1000);
        // omite el cero cuando es un numero como 1000, 2000, 3000, etc.
        string cientos = (n % 1000 == 0 ? "" : findNameForNumber(n % 1000));
        // reemplazar "uno" con "un" en numeros como 741,000
        int pos = miles.find("uno");
        if (pos != string::npos) {
            miles.replace(pos, 3, "un");
        }
        return miles + " mil " + cientos;

    } else if (n <= MAX) {
        // cubre del 1,000,000 al 999,999,999
        string miles = (n % 1000000 == 0 ? "" : findNameForNumber(n % 1000000));
        string millones = findNameForNumber(n / 1000000);
        int pos = millones.find("uno");
        if (pos != string::npos) {
            millones.replace(pos, 3, "un");
            return millones + " millón " + miles;
        }
        return millones + " millones " + miles;
    }
    return "Número fuera de rango";
}

int main(void) {
    cout << "Bienvenido al programa un número a palabra\n";
    while (true) {
        cout << "Ingrese un número entre 0 y " << fixed << setprecision(2) << MAX - 0.01 << ": \n";

        double input;
        cout << "Entrada: ";
        while (!(cin >> input) || input < 0 || input > MAX) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nIngrese un número entre 0 y " << fixed << setprecision(2) << MAX - 0.01 << ": ";
        }
        int decimal = (int)((input - floor(input)) * 100);
        string output = findNameForNumber((int)input);
        output[0] = toupper(output[0]);

        if (decimal == 0) {
            cout << " -> " << output << endl;
        } else {
            cout << " -> " << output << " con " << decimal << " centavos" << endl;
        }
    }
    return 0;
}