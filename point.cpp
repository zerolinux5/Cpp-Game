#include <iostream>
#include "point.h"

Point::Point (int inX, int inY){
	x = inX;
	y = inY;
}

void Point::printPoint(){
	std::cout << "X:" << x << std::endl;
	std::cout << "Y:" << y << std::endl;
}