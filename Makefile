ifeq (git,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "run"
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(RUN_ARGS):;@:)
endif

all: mainGame

mainGame: mainGame.o monster.o attack.o object.o stage.o
	g++ -o mainGame attack.o monster.o object.o stage.o mainGame.o

mainGame.o: mainGame.cpp monster.cpp attack.cpp object.cpp stage.cpp
	g++ -c attack.cpp monster.cpp object.cpp stage.cpp mainGame.cpp

clean:
	rm *.o mainGame

git:
	git add -A
	git commit -m"$(RUN_ARGS)"
	git push -u origin master