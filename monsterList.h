#include <vector>
#include <string>
#include "monster.h"

const int MONSTERSIZE = 2;
std::vector<Monster*> monList(MONSTERSIZE);

void initialize(){
	

	//Attack stats Damage, Range, SP Cost, Name, Description
	Attack slash (10, 1, 0, "Slash", "Slashes forward");
	Attack bite  (13, 1, 1, "Bite", "Bite the target");

	Attack kunai (10, 3, 3, "Kunai", "Throws kunai at target");
	Attack shadowStrike (25, 2, 7, "Shadow Strike", "Slashes target with kunai");
	Attack holydagger (30, 1, 10, "Holy Dagger", "Strkes target with holy light");
	Attack holyShield (50, 1, 20, "Holy Shield", "Shield bashes the target");
	Attack blazingFlames (100, 3, 40, "Blazing Flames", "Erupt the ground in lava");
	Attack firestorm (80, 5, 30, "Fire Storm", "Summon fire from the skies");
	//kunai.printAtk();
	//cout << endl;
	//holydagger.printAtk();
	//cout << endl;

	//Monster stats HP, SP, Atk, Def, Element
	Monster Racoonja (10, 30, 5, 3, "Darkness", "Racoonja", &slash, &kunai, &shadowStrike);

	//Monster stats HP, SP, Atk, Def, Element
	Monster Ninjacoon (15, 50, 4, 4, "Light", "Ninjacoon", &slash, &holydagger, &holyShield);

	Monster Flamecoon (30,100, 30, 25, "Fire", "Flamecoon", &bite, &blazingFlames, &firestorm);

	monList[0] = &Racoonja;
	monList[1] = &Ninjacoon;
	monList[2] = &Flamecoon;
}

Monster getMonAt(int location){
	return *monList[location];
}

void printMonAt(int location){
	monList[location]->printStats();
}