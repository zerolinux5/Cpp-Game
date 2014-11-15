#ifndef __POINT_H__
#define __POINT_H__

class Point{
	int x;
	int y;

   public:
   	Point(int,int);
   	int getX() {return x;}
   	int getY() {return y;}
   	void printPoint();
};

#endif