#include <iostream>
#include <string>

#include "stage.h"

#define MAXSTAGES 3

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

	return 0;
}