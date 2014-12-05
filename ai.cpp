#include <string>
#include <stdlib.h> 
#include "stage.h"
//0-1
enum Strategy{Offense, Defense}; 

//Move the enemy based on algorithm this is based off of 2 move per turn rule
void Stage::moveEnemy(){
	//Get local copies of the locations in case of interrupt in future code
	Point *localLocation = enemyLocation;
	Point *localPlayer = playerLocation;

	//Check whether bigger difference in x or y
	int xDiff = abs(enemyLocation->getX() - playerLocation->getX());
	int yDiff = abs(enemyLocation->getY() - playerLocation->getY());

	//Have 2 cases whether offensive or defensive depending on the health of the monster
	if(enemy->getHp() <= (enemy->getTotalHp()/2)){

	} else {

	}

	//Algorithm will pick the difference that is bigger
	if(xDiff > yDiff){

	} else if(yDiff > xDiff){

	} else {

	}
}