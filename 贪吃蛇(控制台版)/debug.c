#include <stdio.h>
#include "def.h"

void PrintArray(int a[HEIGHT][WIDTH], int w, int h)
{
    int i, j;
    for (i = 0; i < h; ++i)
    {
        for (j = 0; j < w; ++j)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return;
}
