#include <iostream>
#include <string>

#include "stage.h"

using namespace std;

int main()
{
	int response;
	Stage s1 ("Grassland", "This is the basic stage", 1);

	s1.printList();
	cout << "Pick your character:";
	cin >> response;

	return 0;
}