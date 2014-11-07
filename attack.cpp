#include <iostream>
#include <string>
#include "attack.h"

Attack::Attack(int newDamage, std::string newName, std::string newDescription)
{
	damage = newDamage;
	name = newName;
	description = newDescription;
}

void Attack::printAtk()
{
	std::cout << name << "\nBase Power:" << damage << ": \n\t" << description << std::endl;
}
