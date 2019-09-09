#pragma once
#include "Object.h"
class Image;
class Tile :
	public Object
{
private:
	Image* m_pTopImage;
	bool m_bElephant;
	int m_iCameraX;
public:
	Tile();
	~Tile();

	virtual void init(int _x, bool _isElephant);
	virtual void update();
	virtual void render(HDC _hdc);

	void setPosition(int _x);
	void setCameraPosition(int _x);

	//int getPositonX() { return m_position.x; }
	bool getAactive() { return m_bActive; }
	void setActiveTrue() { m_bActive = true; }
};

