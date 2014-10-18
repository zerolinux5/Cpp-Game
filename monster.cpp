#include <math.h>
#include <stdlib.h>
#include <time.h>

class Monster {
	int index;
	int hp;
	int atk;
	int def;
   public:
	Monster(int, int, int, int);
	Monster(unsigned int);
	int getIndex(){return index;}
	int getHp(){return hp;}
	int getAtk(){return atk;}
	int getDef(){return def;}
	void damaged(int);
};

Monster::Monster(int inIndex, int inHp, int inAtk, int inDef){
	index = inIndex;
	hp = inHp;
	atk = inAtk;
	def = inDef;
}

Monster::Monster(unsigned int seed){
	srand (seed);
	index = 1;
	hp = (rand() % 4 + 5);
	atk = rand() % 7 + 1;
	def = rand() % 2;
}

void Monster::damaged(int damageTaken){
	if(damageTaken <= 0){
	} else {
		hp -= damageTaken;
	}
}
