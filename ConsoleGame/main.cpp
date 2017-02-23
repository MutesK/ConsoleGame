#include <iostream>
#include <conio.h>
#include "Console.h"
#include "GameScene.h"

int main()
{
	cs_Initial();

	CScene *scene = new CGameScene();
	while (1)
	{
		cs_BufferClear();
		if (scene->Run())
		{
			cs_MoveCursor(dfSCREEN_WIDTH / 2, dfSCREEN_HEIGHT / 2);
			printf("Game Over !! \n");
			return 0;
		}
		Flip();
		Sleep(50);
	}

	
	cs_ClearScreen();

	return 0;
}