#include <iostream>
#include "Player.cpp"
#include "Monster.cpp"
#include "Map.cpp"

using namespace std;

void battle(Player p1, Monster m1){
	int playerAtk = p1.getAtk() - m1.getDef();
	int monsterAtk = m1.getAtk() - p1.getDef();

	m1.damaged(playerAtk);
	p1.damaged(monsterAtk);

	cout << "Player Hp left:" << p1.getHp() << endl;
	cout << "Monster Hp left:" << m1.getHp() << endl;
}

int findItems(Map m1, char search){
	int total = 0;
	for(int i = 0; i < 5; i ++){
		string checkString = m1.getField(i);
		for(int j = 0; j < 5; j++){
			if(checkString[j] == search){
				total++;
			}
		}
	}
	return total;
}

int main()
{
	int win = 1;
	int index;
	char move;
	Map beginner;

	Player p1;
	Monster m1;

	cout << "Player Hp:" << p1.getHp() << endl;
	cout << "Monster Hp:" << m1.getHp() << endl;

	//Main Loop
	while(win){
		//beginner.printField();
		battle(p1,m1);

		cout << "Battle again?" << endl;
		cin >> win;
	}

	return 0;
}
