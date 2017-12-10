#pragma once
#include <Windows.h>
using namespace std;

class CONSOLE {
public:

	void Nocursortype()
	{
		CONSOLE_CURSOR_INFO Info;
		Info.bVisible = FALSE;
		Info.dwSize = 20;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
	}

	void clrscr()
	{
		CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
		HANDLE	hConsoleOut;
		COORD	Home = { 0, 0 };
		DWORD	dummy;

		hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

		FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
		csbiInfo.dwCursorPosition.X = 0;
		csbiInfo.dwCursorPosition.Y = 0;
		SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
	}

	void gotoXY(int column, int line)
	{
		COORD coord;
		coord.X = column;
		coord.Y = line;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

	void FixConsoleWindow()
	{
		HWND consoleWindow = GetConsoleWindow();
		LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
		style = style & ~(WS_MAXIMIZEBOX)& ~(WS_THICKFRAME);
		SetWindowLong(consoleWindow, GWL_STYLE, style);
		RECT r;
		GetWindowRect(consoleWindow, &r);
		MoveWindow(consoleWindow, r.left, r.top, 1000, 800, TRUE);
	}

	void TextColor(int color)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}

};
