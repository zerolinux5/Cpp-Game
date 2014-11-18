#ifndef __STAGE_H__
#define __STAGE_H__

#include "point.h"

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

const int BOARDSIZE = 10;
const int OBSTACLENUMBER = 20;

class Stage{
	std::string name;
	std::string description;
	std::string board[BOARDSIZE][BOARDSIZE];
	int stageSet;
	Point* playerLocation;
	Point* enemyLocation;

	void addObstacles(std::string, unsigned int);
	int clasify(int, int);
	int relocate(std::string, int, int);
   public:
   	Stage(std::string, std::string, int, unsigned int);
   	Point* getPlayerLocation() {return playerLocation;}
   	Point* getEnemyLocation() {return enemyLocation;}
   	std::string getName() {return name;}
   	std::string getDescription() {return description;}
   	std::string getBoardLocation(int y, int x) {return (((x < BOARDSIZE) && (y < BOARDSIZE)) ? board[y][x] : "NULL");}
   	void printStage();
   	int playerCanMove(int);
   	int enemyCanMove(int);
   	void printPlayerLocation();
   	void printEnemyLocation();
   	void movePlayerLeft();
   	void movePlayerRight();
   	void movePlayerUp();
   	void movePlayerDown();
   	void moveEnemyLeft();
   	void moveEnemyRight();
   	void moveEnemyUp();
   	void moveEnemyDown();
};

#endif
