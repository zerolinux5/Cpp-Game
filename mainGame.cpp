#include <iostream>
#include <string>
#include "monster.h"

using namespace std;

int main()
{
	//Monster stats HP, SP, Atk, Def, Element
	Monster m1 (10,8, 5, 3, "Darkness");
	m1.printStats();

	return 0;
}
