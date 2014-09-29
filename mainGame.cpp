#include <iostream>

using namespace std;

#include "Player.cpp"
#include "Monster.cpp"

int main()
{
	Player p1;
	Monster m1;

	cout << p1.getHp() << " " << m1.getHp() << endl;
	cout << "Main game" << endl;

	return 0;
}
