#pragma once
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

const int CommonShape = 254;
const int ArrayY[] = { 4,7,10,13,16,19,22,25,28 };
const int WIDTH_RAND_HEAD = 1;
const int WIDTH_RAND_TAIL = 71;

class COBSTACLE
{
protected:
	int m_X, m_Y;
	char **m_shape;
public:
	COBSTACLE();
	~COBSTACLE();
	int GetX();
	int GetY();
	char **GetShape();

	void Move();
	void SaveGame(string file_name);
	void LoadGame(string file_name);
};