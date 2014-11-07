all: mainGame

mainGame: mainGame.o monster.o attack.o
	g++ -o mainGame attack.o monster.o mainGame.o

mainGame.o: mainGame.cpp monster.cpp attack.cpp 
	g++ -c attack.cpp monster.cpp mainGame.cpp

clean:
	rm *.o mainGame
