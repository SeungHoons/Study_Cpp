#include "Tile.h"
#include "BitMap.h"


Tile::Tile()
{
}


Tile::~Tile()
{
}

void Tile::init(BitMap* _bitmap, RECT* _rect)
{
	m_rect = *_rect;
	m_pBitmap = _bitmap;
	m_rect.right= m_rect.left + 40;
	m_rect.bottom= m_rect.top + 40;

	debugMode = true;
}

void Tile::render(HDC _hdc)
{
	if (m_pBitmap != nullptr)
		m_pBitmap->render(_hdc, m_rect.left, m_rect.top, TILE_SIZE, TILE_SIZE);

	if (debugMode)
		renderDebugCollitionBox(_hdc);

}

void Tile::renderDebugCollitionBox(HDC _hdc)
{
	HPEN MyPen, OldPen;

	MyPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 55));
	OldPen = (HPEN)SelectObject(_hdc, MyPen);
	//MoveToEx(_hdc, m_rect.left, m_rect.top, NULL);
	//LineTo(_hdc, m_rect.right, m_rect.top);
	//LineTo(_hdc, m_rect.right, m_rect.bottom);
	//LineTo(_hdc, m_rect.left, m_rect.bottom);
	//LineTo(_hdc, m_rect.left, m_rect.top);

	//내부 콜리젼 박스 그려주기
	for (auto iter = m_vecInRect.begin(); iter != m_vecInRect.end(); iter++)
	{
		MoveToEx(_hdc, iter->left, iter->top, NULL);
		LineTo(_hdc, iter->right, iter->top);
		LineTo(_hdc, iter->right, iter->bottom);
		LineTo(_hdc, iter->left, iter->bottom);
		LineTo(_hdc, iter->left, iter->top);
	}
	SelectObject(_hdc, OldPen);
	DeleteObject(MyPen);

}

void Tile::chageMode()
{
	if (debugMode)
		debugMode = false;
	else
		debugMode = true;
}

void Tile::setInRect(POINT _point)
{
	RECT tempRect = { m_rect.left + _point.x, m_rect.top + _point.y ,0,0 };
	tempRect.right = tempRect.left + 20;
	tempRect.bottom = tempRect.top + 20;
	m_vecInRect.push_back(tempRect);
}

bool Tile::checkColltion(RECT & _rc)
{
	RECT checkRect;
	for (auto iter = m_vecInRect.begin(); iter != m_vecInRect.end(); iter++)
	{
		if (IntersectRect(&checkRect, &_rc, &(*iter)))
		{
			return true;
		}
	}
	return false;
}

bool Tile::reduction(RECT & _rc, DIRECTION _dir)
{
	int x = (_rc.left + _rc.right) / 2;
	int y = (_rc.top + _rc.bottom) / 2;

	RECT checkRect;
	for (auto iter = m_vecInRect.begin(); iter != m_vecInRect.end(); iter++)
	{
		if (IntersectRect(&checkRect, &_rc, &(*iter)))
		{
			switch (_dir)
			{
			case DIR_UP:
				iter->bottom -= 10;
				break;
			case DIR_DOWN:
				iter->top += 10;
				break;
			case DIR_LEFT:
				iter->right -= 10;
				break;
			case DIR_RIGHT:
				iter->left += 10;
				break;
			default:
				break;
			}

			if (iter->left == iter->right || iter->bottom == iter->top)
			{
				iter->left = 0;
				iter->right = 0;
				iter->bottom = 0;
				iter->top = 0;
			}
			return true;

		}
	}
	return false;

}
