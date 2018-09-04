#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "def.h"
#include "console.h"
#include "inf.h"

void PrintMenu1(int w, int h, POS * p)
{
    //清屏
	system("cls");

	//确定坐标
	int xL1 = (w / 2 - 11) / 2;
	int yL1 = (h - 9) / 2;
	int xL2 = (w / 2 - 3) / 2;
	int yL2 = yL1 + 2;
	int xL3 = xL1;
	int yL3 = yL2 + 1;

	MoveCursor(xL2 - 1, yL2 - 1);
	printf("Greedy Snake");
	MoveCursor(xL3, yL3 - 1);
	printf("╔══════════╗");
	MoveCursor(xL3, yL3 + 0);
	printf("╬     Start Game     ╬");
	MoveCursor(xL3, yL3 + 1);
	printf("╬     View Help      ╬");
	MoveCursor(xL3, yL3 + 2);
	printf("╬     View About     ╬");
	MoveCursor(xL3, yL3 + 3);
	printf("╬     Quit           ╬");
	MoveCursor(xL3, yL3 + 4);
	printf("╚══════════╝");

	if (p != NULL)
    {
        p->x = xL3 + 3 - 1;
        p->y = yL3 + 1 - 1;
    }

    return;
}

void PrintMenu2(int w, int h, POS * p)
{
//清屏
	system("cls");

	//计算坐标
	int x = (w / 2 - 11) / 2;
	int y = (h - 5) / 2;

	//打印
	MoveCursor(x, y);
	printf("╔══════════╗");
	MoveCursor(x, y + 1);
	printf("╬      Resume        ╬");
	MoveCursor(x, y + 2);
	printf("╬      View Help     ╬");
	MoveCursor(x, y + 3);
	printf("╬      Exit          ╬");
	MoveCursor(x, y + 4);
	printf("╚══════════╝");

	if (p != NULL)
    {
        p->x = x + 3;
        p->y = y + 1;
    }

    return;
}

void PrintMenu3(int w, int h, POS * p)
{
    int x = (w / 2 - 8) / 2;
	int y = (h - 5) / 2 - 1;

	MoveCursor(x, y);
	printf("Do you want to quit?");
	MoveCursor((w / 2 - 13) / 2, y + 1);
	printf("╔═════════════╗");
	MoveCursor((w / 2 - 13) / 2, y + 2);
	printf("╬     Yes,I want to quit.  ╬");
	MoveCursor((w / 2 - 13) / 2, y + 3);
	printf("╬     No,I want to assume. ╬");
	MoveCursor((w / 2 - 13) / 2, y + 4);
	printf("╚═════════════╝");

	if (p != NULL)
    {
        p->x = (w / 2 - 13) / 2 + 2;
        p->y = y + 2;
    }

    return;
}



int Menu1Logic(int w, int h, int index)
{
    //清屏
	system("cls");

	POS p;
	PrintMenu1(w, h, &p);

	//绘制菱形
	MoveCursor(p.x, p.y + index - STARTGAME);
	printf("◆");

	int y1 = p.y + index - STARTGAME;
	char ch;
	while (1)
	{
        ch = _getch();
        switch (ch)
        {
        case UP:
            MoveCursor(p.x, y1);
            printf(" ");
            y1 = max(y1 - 1, p.y);
            break;
        case DOWN:
            MoveCursor(p.x, y1);
            printf(" ");
            y1 = min(y1 + 1, p.y + 3);
            break;
        case ENTER:
            if (y1 == p.y)
                return STARTGAME;
            else if (y1 == p.y + 1)
                return VIEWHELP;
            else if (y1 == p.y + 2)
                return VIEWABOUT;
            else
                return EXIT;
            break;
        default:
            break;
        }
        MoveCursor(p.x, y1);
        printf("◆");
	}
}

int Menu2Logic(int w, int h, int index)
{
    //清屏
	system("cls");

	POS p;
	PrintMenu2(w, h, &p);
	int y1 = p.y;

	switch (index)
	{
    case RESUME:
        y1 += 0;
        break;
    case VIEWHELP:
        y1 += 1;
        break;
    case EXIT:
        y1 += 2;
        break;
    default:
        break;
	}

    //绘制菱形
	MoveCursor(p.x, y1);
	printf("◆");

	char ch;
	while (1)
    {
        fflush(stdin);
        ch = _getch();
        switch (ch)
        {
        case UP:
            MoveCursor(p.x, y1);
            printf(" ");
            y1 = max(y1 - 1, p.y);
            break;
        case DOWN:
            MoveCursor(p.x, y1);
            printf(" ");
            y1 = min(y1 + 1, p.y + 2);
            break;
        case ENTER:
            if (y1 == p.y)
                return RESUME;
            else if (y1 == p.y + 1)
                return VIEWHELP;
            else
                return EXIT;
            break;
        default:
            break;
        }
        MoveCursor(p.x, y1);
        printf("◆");
    }
}

int Menu3Logic(int w, int h)
{
    //清屏
	system("cls");

	POS p;
	PrintMenu3(w, h, &p);

    //绘制菱形
	MoveCursor(p.x, p.y);
	printf("◆");

	int y1 = p.y;
	char ch;
	while (1)
    {
        ch = _getch();
        switch (ch)
        {
        case UP:
            MoveCursor(p.x, y1);
            printf(" ");
            y1 = max(y1 - 1, p.y);
            break;
        case DOWN:
            MoveCursor(p.x, y1);
            printf(" ");
            y1 = min(y1 + 1, p.y + 1);
            break;
        case ENTER:
            if (y1 == p.y)
                return EXIT;
            else
                return RESUME;
            break;
        }
        MoveCursor(p.x, y1);
        printf("◆");
    }
}
