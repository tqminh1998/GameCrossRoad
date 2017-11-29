#include "CGAME.h"
#include <ctime>
#include <cstdlib>

int main()
{
	srand(time(NULL));
	CONSOLE cs;
	CGAME cg;
	cg.SetGame();

	while (1)
	{
		cs.gotoXY(0, 0);
		cs.Nocursortype();

		
		cg.DISPLAY();
		cg.MOVEMENT();
	}

	return 0;
}