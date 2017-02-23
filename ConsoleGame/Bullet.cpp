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
	// �浹 ó��
	CBaseObject *pObj = pScene->CollisionCheck(m_X, m_Y);
	
	// Player -> Enemy
	// Enemy -> Player �϶��� �۵�
	if (pObj != nullptr)
	{
		if (pObj->getType() == e_ENEMY && this->m_Object_Type == e_BULLET_P)
		{
			pObj->dieFlag = true;
			// Player�� �� ź�࿡ ���� �¾Ҵٸ�.
			dieFlag = true;
			return false;
		}
		else if (pObj->getType() == e_PLAYER && this->m_Object_Type == e_BULLET_E)
		{
			// ���� ���� ����
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
	

	
	// Ÿ�Կ� ���� ź�� ������
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