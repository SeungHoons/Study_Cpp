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

	//�׸��� ����             ��׶���  / ����,��������Ʈ / �޺� / ĳ���� / �պ�

	//��׶���
	for (int i = 0; i < m_vecTile.size(); i++)
	{
		m_vecTile[i]->render(m_memDC);
	}

	//���� ��������Ʈ
	//for()
	{

	}

	//�Ҹ� , ĳ����

}

void MainScene::release()
{
}
