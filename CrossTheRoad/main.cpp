#include "CGAME.h"
#include <ctime>
#include <cstdlib>
#include <thread>
#include "Windows.h"

#pragma comment(lib, "winmm.lib")

void CueMusic()
{
	bool isPlay = PlaySound(L"STDIO_SOUND_LOGO.wav", NULL, SND_FILENAME);
}

int main()
{
	srand(time(NULL));
	CONSOLE cs;
	cs.FixConsoleWindow();
	CGAME cg;

	bool Sound = false;
	bool Setting = false;

	
	while (1)
	{
		cs.clrscr();
		cs.Nocursortype();
		int choose = cg.StartGame();
		
		switch (choose)
		{
		case 1:
			CONSOLE cs;
			cs.clrscr();
			cs.gotoXY(10, 5-1);
			printf("Loading...");
			cs.gotoXY(10, 5);
			for (int i = 1; i <= WAITLENGTH; i++)
			{
				cs.TextColor(GREEN);
				putchar(176);
			}
			cs.gotoXY(10, 5);
			for (int i = 1; i <= WAITLENGTH; i++)
			{
				cs.TextColor(GREEN);
				putchar(178);
				Sleep(60);
			}

			cs.gotoXY(10, 5);
			for (int i = 1; i <= WAITLENGTH; i++)
			{
				putchar(' ');
			}
			
			if (Setting)
				cg.SetGame();
			else
				cg.NewGame();

			Setting = false;
			break;
		case 3:
			return 0;
			break;
		case 2:
			cs.clrscr();
			cs.gotoXY(10, 5);
			cout << "1. LEVEL";
			cs.gotoXY(10, 6);
			cout << "2. SOUND";

			char key;
			do {
				if (_kbhit())
					key = _getch();
			} while (key != '1' && key != '2');
			
			if (key == '1')
			{
				cs.clrscr();
				cs.gotoXY(10, 5);
				cout << "1. EASY";
				cs.gotoXY(10, 6);
				cout << "2. MEDIUM";
				cs.gotoXY(10, 7);
				cout << "3. HARD";
				char key1 = '0';
				do {
					if (_kbhit())
						key1 = _getch();
				} while (key1 != '1' && key1 != '2' && key1 != '3');

				if (key1 == '1')
					cg.SetLevel(15);
				else if (key1 == '2')
					cg.SetLevel(25);
				else
					cg.SetLevel(35);

				Setting = true;
			}
			else
			if (key == '2')
			{
				cs.clrscr();
				cs.gotoXY(10, 5);
				cout << "1. ON";
				cs.gotoXY(10, 6);
				cout << "2. OFF";

				char key1 = '0';
				do {
					if (_kbhit())
						key1 = _getch();
				} while (key1 != '1' && key1 != '2');

				if (key1 == '1')
					Sound = true;
				else
					Sound = false;

			}

			cs.gotoXY(10, 9);
			key = '0';
			cout << "Wait a minute...";
			Sleep(2000);
			continue;
		case 4:
			cs.clrscr();
			cs.gotoXY(10, 5);
			string file_in;
			cout << "Enter saved file 's name: ";
			cin >> file_in;

			ifstream fin(file_in, ios::binary);
			if (!fin)
			{
				cs.gotoXY(10, 6);
				cout << "Not found";
				Sleep(2000);
				continue;
			}
			fin.close();

			cg.LoadGame(file_in);
			
		}

		if (Sound)
		{
			thread task(CueMusic);
			task.detach();
		}
		
		bool PlayAgain = false;
		while (1)
		{
			
			if (PlayAgain == true)
			{
				cg.NewGame();
				PlayAgain = false;
			}
			cs.gotoXY(0, 0);
			cs.Nocursortype();


			cg.DISPLAY();
			int movement = cg.MOVEMENT();
			if (movement == 1)
				break;
			else if (movement == 2)
			{
				
				CONSOLE cs;

				cs.gotoXY(Info2_Pos_X, Info2_Pos_Y);
				cout << "                   ";
				cs.TextColor(YELLOW);
				cs.gotoXY(Info2_Pos_X, Info2_Pos_Y + 1);
				cout << "1. Continue";
				cs.gotoXY(Info2_Pos_X, Info2_Pos_Y + 2);
				cout << "2. Back to main menu";
				char key = '0';
				do {
					if (_kbhit())
						key = _getch();
				} while (key != '1' && key != '2');

				if (key == '2')
					break;

			}
			else if (movement == 3)
			{
				continue;
			}


			int res = cg.PROCESS();
			if (res == 1)
			{
				
				bool isPlay = PlaySound(L"car_crash.wav", NULL, SND_FILENAME);
				cg.DeadEffect();
				if (cg.LoseGame() == 1)
				{
					PlayAgain = true;
					continue;
				}
				break;
			}
			else if (res == 2)
			{
				cg.NextLevel();
				continue;
			}
			else if (res == 3)
			{
				bool isPlay = PlaySound(L"applause_y.wav", NULL, SND_FILENAME);
				if (cg.WinGame() == 1)
				{
					PlayAgain = true;
					continue;
				}
				break;
			}

		}
	}

	return 0;
}