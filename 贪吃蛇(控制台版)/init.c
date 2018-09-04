#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "def.h"
#include "console.h"

void InitMap(MAP * map, int w, int h)
{
    int i, j;

    memset(map, 0, sizeof(MAP));
    map->width = w;
    map->height = h;

	for (i = 0; i < h; ++i)
	{
		for (j = 0; j < w; ++j)
		{
			if ((i == 0) | (i == h - 1) | (j == 0) | (j == w - 1))
				map->m[i][j] = WALL;
			else
				map->m[i][j] = SPACE;
		}
	}

	return;
}

void InitSnake(PSNAKE pSnake, int len, MAP * map)
{
    /*构造蛇头节点*/
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	pHead->pos.x = (map->width - 1) / 2;
	pHead->pos.y = (map->height - len) / 2;
	pHead->pNext = NULL;
	map->m[(map->height - len) / 2][(map->width - 1) / 2] = BODY;
	pSnake->pHead = pHead;

	/*构造剩下的(len-1)个节点*/
	int i, x, y;
	PNODE p = pHead;
	for (i = 0; i < len - 1; ++i)
	{
		PNODE pBody = (PNODE)malloc(sizeof(NODE));
		x = p->pos.x;
		y = p->pos.y + 1;
		pBody->pos.x = x;
		pBody->pos.y = y;
		pBody->pNext = NULL;
		map->m[y][x] = BODY;
		p->pNext = pBody;
		p = p->pNext;
	}
	pSnake->length = len;
	return;
}

void DrawMap(MAP map)
{
int i, j;
	for (i = 0; i < map.height; ++i)
	{
		for (j = 0; j < map.width; ++j)
		{
            MoveCursor(j, i);
            switch (map.m[i][j])
            {
            case WALL:
				printf("■");
                break;
            case BODY:
                printf("●");
                break;
            case FOOD:
                printf("⊕");
                break;
            default:
                printf(" ");
                break;
            }
		}
		printf("\n");
	}
	return;
}

