#ifndef __ATTACK_H__
#define __ATTACK_H__

class Attack{
	int damage;
	int range;
	int cost;
	std::string name;
	std::string description;

   public:
   	//Constructor
	Attack(int, int, int, std::string, std::string);

	//Getters
	int getCost() {return cost;}
	int getDamage() {return damage;}
	int getRange() {return range;}
	std::string getName() {return name;}
	std::string getDescription() {return description;}

	//Print
	void printAtk();
};

#endif