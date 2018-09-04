#pragma once

/*�궨��*/
/*��ͼ�ߴ�*/
# define WIDTH 50
# define HEIGHT 50
/*��ͼԪ��*/
# define WALL 1
# define BODY 2
# define FOOD 3
# define SPACE 0
/*��������*/
# define UP 72
# define DOWN 80
# define LEFT 75
# define RIGHT 77
# define ESC 27
# define ENTER 13
/*�¼�*/
#define STARTGAME 1001
#define VIEWHELP  1002
#define VIEWABOUT 1003
#define EXIT      1004
#define RESUME    1005
#define HITWALL   1006
#define HITBODY   1007

/*���ݽṹ����*/
/*λ��*/
typedef struct Pos
{
	int x;
	int y;
}POS;
/*��ͼ*/
typedef struct Map
{
    int m[WIDTH][HEIGHT];
    int width;
    int height;
}MAP;
/*����ڵ�*/
typedef struct Node
{
	POS pos;
	struct Node * pNext;
}NODE, *PNODE;
/*��*/
typedef struct Snake
{
	PNODE pHead;
	int length;
}SNAKE, *PSNAKE;
/*��Ϸ*/
typedef struct Game
{
    int IsRun;
    int score;
}GAME;
