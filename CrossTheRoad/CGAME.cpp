#include "CGAME.h"

CGAME::CGAME()
{
	for (int i = 0; i < MAX_HEIGHT; i++)
	{
		for (int j = 0; j < MAX_WIDTH; j++)
		{
			Buffer[i][j].DrawIt(' ', 7);
		}
	}

	m_density = 15;
}

void CGAME::SetGame()
{
	v_obs.resize(m_density);
	
	for (int i = 0; i < v_obs.size(); i++)
	{
		int x = rand() % 4;
		if (x == 0)
			v_obs[i] = new CBIRD;
		else if (x == 1)
			v_obs[i] = new CCAR;
		else if (x == 2)
			v_obs[i] = new CTRUCK;
		else if (x == 3)
			v_obs[i] = new CDINOSAUR;
	}
}

void CGAME::DrawPlayArea()
{
	//left col
	for (int i = 0; i < GameAreaHeight; i++)
	{
		Buffer[i][0].DrawIt(FrameShape, WHITE);
	}
	//top bar
	for (int i = 0; i < GameAreaWidth; i++)
	{
		Buffer[0][i].DrawIt(FrameShape, WHITE);
	}
	//bottom bar
	for (int i = 0; i < GameAreaWidth; i++)
	{
		Buffer[GameAreaHeight - 1][i].DrawIt(FrameShape, WHITE);
	}
	//right col
	for (int i = 0; i < GameAreaHeight; i++)
	{
		Buffer[i][GameAreaWidth - 1].DrawIt(FrameShape, WHITE);
	}
	//boundary
	for (int i = 3; i <= 30; i += 3)
	{
		for (int j = 1; j < GameAreaWidth - 1; j++)
		{
			Buffer[i][j].DrawIt('-', WHITE);
		}
	}
}


void CGAME::DrawBlock(int x, int y, int hei, int wid,
	char **block, int color)
{
	for (int i = 0; i < hei; i++) {
		for (int j = 0; j < wid; j++) {
			Buffer[y + i][x + j].DrawIt(block[i][j], color);
		}
	}
}

void CGAME::DrawPlayer()
{
	this->DrawBlock(m_player.GETX(), m_player.GETY(), 2, 1,
		m_player.GETSHAPE(), WHITE);
}

void CGAME::DrawObstacle()
{
	for (int i = 0; i < v_obs.size(); i++)
	{
		this->DrawBlock(v_obs[i]->GetX(), v_obs[i]->GetY(), 2, 3,
			v_obs[i]->GetShape(), WHITE);
	}
}

void CGAME::DrawBuffer()
{
	for (int i = 0; i < MAX_HEIGHT; i++) {
		for (int j = 0; j < MAX_WIDTH; j++)
		{
			Buffer[i][j].ColorIt();
			Buffer[i][j].ShapeIt();
			Buffer[i][j].DrawIt(' ', 7);
		}
		putchar('\n');
	}
}

void CGAME::DISPLAY()
{
	this->DrawPlayArea();
	this->DrawPlayer();
	this->DrawObstacle();
	this->DrawBuffer();
}

int CGAME::MOVEMENT()
{
	if (_kbhit())
	{
		char key = _getch();

		m_player.MOVE(key);

	}

	for (int i = 0; i < v_obs.size(); i++)
	{
		v_obs[i]->Move();
	}

	return 0;
}