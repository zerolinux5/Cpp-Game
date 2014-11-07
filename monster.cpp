class Monster{
	int hp;
	int sp;
	int def;
	int atk;
	string element;
   public:
	void Monster(int, int, int, int, string);
	int getHp() {return hp;}
	int getSp() {return sp;}
	int getDef() {return def;}
	int getAtk() {return atk;}
	string getElement() {return element;}	
};

Monster::Monster(int newHp, int newSp, int newDef, int newAtk, string newElement)
{
	hp = newHo;
	sp = newSp;
	atk = newAtk;
	def = newDef;
	element = newElement;
}
