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

void mapRedraw(Map m1, int index, char direction){

}

/*
void moveUnit(Map m1, int index, char direction){
	switch(index){
		case 1:
			mapRedraw(m1, index, direction);
			break;
		case 2:
			break;
	}
}
*/

int main()
{
	int win = 0;
	int index;
	char move;
	Map beginner;

	//Main Loop
	while(!win){
		beginner.printField();

		cout << "Enter index and direction:";
		cin >> index >> move;

		//moveUnit(index, move);
	}

	return 0;
}
