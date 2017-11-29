#pragma once
#include <string>
#include "CONSOLE.h"
using namespace std;

class OnePointCoor {
private:
	char m_shape;
	int m_color;
public:
	OnePointCoor();
	OnePointCoor(int shape, int color);
	OnePointCoor& operator=(const OnePointCoor &opc);

	void ColorIt();
	void ShapeIt();
	void DrawIt(int shape, int color);
};