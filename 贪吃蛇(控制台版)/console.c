#include <stdio.h>
#include <windows.h>

void HideCursor(void)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(hOut, &cursor_info);
}

void MoveCursor(int x, int y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 2 * x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);
}

void SetConsole(const char * title, int width, int height)
{
	char buffer[1024];

	//设置标题
	sprintf_s(buffer, "title %s", "贪吃蛇(控制台版)");
	system(buffer);

	//设置尺寸
	sprintf_s(buffer, "mode con cols=%d", width);
	system(buffer);
	sprintf_s(buffer, "mode con lines=%d", height);
	system(buffer);
}

