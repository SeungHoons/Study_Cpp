#include "MineBox.h"
#include "ResManager.h"
#include "BitMap.h"


MineBox::MineBox()
{
}


MineBox::~MineBox()
{
}

void MineBox::init(int _num)
{
	for (int i = 0; i < _num; i++)
	{
		pBitMap.push_back(new BitMap());
		pBitMap.back() = ResManager::GetInstance()->getBitMap(i);
		//pBitMap.push_back(new BitMap(*(ResManager::GetInstance()->getBitMap(i))));
	}
	system("pause");
}
