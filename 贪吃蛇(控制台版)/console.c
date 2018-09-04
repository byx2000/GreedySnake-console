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

	//���ñ���
	sprintf_s(buffer, "title %s", "̰����(����̨��)");
	system(buffer);

	//���óߴ�
	sprintf_s(buffer, "mode con cols=%d", width);
	system(buffer);
	sprintf_s(buffer, "mode con lines=%d", height);
	system(buffer);
}

