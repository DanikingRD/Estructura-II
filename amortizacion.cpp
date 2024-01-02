/*
 * ENUNCIADO: Tabla de Amortizacion
 * INTEGRANTES: 1113684 - Clay Manuel Gomera Arias
 *              1116614 - Luis Daniel de la Cruz García
 *              1114950 - Elian Gabriel Villegas Báez
 *              1115808 - Edward Diaz
 *              1113902 - Yu jhih Chen Yeh
 *              1116238 - I Chia Chen Wang
 * FECHA: 27/12/2023 <== Fecha de realización
 */
#include <iostream>

using namespace std;

double readDouble(string _);

/*
 * Calcular el pago mensual (PMT)
 * @param tasa Tasa de interes mensual
 * @param nper Numero de pagos o cuotas
 * @param capital Monto del prestamo
 */
double pmt(double tasa, int pagos, double capital) {
    return capital * (tasa * pow(1 + tasa, pagos)) / (pow(1 + tasa, pagos) - 1);
}

/*
 * Formatea un double a un string con formato de moneda
 * Ejemplos:
 * 123456.789 -> $123,456.79
 *   123456.7 -> $123,456.70
 *     123456 -> $123,456.00
 */
string currencyFormat(double value) {
    char format[100];
    // TODO: maybe use the c++ way but it sucks. This is easier and requires no imports.
    snprintf(format, sizeof(format), "%.2f", value);

    string output = std::string(format);

    int pos = -1;
    for (int i = 0; i < output.length(); i++) {
        if (output[i] == '.') {
            pos = i;
            break;
        }
    }
    for (int i = pos - 3; i > 0; i -= 3) {
        output[i] = ',';
    }
    output = "$" + output;
    return output;
}

void start() {
    // monto total del prestamo
    double monto = readDouble("Ingrese el monto del prestamo: ");
    double tasaAnual = readDouble("Ingrese la tasa de interes anual (en porcentaje): ");
    // convertir tasa anual a porcentaje ej 10% -> 0.1
    tasaAnual /= 100.0;
    double pagos = readDouble("Ingrese el numero de pagos o cuotas: (en meses): ");
    double tasaMensual = tasaAnual / 12.0;
    double cuotaMensual = pmt(tasaMensual, pagos, monto);

    printf("\t\t\tTabla de Amortizacion\n");
    printf("* La cuota mensual es de: %.2f\n", cuotaMensual);
    printf("Pago  \t\t  Capital  \t\t  Interes  \t\t  Saldo\n");

    for (int i = 1; i <= pagos; i++) {
        double interes = monto * tasaMensual;
        double capital = cuotaMensual - interes;
        monto -= capital;
        printf("%2d \t\t %8s \t\t %8s \t\t %8s\n", i, currencyFormat(capital).c_str(),
               currencyFormat(interes).c_str(), currencyFormat(monto).c_str());
    }
}

double readDouble(string message) {
    double value;
    cout << message;
    while (!(cin >> value)) {
        cout << "\nEl valor ingresado no es válido. Ingrese nuevamente: ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    return value;
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
    cout << "Bienvenido al programa de calculo de tabla de amortizacion\n";
    bool quit = false;
    while (!quit) {
        cout << "Ingrese: \n"
             << "0. Para salir\n"
             << "1. Para calcular la tabla de amortizacion\n";

        int option = readInt("Ingrese su opcion: ");
        if (option == 0) {
            quit = true;
        } else if (option == 1) {
            start();
        } else {
            cout << "Ingrese una opcion valida.\n";
        }
    }
    cout << "Saliedo del programa...\n";
    return 0;
}
