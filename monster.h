#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "attack.h"

const int ATTACKNUMBER = 3;

class Monster{
	int hp;
	int sp;
	int atk;
	int def;
	std::string element;
	std::string name;
   public:
	Monster(int, int, int, int, std::string, std::string);
	int getHp() {return hp;}
	int getSp() {return sp;}
	int getDef() {return def;}
	int getAtk() {return atk;}
	std::string getElement() {return element;}
	std::string getName() {return name;}
	void printStats();
};

#endif