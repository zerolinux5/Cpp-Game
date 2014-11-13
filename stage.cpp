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

	switch(stageSet){
		case 1:
			for(;i < BOARDSIZE; i++){
				for(j = 0;j < BOARDSIZE; j++){
					board[i][j] = "_";
					//std::cout << "G ";
				}
				//std::cout << std::endl;
			}
			addObstacles("^",seed);

			//Add enemy starting location and player starting location
			board[0][BOARDSIZE/2] = "O";
			board[BOARDSIZE-1][BOARDSIZE/2] = "X";
			break;
		case 2:
			for(;i < BOARDSIZE; i++){
				for(j = 0;j < BOARDSIZE; j++){
					board[i][j] = "_";
					//std::cout << "D ";
				}
				//std::cout << std::endl;
			}
			addObstacles("^",seed);

			//Add enemy starting location and player starting location
			board[0][BOARDSIZE/2] = "O";
			board[BOARDSIZE-1][BOARDSIZE/2] = "X";
			break;
		case 3:
			for(;i < BOARDSIZE; i++){
				for(j = 0;j < BOARDSIZE; j++){
					board[i][j] = "_";
					//std::cout << "W ";
				}
				//std::cout << std::endl;
			}
			addObstacles("^",seed);
			break;
		default:
			std::cout << "Nothing Here" << std::endl;

			//Add enemy starting location and player starting location
			board[0][BOARDSIZE/2] = "O";
			board[BOARDSIZE-1][BOARDSIZE/2] = "X";
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