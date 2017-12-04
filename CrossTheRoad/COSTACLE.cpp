#include "COBSTACLE.h"
#include "CPEOPLE.h"

COBSTACLE::COBSTACLE()
{
	m_shape = new char*[2];
	for (int i = 0; i < 2; i++)
	{
		m_shape[i] = new char[3];
	}

	int a = rand() % 9;
	int b = rand() % 18;

	pair <int, int> tmp = Data[a][b];

	m_X = tmp.second;
	m_Y = tmp.first;

	/*m_Y = ArrayY[rand() % 9];

	m_X = rand() % (WIDTH_RAND_TAIL - WIDTH_RAND_HEAD + 1) +
		WIDTH_RAND_HEAD;*/

}

void COBSTACLE::SaveGame(string file_name)
{
	ofstream fout(file_name, ios::binary | ios::app);
	/*fout.write((char*)this, sizeof(COBSTACLE));*/
	
	fout.write((char*)&m_X, sizeof(int));
	fout.write((char*)&m_Y, sizeof(int));

	fout.close();
}

void COBSTACLE::LoadGame(string file_name, int pos)
{
	ifstream fin(file_name, ios::binary);
	
	fin.seekg(sizeof(int)*2, fin.beg);
	fin.seekg(sizeof(CTRAFFICLIGHT) * 5, fin.cur);
	fin.seekg(sizeof(int), fin.cur);
	fin.seekg(sizeof(int)*2*pos, fin.cur);
	
	int x, y;
	fin.read((char*)&x, sizeof(int));
	fin.read((char*)&y, sizeof(int));

	m_X = x;
	m_Y = y;

	fin.close();
}

COBSTACLE::~COBSTACLE()
{
	for (int i = 0; i < 2; i++)
	{
		delete[]m_shape[i];
	}

	delete[]m_shape;
}

int COBSTACLE::GetX()
{
	return m_X;
}

int COBSTACLE::GetY()
{
	return m_Y;
}

char** COBSTACLE::GetShape()
{
	return m_shape;
}

void COBSTACLE::Move(vector <CTRAFFICLIGHT> &v_traf)
{
	bool STOP = false;
	for (int i = 0; i < v_traf.size(); i++)
	{
		if (m_Y == v_traf[i].GetY())
		{
			if (v_traf[i].GetState() == 0)
			{
				STOP = true;
				break;
			}
		}
	}

	if (STOP == false)
	{
		if (m_Y % 2 == 0)
		{
			m_X += 2;
			if (m_X > WIDTH_RAND_TAIL)
			{
				m_X = WIDTH_RAND_HEAD;
			}

		}
		else
		{
			m_X -= 2;
			if (m_X <= 0)
			{
				m_X = WIDTH_RAND_TAIL;
			}
		}
	}
}