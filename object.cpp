#include <iostream>
#include <string>
#include "object.h"

Object::Object(int newHp, int newDef, std::string inName)
{
	hp = newHp;
	def = newDef;
	name = inName;
}

void Object::printObject(){
	std::cout << "Name:" << name << std::endl;
	std::cout << "Hp:" << hp << std::endl;
	std::cout << "Def:" << def << std::endl;
}
