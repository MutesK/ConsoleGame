#include "Enemy.h"
#include "GameScene.h"
#include "Console.h"


CEnemy::CEnemy(int _x, int _y, char* sprite, CGameScene *pObj)
	:CBaseObject(_x, _y, e_ENEMY), pScene(pObj)
{
	point_X = _x;
	move_X = 6;
	direction = 1;

	memcpy_s(m_sprite, 3, sprite, 3);
}

CEnemy::~CEnemy()
{
}


bool CEnemy::Action()
{
	// 1. 이동, 2. 미사일 발포
	if ((rand() % 10000 + 1) < 100)
	{
		// 미사일 발포
		pScene->CreateBullet(m_X, m_Y, e_BULLET_E);
	}


	if (direction == 1)
		m_X++;
	else
		m_X--;

	// 이동
	if (point_X - m_X == move_X)
	{
		direction = 1;
	}
	else if(point_X - m_X == -move_X)
	{
		direction = -1;
	}

	return true;

}
void CEnemy::Draw()
{
	// 버퍼에 넣는다.
	Sprite_Draw(m_X, m_Y, m_sprite[0]);
	Sprite_Draw(m_X + 1, m_Y, m_sprite[1]);
	Sprite_Draw(m_X + 2, m_Y, m_sprite[2]);
}