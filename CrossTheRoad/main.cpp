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
		cg.SetGame();
		int choose = cg.StartGame();

		
		if (choose == 1)
		{
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
		else if (choose == 3)
			break;
		else if (choose == 4)
		{

		}
	}

	return 0;
}