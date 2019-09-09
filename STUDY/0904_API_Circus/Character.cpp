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
	m_speed = 3;
	m_currentTime = GetTickCount();
	m_iAniBackIndex = 0;
	m_iAniFrontIndex = 0;
}

void Character::update()
{
	if (m_eState == CHARACTER_MOVE)
	{
		switch (m_eDirection)
		{
		case LEFT:
			m_position.x -= m_speed;

			break;
		case RIGHT:
			m_position.x += m_speed;

			break;
		default:
			break;
		}
		animation();
	}
	else
	{
		m_iAniBackIndex = 0;
		m_iAniFrontIndex = 0;
	}

	if (m_eState == CHARACTER_JUMP)
	{
		switch (m_eDirection)
		{
		case LEFT:
			m_position.x -= m_speed;
			for (int angle = 0; angle <= 90; angle++)
			{
				// getPosition을 더한 것은 현재 오브젝트 위치에서 그리기 위함이다.
				int x = (cos(RADIAN * angle) * 3);
				int y = (sin(RADIAN * angle) * 6);
				printf("%d , %d\n", x, y);
				// 구한 점과 오브젝트 포지션의 점을 이어주는 선을 그린다.
			}

         			break;
		case RIGHT:
			m_position.x += m_speed;

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
		m_vecRunImage[0]->render(_hdc, m_position.x, m_position.y, IMAGE_SIZE_MULTIFLY);
		break;
	case CHARACTER_MOVE:
		if (RIGHT)
		{

			m_vecRunImage[m_iAniFrontIndex]->render(_hdc, m_position.x, m_position.y, IMAGE_SIZE_MULTIFLY);
		}
		else if (LEFT)
		{
			m_vecRunImage[m_iAniBackIndex]->render(_hdc, m_position.x, m_position.y, IMAGE_SIZE_MULTIFLY);
		}


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
		if (m_eDirection == RIGHT)
		{
			m_vecRunImage[m_iAniFrontIndex]->render(_hdc, _x, m_position.y, IMAGE_SIZE_MULTIFLY);
		}
		else if (m_eDirection == LEFT)
		{
			m_vecRunImage[m_iAniBackIndex]->render(_hdc, _x, m_position.y, IMAGE_SIZE_MULTIFLY);
		}
		break;
	case CHARACTER_JUMP:
		m_vecRunImage[2]->render(_hdc, _x, m_position.y, IMAGE_SIZE_MULTIFLY);
		break;
	default:
		break;
	}
}

void Character::animation()
{
	if (GetTickCount() - m_currentTime > 200)
	{
		switch (m_eDirection)
		{
		case LEFT:
		{
			m_iAniBackIndex++;
			if (m_iAniBackIndex > m_vecRunImage.size() - 2)
				m_iAniBackIndex = 0;
		}
		break;
		case RIGHT:
		{
			m_iAniFrontIndex++;
			if (m_iAniFrontIndex > m_vecRunImage.size() - 1)
				m_iAniFrontIndex = 0;
		}
		break;
		default:
			break;
		}
		m_currentTime = GetTickCount();
	}

}

void Character::jump()
{
	
}
