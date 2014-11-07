#include <iostream>
#include <string>
#include "monster.h"

using namespace std;

Monster::Monster(int newHp, int newSp, int newAtk, int newDef, string newElement)
{
	hp = newHp;
	sp = newSp;
	atk = newAtk;
	def = newDef;
	element = newElement;
}

void Monster::printStats(){
	cout << "Hp:" << hp << endl;
	cout << "Sp:" << sp << endl;
	cout << "Atk:" << atk << endl;
	cout << "Def:" << def << endl;
	cout << "Element:" << element << endl;
}
