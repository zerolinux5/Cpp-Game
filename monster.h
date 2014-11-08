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
   public:
	Monster(int, int, int, int, std::string);
	int getHp() {return hp;}
	int getSp() {return sp;}
	int getDef() {return def;}
	int getAtk() {return atk;}
	std::string getElement() {return element;}
	void printStats();
};

#endif