#include <iostream>
#include <string>
#include "monster.h"

#include <stdlib.h>
#include <time.h>
#include "point.h"
#include "attack.h"
#include "object.h"
#include "stage.h"

using namespace std;

int main()
{
	//For random seed to pass in to stage
	srand (time(NULL));

	/*Point testPoint (5, 10);
	testPoint.printPoint();
	cout << endl;*/

	//Attack stats Damage, Range, SP Cost, Name, Description
	Attack slash (10, 1, 0, "Slash", "Slashes forward");
	Attack kunai (10, 3, 5, "Kunai", "Throws kunai at target");
	Attack shadowStrike (25, 2, 7, "Shadow Strike", "Slashes target with kunai");
	Attack holydagger (30, 1, 10, "Holy Dagger", "Strkes target with holy light");
	Attack holyShield (50, 1, 20, "Holy Shield", "Shield bashes the target");
	//kunai.printAtk();
	//cout << endl;
	//holydagger.printAtk();
	//cout << endl;

	//Monster stats HP, SP, Atk, Def, Element
	Monster Racoonja (10, 8, 5, 3, "Darkness", "Racoonja", &slash, &kunai, &shadowStrike);
	Racoonja.printStats();

	cout << endl;

	//Monster stats HP, SP, Atk, Def, Element
	Monster Ninjacoon (15, 8, 4, 4, "Light", "Ninjacoon", &slash, &holydagger, &holyShield);
	Ninjacoon.printStats();

	cout << endl;

	//Object stats HP, DEF, Name
	Object tree (100, 2, "Tree");
	tree.printObject();

	cout << endl;
	//Set the stage using 3 different values and a default to grab edge cases
	Stage s1 ("Grassland", "This is the basic stage", 1, (rand() % 1000));

	//cout << "\nShould be either Grass or Tree: " << s1.getBoardLocation(1,1) << endl;
	//cout << "Should be Null: " << s1.getBoardLocation(100,100) << endl << endl;

	s1.printStage();

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

	/*cout << endl;
	//Set the stage using 3 different values and a default to grab edge cases
	Stage s2 ("Desert", "This stage has nothing...", 2, (rand() % 1000));
	s2.printStage();

	cout << endl;
	//Set the stage using 3 different values and a default to grab edge cases
	Stage s3 ("Stadium", "This stage has nothing...", 3, (rand() % 1000));
	s3.printStage();*/



	return 0;
}
