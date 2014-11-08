all: mainGame

mainGame: mainGame.o monster.o attack.o object.o
	g++ -o mainGame attack.o monster.o object.o mainGame.o

mainGame.o: mainGame.cpp monster.cpp attack.cpp object.cpp
	g++ -c attack.cpp monster.cpp object.cpp mainGame.cpp

clean:
	rm *.o mainGame
