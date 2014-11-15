run:
	make all
	clear
	./mainGame

all: mainGame

mainGame: mainGame.o monster.o attack.o object.o stage.o point.o
	g++ -o mainGame point.o attack.o monster.o object.o stage.o mainGame.o

mainGame.o: mainGame.cpp monster.cpp attack.cpp object.cpp stage.cpp point.cpp
	g++ -c point.cpp attack.cpp monster.cpp object.cpp stage.cpp mainGame.cpp

clean:
	rm *.o mainGame