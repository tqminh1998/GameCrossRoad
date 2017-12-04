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

	m_density = BasicDensity;
}

void CGAME::SetGame()
{
	v_obs.resize(m_density);
	m_player.BackToStart();
	v_traf.resize(5);
	
	for (int i = 0; i < v_traf.size(); i++)
	{
		v_traf[i].Locate(i);
	}

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

void CGAME::NewGame()
{
	m_density = BasicDensity;
	this->SetGame();
}

void CGAME::NextLevel()
{
	m_density += 10;
	for (int i = 0; i < v_traf.size(); i++)
	{
		v_traf[i].Locate(i);
	}
	this->WaitingEffect();
	this->SetGame();
}

int CGAME::LoseGame()
{
	CONSOLE cs;
	cs.gotoXY(Info2_Pos_X, Info2_Pos_Y);
	cs.TextColor(YELLOW);
	cout << "You Lose";
	cs.gotoXY(Info2_Pos_X, Info2_Pos_Y + 1);
	cout << "1. Play again";
	cs.gotoXY(Info2_Pos_X, Info2_Pos_Y + 2);
	cout << "2. Back to main menu";
	char key = '0';
	do {
		if (_kbhit())
			key = _getch();
	} while (key != '1' && key != '2');

	if (key == '1')
		return 1;

	return 0;
}

int CGAME::WinGame()
{
	CONSOLE cs;
	cs.gotoXY(Info2_Pos_X, Info2_Pos_Y);
	cs.TextColor(YELLOW);
	cout << "You Win";
	cs.gotoXY(Info2_Pos_X, Info2_Pos_Y + 1);
	cout << "1. Play again";
	cs.gotoXY(Info2_Pos_X, Info2_Pos_Y + 2);
	cout << "2. Back to main menu";
	char key = '0';
	do {
		if (_kbhit())
			key = _getch();
	} while (key != '1' && key != '2');

	if (key == '1')
		return 1;

	return 0;
}

void CGAME::SaveGame()
{
	CONSOLE cs;
	string file_name;
	cs.gotoXY(Info2_Pos_X, Info2_Pos_Y);
	cout << "Enter file name:";
	cs.gotoXY(Info2_Pos_X, Info2_Pos_Y + 1);
	cin >> file_name;
	
	m_player.SaveGame(file_name);
	for (int i = 0; i < v_traf.size(); i++)
	{
		v_traf[i].SaveGame(file_name);
	}

	ofstream fout(file_name, ios::binary | ios::app);
	fout.write((char*)&m_density, sizeof(int));
	fout.close();

	for (int i = 0; i < v_obs.size(); i++)
	{
		v_obs[i]->SaveGame(file_name);
	}

}

void CGAME::LoadGame(string file_name)
{
	m_player.LoadGame(file_name);
	v_traf.resize(5);
	for (int i = 0; i < v_traf.size(); i++)
	{
		v_traf[i].LoadGame(file_name, i);
	}
	ifstream fin(file_name, ios::binary);
	fin.seekg(sizeof(int)*2, fin.beg);
	fin.seekg(sizeof(CTRAFFICLIGHT) * 5, fin.cur);
	fin.read((char*)&m_density, sizeof(int));
	fin.close();
	
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

	for (int i = 0; i < v_obs.size(); i++)
	{
		v_obs[i]->LoadGame(file_name, i);
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

void CGAME::DrawInfoArea()
{
	//left col
	for (int i = 4; i < GameAreaHeight; i++)
	{
		Buffer[i][76].DrawIt(InfoFrameShap, CYAN);
	}
	//top bar
	for (int i = 76; i < 105; i++)
	{
		Buffer[4][i].DrawIt(InfoFrameShap, CYAN);
	}
	//middle bar
	for (int i = 76; i < 105; i++)
	{
		Buffer[GameAreaHeight - 11][i].DrawIt(InfoFrameShap, CYAN);
	}
	//right col
	for (int i = 4; i < GameAreaHeight; i++)
	{
		Buffer[i][105].DrawIt(InfoFrameShap, CYAN);
	}
	//bottom bar
	for (int i = 76; i < 105; i++)
	{
		Buffer[GameAreaHeight - 1][i].DrawIt(InfoFrameShap, CYAN);
	}

	//Level
	this->DrawString(78, 12, "LEVEL: ", RED);
	if (m_density == BasicDensity)
		this->DrawString(84, 12, "EASY", WHITE);
	if (m_density == BasicDensity + 10)
		this->DrawString(84, 12, "MEDIUM", WHITE);
	if (m_density == BasicDensity + 20)
		this->DrawString(84, 12, "HARD", WHITE);
	if (m_density == BasicDensity + 30)
		this->DrawString(84, 12, "EXPERT", WHITE);
	if (m_density == BasicDensity + 40)
		this->DrawString(84, 12, "LEGEND", WHITE);
	if (m_density == BasicDensity + 50)
		this->DrawString(84, 12, "LAST STAND", WHITE);
	//Save
	this->DrawString(78, 16, "Press L: Save", GREY);
	this->DrawString(78, 17, "Press Esc: Back to menu", GREY);
}

void CGAME::DrawString(int x, int y, string s, int color)
{
	for (int i = 0; i < s.length(); i++)
	{
		Buffer[y][i + x].DrawIt(s[i], color);
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
		m_player.GETSHAPE(), PINK);
}

void CGAME::DrawObstacle()
{
	for (int i = 0; i < v_obs.size(); i++)
	{
		this->DrawBlock(v_obs[i]->GetX(), v_obs[i]->GetY(), 2, 3,
			v_obs[i]->GetShape(), WHITE);
	}
}

void CGAME::DrawTrafficLight()
{
	for (int i = 0; i < v_traf.size(); i++)
	{
		v_traf[i].ChangeState();
		if (v_traf[i].GetState() == 1)
		{
			Buffer[v_traf[i].GetY()][v_traf[i].GetX()].DrawIt(220, GREEN);
			Buffer[v_traf[i].GetY() + 1][v_traf[i].GetX()].DrawIt(223, WHITE);
		}
		else
		{
			Buffer[v_traf[i].GetY()][v_traf[i].GetX()].DrawIt(220, RED);
			Buffer[v_traf[i].GetY() + 1][v_traf[i].GetX()].DrawIt(223, WHITE);
		}
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
	this->DrawInfoArea();
	this->DrawPlayer();
	this->DrawObstacle();
	this->DrawTrafficLight();
	this->DrawBuffer();
}

int CGAME::MOVEMENT()
{
	if (_kbhit())
	{
		char key = _getch();

		if (key == 27)
			return 1;

		if (key == 'l')
			this->SaveGame();

		m_player.MOVE(key);

	}

	for (int i = 0; i < v_obs.size(); i++)
	{
		v_obs[i]->Move(v_traf);
	}

	return 0;
}

int CGAME::PROCESS()
{
	if (m_player.isImpact(v_obs))
		return 1;

	if (m_player.isFinish())
		return 2;

	if (m_density > BasicDensity + 50)
		return 3;

	return 0;
}

int CGAME::StartGame()
{
	CONSOLE cs;
	//title line 1
	cs.TextColor(BLUE);


	cs.gotoXY(0, 0);
	cout << "  _________                            __________                  .___\n";
	cout << "  \\\_   ___ \_______  ____  ______ _____\\\______   \\\ _________     __| _/\n";
	cout << "  /    \\\  \\\/\\\_  __ \\\/  _ \\\/  ___//  ___/|       _//  _ \\\__  \\\   / __ | \n";
	cout << "  \\\     \\\____|  | \\\(  <_> )___ \\\ \\\___ \\\ |    |   (  <_> ) __ \\\_/ /_/ | \n";
	cout << "   \\\______  /|__|   \\\____/____  >____  >|____|_  /\\\____(____  /\\\____ | \n";
	cout << "          \\\/                  \\\/     \\\/        \\\/           \\\/      \\\/ \n\n\n";

	cs.TextColor(15);
	printf("                         Start Now \n");
	printf("                         Introduction\n");
	printf("                         Load Game\n");
	printf("                         Exit\n");




	int curPos_x = FirstchoicePos_X;
	int curPos_y = FirstchoicePos_Y;

	cs.gotoXY(curPos_y, curPos_x);
	printf("->");


	char key = _getch();
	while (key != 13)
	{
		if (key == 's' || key == 'S')
		{
			cs.gotoXY(curPos_y, curPos_x);
			printf("  ");

			if (curPos_x == FirstchoicePos_X + NUMofOPTION)
			{
				curPos_x = FirstchoicePos_X;
				cs.gotoXY(curPos_y, curPos_x);
				printf("->");

				if (_getch() != 13) {
					continue;
				}
				else
				{
					break;
				}
			}
			cs.gotoXY(curPos_y, ++curPos_x);
			printf("->");
		}
		else if (key == 'w' || key == 'W')
		{
			cs.gotoXY(curPos_y, curPos_x);
			printf("  ");

			if (curPos_x == FirstchoicePos_X)
			{
				curPos_x = FirstchoicePos_X + NUMofOPTION;
				cs.gotoXY(curPos_y, curPos_x);
				printf("->");

				if (_getch() != 13) {
					continue;
				}
				else
				{
					break;
				}
			}

			cs.gotoXY(curPos_y, --curPos_x);
			printf("->");
		}

		key = _getch();
	}

	if (curPos_x == FirstchoicePos_X + 1)
		return 2;

	if (curPos_x == FirstchoicePos_X)
		return 1;

	if (curPos_x == FirstchoicePos_X + NUMofOPTION)
		return 3;

	if (curPos_x == FirstchoicePos_X + 2)
		return 4;

}

void CGAME::WaitingEffect() {

	CONSOLE cs;

	cs.gotoXY(WAITPOS_X, WAITPOS_Y - 1);
	printf("Loading for next stage...");
	cs.gotoXY(WAITPOS_X, WAITPOS_Y);
	for (int i = 1; i <= WAITLENGTH; i++)
	{
		cs.TextColor(GREEN);
		putchar(176);
	}
	cs.gotoXY(WAITPOS_X, WAITPOS_Y);
	for (int i = 1; i <= WAITLENGTH; i++)
	{
		cs.TextColor(GREEN);
		putchar(178);
		Sleep(60);
	}

	cs.gotoXY(WAITPOS_X, WAITPOS_Y);
	for (int i = 1; i <= WAITLENGTH; i++)
	{
		putchar(' ');
	}
}

int CGAME::getDen()
{
	return m_density;
}
