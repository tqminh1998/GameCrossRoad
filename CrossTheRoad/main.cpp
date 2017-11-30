#include "CGAME.h"
#include <ctime>
#include <cstdlib>

int main()
{
	srand(time(NULL));
	CONSOLE cs;
	CGAME cg;


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
			cout << "HELLO WORLD";
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

		}
	}

	return 0;
}