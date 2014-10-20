#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Player.cpp"
#include "Monster.cpp"

using namespace std;

void battle(Player &p1, Monster &m1){
	int playerAtk = p1.getAtk() - m1.getDef();
	int monsterAtk = m1.getAtk() - p1.getDef();

	m1.damaged(playerAtk);
	p1.damaged(monsterAtk);

	if(p1.getHp() <= 0){
		p1 = NULL;
		cout << "Player Dead" << endl;
		cout << "Monster Hp left:" << m1.getHp() << endl;
	} else if (m1.getHp() <= 0){
		m1 = NULL;
		cout << "Player Hp left:" << p1.getHp() << endl;
		cout << "Monster Dead" << endl;
	} else {
		cout << "Player Hp left:" << p1.getHp() << endl;
		cout << "Monster Hp left:" << m1.getHp() << endl;
	}
}

int main()
{
	int win = 1;
	int index;
	char move;
	srand (time(NULL));
	unsigned int seed = rand()%100;

	Player p1(seed);
	Monster m1(seed);

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
