all: mainGame

mainGame: mainGame.o
	g++ -o mainGame mainGame.o

mainGame.o: mainGame.cpp
	g++ -c mainGame.cpp

clean:
	rm *.o mainGame
