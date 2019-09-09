#include "Tile.h"
#include "Image.h"
#include "ResManager.h"

Tile::Tile()
{
}


Tile::~Tile()
{
}

void Tile::init(int _x, bool _isElephant)
{
	if (_isElephant)
	{
		m_pTopImage = ResManager::getSingleton()->getBitMap(FILE_BACK_DEKO);
	}
	else
		m_pTopImage = ResManager::getSingleton()->getBitMap(FILE_BACK_NORMAL);

	int tempTileY = ResManager::getSingleton()->getBitMap(FILE_BACK)->getSize().cy;

	m_pImage = ResManager::getSingleton()->getBitMap(FILE_BACK);
	m_position.x = _x;
	m_position.y = CLIENT_HEIGHT - (tempTileY * IMAGE_SIZE_MULTIFLY);
	m_iCameraX = 0;
	m_bActive = true;
}

void Tile::update()
{
	//카메라 시야에 없으면 활성상태를 펄스로 만듬.
	if ((m_position.x - m_iCameraX) < -150)
	{
		m_bActive = false;
	}
	else if ((m_position.x - CLIENT_WIDTH) > CLIENT_WIDTH +150)
	{
		m_bActive = false;
	}

	if ((m_position.x - m_iCameraX) > -120 && (m_position.x - m_iCameraX) < CLIENT_WIDTH + 120)
	{
		m_bActive = true;
	}

}

void Tile::render(HDC _hdc)
{
	if (m_bActive == true)
	{
		m_pTopImage->render(_hdc, m_position.x - m_iCameraX, (m_position.y - (m_pTopImage->getSize().cy)*IMAGE_SIZE_MULTIFLY), IMAGE_SIZE_MULTIFLY);
		m_pImage->render(_hdc, m_position.x - m_iCameraX, m_position.y, IMAGE_SIZE_MULTIFLY);
	}
	//m_pTopImage->render(_hdc, m_position.x, (m_position.y - m_pTopImage->getSize().cy));
	//m_pImage->render(_hdc, m_position.x, m_position.y);
}

void Tile::setPosition(int _x)
{
	m_position.x = _x;
}

void Tile::setCameraPosition(int _x)
{
	m_iCameraX = _x;
}


