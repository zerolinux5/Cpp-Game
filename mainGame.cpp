#include <iostream>
#include <string>
#include "monster.h"
#include "attack.h"
#include "object.h"

using namespace std;

int main()
{
	//Monster stats HP, SP, Atk, Def, Element
	Monster m1 (10, 8, 5, 3, "Darkness");
	m1.printStats();

	cout << endl;

	//Attack stats Damage, name, description
	Attack firestorm (30, "Firestorm", "Causes fire to surround the target");
	firestorm.printAtk();

	cout << endl;
	
	//Object stats HP, DEF, Name
	Object tree (100, 2, "Tree");
	tree.printObject();

	return 0;
}
