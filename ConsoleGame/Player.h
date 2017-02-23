#pragma once

#include "BaseObject.h"


class CGameScene;

class CPlayer : public CBaseObject
{
protected:
	char m_sprite[3];
	CGameScene *m_pScene;
	int hp;
public:
	CPlayer(int x, int y, char* Sprite, CGameScene *pScene);

	virtual ~CPlayer();
	virtual bool Action();
	virtual void Draw();
	int getHp()
	{
		return hp;
	}
	
	void setHp(int h)
	{
		hp = h;
	}

	void KeyPressed();
};

