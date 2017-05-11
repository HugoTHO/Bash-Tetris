#include "../include/rand.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>

/*
 * One of the wrong ways to use random numbers
 * is to go to srand each time, so that when the
 * call is very close to the same value (and the
 * time is very large) and srand once there is
 * no such problem.
 */
Rand::Rand()
{
    srand(unsigned(time(0)));
}

int Rand::randNum(int x,int y)
{
    int randNum;
    double random(double,double);
    randNum = int(random(x,y));
    return randNum;
}

double random(double start,double end)
{
    return start + (end - start)*rand()/(RAND_MAX + 1.0);
}