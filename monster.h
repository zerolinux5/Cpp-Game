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
	Attack* basicHit;
	Attack* spHit1;
	Attack* spHit2;
   public:
   	//Constructor and Deconstructor
	Monster(int, int, int, int, std::string, std::string, Attack, Attack, Attack);
	void deleteAttacks();

	//Getters
	int getHp() {return hp;}
	int getSp() {return sp;}
	int getDef() {return def;}
	int getAtk() {return atk;}
	std::string getElement() {return element;}
	std::string getName() {return name;}

	// Setters
	void damaged(int damage) {hp -= (damage - def);}
	void spUse(int amount) {sp -= amount;}

	//Print
	void printStats();
};

#endif