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

}

void Tile::update()
{
	
}

void Tile::render(HDC _hdc)
{
	m_pTopImage->render(_hdc, m_position.x - m_iCameraX, (m_position.y - (m_pTopImage->getSize().cy)*IMAGE_SIZE_MULTIFLY), IMAGE_SIZE_MULTIFLY);
	m_pImage->render(_hdc, m_position.x - m_iCameraX, m_position.y, IMAGE_SIZE_MULTIFLY);
	//m_pTopImage->render(_hdc, m_position.x, (m_position.y - m_pTopImage->getSize().cy));
	//m_pImage->render(_hdc, m_position.x, m_position.y);
}

void Tile::setPosition(int _x)
{
	m_iCameraX = _x;
}


