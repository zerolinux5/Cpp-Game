#include <vector>
#include <string>
#include "monster.h"

const int MONSTERSIZE = 6;
int initialized = 0;
std::vector<Monster*> monList(MONSTERSIZE);

int isInitialized(){
	return initialized;
}

void initialize(){
	if(!initialized){
		initialized = 1;
		//Attack stats Damage, Range, SP Cost, Name, Description
		Attack slash (10, 1, 0, "Slash", "Slashes forward");
		Attack bite (13, 1, 0, "Bite", "Bite the target");

		Attack kunai (10, 3, 3, "Kunai", "Throws kunai at target");
		Attack shadowStrike (25, 2, 7, "Shadow Strike", "Slashes target with kunai");
		Attack holydagger (30, 1, 10, "Holy Dagger", "Strkes target with holy light");
		Attack holyShield (50, 1, 20, "Holy Shield", "Shield bashes the target");
		Attack blazingFlames (100, 3, 40, "Blazing Flames", "Erupt the ground in lava");
		Attack firestorm (80, 5, 30, "Fire Storm", "Summon fire from the skies");
		Attack icestorm (70, 7, 25, "Ice Storm", "Summon a blizzard towards the enemy");
		Attack freeze(40, 3, 15, "Freeze", "Send an icy wind to freeze the target");
		Attack assassinate (150, 1, 70, "Assassinate", "Use all one's energy to finish off the target");
		Attack darkslash (100, 2, 30, "Dark Slash", "Strike the enemy with a darkness augmented kunai");
		//kunai.printAtk();
		//cout << endl;
		//holydagger.printAtk();
		//cout << endl;

		Monster* Racoonja = new Monster(10, 30, 5, 3, "Darkness", "Racoonja", slash, kunai, shadowStrike);
		Monster* Ninjacoon = new Monster(15, 50, 4, 4, "Light", "Ninjacoon", slash, holydagger, holyShield);
		Monster* Flamecoon = new Monster(30,100, 30, 25, "Fire", "Flamecoon", bite, blazingFlames, firestorm);
		Monster* Icecoon = new Monster(40, 100, 25, 20, "Ice", "Icecoon", bite, freeze, icestorm);
		Monster* Dracocoon = new Monster(100, 150, 75, 50, "Dragon", "Dracocoon", slash, blazingFlames, icestorm);
		Monster* Necrocoon = new Monster(100, 150, 90, 20, "Darkness", "Necrocoon", slash, darkslash, assassinate);

		monList[0] = Racoonja;
		monList[1] = Ninjacoon;
		monList[2] = Flamecoon;
		monList[3] = Icecoon;
		monList[4] = Dracocoon;
		monList[5] = Necrocoon;
	}
}

void uninitialize(){
	int i = 0;
	if(initialized){
		for(;i < MONSTERSIZE;i++){
			monList[i]->deleteAttacks();
			delete monList[i];
		}
		initialized = 0;
	}
}

Monster getMonAt(int location){
	return *monList[location];
}

void printMonAt(int location){
	monList[location]->printStats();
}