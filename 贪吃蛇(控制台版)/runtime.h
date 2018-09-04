#pragma once

#include "def.h"

void GetHeadPos(SNAKE s, POS * p);
void GetTailPos(SNAKE s, POS * p);
void AddHead(PSNAKE pSnake, char direction);
void EraseTail(PSNAKE pSnake, MAP * map);

void GoUp(PSNAKE pSnake, MAP * map);
void GoDown(PSNAKE pSnake, MAP * map);
void GoLeft(PSNAKE pSnake, MAP * map);
void GoRight(PSNAKE pSnake, MAP * map);

void MakeFood(POS * food, MAP * map);
