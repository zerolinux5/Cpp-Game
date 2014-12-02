#ifndef __POINT_H__
#define __POINT_H__

class Point{
	int x;
	int y;

   public:
      //Constructor
   	Point(int,int);

      //Getters
   	int getX() {return x;}
   	int getY() {return y;}
   	void plusX() {x++;}
   	void plusY() {y++;}
   	void minusX() {x--;}
   	void minusY() {y--;}

      //Print
   	void printPoint();
};

#endif