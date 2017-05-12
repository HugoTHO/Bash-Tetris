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

	Score s;

private:
	
	//Whether landing (whether to encounter the bottom)
	bool isAttachBottom();
	//Whether meet the left
	bool isAttachLeft();
	//Whether meet the right
	bool isAttachRight();
	//Randomly get the tetromino's shape
	char getShape();
	//check the panel to identify illegal block creation
	bool checkPanel();
	//Incorporate the block shape on panel when touch
	void increasePanel();
public:
	Game();

	~Game();

	//Randomly create a tetromino
	void createCube();
	//Move method, move changing m_penal
	void move(int dir);
	//Rotation method
	void roll();
	//Down the tetromino to the panel;
	void fall();
	//Detect and erase full lines
	void checkLines();
	//Down upper graphics over the erased line
	void downPanel(int level);

	void printNextCube(Context* m_graph);
	void gameInit();

	MARK getMark();
	void setMark( MARK );

	void printHelep();
};

#endif