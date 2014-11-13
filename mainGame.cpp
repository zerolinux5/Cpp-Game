#include <iostream>
#include <string>
#include "monster.h"

#include <stdlib.h>
#include <time.h>
#include "attack.h"
#include "object.h"
#include "stage.h"

using namespace std;

int main()
{
	//For random seed to pass in to stage
	srand (time(NULL));

	//Monster stats HP, SP, Atk, Def, Element
	Monster m1 (10, 8, 5, 3, "Darkness", "Racoonja");
	m1.printStats();

	cout << endl;

	//Attack stats Damage, name, description
	Attack firestorm (30, "Firestorm", "Causes fire to surround the target");
	firestorm.printAtk();

	cout << endl;

	//Object stats HP, DEF, Name
	Object tree (100, 2, "Tree");
	tree.printObject();

	cout << endl;
	//Set the stage using 3 different values and a default to grab edge cases
	Stage s1 ("Grassland", "This stage has nothing...", 1, (rand() % 1000));

	cout << "\nShould be either Grass or Tree: " << s1.getBoardLocation(1,1) << endl;
	cout << "Should be Null: " << s1.getBoardLocation(100,100) << endl << endl;

	s1.printStage();

	cout << endl;
	//Set the stage using 3 different values and a default to grab edge cases
	Stage s2 ("Desert", "This stage has nothing...", 2, (rand() % 1000));
	s2.printStage();

	cout << endl;
	//Set the stage using 3 different values and a default to grab edge cases
	Stage s3 ("Stadium", "This stage has nothing...", 3, (rand() % 1000));
	s3.printStage();



	return 0;
}
