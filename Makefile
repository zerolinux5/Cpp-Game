run:
	make all
	clear
	./tests

game:
	make actualGame
	clear
	./game

actualGame: makeGame

makeGame: game.o monster.o attack.o object.o stage.o point.o ai.o
	g++ -o game point.o attack.o monster.o object.o stage.o ai.o game.o

game.o: game.cpp monster.cpp attack.cpp object.cpp stage.cpp point.cpp ai.cpp
	g++ -c point.cpp attack.cpp monster.cpp object.cpp stage.cpp ai.cpp game.cpp

all: tests

tests: tests.o monster.o attack.o object.o stage.o point.o ai.o
	g++ -o tests point.o attack.o monster.o object.o stage.o ai.o tests.o

tests.o: tests.cpp monster.cpp attack.cpp object.cpp stage.cpp point.cpp ai.cpp
	g++ -c point.cpp attack.cpp monster.cpp object.cpp stage.cpp ai.cpp tests.cpp

spotless:
	rm *.o tests game

clean:
	rm *.o tests

cleanGame:
	rm *.o game