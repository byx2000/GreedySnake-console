#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include "def.h"
#include "console.h"

void GetHeadPos(SNAKE s, POS * p)
{
    p->x = s.pHead->pos.x;
    p->y = s.pHead->pos.y;

    return;
}

void GetTailPos(SNAKE s, POS * p)
{
    PNODE pN = s.pHead;
	while (pN->pNext != NULL)
	{
		pN = pN->pNext;
	}

	p->x = pN->pos.x;
	p->y = pN->pos.y;

	return;
}

void AddHead(PSNAKE pSnake, char direction)
{
    POS pt;
    int x, y;

    GetHeadPos(*pSnake, &pt);
    PNODE pN = (PNODE)malloc(sizeof(NODE));

    switch (direction)
	{
	case UP:
		x = pt.x;
		y = pt.y - 1;
		break;
	case DOWN:
		x = pt.x;
		y = pt.y + 1;
		break;
	case LEFT:
		x = pt.x - 1;
		y = pt.y;
		break;
	case RIGHT:
		x = pt.x + 1;
		y = pt.y;
		break;
	}

	//新的蛇头
	pN->pNext = pSnake->pHead;
	//pN->pos = { x, y };
	pN->pos.x = x;
	pN->pos.y = y;
	pSnake->pHead = pN;

	return;
}

void EraseTail(PSNAKE pSnake, MAP * map)
{
    POS pt;
    PNODE pN = pSnake->pHead;

    //获取蛇尾坐标
	GetTailPos(*pSnake, &pt);

    //让pN指向倒数第二个节点
	while (pN->pNext->pNext != NULL)
	{
		pN = pN->pNext;
	}
	//释放内存
	free(pN->pNext);
	//新的蛇尾
	pN->pNext = NULL;
	//擦去蛇尾
	MoveCursor(pt.x, pt.y);
	printf(" ");
	//更新地图
	map->m[pt.y][pt.x] = SPACE;

	return;
}


void GoUp(PSNAKE pSnake, MAP * map)
{
    //增加蛇头
	AddHead(pSnake, UP);
	//擦去蛇尾
	EraseTail(pSnake, map);

	return;
}

void GoDown(PSNAKE pSnake, MAP * map)
{
    //增加蛇头
	AddHead(pSnake, DOWN);
	//擦去蛇尾
	EraseTail(pSnake, map);

	return;
}

void GoLeft(PSNAKE pSnake, MAP * map)
{
    //增加蛇头
	AddHead(pSnake, LEFT);
	//擦去蛇尾
	EraseTail(pSnake, map);

	return;
}

void GoRight(PSNAKE pSnake, MAP * map)
{
    //增加蛇头
	AddHead(pSnake, RIGHT);
	//擦去蛇尾
	EraseTail(pSnake, map);

	return;
}

void MakeFood(POS * food, MAP * map)
{
    //随机生成一个坐标
	srand((unsigned int)time(NULL));
	food->x = rand() % (map->width - 2) + 1;
	food->y = rand() % (map->height - 2) + 1;

	//防止食物生成在蛇身上或墙上
	while (map->m[food->y][food->x] == BODY || map->m[food->y][food->x] == WALL)
	{
		food->x = rand() % (map->width - 2) + 1;
		food->y = rand() % (map->height - 2) + 1;
	}

	//更新地图
	map->m[food->y][food->x] = FOOD;

	//绘制食物
	MoveCursor(food->x, food->y);
	printf("⊕");

	return;
}
