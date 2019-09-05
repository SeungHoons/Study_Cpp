#pragma once
#include "Global.h"
#include "SingletoneBase.h"


enum SCENE_STATE
{
	SCENE_MENU,
	SCENE_STAGE_ONE
};

class Scene;
class SceneManager : public singletonBase<SceneManager>
{
private:
	HWND m_hWnd;
	Scene* m_pNowScene;
	SCENE_STATE m_eNowSceneState;
	SCENE_STATE m_eNextScene;
	bool m_bSceneChage;			//���� ����ɰ��ΰ�
	bool m_bGameEnd;

public:
	SceneManager();
	~SceneManager();

	void init(HWND _hWnd);
	void update();
	void render(HDC _hdc);
	void input(WPARAM _wParam);

	void freeInst();
	void sceneChange(SCENE_STATE _state);

	inline void nextSceneChange(SCENE_STATE _state) // �� ���� �����Լ�
	{ 
		m_eNextScene = _state;
		m_bSceneChage = true;
	}
	inline SCENE_STATE getNextScene(void)   // ����� ���� ����
	{
		return m_eNextScene;
	}
	inline bool getSceneChange (void)    // ���������� ����
	{
		return m_bSceneChage;
	}
	inline void setGameEnd(bool _bEnd)      // ������ ����� ���ΰ�?
	{
		m_bGameEnd = _bEnd;
	}
	inline bool getGameEnd(void)      // ������ ����Ǿ��°�?
	{
		return m_bGameEnd;
	}
	inline SCENE_STATE getNowState(void) // ���� ���� ��ȯ
	{
		return m_eNowSceneState;
	}
};

