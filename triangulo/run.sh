#!/bin/bash
# always run a clean build
rm -f triangulo
g++ -std=c++17 -o triangulo triangulo.cpp -lSDL2
./triangulo
