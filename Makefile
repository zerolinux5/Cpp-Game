run:
	make all
	clear
	./tests

all: tests

tests: tests.o monster.o attack.o object.o stage.o point.o ai.o
	g++ -o tests point.o attack.o monster.o object.o stage.o ai.o tests.o

tests.o: tests.cpp monster.cpp attack.cpp object.cpp stage.cpp point.cpp ai.cpp
	g++ -c point.cpp attack.cpp monster.cpp object.cpp stage.cpp ai.cpp tests.cpp

clean:
	rm *.o tests