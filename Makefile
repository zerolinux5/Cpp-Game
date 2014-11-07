all: mainGame

mainGame: mainGame.o monster.o
	g++ -o mainGame monster.o mainGame.o

mainGame.o: mainGame.cpp monster.cpp
	g++ -c monster.cpp mainGame.cpp

clean:
	rm *.o mainGame
