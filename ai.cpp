#include <string>
#include <stdlib.h> 
#include "stage.h"

//Move the enemy based on algorithm
void Stage::moveEnemy(){
	//Get local copies of the locations in case of interrupt in future code
	Point *localLocation = enemyLocation;
	Point *localPlayer = playerLocation;

	//Check whether bigger difference in x or y
	int xDiff = abs(enemyLocation->getX() - playerLocation->getX());
	int yDiff = abs(enemyLocation->getY() - playerLocation->getY());

	//First check if can hit player

	//Algorithm will pick the difference that is bigger
	if(xDiff > yDiff){

	} else if(yDiff > xDiff){

	} else {

	}
}