#include "MainScene.h"
#include "SceneManager.h"
#include "Object.h"
#include "Image.h"
#include "ResManager.h"
#include "TileManager.h"
#include "MoveObject.h"
#include "Character.h"



MainScene::MainScene()
{
	//SceneManager::getSingleton()->nextSceneChange(SCENE_MENU);
}


MainScene::~MainScene()
{
}

void MainScene::init(HDC _hdc, HWND _hWnd)
{
	m_hWnd = _hWnd;
	m_memDC = CreateCompatibleDC(_hdc);

	//////////////�̰� �����ϱ�
	m_memBitmap = CreateCompatibleBitmap(_hdc, 1024, 768);
	SelectObject(m_memDC, m_memBitmap);

	m_pTileManager = new TileManager();
	m_pTileManager->init((CLIENT_WIDTH / TILE_WIDTH) + 2);
	m_pImageDark = ResManager::getSingleton()->getBitMap(FILE_BACK_DARK);

	//ĳ����
	m_pCharacter = new Character();
	m_pCharacter->init();

	//ī�޶� ��ǥ
	m_iCameraPoint = 0;

}

void MainScene::input(UINT iMessage, WPARAM _wParam)
{
	//ĳ���� ������ �����Ұ�
	//Ű������Ʈ�� �������� ���� ���¿����� ��Ű�� �Ե��� �����Ұ�

	switch (iMessage)
	{
	case WM_KEYDOWN:
		switch (_wParam)
		{
		case VK_LEFT:
			m_eKeyState = KEYSTATE_LEFT;
			m_pCharacter->setDirection(LEFT);
			m_pCharacter->setState(CHARACTER_MOVE);
			break;
		case VK_RIGHT:
			m_eKeyState = KEYSTATE_RIGHT;
			m_pCharacter->setDirection(RIGHT);
			m_pCharacter->setState(CHARACTER_MOVE);
			break;
		case VK_SPACE:
			break;
		default:
			break;
		}
		break;
	case WM_KEYUP:
		switch (_wParam)
		{
		case VK_LEFT:
			if (m_eKeyState == KEYSTATE_LEFT)
			{
				m_pCharacter->setState(CHARACTER_STOP);
			}
			break;
		case VK_RIGHT:
			if (m_eKeyState == KEYSTATE_RIGHT)
			{
				m_pCharacter->setState(CHARACTER_STOP);
			}
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	//update();
}

void MainScene::update()
{
	m_pCharacter->update();
	setCamera();
	m_pTileManager->setPosition(m_pCharacter->getPositionX());
}

void MainScene::render(HDC _hdc)
{

	//�׸��� ����             ��׶���  / ����,��������Ʈ / �޺� / ĳ���� / �պ�
	//���� ���
	m_pImageDark->render(m_memDC, 0, 0);
	//Ÿ��
	m_pTileManager->render(m_memDC);

	//���� ��������Ʈ

	//�ҿ� , ĳ����
	m_pCharacter->render(m_memDC, CHARACTER_CONST_POINT_X);
	//���� hdc�� ������ ����
	BitBlt(_hdc, 0, 0, CLIENT_WIDTH, CLIENT_HEIGHT, m_memDC, 0, 0, SRCCOPY);
}

void MainScene::release()
{
}

void MainScene::setCamera()
{
	m_iCameraPoint = m_pCharacter->getPositionX() - CHARACTER_CONST_POINT_X;
}
