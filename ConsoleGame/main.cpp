#include <iostream>
#include <conio.h>
#include "Console.h"
#include "GameScene.h"

int main()
{
	cs_Initial();

	CScene *scene = new CGameScene;
	
	while (1)
	{
		cs_BufferClear();
		scene->Run();
		Flip();
		Sleep(50);
	}

	
	cs_ClearScreen();

	return 0;
}