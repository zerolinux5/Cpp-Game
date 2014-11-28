#include <vector>
#include <string>
#include "monster.h"

const int MONSTERSIZE = 2;

void initialize(){
	std::vector<Monster*> monList(MONSTERSIZE);

	//Attack stats Damage, Range, SP Cost, Name, Description
	Attack slash (10, 1, 0, "Slash", "Slashes forward");
	Attack kunai (10, 3, 5, "Kunai", "Throws kunai at target");
	Attack shadowStrike (25, 2, 7, "Shadow Strike", "Slashes target with kunai");
	Attack holydagger (30, 1, 10, "Holy Dagger", "Strkes target with holy light");
	Attack holyShield (50, 1, 20, "Holy Shield", "Shield bashes the target");
	//kunai.printAtk();
	//cout << endl;
	//holydagger.printAtk();
	//cout << endl;

	//Monster stats HP, SP, Atk, Def, Element
	Monster Racoonja (10, 8, 5, 3, "Darkness", "Racoonja", &slash, &kunai, &shadowStrike);

	//Monster stats HP, SP, Atk, Def, Element
	Monster Ninjacoon (15, 8, 4, 4, "Light", "Ninjacoon", &slash, &holydagger, &holyShield);

	monList[0] = &Racoonja;
	monList[1] = &Ninjacoon;
}

void uninitialize(){

}