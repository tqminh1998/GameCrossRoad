#pragma once
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

const int Y[] = { 4,7,10,13,16,19,22,25,28 };

class CTRAFFICLIGHT
{
private:
	int m_X, m_Y;
	int m_state;
	int m_cntTime;
public:
	CTRAFFICLIGHT();
	int GetState();
	int GetX();
	int GetY();
	void Locate(int i);
	void ChangeState();
	void SaveGame(string file_name);
	void LoadGame(string file_name, int pos);
};