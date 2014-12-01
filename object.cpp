#include <iostream>
#include <string>
#include "object.h"

Object::Object(int newHp, int newDef, std::string inName, int x, int y)
{
	hp = newHp;
	def = newDef;
	name = inName;
	location = new Point(x, y);
}

void Object::printObject(){
	std::cout << "Name:" << name << std::endl;
	std::cout << "Hp:" << hp << std::endl;
	std::cout << "Def:" << def << std::endl;
	std::cout << "X:" << location->getX() << std::endl;
	std::cout << "Y:" << location->getY() << std::endl;
}

void Object::deleteObject(){
	hp = 0;
	def = 0;
	name = "";
	delete location;
}