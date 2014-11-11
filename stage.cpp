#include <iostream>
#include <string>
#include "stage.h"

Stage::Stage(std::string newName, std::string newDescription, int stageNum)
{
	int i = 0, j = 0;
	name = newName;
	description = newDescription;
	stageSet = stageNum;

	switch(stageSet){
		case 1:
			for(;i < BOARDSIZE; i++){
				for(;j < BOARDSIZE; j++){
					board[i][j] = "G";
					std::cout << "G" << std::endl;
				}
			}
			break;
		case 2:
			for(;i < BOARDSIZE; i++){
				for(;j < BOARDSIZE; j++){
					board[i][j] = "D";
					std::cout << "D" << std::endl;
				}
			}
			break;
		case 3:
			for(;i < BOARDSIZE; i++){
				for(;j < BOARDSIZE; j++){
					board[i][j] = "W";
					std::cout << "W" << std::endl;
				}
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
		for(;x < BOARDSIZE; x++){
			if (x == (BOARDSIZE - 1)){
				std::cout << board[y][x] << std::endl;
			} else {
				std::cout << board[y][x] << " ";
			}
		}
	}
}