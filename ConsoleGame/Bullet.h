#pragma once

#include "BaseObject.h"

class CGameScene;

class CBullet : public CBaseObject
{
protected:
	CGameScene *pScene;
public:
	CBullet(int _x, int _y, int _type, CGameScene* pScene);
	virtual ~CBullet();

	virtual bool Action();
	virtual void Draw();


};

