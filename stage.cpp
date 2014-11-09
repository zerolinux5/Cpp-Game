#include <iostream>
#include <string>
#include "stage.h"

Stage::Stage(std::string newName, std::string newDescription)
{
	name = newName;
	description = newDescription;
}

void Stage::printStage()
{
	int x = 0, y = 0;

	for(; y < BOARDSIZE; y++){
		for(;x < BOARDSIZE; x++){
			if (x == BOARDSIZE - 1){
				std::cout << board[y][x] << std::endl;
			} else {
				std::cout << board[y][x] << " ";
			}
		}
	}
}