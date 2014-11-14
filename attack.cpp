#include <iostream>
#include <string>
#include "attack.h"

Attack::Attack(int newDamage, int newRange, int newCost, std::string newName, std::string newDescription)
{
	damage = newDamage;
	range = newRange;
	name = newName;
	cost = newCost;
	description = newDescription;
}



void Attack::printAtk()
{
	std::cout << name << "\nBase Power:" << damage << "\nRange:" << range << "\nCost:" << cost << "\n\t" << description << std::endl;
}
