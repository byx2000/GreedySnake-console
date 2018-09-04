#pragma once

/*宏定义*/
/*地图尺寸*/
# define WIDTH 50
# define HEIGHT 50
/*地图元素*/
# define WALL 1
# define BODY 2
# define FOOD 3
# define SPACE 0
/*按键代码*/
# define UP 72
# define DOWN 80
# define LEFT 75
# define RIGHT 77
# define ESC 27
# define ENTER 13
/*事件*/
#define STARTGAME 1001
#define VIEWHELP  1002
#define VIEWABOUT 1003
#define EXIT      1004
#define RESUME    1005
#define HITWALL   1006
#define HITBODY   1007

/*数据结构定义*/
/*位置*/
typedef struct Pos
{
	int x;
	int y;
}POS;
/*地图*/
typedef struct Map
{
    int m[WIDTH][HEIGHT];
    int width;
    int height;
}MAP;
/*蛇身节点*/
typedef struct Node
{
	POS pos;
	struct Node * pNext;
}NODE, *PNODE;
/*蛇*/
typedef struct Snake
{
	PNODE pHead;
	int length;
}SNAKE, *PSNAKE;
/*游戏*/
typedef struct Game
{
    int IsRun;
    int score;
}GAME;
