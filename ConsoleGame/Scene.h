#pragma once

#include "List.h"

class CBaseObject;

class CGameScene;
class CGameOverScene;

class CScene
{
protected:
	CList <CBaseObject *> ObjectList;

	enum
	{
		CGAMESCENE = 1,
		CGAMEOVERSCENE = 2,
	};
public:
	virtual bool Run() = 0;
	void LoadScene(int SceneType);

	CScene();
	virtual ~CScene();
};

