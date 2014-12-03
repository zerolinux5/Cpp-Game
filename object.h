#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "point.h"

class Object{
	int hp;
	int def;
	std::string name;
	Point* location;
	
   public:
   	//Constructors and Deconstructor
	Object(int, int, std::string, int, int);
	void deleteObject();

	//Getters
	int getHp() {return hp;}
	int getDef() {return def;}
	void damaged(int amount) {hp -= (amount - def);}
	std::string getName() {return name;}
	Point getLocation() {return *location;}
	int getXPos() {return location->getX();}
	int getYPos() {return location->getY();}

	//Print
	void printObject();
};

#endif