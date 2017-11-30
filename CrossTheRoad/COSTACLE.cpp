#include "COBSTACLE.h"
#include "CPEOPLE.h"

COBSTACLE::COBSTACLE()
{
	m_shape = new char*[2];
	for (int i = 0; i < 2; i++)
	{
		m_shape[i] = new char[3];
	}

	m_Y = ArrayY[rand() % 9];

	m_X = rand() % (WIDTH_RAND_TAIL - WIDTH_RAND_HEAD + 1) +
		WIDTH_RAND_HEAD;

}

void COBSTACLE::SaveGame(string file_name)
{
	ofstream fout(file_name, ios::binary | ios::app);
	fout.write((char*)this, sizeof(COBSTACLE));
	fout.close();
}

void COBSTACLE::LoadGame(string file_name)
{
	ifstream fin(file_name, ios::binary);
	
	fin.seekg(sizeof(CPEOPLE), fin.beg);

	

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

void COBSTACLE::Move()
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