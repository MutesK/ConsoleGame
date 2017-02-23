#include "Player.h"
#include "GameScene.h"
#include "Console.h"


CPlayer::CPlayer(int x, int y, char* Sprite, CGameScene *pScene)
	:CBaseObject(x, y, e_PLAYER),  m_pScene(pScene)
{
	memcpy_s(m_sprite, 3, Sprite, 3);
	hp = 15;
}


CPlayer::~CPlayer()
{
}

bool CPlayer::Action()
{
	// 1. 총알 
	// 2. 움직인다.
	KeyPressed();
	return true;

}

void CPlayer::Draw()
{
	// 버퍼에 넣는다.
	Sprite_Draw(m_X, m_Y, m_sprite[0]);
	Sprite_Draw(m_X + 1, m_Y, m_sprite[1]);
	Sprite_Draw(m_X + 2, m_Y, m_sprite[2]);

}

void CPlayer::KeyPressed()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		// X 값은 0부터 dfSCREEN_WIDTH - 1까지 0 <= X < 79  80 = NULL
		//  1 <= X <= 78
		if (m_X >= 1)
			m_X--;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (m_X <= dfSCREEN_WIDTH - 3)
			m_X++;

	}

	if (GetAsyncKeyState(VK_UP))
	{
		// 0 <= Y < dfSCREEN_HEIGHT - 1
		// 1 <= Y <= dfSCREEN_HEIGHT - 2
		if (m_Y >= 1)
			m_Y--;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		if (m_Y <= dfSCREEN_HEIGHT)
			m_Y++;
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		//Shot(player.Xpos, player.Ypos, 1);
		m_pScene->CreateBullet(m_X + 1, m_Y, e_BULLET_P);
	}
}