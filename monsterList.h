#include <vector>
#include <string>
#include "monster.h"

const int MONSTERSIZE = 3;
int initialized = 0;
std::vector<Monster*> monList(MONSTERSIZE);

int isInitialized(){
	return initialized;
}

void initialize(){
	if(!initialized){
		initialized = 1;
		//Attack stats Damage, Range, SP Cost, Name, Description
		Attack* slash = new Attack(10, 1, 0, "Slash", "Slashes forward");
		Attack* bite = new Attack(13, 1, 1, "Bite", "Bite the target");

		Attack* kunai = new Attack(10, 3, 3, "Kunai", "Throws kunai at target");
		Attack* shadowStrike = new Attack(25, 2, 7, "Shadow Strike", "Slashes target with kunai");
		Attack* holydagger = new Attack(30, 1, 10, "Holy Dagger", "Strkes target with holy light");
		Attack* holyShield = new Attack(50, 1, 20, "Holy Shield", "Shield bashes the target");
		Attack* blazingFlames = new Attack(100, 3, 40, "Blazing Flames", "Erupt the ground in lava");
		Attack* firestorm = new Attack(80, 5, 30, "Fire Storm", "Summon fire from the skies");
		//kunai.printAtk();
		//cout << endl;
		//holydagger.printAtk();
		//cout << endl;

		Monster* Racoonja = new Monster(10, 30, 5, 3, "Darkness", "Racoonja", slash, kunai, shadowStrike);
		Monster* Ninjacoon = new Monster(15, 50, 4, 4, "Light", "Ninjacoon", slash, holydagger, holyShield);
		Monster* Flamecoon = new Monster(30,100, 30, 25, "Fire", "Flamecoon", bite, blazingFlames, firestorm);

		monList[0] = Racoonja;
		monList[1] = Ninjacoon;
		monList[2] = Flamecoon;
	}
}

void uninitialize(){
	int i = 0;
	if(initialized){
		for(;i < MONSTERSIZE;i++){
			delete monList[i];
		}
	}
}

Monster getMonAt(int location){
	return *monList[location];
}

void printMonAt(int location){
	monList[location]->printStats();
}