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

	cout << endl;
	s1.movePlayerLeft();
	s1.moveEnemyRight();
	s1.printPlayerLocation();
	s1.printEnemyLocation();

	s1.movePlayerRight();
	s1.moveEnemyLeft();
	s1.printPlayerLocation();
	s1.printEnemyLocation();

	s1.movePlayerUp();
	s1.moveEnemyDown();
	s1.printPlayerLocation();
	s1.printEnemyLocation();

	s1.movePlayerDown();
	s1.moveEnemyUp();
	s1.printPlayerLocation();
	s1.printEnemyLocation();

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
