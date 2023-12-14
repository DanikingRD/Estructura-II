/*
 * Grupo 1: Programa C++ que Invierta las palabras en un archivo de texto
 * INTEGRANTES:
 *              1113684 - Clay Manuel Gomera Arias
 *              1116614 - Luis Daniel de la Cruz García
 *              1114950 - Elian Gabriel Villegas Báez
 *              1115808 - Edward Diaz
 *              1113902 - Yu jhih Chen Yeh
 *              1116238 - I Chia Chen Wang
 *
 * FECHA: 12/13/2023 <== Fecha de realización
 */

//* Librerias utilizadas
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <sstream>

/// @brief Esta funcion se encarga de invertir cada palabra de forma singular
/// @param word
/// @return La palabra que fue parametrizada, en su forma invertida. Ejemplo: (input: word, output: drow)
std::string string_reversing(std::string word)
{
    std::string reversed;
    for (int i = word.length() - 1; i >= 0; --i)
    {
        reversed += word[i];
    }
    return reversed;
}
/// @brief Se encargará de modificar el archivo como un conjunto y luego introducirá el texto en conjunto
/// @param inputNameFile
/// @param outputNameFile
/// @return Todo el texto con la modificación a cada palabra
std::string bulkReversing(const std::string &inputNameFile, const std::string &outputNameFile)
{
    char character;
    std::string word;
    std::stringstream content;

    std::ifstream inputFile;
    std::ofstream outputFile;
    inputFile.open(inputNameFile);

    while (inputFile.get(character))
    {
        if (std::isalpha(character))
        {
            word += character;
        }
        else
        {
            if (!word.empty())
            {
                content << string_reversing(word);
                word.clear();
            }
            content << character;
        }
    }
    inputFile.close();

    outputFile.open(outputNameFile);
    outputFile.clear();
    outputFile << content.str();
    outputFile.close();

    return content.str();
}

/// @brief Funcion en caso de que el usuario decida cambiar el nombre del archivo de salida.
/// @param inputNameFile
void createNewFile(const std::string &inputNameFile)
{
    std::string outputNameFile;
    std::ofstream outputFile;
    while (!outputFile.is_open())
    {
        std::cout << "Porfavor eliga el nombre para su archivo de salida: ";
        std::cin >> outputNameFile;
        outputNameFile += ".txt";
        std::ofstream outputFile(outputNameFile);
        outputFile.open(outputNameFile);
        if (!outputFile.is_open())
        {
            std::cout << std::endl
                      << "\nError abriendo el archivo: " << outputNameFile << std::endl;
            std::cout << "Recuerde que tiene que ser un nombre valido para un archivo .txt (no escriba la extension .txt)" << std::endl;
        }
        else
        {
            outputFile.close();
            break;
        }
    }

    bulkReversing(inputNameFile, outputNameFile);

    std::cout << "\nEl archivo manipulado con palabras en reverso está en: '" << outputNameFile << "'" << std::endl;
}

/// @brief Función Principal: encargada de revisar si archivo existe e inicializar las variantes
/// @param  void
void Manipulation(void)
{
    // Inicialización de variables
    std::string inputNameFile, outputNameFile;
    std::string confirmation;
    std::ifstream inputFile;

    // Bucle en caso de que el usuario no introduzca un valor valido
    while (!inputFile.is_open())
    {
        std::cout << "\nPorfavor ingrese el nombre del archivo. \nNo ponga el tipo de extension(.txt)\nEste programa solo puede reescribir archivos '.txt'\n\nNombre: ";
        std::cin >> inputNameFile;
        inputNameFile += ".txt";
        std::ifstream inputFile(inputNameFile);
        inputFile.open(inputNameFile);
        // Revisa si es un archivo de texto valido
        if (!inputFile.is_open())
        {
            std::cout << std::endl
                      << "\nError abriendo el archivo: " << inputNameFile << std::endl;
            std::cout << "Recuerde que de be ser un archivo .txt (no escriba .txt)" << std::endl;
        }
        else // Si es un nombre correcto, cerrará el archivo para no tener inconvenientes futuros con la apertura y el cerrado
        {
            inputFile.close();
            break;
        }
    }

    // Pregunta si el ususario quiere cambiar el nombre del archivo de salida
    while (true)
    {
        std::cout << "Desea asignar crear un nuevo archivo para la salida? [Y, N]: ";
        std::cin >> confirmation;
        if (confirmation == "y" || confirmation == "Y")
        {
            createNewFile(inputNameFile);
            exit(0);
        }
        else if (confirmation == "n" || confirmation == "Y")
        {
            std::cout << "\nEl archivo de entrada va a ser reutilizado\n"
                      << std::endl;
            outputNameFile = inputNameFile;
            break;
        }
        else
        {
            std::cout << "\nPorfavor elija una opcion valida.\n"
                      << std::endl;
        }
    }

    bulkReversing(inputNameFile, outputNameFile);

    std::cout << "\nEl archivo manipulado con palabras en reverso está en: '" << outputNameFile << "'" << std::endl;
}

int main(int argc, char const *argv[])
{
    std::cout << "\n Inicializando programa...\n"
              << std::endl;
    Manipulation();
    return 0;
}
