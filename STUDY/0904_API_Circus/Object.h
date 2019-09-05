#pragma once
#include "Global.h"

class Image;
class Object
{
private:
	POINT m_position;
	Image* m_image;

public:
	Object();
	~Object();

	void init();
	void update();
	void render(HDC _hdc);
};

