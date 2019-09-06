#include "MainScene.h"
#include "SceneManager.h"
#include "Object.h"
#include "Tile.h"


MainScene::MainScene()
{
	//SceneManager::getSingleton()->nextSceneChange(SCENE_MENU);
}


MainScene::~MainScene()
{
}

void MainScene::init(HWND _hWnd)
{
	m_hWnd = _hWnd;
	m_memDC = CreateCompatibleDC(GetDC(_hWnd));


}

void MainScene::input(WPARAM _wParam)
{
}

void MainScene::update()
{
}

void MainScene::render(HDC _hdc)
{

	//그리는 순서             백그라운드  / 땅불,엔드포인트 / 뒷불 / 캐릭터 / 앞불

	//백그라운드
	for (int i = 0; i < m_vecTile.size(); i++)
	{
		m_vecTile[i]->render(m_memDC);
	}

	//땅불 엔드포인트
	//for()
	{

	}

	//불링 , 캐릭터

}

void MainScene::release()
{
}
