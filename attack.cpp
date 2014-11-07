#include "attack.h"

Attack::Attack(int newDamage, std::string newName, std::string newDescription)
{
	damage = newDamage;
	name = newName;
	description = newDescription;
}

void Attack::printAtk()
{
	std::cout << name << ": " << description << " Base Power:" << damage << std::endl;
}
