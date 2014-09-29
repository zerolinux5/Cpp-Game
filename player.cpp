class Player {
	int hp;
	int atk;
	int def;
   public:
	Player (int, int, int);
	Player;
	int getHp() { return hp; }
	int getLives() { return lives;}
	int getAtk() { return atk; }
	int getDef() { return def; }
}

Player::Player (int inHp, int inAtk, int inDef){
	int hp = inHp;
	int atk = inAtk;
	int def = inDef;
}

Player::Player(){
	int hp = 100;
	int atk = 1;
	int def = 1;
}
