/*
 * ENUNCIADO: Inicie colocando tres puntos de manera de esos puntos determinen un triangulo
 * equilátero o isosceles. Coloque un cuarto punto fuera del triángulo imaginario que
 * forman los anteriores tres puntos (como vértices de triángulo).
 * INTEGRANTES: 1113684 - Clay Manuel Gomera Arias
 *              1116614 - Luis Daniel de la Cruz García
 *              1114950 - Elian Gabriel Villegas Báez
 *              1115808 - Edward Diaz
 *              1113902 - Yu jhih Chen Yeh
 *              1116238 - I Chia Chen Wang
 * FECHA: 12/12/2023 <== Fecha de realización
 */

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

// Definición de tipos para mayor claridad en el código
typedef sf::Vector2f Vec2;
typedef sf::RenderWindow Window;

// Configuración inicial de la ventana
void setup(Window* w) {
    w->create(sf::VideoMode(1280, 720), "Triangulo");
    w->setFramerateLimit(60);
}

// Dibuja un vértice en la ventana con un color específico
void drawVertex(Vec2 p, sf::Color color, Window* window) {
    sf::VertexArray vertex(sf::Points, 1);
    vertex[0].position = p;
    vertex[0].color = color;
    window->draw(vertex);
}

// Maneja los eventos de la ventana, en este caso, se cierra la ventana al hacer clic en el botón de cerrar
void pollEvents(Window* w) {
    sf::Event e;
    while (w->pollEvent(e)) {
        if (e.type == sf::Event::Closed) {
            w->close();
        }
    }
}

int main(void) {
    cout << "Bienvenido al programa triangulo" << endl;
    Window w;
    setup(&w);

    while (w.isOpen()) {
        pollEvents(&w);
        w.clear();

        int windowWidth = w.getSize().x;
        int windowHeight = w.getSize().y;
        int distance = 320;

        // Definición de los vértices del triángulo y un punto exterior
        Vec2 v1 = Vec2(windowWidth / 2.0, windowHeight / 2.0 - distance);
        Vec2 v2 = Vec2(windowWidth / 2.0 + distance, windowHeight / 2.0 + distance);
        Vec2 v3 = Vec2(windowWidth / 2.0 - distance, windowHeight / 2.0 + distance);
        Vec2 vExterior = Vec2(windowWidth / 2.0, windowHeight / 2.0 + distance * 2);

        // Dibuja los vértices del triángulo y el punto exterior
        drawVertex(v1, sf::Color::Red, &w);
        drawVertex(v2, sf::Color::Green, &w);
        drawVertex(v3, sf::Color::Blue, &w);
        drawVertex(vExterior, sf::Color::Yellow, &w);

        // Algoritmo de generación de puntos para formar un fractal
        for (int i = 0; i < 30000; i++) {
            int dice = rand() % 3 + 1;

            Vec2 vRandom;
            switch (dice) {
                case 1: vRandom = Vec2((v1.x + vExterior.x) / 2, (v1.y + vExterior.y) / 2); break;
                case 2: vRandom = Vec2((v2.x + vExterior.x) / 2, (v2.y + vExterior.y) / 2); break;
                default: vRandom = Vec2((v3.x + vExterior.x) / 2, (v3.y + vExterior.y) / 2); break;
            }

            // Colores para los puntos generados
            sf::Color colors[2] = {sf::Color::Yellow, sf::Color::Green};

            // Dibuja el punto aleatorio con un color específico
            drawVertex(vRandom, colors[i % 2], &w);

            vExterior = vRandom;

            // Actualiza la ventana cada cierto número de iteraciones para mostrar el progreso
            if (i % 12 == 0) {
                w.display();
            }
        }
    }

    return 0;
}
