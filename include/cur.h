#ifndef CUR_H_
#define CUR_H_

#include <iostream>
using namespace std;

class Cur{
public:
	void saveCur();		//Save the cursor position
	void moveCur(const int x,const int y);  //Move the cursor position to the (x, y) coordinates
	void resumeCur();     //Restore the cursor position
};
#endif