#pragma once
#include "Global.h"

class Image;
class Object
{
protected:
	POINT m_position;
	Image* m_pImage;
	bool m_active;			//Ȱ��ȭ �Ǿ��ִ°�.
public:
	Object();
	~Object();

	virtual void init();
	virtual void update();
	virtual void render(HDC _hdc);
};

