#pragma once
#include "Global.h"

class Image;
class Object
{
protected:
	POINT m_position;
	Image* m_image;

public:
	Object();
	~Object();

	virtual void init();
	virtual void update();
	virtual void render(HDC _hdc);
};

