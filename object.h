#ifndef __OBJECT_H__
#define __OBJECT_H__

class Object{
	int hp;
	int def;
	std::string name;
   public:
	Object(int, int, std::string);
	int getHp() {return hp;}
	int getDef() {return def;}
	void damaged(int amount) {hp -= (amount - def);}
	std::string getName() {return name;}
	void printObject();
};

#endif