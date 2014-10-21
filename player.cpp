#include <math.h>
#include <stdlib.h>
#include <time.h>

class Player {
	int index;
	int hp;
	int atk;
	int def;
	int experience;
	int level;
   public:
	Player (int, int, int, int, int);
	Player(unsigned int);
	void dead();
	int getIndex(){return index;}
	int getHp() {return hp;}
	int getAtk() {return atk;}
	int getDef() {return def;}
	int getExperience() {return experience;}
	void damaged(int);
	void addExperience(int);
};

Player::Player (int inIndex, int inHp, int inAtk, int inDef, int inExperience){
	index = inIndex;
	hp = inHp;
	atk = inAtk;
	def = inDef;
	experience = inExperience;
}

Player::Player(unsigned int seed){
	srand (seed);

	index = 1;
	level = 1;
	experience = 0;
	hp = (rand() % 4 + 7) + (5*level);
	atk = rand() % 5 + 1 + (1.5*level);
	def = rand() % 3 + 1 + (1*level);
}

void Player::dead(){
	index = 0;
	level = 0;
	experience = 0;
	hp = 0;
	atk = 0;
	def = 0;
}

void Player::damaged(int damageTaken){
	if(damageTaken <=0){
	} else {
		hp -= damageTaken;
	}
}

void Player::addExperience(int newExperience){
	experience += newExperience;
	if(experience >= 100){
		experience %= 100;
		level++;
	}
}
