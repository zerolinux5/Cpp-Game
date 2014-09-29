class Player {
	int hp;
	int atk;
	int def;
   public:
	Player (int, int, int);
	Player();
	int getHp() { return hp; }
	int getAtk() { return atk; }
	int getDef() { return def; }
	void damaged(int);
};

Player::Player (int inHp, int inAtk, int inDef){
	hp = inHp;
	atk = inAtk;
	def = inDef;
}

Player::Player(){
	hp = 100;
	atk = 1;
	def = 1;
}

void Player::damaged(int damageTaken){
	hp -= damageTaken;
}
