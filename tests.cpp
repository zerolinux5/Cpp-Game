#include <iostream>
#include <string>
#include <stdlib.h>
#include "point.h"
#include "attack.h"
#include "object.h"
#include "stage.h"

using namespace std;

int main()
{
	//int i = 0;
	//For random seed to pass in to stage
	//srand (time(NULL));

	//Test monsterList.h
	/*for(i = 0; i < MONSTERSIZE; i++){
		printMonAt(i);
		cout << endl;
	}
	cout << endl;*/

	//Set the stage and set Racoonja and Ninjacoon
	Stage s1 ("Grassland", "This is the basic stage", 1);

	s1.printStage();

	cout << endl;

	//Print monsters on field
	s1.printPlayer();
	s1.printEnemy();

/*	cout << "\nShould be either Grass or Tree: " << s1.getBoardLocation(1,1) << endl;
	cout << "Should be Null: " << s1.getBoardLocation(100,100) << endl << endl;

	s1.printObjects();
	cout << endl;

	s1.printPlayerLocation();
	s1.printEnemyLocation();

	//Test movement to see if it can move in that direction
	cout << "---Player---" << endl;
	cout << "Left:" << s1.playerCanMove(LEFT) << endl;
	cout << "Right:" << s1.playerCanMove(RIGHT) << endl;
	cout << "Up:" << s1.playerCanMove(UP) << endl;
	cout << "Down:" << s1.playerCanMove(DOWN) << endl;

	cout << "---Enemy---" << endl;
	cout << "Left:" << s1.enemyCanMove(LEFT) << endl;
	cout << "Right:" << s1.enemyCanMove(RIGHT) << endl;
	cout << "Up:" << s1.enemyCanMove(UP) << endl;
	cout << "Down:" << s1.enemyCanMove(DOWN) << endl;

	//Testing movement through the board
	cout << endl;
	if(s1.movePlayerLeft()){
		cout << "Player Left" << endl;
	}
	if (s1.moveEnemyRight()){
		cout << "Enemy Right" << endl;
	}

	if (s1.movePlayerRight()){
		cout << "Player Right" << endl;
	}
	if (s1.moveEnemyLeft()){
		cout << "Enemy Left" << endl;
	}

	if(s1.movePlayerUp()){
		cout << "Player Up" << endl;
	}
	if(s1.moveEnemyDown()){
		cout << "Enemy Down" << endl;
	}

	if(s1.movePlayerDown()){
		cout << "Player Down" << endl;
	}
	if(s1.moveEnemyUp()){
		cout << "Enemy Up" << endl;
	}

	cout << endl;
	cout << "Number of objects on field:" << s1.getObjectCount() << endl;
	s1.clearStage();*/


	return 0;
}
