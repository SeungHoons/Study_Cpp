#pragma once
#include "Object.h"

class MoveObject : public Object
{
protected:
	int m_speed;
	RECT m_rect;
public:
	MoveObject();
	~MoveObject();

	virtual void init();
	virtual void update();
	virtual void render(HDC _hdc);

	void setPosition(POINT _point);

};

