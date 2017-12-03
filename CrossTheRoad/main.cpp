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
	CGAME cg;

	thread task(CueMusic);
	task.detach();
	
	while (1)
	{
		cs.clrscr();
		cs.Nocursortype();
		int choose = cg.StartGame();
		
		switch (choose)
		{
		case 1:
			cg.NewGame();
			break;
		case 3:
			return 0;
			break;
		case 2:
			cs.clrscr();
			cs.gotoXY(10, 5);
			cout << "HELLO, IT'S ME";
			Sleep(1000);
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
			if (cg.MOVEMENT() == 1)
				break;

			int res = cg.PROCESS();
			if (res == 1)
			{
				bool isPlay = PlaySound(L"car_crash.wav", NULL, SND_FILENAME);
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