#ifndef __STAGE_H__
#define __STAGE_H__

#include <vector>
#include "point.h"
#include "object.h"
#include "monster.h"

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
#define OFFEND 0
#define CRASH 2

const int BOARDSIZE = 10;

class Stage{
	std::string name;
	std::string description;
	std::string board[BOARDSIZE][BOARDSIZE];
	int stageSet;
	int objectCount;
	Point* playerLocation;
	Point* enemyLocation;
	Monster* enemy;
	Monster* player;

	void addObstacles(std::string, unsigned int);
	int clasify(int, int);
	int relocate(std::string, int, int);
	void setBlanks(std::string);

   public:
   	//Constructor and deconstructor
   	Stage(std::string, std::string, int);
   	void clearStage();

   	//Getters
   	int getObjectCount(){return objectCount;}
   	Point getPlayerLocation() {return *playerLocation;}
   	Point getEnemyLocation() {return *enemyLocation;}
   	std::string getName() {return name;}
   	std::string getDescription() {return description;}
   	std::string getBoardLocation(int y, int x) {return (((x < BOARDSIZE) && (y < BOARDSIZE)) ? board[y][x] : "NULL");}

   	//Check movement
   	int playerCanMove(int);
   	int enemyCanMove(int);

   	//Movements
   	int movePlayerLeft();
   	int movePlayerRight();
   	int movePlayerUp();
   	int movePlayerDown();
   	int moveEnemyLeft();
   	int moveEnemyRight();
   	int moveEnemyUp();
   	int moveEnemyDown();

   	//Print Commands
   	void printStage();
   	void printPlayerLocation();
   	void printEnemyLocation();
   	void printObjects();
   	void printEnemy();
   	void printPlayer();

   	//AI
   	void moveEnemy();
};

#endif
