#include <iostream>
#include <string>
#include "attack.h"

Attack::Attack(int newDamage, int newRange, std::string newName, std::string newDescription)
{
	damage = newDamage;
	range = newRange;
	name = newName;
	description = newDescription;
}



void Attack::printAtk()
{
	std::cout << name << "\nBase Power:" << damage << "\nRange:" << range << " \n\t" << description << std::endl;
}
