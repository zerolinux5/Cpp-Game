#include <iostream>
#include <string>
#include "monster.h"

Monster::Monster(int newHp, int newSp, int newAtk, int newDef, std::string newElement, std::string newName)
{
	hp = newHp;
	sp = newSp;
	atk = newAtk;
	def = newDef;
	element = newElement;
	name = newName;
}

void Monster::printStats(){
	std::cout << "Name:" << name << std::endl;
	std::cout << "Hp:" << hp << std::endl;
	std::cout << "Sp:" << sp << std::endl;
	std::cout << "Atk:" << atk << std::endl;
	std::cout << "Def:" << def << std::endl;
	std::cout << "Element:" << element << std::endl;
}
