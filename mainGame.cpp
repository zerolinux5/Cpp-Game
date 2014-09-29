#include <iostream>

using namespace std;

#include "Player.cpp"
#include "Monster.cpp"

void battle(Player p1, Monster m1){
	int playerAtk = p1.getAtk() - m1.getDef();
	int monsterAtk = m1.getAtk() - p1.getDef();

	m1.damaged(playerAtk);
	p1.damaged(monsterAtk);

	cout << "Player Hp left:" << p1.getHp() << endl;
	cout << "Monster Hp left:" << m1.getHp() << endl;
}

int main()
{
	Player p1;
	Monster m1;

	return 0;
}
