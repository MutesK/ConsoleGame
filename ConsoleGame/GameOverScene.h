#pragma once

#include "Scene.h"
#include "Console.h"
#include <iostream>

class CGameOverScene : public CScene
{
public:
	virtual bool Run()
	{
		Message_Draw(dfSCREEN_WIDTH / 2, dfSCREEN_HEIGHT / 2, "Game Over !!");
		return true;
	}
};

