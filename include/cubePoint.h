#ifndef CUBEPOINT_H_
#define CUBEPOINT_H_

#include <iostream>
#include "cur.h"
using namespace std;

enum color{
	CLEAR = 0,
	BLACK = 30,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	PURPLE,
	DEEP_GREEN,
	WHITE
};

/*
 * On display panel we see a lot of small dots (or points)
 * Each point is clearly a coordinate value and a color
 * This thinking to design more reasonable
 */
class CubePoint {
protected:
	int color;
	int x;
	int y;
public:
	CubePoint()
	{
		color = CLEAR;
		x = 0;
		y = 0;
	}
	CubePoint(int a,int b,int c)
	{
		color = a;
		x = b;
		y = c;
	}

	void setLocate(const int x,const int y){this->x = x;this->y = y;}
	void setColor(const int color){this->color = color;}
	
	int getColor(){return color;}
	void getLocate(int&x,int &y){x = this->x;y = this->y;}

	//Print method of the point
	void printPoint();
};

#endif