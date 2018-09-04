#include "def.h"
#include "runtime.h"

int IsHitWall(SNAKE s, MAP * map)
{
	POS pt;
	int x;
	int y;

	//获取蛇头坐标
	GetHeadPos(s, &pt);
	x = pt.x;
	y = pt.y;

	//根据蛇头坐标来判断是否撞墙
	if (map->m[y][x] == WALL)
		return 1;
	else
		return 0;
}

int IsHitBody(SNAKE s, MAP * map)
{
    POS pt;
	int x;
	int y;

	//获取蛇头坐标
	GetHeadPos(s, &pt);
	x = pt.x;
	y = pt.y;

	//根据蛇头坐标来判断是否撞到身体
	if (map->m[y][x] == BODY)
		return 1;
	else
		return 0;
}

int IsEatFood(SNAKE s, MAP * map)
{
    POS pt;
	int x;
	int y;

	//获取蛇头坐标
	GetHeadPos(s, &pt);
	x = pt.x;
	y = pt.y;

	//根据蛇头坐标来判断是否吃到食物
	if (map->m[y][x] == FOOD)
		return 1;
	else
		return 0;
}

int IsAddSpeed(SNAKE s, int ScoreAddCond, int speed)
{
    if ((s.length % ScoreAddCond == 0) && (speed <= 10))
		return 1;
	else
		return 0;
}
