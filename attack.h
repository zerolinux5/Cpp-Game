#ifndef __ATTACK_H__
#define __ATTACK_H__

class Attack{
	int damage;
	int range;
	std::string name;
	std::string description;
   public:
	Attack(int, int, std::string, std::string);
	int getDamage() {return damage;}
	int getRange() {return range;}
	std::string getName() {return name;}
	std::string getDescription() {return description;}
	void printAtk();
};

#endif
