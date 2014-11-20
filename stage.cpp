#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "stage.h"
#include "object.h"

#define BOARD (board[y][x])
#define XPLUS (board[y][x+1])
#define YLPUS (board[y+1][x])
#define XMINUS (board[y][x-1])
#define YMINUS (board[y-1][x])

#define OBSTACLE "^"
#define ENEMY "O"
#define PLAYER "X"

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

	if(obstacleName.compare(BOARD) == 0){
		flag = 1;
	} else {
		switch(location){
			case CornerLeftT:
				//std::cout << "case CornerLeftT" << std::endl;
				if (obstacleName.compare(XPLUS) == 0){
					flag = 1;
				} else if (obstacleName.compare(YLPUS) == 0){
					flag = 1;
				}
				break;
			case Top:
				//std::cout << "case Top" << std::endl;
				if (obstacleName.compare(XPLUS) == 0){
					flag = 1;
				} else if (obstacleName.compare(YLPUS) == 0){
					flag = 1;
				} else if (obstacleName.compare(XMINUS) == 0){
					flag = 1;
				}
				break;
			case CornerRightT:
				//std::cout << "case CornerRightT" << std::endl;
				if (obstacleName.compare(XMINUS) == 0){
					flag = 1;
				} else if (obstacleName.compare(YLPUS) == 0){
					flag = 1;
				}
				break;
			case Left:
				//std::cout << "case Left" << std::endl;
				if (obstacleName.compare(XPLUS) == 0){
					flag = 1;
				} else if (obstacleName.compare(YLPUS) == 0){
					flag = 1;
				} else if (obstacleName.compare(YMINUS) == 0){
					flag = 1;
				}
				break;
			case Middle:
				//std::cout << "case Middle" << std::endl;
				if (obstacleName.compare(XPLUS) == 0){
					flag = 1;
				} else if (obstacleName.compare(YLPUS) == 0){
					flag = 1;
				} else if (obstacleName.compare(XMINUS) == 0){
					flag = 1;
				} else if (obstacleName.compare(YMINUS) == 0){
					flag = 1;
				}
				break;
			case Right:
				//std::cout << "case Right" << std::endl;
				if (obstacleName.compare(XMINUS) == 0){
					flag = 1;
				} else if (obstacleName.compare(YLPUS) == 0){
					flag = 1;
				} else if (obstacleName.compare(YMINUS) == 0){
					flag = 1;
				}
				break;
			case CornerLeftB:
				//std::cout << "case CornerLeftB" << std::endl;
				if (obstacleName.compare(XPLUS) == 0){
					flag = 1;
				} else if (obstacleName.compare(YMINUS) == 0){
					flag = 1;
				}
				break;
			case Bottom:
				//std::cout << "case Bottom" << std::endl;
				if (obstacleName.compare(XPLUS) == 0){
					flag = 1;
				} else if (obstacleName.compare(XMINUS) == 0){
					flag = 1;
				} else if (obstacleName.compare(YMINUS) == 0){
					flag = 1;
				}
				break;
			case CornerRightB:
				//std::cout << "case CornerRightB" << std::endl;
				if (obstacleName.compare(XMINUS) == 0){
					flag = 1;
				} else if (obstacleName.compare(YMINUS) == 0){
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
		board[randY][randX] = obstacleName;
	}
}

Stage::Stage(std::string newName, std::string newDescription, int stageNum, unsigned int seed)
{
	int i = 0, j = 0;
	name = newName;
	description = newDescription;
	stageSet = stageNum;
	enemyLocation = new Point(BOARDSIZE/2, 0);

	switch(stageSet){
		case 1:
			int flag;
			for(;i < BOARDSIZE; i++){
				for(j = 0;j < BOARDSIZE; j++){
					board[i][j] = "_";
					//std::cout << "G ";
				}
				//std::cout << std::endl;
			}
			addObstacles(OBSTACLE,seed);

			//Add enemy starting location and player starting location
			board[0][BOARDSIZE/2] = ENEMY;
			if (BOARDSIZE % 2 == 0){
				board[BOARDSIZE-1][BOARDSIZE/2 - 1] = PLAYER;
				playerLocation = new Point(BOARDSIZE/2 - 1,BOARDSIZE - 1);
			} else {
				board[BOARDSIZE-1][BOARDSIZE/2] = PLAYER;
				playerLocation = new Point(BOARDSIZE/2,BOARDSIZE - 1);
			}
			break;
		case 2:
			for(;i < BOARDSIZE; i++){
				for(j = 0;j < BOARDSIZE; j++){
					board[i][j] = "_";
					//std::cout << "D ";
				}
				//std::cout << std::endl;
			}
			addObstacles(OBSTACLE,seed);

			//Add enemy starting location and player starting location
			board[0][BOARDSIZE/2] = ENEMY;
			if (BOARDSIZE % 2 == 0){
				board[BOARDSIZE-1][BOARDSIZE/2 - 1] = PLAYER;
				playerLocation = new Point(BOARDSIZE/2 - 1,BOARDSIZE - 1);
			} else {
				board[BOARDSIZE-1][BOARDSIZE/2] = PLAYER;
				playerLocation = new Point(BOARDSIZE/2,BOARDSIZE - 1);
			}
			break;
		case 3:
			for(;i < BOARDSIZE; i++){
				for(j = 0;j < BOARDSIZE; j++){
					board[i][j] = "_";
					//std::cout << "W ";
				}
				//std::cout << std::endl;
			}
			addObstacles(OBSTACLE,seed);

			//Add enemy starting location and player starting location
			board[0][BOARDSIZE/2] = ENEMY;
			if (BOARDSIZE % 2 == 0){
				board[BOARDSIZE-1][BOARDSIZE/2 - 1] = PLAYER;
				playerLocation = new Point(BOARDSIZE/2 - 1,BOARDSIZE - 1);
			} else {
				board[BOARDSIZE-1][BOARDSIZE/2] = PLAYER;
				playerLocation = new Point(BOARDSIZE/2,BOARDSIZE - 1);
			}
			break;
		default:
			std::cout << "Nothing Here" << std::endl;
			break;
	}
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
			} else if ((board[playerLocation->getY()][playerLocation->getX() - 1]).compare(OBSTACLE) == 0){
				flag = CRASH;
			} else {
				flag = 1;
			}
			break;
		case RIGHT:
			if(playerLocation->getX() == BOARDSIZE - 1){
				flag = OFFEND;
			} else if ((board[playerLocation->getY()][playerLocation->getX() + 1]).compare(OBSTACLE) == 0){
				flag = CRASH;
			} else {
				flag = 1;
			}
			break;
		case UP:
			if(playerLocation->getY() == 0){
				flag = OFFEND;
			} else if ((board[playerLocation->getY() - 1][playerLocation->getX()]).compare(OBSTACLE) == 0){
				flag = CRASH;
			} else {
				flag = 1;
			}
			break;
		case DOWN:
			if(playerLocation->getY() == BOARDSIZE - 1){
				flag = OFFEND;
			} else if ((board[playerLocation->getY() + 1][playerLocation->getX()]).compare(OBSTACLE) == 0){
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
			} else if ((board[enemyLocation->getY()][enemyLocation->getX() - 1]).compare(OBSTACLE) == 0){
				flag = CRASH;
			} else {
				flag = 1;
			}
			break;
		case RIGHT:
			if(enemyLocation->getX() == BOARDSIZE - 1){
				flag = OFFEND;
			} else if ((board[enemyLocation->getY()][enemyLocation->getX() + 1]).compare(OBSTACLE) == 0){
				flag = CRASH;
			} else {
				flag = 1;
			}
			break;
		case UP:
			if(enemyLocation->getY() == 0){
				flag = OFFEND;
			} else if ((board[enemyLocation->getY() - 1][enemyLocation->getX()]).compare(OBSTACLE) == 0){
				flag = CRASH;
			} else {
				flag = 1;
			}
			break;
		case DOWN:
			if(enemyLocation->getY() == BOARDSIZE - 1){
				flag = OFFEND;
			} else if ((board[enemyLocation->getY() + 1][enemyLocation->getX()]).compare(OBSTACLE) == 0){
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
void Stage::movePlayerLeft()
{
	if(playerCanMove(LEFT) == 1){
		board[playerLocation->getY()][playerLocation->getX()] = "_";
		board[playerLocation->getY()][playerLocation->getX() - 1] = PLAYER;
		playerLocation->minusX();
	} else {
		std::cout << "ERROR" << std::endl;
	}
}
void Stage::movePlayerRight()
{
	if(playerCanMove(RIGHT) == 1){
		board[playerLocation->getY()][playerLocation->getX()] = "_";
		board[playerLocation->getY()][playerLocation->getX() + 1] = PLAYER;
		playerLocation->plusX();
	} else {
		std::cout << "ERROR" << std::endl;
	}
}
void Stage::movePlayerUp()
{
	if(playerCanMove(UP) == 1){
		board[playerLocation->getY()][playerLocation->getX()] = "_";
		board[playerLocation->getY() - 1][playerLocation->getX()] = PLAYER;
		playerLocation->minusY();
	} else {
		std::cout << "ERROR" << std::endl;
	}
}
void Stage::movePlayerDown()
{
	if(playerCanMove(DOWN) == 1){
		board[playerLocation->getY()][playerLocation->getX()] = "_";
		board[playerLocation->getY() + 1][playerLocation->getX()] = PLAYER;
		playerLocation->plusY();
	} else {
		std::cout << "ERROR" << std::endl;
	}
}

//Enemy movement
void Stage::moveEnemyLeft()
{
	board[enemyLocation->getY()][enemyLocation->getX()] = "_";
	board[enemyLocation->getY()][enemyLocation->getX() - 1] = ENEMY;
	enemyLocation->minusX();
}
void Stage::moveEnemyRight()
{
	board[enemyLocation->getY()][enemyLocation->getX()] = "_";
	board[enemyLocation->getY()][enemyLocation->getX() + 1] = ENEMY;
	enemyLocation->plusX();
}
void Stage::moveEnemyUp()
{
	board[enemyLocation->getY()][enemyLocation->getX()] = "_";
	board[enemyLocation->getY() - 1][enemyLocation->getX()] = ENEMY;
	enemyLocation->minusY();
}
void Stage::moveEnemyDown()
{
	board[enemyLocation->getY()][enemyLocation->getX()] = "_";
	board[enemyLocation->getY() + 1][enemyLocation->getX()] = ENEMY;
	enemyLocation->plusY();
}