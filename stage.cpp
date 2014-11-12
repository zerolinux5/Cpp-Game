#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "stage.h"
#include "object.h"


//Private helper function to add obstacles
void Stage::addObstacles(std::string obstacleName){
	int i = 0, randX, randY;
	srand (time(NULL));
	for(; i < OBSTACLENUMBER; i++){
		randX = rand() % BOARDSIZE;
		randY = rand() % BOARDSIZE;
		board[randY][randX] = obstacleName;
	}
}

Stage::Stage(std::string newName, std::string newDescription, int stageNum)
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
			addObstacles("Tree");
			break;
		case 2:
			for(;i < BOARDSIZE; i++){
				for(j = 0;j < BOARDSIZE; j++){
					board[i][j] = "Desert";
					//std::cout << "D ";
				}
				//std::cout << std::endl;
			}
			addObstacles("Mound");
			break;
		case 3:
			for(;i < BOARDSIZE; i++){
				for(j = 0;j < BOARDSIZE; j++){
					board[i][j] = "Concrete";
					//std::cout << "W ";
				}
				//std::cout << std::endl;
			}
			addObstacles("Wall");
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