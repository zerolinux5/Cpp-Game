#include <iostream>
#include <string>
#include "monster.h"

Monster::Monster(int newHp, int newSp, int newAtk, int newDef, std::string newElement, std::string newName, Attack baseHit, Attack newSpHit1, Attack newSpHit2)
{
	hp = newHp;
	sp = newSp;
	atk = newAtk;
	def = newDef;
	element = newElement;
	name = newName;
	basicHit = new Attack(baseHit);
	spHit1 = new Attack(newSpHit1);
	spHit2 = new Attack(newSpHit2);
}

void Monster::printStats(){
	std::cout << "Name:" << name << std::endl;
	std::cout << "Hp:" << hp << std::endl;
	std::cout << "Sp:" << sp << std::endl;
	std::cout << "Atk:" << atk << std::endl;
	std::cout << "Def:" << def << std::endl;
	std::cout << "Element:" << element << std::endl;
	std::cout << "Base Attack:";
	basicHit->printAtk();
	std::cout << "\nFirst Special Attack:";
	spHit1->printAtk();
	std::cout << "\nSecond Special Attack:";
	spHit2->printAtk();
}

void Monster::deleteAttacks(){
	delete basicHit;
	delete spHit1;
	delete spHit2;
}