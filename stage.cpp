#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "stage.h"
#include "object.h"
#include "monsterList.h"

#define BOARD (board[y][x])
#define XPLUS (board[y][x+1])
#define YPLUS (board[y+1][x])
#define XMINUS (board[y][x-1])
#define YMINUS (board[y-1][x])
#define COMPARE(x,y) (x.compare(y) == 0)

#define OBSTACLE "^"
#define ENEMY "O"
#define PLAYER "X"
#define FIELD "_"
#define TESTMON1 (*monList[0])
#define TESTMON2 (*monList[1])


const int OBSTACLENUMBER = 20;
std::vector<Object*> objectList(OBSTACLENUMBER);

const std::string OBJECTNAME = "Tree";
const int OBJECTHP = 20;
const int OBJECTDEF = 5;

//0-8
enum Location{CornerLeftT, Top, CornerRightT, Left, Middle, Right, CornerLeftB, Bottom, CornerRightB};


int Stage::clasify(int x, int y){
	int flag;
	if(x == 0 && y == 0){
		flag = CornerLeftT;
	} else if ((x == BOARDSIZE - 1) && y == 0){
		flag = CornerRightT;
	} else if (x == 0 && (y == BOARDSIZE - 1)){
		flag = CornerLeftB;
	} else if ((x == BOARDSIZE - 1) && (y == BOARDSIZE - 1)){
		flag = CornerRightB;
	} else if (y == 0){
		flag = Top;
	} else if (y == BOARDSIZE - 1){
		flag = Bottom;
	} else if (x == 0){
		flag = Left;
	} else if (x == BOARDSIZE - 1){
		flag = Right;
	} else {
		flag = Middle;
	}

	return flag;
}

int Stage::relocate(std::string obstacleName, int x, int y){
	int flag = 0, location = clasify(x, y);
	if(COMPARE(obstacleName,BOARD)){
		flag = 1;
	} else {
		switch(location){
			case CornerLeftT:
				//std::cout << "case CornerLeftT" << std::endl;
				if (COMPARE(obstacleName,XPLUS)){
					flag = 1;
				} else if (COMPARE(obstacleName,YPLUS)){
					flag = 1;
				}
				break;
			case Top:
				//std::cout << "case Top" << std::endl;
				if (obstacleName.compare(XPLUS)){
					flag = 1;
				} else if (obstacleName.compare(YPLUS)){
					flag = 1;
				} else if (COMPARE(obstacleName,XMINUS)){
					flag = 1;
				}
				break;
			case CornerRightT:
				//std::cout << "case CornerRightT" << std::endl;
				if (COMPARE(obstacleName,XMINUS)){
					flag = 1;
				} else if (COMPARE(obstacleName,YPLUS)){
					flag = 1;
				}
				break;
			case Left:
				//std::cout << "case Left" << std::endl;
				if (COMPARE(obstacleName,XPLUS)){
					flag = 1;
				} else if (COMPARE(obstacleName,YPLUS)){
					flag = 1;
				} else if (COMPARE(obstacleName,YMINUS)){
					flag = 1;
				}
				break;
			case Middle:
				//std::cout << "case Middle" << std::endl;
				if (COMPARE(obstacleName,XPLUS)){
					flag = 1;
				} else if (COMPARE(obstacleName,YPLUS)){
					flag = 1;
				} else if (COMPARE(obstacleName,XMINUS)){
					flag = 1;
				} else if (COMPARE(obstacleName,YMINUS)){
					flag = 1;
				}
				break;
			case Right:
				//std::cout << "case Right" << std::endl;
				if (COMPARE(obstacleName,XMINUS)){
					flag = 1;
				} else if (COMPARE(obstacleName,YPLUS)){
					flag = 1;
				} else if (COMPARE(obstacleName,YMINUS)){
					flag = 1;
				}
				break;
			case CornerLeftB:
				//std::cout << "case CornerLeftB" << std::endl;
				if (COMPARE(obstacleName,XPLUS)){
					flag = 1;
				} else if (COMPARE(obstacleName,YMINUS)){
					flag = 1;
				}
				break;
			case Bottom:
				//std::cout << "case Bottom" << std::endl;
				if (COMPARE(obstacleName,XPLUS)){
					flag = 1;
				} else if (COMPARE(obstacleName,XMINUS)){
					flag = 1;
				} else if (COMPARE(obstacleName,YMINUS)){
					flag = 1;
				}
				break;
			case CornerRightB:
				//std::cout << "case CornerRightB" << std::endl;
				if (COMPARE(obstacleName,XMINUS)){
					flag = 1;
				} else if (COMPARE(obstacleName,YMINUS)){
					flag = 1;
				}
				break;
			default:
				std::cout << "Error" << std::endl;
				break;
		}
	}
	return flag;
}

//Private helper function to add obstacles
void Stage::addObstacles(std::string obstacleName, unsigned int seed){
	int i = 0, randX, randY, segment;
	srand (seed);
	for(; i < OBSTACLENUMBER; i++){
		do{
			randX = rand() % BOARDSIZE;
			randY = rand() % BOARDSIZE;
		} while (relocate(obstacleName, randX, randY));
		objectList[i] = new Object(OBJECTHP, OBJECTDEF, OBJECTNAME, randX, randY);
		board[randY][randX] = obstacleName;
	}
}

void Stage::setBlanks(std::string inChar){
	int i = 0, j = 0;
	for(;i < BOARDSIZE; i++){
		for(j = 0;j < BOARDSIZE; j++){
			board[i][j] = inChar;
			//std::cout << "G ";
		}
		//std::cout << std::endl;
	}
}

Stage::Stage(std::string newName, std::string newDescription, int stageNum)
{
	int flag = 1;
	initialize();

	enemy = new Monster(TESTMON1);
	player = new Monster(TESTMON2);
	name = newName;
	description = newDescription;
	stageSet = stageNum;
	objectCount = OBSTACLENUMBER;
	srand (time(NULL));
	unsigned int seed = rand() % 1000;
	enemyLocation = new Point(BOARDSIZE/2, 0);

	switch(stageSet){
		case 1:
			setBlanks(FIELD);
			addObstacles(OBSTACLE,seed);
			break;
		case 2:
			setBlanks(FIELD);
			addObstacles(OBSTACLE,seed);
			break;
		case 3:
			setBlanks(FIELD);
			addObstacles(OBSTACLE,seed);
			break;
		default:
			flag = 0;
			std::cout << "Nothing Here" << std::endl;
			break;
	}
	if (flag){
		//Add enemy starting location and player starting location
		board[0][BOARDSIZE/2] = ENEMY;
		if (BOARDSIZE % 2 == 0){
			board[BOARDSIZE-1][BOARDSIZE/2 - 1] = PLAYER;
			playerLocation = new Point(BOARDSIZE/2 - 1,BOARDSIZE - 1);
		} else {
			board[BOARDSIZE-1][BOARDSIZE/2] = PLAYER;
			playerLocation = new Point(BOARDSIZE/2,BOARDSIZE - 1);
		}
	}
}

void Stage::setPlayer(int monNum)
{
	delete player;	
	player = new Monster(*monList[monNum-1]);
}

void Stage::setEnemy(int monNum)
{
	delete enemy;
	enemy = new Monster(*monList[monNum-1]);
}

void Stage::printStage()
{
	int x = 0, y = 0;

	for(; y < BOARDSIZE; y++){
		for(x = 0;x < BOARDSIZE; x++){
			if (x == (BOARDSIZE - 1)){
				std::cout << board[y][x] << std::endl;
			} else {
				std::cout << board[y][x] << " ";
			}
		}
	}
}

void Stage::printPlayerLocation()
{
	std::cout << "Player is at:\n";
	playerLocation->printPoint();
}

void Stage::printEnemyLocation()
{
	std::cout << "Enemy is at:\n";
	enemyLocation->printPoint();
}

//Check to see if player/enemy can move in said direction
int Stage::playerCanMove(int direction)
{
	int flag;
	switch(direction){
		case LEFT:
			if(playerLocation->getX() == 0){
				flag = OFFEND;
			} else if (COMPARE((board[playerLocation->getY()][playerLocation->getX() - 1]),OBSTACLE)){
				flag = CRASH;
			} else {
				flag = 1;
			}
			break;
		case RIGHT:
			if(playerLocation->getX() == BOARDSIZE - 1){
				flag = OFFEND;
			} else if (COMPARE((board[playerLocation->getY()][playerLocation->getX() + 1]),OBSTACLE)){
				flag = CRASH;
			} else {
				flag = 1;
			}
			break;
		case UP:
			if(playerLocation->getY() == 0){
				flag = OFFEND;
			} else if (COMPARE((board[playerLocation->getY() - 1][playerLocation->getX()]),OBSTACLE)){
				flag = CRASH;
			} else {
				flag = 1;
			}
			break;
		case DOWN:
			if(playerLocation->getY() == BOARDSIZE - 1){
				flag = OFFEND;
			} else if (COMPARE((board[playerLocation->getY() + 1][playerLocation->getX()]),OBSTACLE)){
				flag = CRASH;
			} else {
				flag = 1;
			}
			break;
		default:
			std::cout << "Wrong direction.";
			flag = 0;
			break;
	}
	return flag;
}

int Stage::enemyCanMove(int direction)
{
	int flag;
	switch(direction){
		case LEFT:
			if(enemyLocation->getX() == 0){
				flag = OFFEND;
			} else if (COMPARE((board[enemyLocation->getY()][enemyLocation->getX() - 1]),OBSTACLE)){
				flag = CRASH;
			} else {
				flag = 1;
			}
			break;
		case RIGHT:
			if(enemyLocation->getX() == BOARDSIZE - 1){
				flag = OFFEND;
			} else if (COMPARE((board[enemyLocation->getY()][enemyLocation->getX() + 1]),OBSTACLE)){
				flag = CRASH;
			} else {
				flag = 1;
			}
			break;
		case UP:
			if(enemyLocation->getY() == 0){
				flag = OFFEND;
			} else if (COMPARE((board[enemyLocation->getY() - 1][enemyLocation->getX()]),OBSTACLE)){
				flag = CRASH;
			} else {
				flag = 1;
			}
			break;
		case DOWN:
			if(enemyLocation->getY() == BOARDSIZE - 1){
				flag = OFFEND;
			} else if (COMPARE((board[enemyLocation->getY() + 1][enemyLocation->getX()]),OBSTACLE)){
				flag = CRASH;
			} else {
				flag = 1;
			}
			break;
		default:
			std::cout << "Wrong direction.";
			flag = 0;
			break;
	}
	return flag;
}

//Void return functions to move the player and enemy 1 tile
//Player movement
int Stage::movePlayerLeft()
{
	int flag;
	if(playerCanMove(LEFT) == 1){
		board[playerLocation->getY()][playerLocation->getX()] = FIELD;
		board[playerLocation->getY()][playerLocation->getX() - 1] = PLAYER;
		playerLocation->minusX();
		flag = 1;
	} else {
		flag = 0;
	}
	return flag;
}
int Stage::movePlayerRight()
{
	int flag;
	if(playerCanMove(RIGHT) == 1){
		board[playerLocation->getY()][playerLocation->getX()] = FIELD;
		board[playerLocation->getY()][playerLocation->getX() + 1] = PLAYER;
		playerLocation->plusX();
		flag = 1;
	} else {
		flag = 0;
	}
	return flag;
}
int Stage::movePlayerUp()
{
	int flag;
	if(playerCanMove(UP) == 1){
		board[playerLocation->getY()][playerLocation->getX()] = FIELD;
		board[playerLocation->getY() - 1][playerLocation->getX()] = PLAYER;
		playerLocation->minusY();
		flag = 1;
	} else {
		flag = 0;
	}
	return flag;
}
int Stage::movePlayerDown()
{
	int flag;
	if(playerCanMove(DOWN) == 1){
		board[playerLocation->getY()][playerLocation->getX()] = FIELD;
		board[playerLocation->getY() + 1][playerLocation->getX()] = PLAYER;
		playerLocation->plusY();
		flag = 1;
	} else {
		flag = 0;
	}
	return flag;
}

//Enemy movement
int Stage::moveEnemyLeft()
{
	int flag;
	if(enemyCanMove(LEFT) == 1){
		board[enemyLocation->getY()][enemyLocation->getX()] = FIELD;
		board[enemyLocation->getY()][enemyLocation->getX() - 1] = ENEMY;
		enemyLocation->minusX();
		flag = 1;
	} else {
		flag = 0;
	}
	return flag;
}
int Stage::moveEnemyRight()
{
	int flag;
	if(enemyCanMove(RIGHT) == 1){
		board[enemyLocation->getY()][enemyLocation->getX()] = FIELD;
		board[enemyLocation->getY()][enemyLocation->getX() + 1] = ENEMY;
		enemyLocation->plusX();
		flag = 1;
	} else {
		flag = 0;
	}
	return flag;
}
int Stage::moveEnemyUp()
{
	int flag;
	if(enemyCanMove(UP) == 1){
		board[enemyLocation->getY()][enemyLocation->getX()] = FIELD;
		board[enemyLocation->getY() - 1][enemyLocation->getX()] = ENEMY;
		enemyLocation->minusY();
		flag = 1;
	} else {
		flag = 0;
	}
	return flag;
}
int Stage::moveEnemyDown()
{
	int flag;
	if(enemyCanMove(DOWN) == 1){
		board[enemyLocation->getY()][enemyLocation->getX()] = FIELD;
		board[enemyLocation->getY() + 1][enemyLocation->getX()] = ENEMY;
		enemyLocation->plusY();
		flag = 1;
	} else {
		flag = 0;
	}
	return flag;
}

void Stage::printPlayer()
{
	std::cout << "Player:" << std::endl;
	player->printStats();
	std::cout << "With location at:" << std::endl;
	playerLocation->printPoint();
}

void Stage::printEnemy()
{
	std::cout << "Enemy:" << std::endl;
	enemy->printStats();
	std::cout << "With location at:" << std::endl;
	enemyLocation->printPoint();
}

void Stage::printObjects()
{
	int i = 0;
	for(;i< OBSTACLENUMBER; i++){
		std::cout << (i+1) << " :\n";
		objectList[i]->printObject();
		std::cout << "\n";
	}
}

void Stage::clearStage()
{
	uninitialize();
	int i = 0;
	name = "";
	description = "";
	for(;i< OBSTACLENUMBER; i++){
		objectList[i]->deleteObject();
		delete objectList[i];
	}
	delete player;
	delete enemy;
	delete playerLocation;
	delete enemyLocation;
}

void Stage::printList(){
	int i = 0;
	for(;i < MONSTERSIZE; i++){
		std::cout << (i+1) << ": ";
		printMonAt(i);
		std::cout << std::endl;
	}
}

void Stage::printStageName(){
	std::cout << name << std::endl;
	std::cout << description << std::endl;
}