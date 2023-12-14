CC:=g++ 
CFLAGS:= -std=c++17 -lsfml-graphics -lsfml-window -lsfml-system -Wall -Wextra
OUTPUT:=triangulo

all: triangulo.o
	${CC} -o ${OUTPUT} triangulo.o ${CFLAGS}

clean:
	rm -f triangulo
	rm -f *.o

run: all
	./${OUTPUT}
