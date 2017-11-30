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
#include <fstream>

//STAT
const int MAX_WIDTH = 115;
const int MAX_HEIGHT = 40;
const int MAX_BLOCK_WIDTH = 4;
const int GameAreaHeight = 35;
const int GameAreaWidth = 75;

//SHAPE
const int FrameShape = 178;
const int InfoFrameShap = 254;

//DENSITY
const int BasicDensity = 15;
const int HighestDensity = 55;

//COLOR
const int WHITE = 15;
const int GREY = 8;
const int BLUE = 9;
const int GREEN = 10;
const int CYAN = 11;
const int RED = 12;
const int PINK = 13;
const int YELLOW = 14;

//StartGame Pos
const int FirstchoicePos_X = 8;
const int FirstchoicePos_Y = 21;
const int NUMofOPTION = 3;

//Wait Pos
const int WAITPOS_X = 78;
const int WAITPOS_Y = 27;
const int WAITLENGTH = 25;

//Second Info Box Pos
const int Info2_Pos_X = 80;
const int Info2_Pos_Y = 26;

class CGAME
{
private:
	OnePointCoor Buffer[MAX_HEIGHT][MAX_WIDTH];
	CPEOPLE m_player;
	int m_density;
	vector <COBSTACLE*> v_obs;
public:
	CGAME();


	void DrawBlock(int x, int y, int hei, int wid,
		char **block, int color);
	void CGAME::DrawString(int x, int y,
		string s, int color);
	void DrawPlayArea();
	void DrawInfoArea();
	void DrawPlayer();
	void DrawBuffer();
	void DrawObstacle();

	void SetGame();
	int StartGame();
	int LoseGame();
	void WaitingEffect();
	void NextLevel();
	void NewGame();
	void SaveGame();
	void LoadGame(string file_name);

	void DISPLAY();
	int MOVEMENT();
	int PROCESS();
};