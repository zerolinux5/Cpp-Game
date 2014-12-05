#include <iostream>
#include <string>
#include "monster.h"

Monster::Monster(int newHp, int newSp, int newAtk, int newDef, std::string newElement, std::string newName, Attack baseHit, Attack newSpHit1, Attack newSpHit2)
{
	hp = totalHp = newHp;
	sp = newSp;
	atk = newAtk;
	def = newDef;
	element = newElement;
	name = newName;

	//Add attacks and check max and min values
	basicHit = new Attack(baseHit);
	maxDamage = basicHit->getDamage();
	maxRange = basicHit->getRange();
	minSp = basicHit->getCost();
	spHit1 = new Attack(newSpHit1);
	if(spHit1->getDamage() > maxDamage){
		maxDamage = spHit1->getDamage();
	}
	if(spHit1->getRange() > maxRange){
		maxRange = spHit1->getRange();
	}
	if(spHit1->getCost() < minSp){
		minSp = spHit1->getCost();
	}
	spHit2 = new Attack(newSpHit2);
	if(spHit2->getDamage() > maxDamage){
		maxDamage = spHit2->getDamage();
	}
	if(spHit2->getRange() > maxRange){
		maxRange = spHit2->getRange();
	}
	if(spHit2->getCost() < minSp){
		minSp = spHit2->getCost();
	}
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