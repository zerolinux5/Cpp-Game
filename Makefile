all: mainGame

mainGame: mainGame.o monster.o attack.o
	g++ -o mainGame monster.o attack.o mainGame.o

mainGame.o: mainGame.cpp monster.cpp attack.cpp 
	g++ -c monster.cpp attack.cpp mainGame.cpp

clean:
	rm *.o mainGame
