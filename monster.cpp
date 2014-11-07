#include <iostream>
#include <string>

using namespace std;

class Monster{
	int hp;
	int sp;
	int atk;
	int def;
	string element;
   public:
	Monster(int, int, int, int, string);
	int getHp() {return hp;}
	int getSp() {return sp;}
	int getDef() {return def;}
	int getAtk() {return atk;}
	string getElement() {return element;}	
	void printStats();
};

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
