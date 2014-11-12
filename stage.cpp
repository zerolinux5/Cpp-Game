#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "stage.h"
#include "object.h"

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

void Stage::relocate(int x, int y){
	int location = clasify(x, y);

	switch(location){
		case CornerLeftT:
			std::cout << "case CornerLeftT" << std::endl;
			break;
		case Top:
			std::cout << "case Top" << std::endl;
			break;
		case CornerRightT:
			std::cout << "case CornerRightT" << std::endl;
			break;
		case Left:
			std::cout << "case Left" << std::endl;
			break;
		case Middle:
			std::cout << "case Middle" << std::endl;
			break;
		case Right:
			std::cout << "case Right" << std::endl;
			break;
		case CornerLeftB:
			std::cout << "case CornerLeftB" << std::endl;
			break;
		case Bottom:
			std::cout << "case Bottom" << std::endl;
			break;
		case CornerRightB:
			std::cout << "case CornerRightB" << std::endl;
			break;
		default:
			std::cout << "Error" << std::endl;
			break;

	}
}

//Private helper function to add obstacles
void Stage::addObstacles(std::string obstacleName, unsigned int seed){
	int i = 0, randX, randY, segment;
	srand (seed);
	for(; i < OBSTACLENUMBER; i++){
		randX = rand() % BOARDSIZE;
		randY = rand() % BOARDSIZE;
		relocate(randX, randY);
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
					board[i][j] = "Grass";
					//std::cout << "G ";
				}
				//std::cout << std::endl;
			}
			addObstacles("Tree",seed);
			break;
		case 2:
			for(;i < BOARDSIZE; i++){
				for(j = 0;j < BOARDSIZE; j++){
					board[i][j] = "Desert";
					//std::cout << "D ";
				}
				//std::cout << std::endl;
			}
			addObstacles("Mound",seed);
			break;
		case 3:
			for(;i < BOARDSIZE; i++){
				for(j = 0;j < BOARDSIZE; j++){
					board[i][j] = "Concrete";
					//std::cout << "W ";
				}
				//std::cout << std::endl;
			}
			addObstacles("Wall",seed);
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