#pragma once

#include "List.h"

class CBaseObject;

class CScene
{
protected:
	CList <CBaseObject *> ObjectList;
public:
	virtual bool Run() = 0;
	void LoadScene(int SceneType);

	CScene();
	virtual ~CScene();
};

