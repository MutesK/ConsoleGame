#include "GameScene.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"


CGameScene::CGameScene()
{
	player = new CPlayer(30,20, ".|.", this);

	int StartX = 10;
	int StartY = 1;

	int IncrementX = 4;
	int IncrementY = 4;

	int i = 0;
	while (i < 30)
	{
		for (int j = 0; j < 10; j++)
		{
			CreateEnemy(StartX, StartY, "|=|");
			StartX += IncrementX;
			i++;
		}

		StartY += IncrementY;
		StartX = 10;
	}


}


CGameScene::~CGameScene()
{
	delete player;
}


bool CGameScene::Run()
{
	Action();
	CollisionProcess();

	if (GameOverCheck())
	{
		this->LoadScene(CGAMEOVERSCENE);
		return true;
	}
	Draw();

	return false;
}

void CGameScene::CreateBullet(int _x, int _y, int type)
{
	CBullet *cb = new CBullet(_x, _y, type, this);
	ObjectList.push_back(cb);
}

void CGameScene::CreateEnemy(int x, int y, char* sprite)
{
	CEnemy *ce = new CEnemy(x, y, sprite, this);
	ObjectList.push_back(ce);
}

CBaseObject* CGameScene::CollisionCheck(int x, int y)
{
	// 먼저 Player 검사
	if (player->getY() == y)
	{
		// x는 0,1,2 
		int Px = player->getX();
		if (Px ==  x ||Px == (x - 1) || Px == (x - 2) || Px == (x - 3))
		{
			return player;
		}
	}

	CList<CBaseObject *>::iterator iter;
	for (iter = ObjectList.begin(); iter != ObjectList.end(); iter++)
	{
		if ((*iter)->getType() == (*iter)->e_ENEMY)
		{

			if ((*iter)->getY() == y)
			{
				int Ex = (*iter)->getX();
				if (Ex == x || Ex ==  (x - 1) || Ex == (x - 2) || Ex == (x - 3))
				{
					return (*iter);
				}
			}
		}
	}
	return nullptr;
}
bool CGameScene::GameOverCheck()
{
	CList<CBaseObject *>::iterator iter;

	if (player->getHp() <= 0)
	{
		return true;
	}


	for (iter = ObjectList.begin(); iter != ObjectList.end(); iter++)
	{
		if ((*iter)->getType() == (*iter)->e_ENEMY)
		{
			return false;
		}
	}
	return true;
}


void CGameScene::Action()
{
	CList<CBaseObject *>::iterator iter;

	player->Action();
	for (iter = ObjectList.begin(); iter != ObjectList.end(); iter++)
	{
		(*iter)->Action();
	}
}
void CGameScene::CollisionProcess()
{
	CList<CBaseObject *>::iterator iter;

	if (player->dieFlag)
	{
		int hp = player->getHp();
		player->setHp(hp - 1);
		player->dieFlag = false;
	}
	for (iter = ObjectList.begin(); iter != ObjectList.end(); iter++)
	{
		if ((*iter)->dieFlag)
		{
			iter = ObjectList.erase(iter);
			--iter;
		}
	}
}
void CGameScene::Draw()
{
	CList<CBaseObject *>::iterator iter;

	for (iter = ObjectList.begin(); iter != ObjectList.end(); iter++)
	{
		(*iter)->Draw();
	}

	player->Draw();
	Hp_Draw(0, dfSCREEN_HEIGHT - 1, player->getHp());

}