#pragma once
#include "BaseObject.h"

class CGameScene;

class CEnemy : public CBaseObject
{
protected:
	CGameScene *pScene;
	char m_sprite[3];

	int point_X;
	int move_X;
	int direction;
public:
	CEnemy(int _x, int _y, char* sprite, CGameScene *pObj);
	virtual ~CEnemy();

	virtual bool Action();
	virtual void Draw();
};

