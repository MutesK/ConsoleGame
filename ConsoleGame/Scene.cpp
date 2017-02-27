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


// ���� ��ü�� ������ �ٲ�� ��.
void CScene::LoadScene(int SceneType)
{
	void *p = this;

	switch (SceneType)
	{
		case CGAMEOVERSCENE:
		{		
			delete this;
			// ���� ��ġ���ٰ� ������ �ȴ�.
			CGameOverScene *tep = new CGameOverScene();
			memcpy(p, tep, sizeof(CGameOverScene));
			return;
		}
		case CGAMESCENE:
		{
			delete this;
			// ���� ��ġ���ٰ� ������ �ȴ�.
			CGameScene *tep = new CGameScene();
			memcpy(p, tep, sizeof(CGameScene));
			return;
		}
	}
	
}