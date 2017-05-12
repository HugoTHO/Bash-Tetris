#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "cubePoint.h"
#define DOWN 0
#define LEFT 1
#define RIGHT 2

using namespace std;

class Gbase{
protected:
	int x;
	int y;	//a[0][0] position
	int a[4][4];
public:
	Gbase(){
		int i,j;
		x = 0;
		y = 0;
		for(j = 0; j < 4; j++)
		for(i = 0; i < 4; i++)
		a[i][j] = 0;
	}
	int move(int dir);
	virtual int roll();
	virtual void draw(){}
	virtual void setLocate(int a,int b){x = a;y = b;}
	void getLocate(int* a,int* b){*a = x;*b = y;}
	void printG(int color);
	
	//Get the first address of the array
	void* getArray(){return (void*)a;}
};

class Zgraph : public Gbase{
public:
	void draw(){
		a[0][0] = 1;
		a[0][1] = 1;
		a[0][2] = 0;
		a[0][3] = 0;
		a[1][0] = 0;
		a[1][1] = 1;
		a[1][2] = 1;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 0;
		a[2][2] = 0;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 0;
	}
};

class Sgraph : public Gbase{
public:
	void draw(){
		a[0][0] = 0;
		a[0][1] = 1;
		a[0][2] = 1;
		a[0][3] = 0;
		a[1][0] = 1;
		a[1][1] = 1;
		a[1][2] = 0;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 0;
		a[2][2] = 0;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 0;
	}
};

class Tgraph : public Gbase{
public:
	void setLocate(int a,int b){x = --a;y = b;}
	void draw(){
		a[0][0] = 0;
		a[0][1] = 0;
		a[0][2] = 0;
		a[0][3] = 0;
		a[1][0] = 1;
		a[1][1] = 1;
		a[1][2] = 1;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 1;
		a[2][2] = 0;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 0;
	}
};

class Ograph : public Gbase{
public:
	void draw(){
		a[0][0] = 1;
		a[0][1] = 1;
		a[0][2] = 0;
		a[0][3] = 0;
		a[1][0] = 1;
		a[1][1] = 1;
		a[1][2] = 0;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 0;
		a[2][2] = 0;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 0;
	}
	virtual int roll(){}
};

class Igraph : public Gbase{
public:
	void draw(){
		a[0][0] = 0;
		a[0][1] = 1;
		a[0][2] = 0;
		a[0][3] = 0;
		a[1][0] = 0;
		a[1][1] = 1;
		a[1][2] = 0;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 1;
		a[2][2] = 0;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 1;
		a[3][2] = 0;
		a[3][3] = 0;
	}
	virtual int roll();
};

class Lgraph : public Gbase{
public:
	void draw(){
		a[0][0] = 0;
		a[0][1] = 1;
		a[0][2] = 0;
		a[0][3] = 0;
		a[1][0] = 0;
		a[1][1] = 1;
		a[1][2] = 0;
		a[1][3] = 0;
		a[2][0] = 0;
		a[2][1] = 1;
		a[2][2] = 1;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 0;
	}
};

class Jgraph : public Gbase{
public:
	void draw(){
		a[0][0] = 0;
		a[0][1] = 1;
		a[0][2] = 0;
		a[0][3] = 0;
		a[1][0] = 0;
		a[1][1] = 1;
		a[1][2] = 0;
		a[1][3] = 0;
		a[2][0] = 1;
		a[2][1] = 1;
		a[2][2] = 0;
		a[2][3] = 0;
		a[3][0] = 0;
		a[3][1] = 0;
		a[3][2] = 0;
		a[3][3] = 0;
	}
};

class Context
{
private:
	Gbase* gbase;
	color clr;

public:
	~Context()
	{
		delete gbase;
	}
	Context(char cType)
	{
		switch(cType)
		{
			case 'Z':
				gbase = new Zgraph();clr = YELLOW;///
				break;
			case 'S':
				gbase = new Sgraph();clr = PURPLE;///
				break;
			case 'T':
				gbase = new Tgraph();clr = GREEN;///
				break;
			case 'O':
				gbase = new Ograph();clr = PURPLE;///
				break;
			case 'I':
				gbase = new Igraph();clr = DEEP_GREEN;///
				break;
			case 'L':
				gbase = new Lgraph();clr = WHITE;///
				break;
			case 'J':
				gbase = new Jgraph();clr = DEEP_GREEN;///
				break;
			default:
				printf("no %c type\n",cType);
				break;
		}
	}
	int move(int dir){return gbase->move(dir);}
	int roll(){return gbase->roll();}
	void draw(){gbase->draw();}

	void setLocate(int a,int b){gbase->setLocate(a,b);}
	void getLocate(int *a,int* b){gbase->getLocate(a,b);}
	void* getArray(){gbase->getArray();}

	void printG(int color){
		if(color == CLEAR)
			gbase->printG(CLEAR);
		else gbase->printG(clr);
	}

	void setColor(color clr){
		this->clr = clr;
	}

	color getColor(){
		return clr;
	}

};

#endif