#pragma once

#include "def.h"

int IsHitWall(SNAKE s, MAP * map);
int IsHitBody(SNAKE s, MAP * map);int IsEatFood(SNAKE s, MAP * map);
int IsAddSpeed(SNAKE s, int ScoreAddCond, int speed);
