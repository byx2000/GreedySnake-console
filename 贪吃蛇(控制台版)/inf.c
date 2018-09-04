#include <stdio.h>
#include <windows.h>
#include <conio.h>

void ViewHelp(void)
{
    system("cls");

    printf("Introduction:\n");
	printf("With the direction key,you need to control the snake to eat food.Attention not to hit wall or snake body.\n\n");
	printf("GamePlay:\n");
	printf("Use four direction key on the keyboard.\n\n");
	printf("Notice:\n");
	printf("Remember to turn off your input method before the game begins.\n\n");
	printf("\n");


    fflush(stdin);
	printf("Press ENTER to back...");
	getchar();
	//fflush(stdin);

	return;
}

void ViewAbout(void)
{
    system("cls");

	printf("GreedySnake(Console)\n");

    fflush(stdin);
	printf("Press ENTER to back...");
	getchar();

	return;
}
