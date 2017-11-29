#include "CPEOPLE.h"
#include "CGAME.h"

CPEOPLE::CPEOPLE()
{
	m_X = PLAYER_STARTPOS_X;
	m_Y = PLAYER_STARTPOS_Y;

	m_shape = new char*[2];
	for (int i = 0; i < 2; i++)
	{
		m_shape[i] = new char[1];
	}

	m_shape[0][0] = 254;
	m_shape[1][0] = 208;
}

char** CPEOPLE::GETSHAPE()
{
	return m_shape;
}

int CPEOPLE::GETX()
{
	return m_X;
}

int CPEOPLE::GETY()
{
	return m_Y;
}

void CPEOPLE::UP()
{
	m_Y -= 3;
}

void CPEOPLE::DOWN()
{
	m_Y += 3;
}

void CPEOPLE::LEFT()
{
	m_X-=2;
}

void CPEOPLE::RIGHT()
{
	m_X+=2;
}

void CPEOPLE::MOVE(int key)
{
	if ((key == 'a' || key == 'A') && (m_X >= 2))
		this->LEFT();
	else if ((key == 's' || key == 'S') && (m_Y != PLAYER_STARTPOS_Y))
		this->DOWN();
	else if ((key == 'w' || key == 'W') && (m_Y != 1))
		this->UP();
	else if ((key == 'd' || key == 'D') && (m_X <= GameAreaWidth - 3))
		this->RIGHT();

}

CPEOPLE::~CPEOPLE()
{
	for (int i = 0; i < 2; i++)
	{
		delete[]m_shape[i];
	}

	delete[]m_shape;
}