#include <stdio.h>
#include "console.h"

void PrintSnakeLength(int len, int w)
{
    int x = w + 6;
	int y = (w - 5) / 2 - 1;

	MoveCursor(x, y);
	printf("%d", len);

	return;
}

void PrintScore(int score, int w)
{
    int x = w + 6;
	int y = (w - 5) / 2;

	MoveCursor(x, y);
	printf("%d", score);

	return;
}

void PrintSpeed(int speed, int w)
{
	int x = w + 6;
	int y = (w - 5) / 2 + 1;

	MoveCursor(x, y);
	printf("%d", speed);

	return;
}
