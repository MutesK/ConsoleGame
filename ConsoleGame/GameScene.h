#pragma once

#include "Scene.h"
#include "Console.h"

class CPlayer;
class CBullet;
class CEnemy;

class CGameScene : public CScene
{
protected: 
	CPlayer * player;
public:
	CGameScene();
	virtual ~CGameScene();

	virtual bool Run();

	CBaseObject* CollisionCheck(int x, int y);
	void CreateEnemy(int x, int y, char* sprite);
	void CreateBullet(int _x, int _y, int type);

	bool GameOverCheck();

	void Action();
	void CollisionProcess();
	void Draw();


};

