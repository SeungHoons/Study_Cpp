#pragma once
#include "Object.h"
class Tile :
	public Object
{
public:
	Tile();
	~Tile();

	virtual void init(HDC _hdc);
	virtual void update();
	virtual void render(HDC _hdc);
};

