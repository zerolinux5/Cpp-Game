#include <iostream>
#include "Player.cpp"
#include "Monster.cpp"

using namespace std;

void battle(Player &p1, Monster &m1){
	int playerAtk = p1.getAtk() - m1.getDef();
	int monsterAtk = m1.getAtk() - p1.getDef();

	m1.damaged(playerAtk);
	p1.damaged(monsterAtk);

	cout << "Player Hp left:" << p1.getHp() << endl;
	cout << "Monster Hp left:" << m1.getHp() << endl;
}

int main()
{
	int win = 1;
	int index;
	char move;

	Player p1;
	Monster m1;

	cout << "Player Hp:" << p1.getHp() << endl;
	cout << "Monster Hp:" << m1.getHp() << endl << endl;

	//Main Loop
	while(win){
		//beginner.printField();
		battle(p1,m1);

		cout << "Battle again?" << endl;
		cin >> win;
	}

	return 0;
}
