#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "def.h"
#include "console.h"
#include "init.h"
#include "judge.h"
#include "runtime.h"
#include "exit.h"
#include "menu.h"
#include "inf.h"
#include "prompt.h"

int GameLogic(MAP * map, GAME * g)
{
    /*游戏相关变量*/
    SNAKE s;
    POS food;
    int FoodStatus = 0;
    int speed = 1;
    int ScoreAdd = 30;
    int SpeedAdd = 20;
    int BeginSpeed = 200;
    int ScoreAddCond = 15;
    POS t;

    char direction = UP;
    char ch;
    int ret;

	/*初始化工作*/
    g->IsRun = 1;
    g->score = 0;
    InitMap(map, 34, 34);
    InitSnake(&s, 3, map);

     /*清屏*/
	system("cls");

	DrawMap(*map);

    /*打印提示信息*/
    MoveCursor(35, (map->width - 5) / 2 - 1);
    printf("Length:");
    PrintSnakeLength(s.length, map->width);
    MoveCursor(35, (map->width - 5) / 2);
    printf("Score:");
    PrintScore(g->score, map->width);
    MoveCursor(35, (map->width - 5) / 2 + 1);
    printf("Speed:");
    PrintSpeed(speed, map->width);
    MoveCursor(35, (map->width - 5) / 2 + 3);
    printf("Use ↑ ↓ ← → to control the snake.");

	/*游戏主循环*/
	while (1)
    {
        /*如果没有食物，先造一个食物*/
		if (!FoodStatus)
		{
			MakeFood(&food, map);
			FoodStatus = 1;
		}

		/*如果有按键按下，根据按键改变当前方向*/
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
			case UP:
				//判断所按的键是否与当前方向相反
				if (direction != DOWN)
				{
					direction = UP;
					break;
				}
				break;
			case DOWN:
				if (direction != UP)
				{
					direction = DOWN;
					break;
				}
				break;
			case LEFT:
				if (direction != RIGHT)
				{
					direction = LEFT;
					break;
				}
				break;
			case RIGHT:
				if (direction != LEFT)
				{
					direction = RIGHT;
					break;
				}
				break;
			case ESC:
			    ret = Menu2Logic(113, 35, RESUME);
				while (ret != RESUME)
                {
                    switch (ret)
                    {
                    case RESUME:
                        break;
                    case VIEWHELP:
                        ViewHelp();
                        break;
                    case EXIT:
                        ret = Menu3Logic(113, 35);
                        while (ret != RESUME)
                        {
                            switch (ret)
                            {
                            case RESUME:
                                break;
                            case EXIT:
                                ExitGame(s);
                                return EXIT;
                            }
                            ret = Menu3Logic(113, 35);
                        }
                        ret = EXIT;
                        break;
                    }

                    ret = Menu2Logic(113, 35, ret);
                }

                /*返回游戏*/
                system("cls");
                DrawMap(*map);
                /*打印提示信息*/
               MoveCursor(35, (map->width - 5) / 2 - 1);
                printf("Length:");
                PrintSnakeLength(s.length, map->width);
                MoveCursor(35, (map->width - 5) / 2);
                printf("Score:");
                PrintScore(g->score, map->width);
                MoveCursor(35, (map->width - 5) / 2 + 1);
                printf("Speed:");
                PrintSpeed(speed, map->width);
                MoveCursor(35, (map->width - 5) / 2 + 3);
                printf("Use ↑ ↓ ← → to control the snake.");
			default:
				//如果按下其它键，则依照当前方向继续移动
				ch = direction;
				break;
			}
		}

		/*如果没有按键，则依照当前方向移动*/
		else
		{
			switch (direction)
			{
			case UP:
				GoUp(&s, map);
				break;
			case DOWN:
				GoDown(&s, map);
				break;
			case LEFT:
				GoLeft(&s, map);
				break;
			case RIGHT:
				GoRight(&s, map);
				break;
			}
			if (IsHitWall(s, map))
			{
				ExitGame(s);
				return HITWALL;
			}

			if (IsHitBody(s, map))
            {
                ExitGame(s);
				return HITBODY;
            }
			//如果吃到食物
			if (IsEatFood(s, map))
			{
				//蛇尾添一节
				PNODE p = s.pHead;
				while (p->pNext != NULL)
					p = p->pNext;
				PNODE pN = (PNODE)malloc(sizeof(NODE));
				pN->pos = p->pos;
				pN->pNext = NULL;
				p->pNext = pN;
				//长度增加
				s.length++;
				//打印长度
				PrintSnakeLength(s.length, map->width);
				//得分增加
				g->score += ScoreAdd;
				//打印得分
				PrintScore(g->score, map->width);
				//食物状态标记为false
				FoodStatus = 0;
				//判断是否加速
				if (IsAddSpeed(s, ScoreAddCond, speed))
				{
					speed += 1;
					//打印速度
					PrintSpeed(speed, map->width);
				}
			}
			GetHeadPos(s, &t);
			map->m[t.y][t.x] = BODY;
			MoveCursor(t.x, t.y);
			printf("●");
			Sleep(BeginSpeed + SpeedAdd - SpeedAdd * speed);
		}
    }

    return EXIT;
}
