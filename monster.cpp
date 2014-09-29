class Monster {
	int hp;
	int atk;
	int def;
   public:
	Monster(int, int, int);
	Monster();
	int getHp(){ return hp;}
	int getAtk(){ return atk;}
	int getDef(){ return def;}
	void damaged(int);
};

Monster::Monster(int inHp, int inAtk, int inDef){
	hp = inHp;
	atk = inAtk;
	def = inDef;
}

Monster::Monster(){
	hp = 50;
	atk = 1;
	def = 1;
}

void Monster::damaged(int damageTaken){
	hp -= damageTaken;
}
