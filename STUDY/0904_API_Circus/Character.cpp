#include "Character.h"
#include "ResManager.h"
#include "Image.h"


Character::Character()
{
}


Character::~Character()
{
}

void Character::init()
{
	m_vecRunImage.push_back(ResManager::getSingleton()->getBitMap(FILE_CHARACTER_IDLE_0));
	m_vecRunImage.push_back(ResManager::getSingleton()->getBitMap(FILE_CHARACTER_IDLE_1));
	m_vecRunImage.push_back(ResManager::getSingleton()->getBitMap(FILE_CHARACTER_IDLE_2));

	m_vecWinImage.push_back(ResManager::getSingleton()->getBitMap(FILE_CHARACTER_WIN1));
	m_vecWinImage.push_back(ResManager::getSingleton()->getBitMap(FILE_CHARACTER_WIN2));
	
	m_pDIeImage = ResManager::getSingleton()->getBitMap(FILE_CHARACTER_DIE);

	m_position.x = CHARACTER_CONST_POINT_X;
	m_position.y = 540;
	m_eState = CHARACTER_STOP;
}

void Character::update()
{
	if (m_eState == CHARACTER_MOVE)
	{
		switch (m_eDirection)
		{
		case LEFT:
			m_position.x--;
			break;
		case RIGHT:
			m_position.x++;
			break;
		default:
			break;
		}
	}
}

void Character::render(HDC _hdc)
{
	switch (m_eState)
	{
	case CHARACTER_STOP:
		m_vecRunImage[0]->render(_hdc, m_position.x, m_position.y , IMAGE_SIZE_MULTIFLY);
		break;
	case CHARACTER_MOVE:
		m_vecRunImage[2]->render(_hdc, m_position.x, m_position.y, IMAGE_SIZE_MULTIFLY);

		break;
	case CHARACTER_JUMP:
		break;
	default:
		break;
	}
}

//캐릭터 좌표를 받아서 계싼스
void Character::render(HDC _hdc, int _x)
{
	switch (m_eState)
	{
	case CHARACTER_STOP:
		m_vecRunImage[0]->render(_hdc, _x, m_position.y, IMAGE_SIZE_MULTIFLY);
		break;
	case CHARACTER_MOVE:
		m_vecRunImage[2]->render(_hdc, _x, m_position.y, IMAGE_SIZE_MULTIFLY);

		break;
	case CHARACTER_JUMP:
		break;
	default:
		break;
	}
}
