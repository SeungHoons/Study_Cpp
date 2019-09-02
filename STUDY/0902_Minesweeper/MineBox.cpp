#include "MineBox.h"
#include "ResManager.h"
#include "BitMap.h"


MineBox::MineBox()
{
}


MineBox::~MineBox()
{
}

void MineBox::init(int _num, int _x, int _y, POINT _start)
{
	for (int i = 0; i < _num; i++)
	{
		pBitMap.push_back(new BitMap());
		pBitMap.back() = ResManager::GetInstance()->getBitMap(i);
		//pBitMap.push_back(new BitMap(*(ResManager::GetInstance()->getBitMap(i))));
	}
	point.x = _x;
	point.y = _y;
	startPoint = _start;
	nowState = STATE_TYPE_BLOCK;
	inState = STATE_TYPE_BLOCK_00;
	isOpen = false;
	//system("pause");
}

void MineBox::draw(HDC _hdc)
{
	//BITMAP bitmap;
	//GetObject(pBitMap[nowState], sizeof(bitmap), &bitmap);
	////m_size.cx = bitmap.bmWidth;
	////m_size.cy = bitmap.bmHeight;
	SIZE tempSize;
	tempSize = pBitMap[nowState]->getSize();
	pBitMap[nowState]->draw(_hdc,startPoint.x + (point.x * tempSize.cx), startPoint.y +(point.y * tempSize.cy));
}

void MineBox::setBlock(STATE_BOX _state)
{
	inState = _state;
}

void MineBox::clickBox(POINT _point)
{

	SIZE tempSize;
	tempSize = pBitMap[nowState]->getSize();
	RECT rc = { startPoint.x + (point.x * tempSize.cx),
	startPoint.y + (point.y * tempSize.cy) ,
	startPoint.x + (point.x * tempSize.cy) + tempSize.cx,
	startPoint.y + (point.y * tempSize.cy) + tempSize.cy };
	if (PtInRect(&rc, _point))
	{
		checkMine();
	}
}

void MineBox::checkMine()
{
	if (inState == STATE_TYPE_MINE)
	{

	}
	else
	{
		nowState = inState;
	}
}
