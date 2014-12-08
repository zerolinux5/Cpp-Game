#include <iostream>
#include <string>

#include "stage.h"

#define MAXSTAGES 3
#define MONSTERLIST 6

using namespace std;

int main()
{
	int stage, player, enemy;
	Stage s1 ("Grassland", "Grass stage with trees", 1);
	Stage s2 ("Marshes", "Muddy land with swamps", 2);
	Stage s3 ("Mountains", "Mountain area with high peaks", 3);

	do{
		s1.printStageName();
		cout << endl;
		s2.printStageName();
		cout << endl;
		s3.printStageName();
		cout << endl;

		cout << "Enter which Stage:(1-3):";
		cin >> stage;
	} while (stage < 0 || stage > MAXSTAGES);

	switch(stage){
		case 1:
			do{
				s1.printList();
				cout << "\nEnter which monster you will use (1-" << MONSTERLIST << "): ";
				cin >> player;
			} while(player < 0 || player > MONSTERLIST);
			do{
				s1.printList();
				cout << "\nEnter which monster you will fight (1-" << MONSTERLIST << "): ";
				cin >> enemy;
			} while(enemy < 0 || enemy > MONSTERLIST);
			break;
		case 2:
			do{
				s2.printList();
				cout << "\nEnter which monster you will use (1-" << MONSTERLIST << "): ";
				cin >> player;
			} while(player < 0 || player > MONSTERLIST);
			do{
				s2.printList();
				cout << "\nEnter which monster you will fight (1-" << MONSTERLIST << "): ";
				cin >> enemy;
			} while(enemy < 0 || enemy > MONSTERLIST);
			break;
		case 3:
			do{
				s3.printList();
				cout << "\nEnter which monster you will use (1-" << MONSTERLIST << "): ";
				cin >> player;
			} while(player < 0 || player > MONSTERLIST);
			do{
				s3.printList();
				cout << "\nEnter which monster you will fight (1-" << MONSTERLIST << "): ";
				cin >> enemy;
			} while(enemy < 0 || enemy > MONSTERLIST);
			break;
		default:
			break;
	}

	return 0;
}