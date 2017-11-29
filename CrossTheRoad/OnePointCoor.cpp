#include "OnePointCoor.h"

OnePointCoor::OnePointCoor()
{
	m_shape = ' ';
	m_color = ' ';
}

OnePointCoor::OnePointCoor(int shape, int color)
{
	m_shape = shape;
	m_color = color;
}

OnePointCoor& OnePointCoor::operator=(const OnePointCoor &opc)
{
	m_shape = opc.m_shape;
	m_color = opc.m_color;

	return *this;
}

void OnePointCoor::DrawIt(int shape, int color)
{
	m_shape = shape;
	m_color = color;
}

void OnePointCoor::ColorIt()
{
	CONSOLE cs;
	cs.TextColor(m_color);
}

void OnePointCoor::ShapeIt()
{
	putchar(m_shape);
}