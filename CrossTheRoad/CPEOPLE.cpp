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

bool CPEOPLE::isImpact(vector <COBSTACLE*> &v_obs)
{
	for (int i = 0; i < v_obs.size(); i++)
	{
		if (v_obs[i]->GetX() == m_X && v_obs[i]->GetY() == m_Y)
			return true;
		if (v_obs[i]->GetX() + 1 == m_X && v_obs[i]->GetY() == m_Y)
			return true;
		if (v_obs[i]->GetX() + 2 == m_X && v_obs[i]->GetY() == m_Y)
			return true;
	}

	return false;
}

bool CPEOPLE::isFinish()
{
	return m_Y == 1;
}

void CPEOPLE::BackToStart()
{
	m_X = PLAYER_STARTPOS_X;
	m_Y = PLAYER_STARTPOS_Y;
}

void CPEOPLE::SaveGame(string file_name)
{
	ofstream fout(file_name, ios::binary | ios::app);

	/*fout.write((char*)this, sizeof(CPEOPLE));*/

	fout.write((char*)&m_X, sizeof(int));
	fout.write((char*)&m_Y, sizeof(int));

	fout.close();
}

void CPEOPLE::LoadGame(string file_name)
{
	ifstream fin(file_name, ios::binary);
	/*fin.read((char*)this, sizeof(CPEOPLE));*/

	int x, y;
	fin.read((char*)&x, sizeof(int));
	fin.read((char*)&y, sizeof(int));

	m_X = x;
	m_Y = y;

	fin.close();
}

CPEOPLE::~CPEOPLE()
{
	for (int i = 0; i < 2; i++)
	{
		delete[]m_shape[i];
	}

	delete[]m_shape;
}

