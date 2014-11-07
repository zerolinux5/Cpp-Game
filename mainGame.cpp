#include <iostream>
#include <string>
#include "monster.h"
#include "attack.h"

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

	return 0;
}
