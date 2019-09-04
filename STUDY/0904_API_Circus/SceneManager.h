#pragma once
#include "Global.h"
#include "SingletoneBase.h"


enum SCENE_STATE
{
	MENU,
	STAGE_ONE
};

class Scene;
class SceneManager : public singletonBase<SceneManager>
{
private: 
	Scene* m_pNowScene;
	SCENE_STATE m_eNowSceneState;
	SCENE_STATE m_eNextScene;
	bool m_bSceneChage;			//씬이 변경될것인가
	bool m_bGameEnd;

public:
	SceneManager();
	~SceneManager();


	void init(HWND hWnd);
	void update();
	void render();
	void input();

};

