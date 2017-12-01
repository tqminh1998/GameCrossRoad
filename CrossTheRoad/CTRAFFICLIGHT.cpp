#include "CTRAFFICLIGHT.h"
#include "CPEOPLE.h"

CTRAFFICLIGHT::CTRAFFICLIGHT()
{
	m_state = rand() % 2;
	m_cntTime = 0;
	m_X = 73;
	//bool check;
	//int x;
	//do {
	//	check = true;
	//	x = rand() % 9;
	//	for (int i = 0; i < tmp.size(); i++)
	//	{
	//		if (x == tmp[i]) {
	//			check = false;
	//			break;
	//		}
	//	}

	//} while(!check);
	//tmp.push_back(1);
	m_Y = Y[rand() % 9];
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
	fin.seekg(sizeof(CPEOPLE), fin.beg);
	fin.seekg(sizeof(CTRAFFICLIGHT)*pos, fin.cur);

	fin.close();
}