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
	Monster();
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

Monster::Monster(){
	srand (time(NULL));
	index = 1;
	hp = (rand() % 4 + 3)*10;
	atk = rand() % 2 + 1;
	def = rand() % 2;
}

void Monster::damaged(int damageTaken){
	hp -= damageTaken;
}
