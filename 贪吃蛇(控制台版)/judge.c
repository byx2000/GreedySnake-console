#include "def.h"
#include "runtime.h"

int IsHitWall(SNAKE s, MAP * map)
{
	POS pt;
	int x;
	int y;

	//��ȡ��ͷ����
	GetHeadPos(s, &pt);
	x = pt.x;
	y = pt.y;

	//������ͷ�������ж��Ƿ�ײǽ
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

	//��ȡ��ͷ����
	GetHeadPos(s, &pt);
	x = pt.x;
	y = pt.y;

	//������ͷ�������ж��Ƿ�ײ������
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

	//��ȡ��ͷ����
	GetHeadPos(s, &pt);
	x = pt.x;
	y = pt.y;

	//������ͷ�������ж��Ƿ�Ե�ʳ��
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
