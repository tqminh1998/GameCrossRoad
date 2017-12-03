#pragma once
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include <utility>
#include "CTRAFFICLIGHT.h"
using namespace std;

#define mb make_pair

const int CommonShape = 254;
const int ArrayY[] = { 4,7,10,13,16,19,22,25,28 };
const int WIDTH_RAND_HEAD = 1;
const int WIDTH_RAND_TAIL = 71;
const pair<int, int>
Data[9][18] =
{
	mb(4, 1),mb(4, 5),mb(4, 9),mb(4, 13),mb(4, 17),mb(4, 21),mb(4, 25),mb(4, 29),mb(4, 33),mb(4, 37),mb(4, 41),mb(4, 45),mb(4, 49),mb(4, 53),mb(4, 57),mb(4, 61),mb(4, 65),mb(4, 69),
	mb(7, 1),mb(7, 5),mb(7, 9),mb(7, 13),mb(7, 17),mb(7, 21),mb(7, 25),mb(7, 29),mb(7, 33),mb(7, 37),mb(7, 41),mb(7, 45),mb(7, 49),mb(7, 53),mb(7, 57),mb(7, 61),mb(7, 65),mb(7, 69),
	mb(10, 1),mb(10, 5),mb(10, 9),mb(10, 13),mb(10, 17),mb(10, 21),mb(10, 25),mb(10, 29),mb(10, 33),mb(10, 37),mb(10, 41),mb(10, 45),mb(10, 49),mb(10, 53),mb(10, 57),mb(10, 61),mb(10, 65),mb(10, 69),
	mb(13, 1),mb(13, 5),mb(13, 9),mb(13, 13),mb(13, 17),mb(13, 21),mb(13, 25),mb(13, 29),mb(13, 33),mb(13, 37),mb(13, 41),mb(13, 45),mb(13, 49),mb(13, 53),mb(13, 57),mb(13, 61),mb(13, 65),mb(13, 69),
	mb(16, 1),mb(16, 5),mb(16, 9),mb(16, 13),mb(16, 17),mb(16, 21),mb(16, 25),mb(16, 29),mb(16, 33),mb(16, 37),mb(16, 41),mb(16, 45),mb(16, 49),mb(16, 53),mb(16, 57),mb(16, 61),mb(16, 65),mb(16, 69),
	mb(19, 1),mb(19, 5),mb(19, 9),mb(19, 13),mb(19, 17),mb(19, 21),mb(19, 25),mb(19, 29),mb(19, 33),mb(19, 37),mb(19, 41),mb(19, 45),mb(19, 49),mb(19, 53),mb(19, 57),mb(19, 61),mb(19, 65),mb(19, 69),
	mb(22, 1),mb(22, 5),mb(22, 9),mb(22, 13),mb(22, 17),mb(22, 21),mb(22, 25),mb(22, 29),mb(22, 33),mb(22, 37),mb(22, 41),mb(22, 45),mb(22, 49),mb(22, 53),mb(22, 57),mb(22, 61),mb(22, 65),mb(22, 69),
	mb(25, 1),mb(25, 5),mb(25, 9),mb(25, 13),mb(25, 17),mb(25, 21),mb(25, 25),mb(25, 29),mb(25, 33),mb(25, 37),mb(25, 41),mb(25, 45),mb(25, 49),mb(25, 53),mb(25, 57),mb(25, 61),mb(25, 65),mb(25, 69),
	mb(28, 1),mb(28, 5),mb(28, 9),mb(28, 13),mb(28, 17),mb(28, 21),mb(28, 25),mb(28, 29),mb(28, 33),mb(28, 37),mb(28, 41),mb(28, 45),mb(28, 49),mb(28, 53),mb(28, 57),mb(28, 61),mb(28, 65),mb(28, 69)


};
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

	void Move(vector <CTRAFFICLIGHT> &v_traf);
	void SaveGame(string file_name);
	void LoadGame(string file_name, int pos);
};