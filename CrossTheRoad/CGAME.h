#pragma once
#include "OnePointCoor.h"
#include "CPEOPLE.h"
#include "CBIRD.h"
#include "CCAR.h"
#include "CDINOSAUR.h"
#include "CTRUCK.h"
#include <iostream>
#include <conio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

const int MAX_WIDTH = 90;
const int MAX_HEIGHT = 40;

const int MAX_BLOCK_WIDTH = 4;

const int FrameShape = 178;
const int GameAreaHeight = 35;
const int GameAreaWidth = 75;
const int WHITE = 15;


class CGAME
{
private:
	OnePointCoor Buffer[MAX_HEIGHT][MAX_WIDTH];
	CPEOPLE m_player;
	int m_density;
	vector <COBSTACLE*> v_obs;
public:
	CGAME();
	void SetGame();

	void DrawBlock(int x, int y, int hei, int wid,
		char **block, int color);
	void DrawPlayArea();
	void DrawPlayer();
	void DrawBuffer();
	void DrawObstacle();
	void DISPLAY();

	int MOVEMENT();
};