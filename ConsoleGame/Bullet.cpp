#include <iostream>
#include "Bullet.h"
#include "GameScene.h"
#include "Enemy.h"
using namespace std;


CBullet::CBullet(int _x, int _y, int _type, CGameScene* p_Scene)
	:CBaseObject(_x, _y, _type), pScene(p_Scene)
{
	dieFlag = false;
}


CBullet::~CBullet()
{
}

bool CBullet::Action()
{
	// 충돌 처리
	CBaseObject *pObj = pScene->CollisionCheck(m_X, m_Y);
	
	// Player -> Enemy
	// Enemy -> Player 일때만 작동
	if (pObj != nullptr)
	{
		if (pObj->getType() == e_ENEMY && this->m_Object_Type == e_BULLET_P)
		{
			pObj->dieFlag = true;
			// Player가 쏜 탄약에 적이 맞았다면.
			dieFlag = true;
			return false;
		}
		else if (pObj->getType() == e_PLAYER && this->m_Object_Type == e_BULLET_E)
		{
			// 게임 종료 시점
			pObj->dieFlag = true;
			dieFlag = true;

			return false;
		}
	}
	if ((m_X < 0 || m_X > dfSCREEN_WIDTH) ||
			(m_Y < 0 || m_Y > dfSCREEN_HEIGHT))
	{
		dieFlag = true;
		return false;
	}
	

	
	// 타입에 따라 탄약 움직임
	switch (m_Object_Type)
	{
	case e_BULLET_P:
		m_Y--;
		break;
	case e_BULLET_E:
		m_Y++;
		break;
	}
	return true;
}
void CBullet::Draw()
{
	switch (m_Object_Type)
	{
	case e_BULLET_P:
		Sprite_Draw(m_X, m_Y, '^');
		break;
	case e_BULLET_E:
		Sprite_Draw(m_X, m_Y, 'V');
		break;
	}
}