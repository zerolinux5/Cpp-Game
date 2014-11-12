run:
	make all
	clear
	./mainGame

all: mainGame

mainGame: mainGame.o monster.o attack.o object.o stage.o
	g++ -o mainGame attack.o monster.o object.o stage.o mainGame.o

mainGame.o: mainGame.cpp monster.cpp attack.cpp object.cpp stage.cpp
	g++ -c attack.cpp monster.cpp object.cpp stage.cpp mainGame.cpp

clean:
	rm *.o mainGame