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

	m_inRect[0] = m_rect;
	m_inRect[0].right -= 20;
	m_inRect[0].bottom -= 20;

	m_inRect[1] = m_inRect[0];
	m_inRect[1].left += 20;
	m_inRect[1].right += 20;

	m_inRect[2] = m_inRect[0];
	m_inRect[2].top += 20;
	m_inRect[2].bottom += 20;

	m_inRect[3] = m_inRect[1];
	m_inRect[3].top += 20;
	m_inRect[3].bottom += 20;
}

void Tile::render(HDC _hdc)
{
	if (m_pBitmap != nullptr)
		m_pBitmap->render(_hdc, m_rect.left, m_rect.top, TILE_SIZE, TILE_SIZE);

	HPEN MyPen, OldPen;

	MyPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 55));
	OldPen = (HPEN)SelectObject(_hdc, MyPen);
	MoveToEx(_hdc, m_rect.left, m_rect.top, NULL);
	LineTo(_hdc, m_rect.right, m_rect.top);
	LineTo(_hdc, m_rect.right, m_rect.bottom);
	LineTo(_hdc, m_rect.left, m_rect.bottom);
	LineTo(_hdc, m_rect.left, m_rect.top);
	for (int i = 0; i < 4; i++)
	{
		MoveToEx(_hdc, m_inRect[i].left, m_inRect[i].top, NULL);
		LineTo(_hdc, m_inRect[i].right, m_inRect[i].top);
		LineTo(_hdc, m_inRect[i].right, m_inRect[i].bottom);
		LineTo(_hdc, m_inRect[i].left, m_inRect[i].bottom);
		LineTo(_hdc, m_inRect[i].left, m_inRect[i].top);
	}
	SelectObject(_hdc, OldPen);
	DeleteObject(MyPen);


}
