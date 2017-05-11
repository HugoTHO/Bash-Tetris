#ifndef GAME_H_
#define GAME_H_

#include "graph.h"
#include "rand.h"
#include "score.h"

enum MARK{
	GAME_STOP = -1,
	GAME_PAUSE = 0,
	GAME_RUN = 1
};


class Game
{
private:
	int m_penal[24][17];
	color m_color[24][17];
	Context* m_graph;

	Context* nextGraph;
	MARK mark;
public:
	int x;
	int y;//This value can only be set if the current box's position, box movement, or rotation is successful

private:
	Score s;
private:
	//Restore settings (the box will explore the next location is legitimate, illegal to restore the panel)
	bool recoverPenal();
	//Whether landing (whether to encounter the bottom)
	bool isAttachBottom();
	//Whether meet the left
	bool isAttachLeft();
	//Whether meet the right
	bool isAttachRight();
	//Randomly get the tetromino's shape
	char getShape();
	//Use a square array to assign an array of panels
	bool setPenal();
	//After the block moves, the left panel information should be erased
	bool erasePenal();
public:
	Game();

	~Game();

	//Randomly create a tetromino
	void createCube();
	//Move method, move changing m_penal
	void move(int dir);
	//Rotation method
	void roll();
	//Stop the tetromino
	void stop();
	//Detect and erase full lines
	void erase();
	//Down upper graphics over the erased line
	void down(int level);

	void printNextCube(Context* m_graph);
	void gameInit();

	MARK getMark();
	void setMark( MARK );

	void printHelep();
};

#endif