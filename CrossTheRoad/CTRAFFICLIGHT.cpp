#include "CTRAFFICLIGHT.h"
#include "CPEOPLE.h"



CTRAFFICLIGHT::CTRAFFICLIGHT()
{
	m_state = rand() % 2;
	m_cntTime = 0;
	m_X = 73;

	m_Y = Y[rand() % 9];
}

void CTRAFFICLIGHT::Locate(int i)
{
	m_state = rand() % 2;

	int k = rand() % 3;

	if (k == 0)
	{
		switch (i)
		{
		case 0:
			m_Y = 4;
			break;
		case 1:
			m_Y = 13;
			break;
		case 2:
			m_Y = 22;
			break;
		case 3:
			m_Y = 19;
			break;
		case 4:
			m_Y = 28;
			break;
		}
	}
	else if (k == 1)
	{
		switch (i)
		{
		case 0:
			m_Y = 7;
			break;
		case 1:
			m_Y = 13;
			break;
		case 2:
			m_Y = 16;
			break;
		case 3:
			m_Y = 19;
			break;
		case 4:
			m_Y = 25;
			break;
		}
	}
	else if (k == 2)
	{
		switch (i)
		{
		case 0:
			m_Y = 4;
			break;
		case 1:
			m_Y = 16;
			break;
		case 2:
			m_Y = 22;
			break;
		case 3:
			m_Y = 19;
			break;
		case 4:
			m_Y = 28;
			break;
		}
	}
}

int CTRAFFICLIGHT::GetX()
{
	return m_X;
}

int CTRAFFICLIGHT::GetY()
{
	return m_Y;
}

int CTRAFFICLIGHT::GetState()
{
	return m_state;
}

void CTRAFFICLIGHT::ChangeState()
{
	m_cntTime++;
	
	if (m_cntTime == 20)
	{
		m_cntTime = 0;
		if (m_state == 0)
			m_state = 1;
		else
			m_state = 0;
	}
}

void CTRAFFICLIGHT::SaveGame(string file_name)
{
	ofstream fout(file_name, ios::binary | ios::app);
	fout.write((char*)this, sizeof(CTRAFFICLIGHT));
	fout.close();
}

void CTRAFFICLIGHT::LoadGame(string file_name, int pos)
{
	ifstream fin(file_name, ios::binary);
	fin.seekg(sizeof(int)*2, fin.beg);
	fin.seekg(sizeof(CTRAFFICLIGHT)*pos, fin.cur);

	fin.close();
}