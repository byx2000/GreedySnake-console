/*包含头文件*/
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <malloc.h>
#include <time.h>
#include "debug.h"
#include "def.h"
#include "console.h"
#include "init.h"
#include "runtime.h"
#include "judge.h"
#include "menu.h"
#include "logic.h"
#include "exit.h"
#include "inf.h"
#include "prompt.h"

/*全局变量*/
/*游戏元素*/
MAP map;    //地图
SNAKE s;    //蛇
GAME g;     //游戏

int main()
{
	//char* title = "Greedy Snake";
    //SetConsole(title, 113, 35);
	system("title GreedySnake");
	system("mode con cols=113");
	system("mode con lines=35");
    HideCursor();

    HWND hConsole = FindWindowA("ConsoleWindowClass", "Greedy Snake");
    SetWindowPos(hConsole, HWND_TOP, 0, 0, 0, 0, SWP_NOSIZE);

    int ret;

    ret = STARTGAME;
    while (ret != EXIT)
    {
        ret = Menu1Logic(113, 35, ret);

        switch (ret)
        {
        case STARTGAME:
            ret = GameLogic(&map, &g);

            system("cls");
            printf("Your score is:\t%d\n", g.score);
            MessageBeep(MB_ICONERROR);
            printf("\n");

            switch (ret)
            {
            case HITWALL:
                printf("You hit the wall!\n\n");
                break;
            case HITBODY:
                printf("You hit the snake's body!\n\n");
                break;
            case EXIT:
                printf("You have exited the game.\n\n");
                break;
            }
            ret = STARTGAME;

            fflush(stdin);
            printf("Press ENTER to back...");
            getchar();
            break;
        case VIEWHELP:
            ViewHelp();
            break;
        case VIEWABOUT:
            ViewAbout();
            break;
        case EXIT:
            break;
        default:
            break;
        }
    }

    //PrintMenu2(113, 35, NULL);
    //Menu2Logic(113, 35);
    //PrintMenu3(113, 35, NULL);
    //Menu3Logic(113, 35);
    //getchar();

    return 0;
}
