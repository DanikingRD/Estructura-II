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
#include <math.h>

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
 * 123456.7   -> $123,456.70
 */
string currencyFormat(double value) {
    char format[32];
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
    if (pos != -1) {
        for (int i = pos - 3; i > 0; i -= 3) {
            output.insert(i, ",");
        }
    }
    output = "$" + output;
    return output;
}

/**
 * Lee el porcentaje.
 */
double readPercentage(std::string message) {
    double out = 0;

    while (true) {
        cout << message;
        string input;
        cin >> input;
        if (input[input.length() - 1] == '%') {
            input = input.substr(0, input.length() - 1);
        }

        try {
            out = stod(input);
            break;
        } catch (const std::exception& e) {
            cout << "El valor ingresado no es válido.\n";
        }
    }

    return out / 100;
}
void start() {
    // monto total del prestamo
    double monto = readDouble("Ingrese el monto del prestamo: ");
    double tasaAnual = readPercentage("Ingrese la tasa de interes anual: ");
    double pagos = readDouble("Ingrese el numero de pagos o cuotas: (en meses): ");
    double tasaMensual = tasaAnual / 12.0;
    double cuotaMensual = pmt(tasaMensual, pagos, monto);
    double interesTotal = cuotaMensual * pagos - monto;

    printf("\n");
    printf("* La cuota mensual es de: %s\n", currencyFormat(cuotaMensual).c_str());
    printf("* El interes total a pagar es de: %s\n", currencyFormat(interesTotal).c_str());
    printf("* El monto total a pagar es de: %s\n", currencyFormat(cuotaMensual * pagos).c_str());
    printf("\n");

    printf("\t\t\tTabla de Amortizacion\n\n");
    printf("Pago   \t\t  Capital  \t\t  Interes  \t\t  Saldo\n");

    for (int i = 1; i <= pagos; i++) {
        double interes = monto * tasaMensual;
        double capital = cuotaMensual - interes;
        monto = std::max(0.0, monto - capital);
        string capitalStr = currencyFormat(capital);
        string interesStr = currencyFormat(interes);
        string montoStr = currencyFormat(monto);
        printf("%2d \t\t %10s \t\t %10s \t\t %10s\n", i, capitalStr.c_str(), interesStr.c_str(),
               montoStr.c_str());
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
