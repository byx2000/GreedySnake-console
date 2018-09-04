#include <stdio.h>
#include <malloc.h>
#include "def.h"

void ExitGame(SNAKE s)
{
    //ÊÍ·ÅÄÚ´æ
	PNODE p1 = s.pHead;
	PNODE p2;

	while (p1 != NULL)
	{
		p2 = p1->pNext;
		free(p1);
		p1 = p2;
	}
	s.pHead = NULL;

	return;
}
