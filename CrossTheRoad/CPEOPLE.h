#pragma once
#include "COBSTACLE.h"
#include <vector>
using namespace std;

const int PLAYER_STARTPOS_X = 31;
const int PLAYER_STARTPOS_Y = 31;

class CPEOPLE
{
	int m_X, m_Y;
	char **m_shape;
public:
	CPEOPLE();
	~CPEOPLE();
	int GETX();
	int GETY();
	char** GETSHAPE();

	void UP();
	void LEFT();
	void RIGHT();
	void DOWN();
	void MOVE(int key);

	bool isImpact(vector <COBSTACLE*> &v_obs);
	bool isFinish();
	void BackToStart();
	void SaveGame(string file_name);
	void LoadGame(string file_name);
};