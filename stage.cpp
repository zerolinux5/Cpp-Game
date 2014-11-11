#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "stage.h"
#include "object.h"

Stage::Stage(std::string newName, std::string newDescription, int stageNum)
{
	int i = 0, j = 0, randX, randY;
	name = newName;
	description = newDescription;
	stageSet = stageNum;
	srand (time(NULL));

	switch(stageSet){
		case 1:
			for(;i < BOARDSIZE; i++){
				for(j = 0;j < BOARDSIZE; j++){
					board[i][j] = "Grass";
					//std::cout << "G ";
				}
				//std::cout << std::endl;
			}
			for(i = 0; i < OBSTACLENUMBER; i++){
				randX = rand() % BOARDSIZE;
				randY = rand() % BOARDSIZE;
				board[randY][randX] = "Tree";
			}
			break;
		case 2:
			for(;i < BOARDSIZE; i++){
				for(j = 0;j < BOARDSIZE; j++){
					board[i][j] = "Desert";
					//std::cout << "D ";
				}
				//std::cout << std::endl;
			}
			for(i = 0; i < OBSTACLENUMBER; i++){
				randX = rand() % BOARDSIZE;
				randY = rand() % BOARDSIZE;
				board[randY][randX] = "Mound";
			}
			break;
		case 3:
			for(;i < BOARDSIZE; i++){
				for(j = 0;j < BOARDSIZE; j++){
					board[i][j] = "Concrete";
					//std::cout << "W ";
				}
				//std::cout << std::endl;
			}
			for(i = 0; i < OBSTACLENUMBER; i++){
				randX = rand() % BOARDSIZE;
				randY = rand() % BOARDSIZE;
				board[randY][randX] = "Wall";
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