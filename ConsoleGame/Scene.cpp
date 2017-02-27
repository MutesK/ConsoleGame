#include "Scene.h"
#include "GameOverScene.h"
#include "GameScene.h"


CScene::CScene()
{
}


CScene::~CScene()
{
	ObjectList.clear();
}


// 현재 객체의 정보를 바꿔야 됨.
void CScene::LoadScene(int SceneType)
{
	void *p = this;

	switch (SceneType)
	{
		case CGAMEOVERSCENE:
		{		
			delete this;
			// 현재 위치에다가 만들어야 된다.
			CGameOverScene *tep = new CGameOverScene();
			memcpy(p, tep, sizeof(CGameOverScene));
			return;
		}
		case CGAMESCENE:
		{
			delete this;
			// 현재 위치에다가 만들어야 된다.
			CGameScene *tep = new CGameScene();
			memcpy(p, tep, sizeof(CGameScene));
			return;
		}
	}
	
}