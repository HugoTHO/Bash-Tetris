#include "../include/graph.h"
#include <unistd.h>

void Gbase::printG(int color)
{
    int i,j;
    CubePoint p;
    for(i = x; i < x+4; i++)
        for(j = y; j < y+4; j++)
        {
            if(a[i - x][j - y] == 1)
            {
                p.setLocate(i,j);
                p.setColor(color);
                p.printPoint();
            }
        }
}

int Gbase::move(int dir)
{
	switch(dir)
	{
		case DOWN:x++;break;
		case LEFT:y--;break;
		case RIGHT:y++;break;
		default:
				break;
	}
    return 0;
}

int Gbase::roll()
{
    int i,j;
    int b[3][3];
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        {
            b[2-j][i] = a[i][j];
        }
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        {
            a[i][j] = b[i][j];
        }
}

int Igraph::roll()
{
    if (a[0][1] == 0)
    {
        a[0][1] = 1;
        a[1][0] = 0;
        a[1][2] = 0;
        a[1][3] = 0;
        a[2][1] = 1;
        a[3][1] = 1;
    }
    else
    {
        a[0][1] = 0;
        a[1][0] = 1;
        a[1][1] = 1;
        a[1][2] = 1;
        a[1][3] = 1;
        a[2][1] = 0;
        a[3][1] = 0;
    }
}