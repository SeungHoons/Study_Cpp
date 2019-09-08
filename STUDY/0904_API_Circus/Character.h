#pragma once
#include "MoveObject.h"


enum CHARACTER_STATE
{
	CHARACTER_STOP,
	CHARACTER_MOVE,
	CHARACTER_JUMP
};

enum CHARACTER_DIRECTION
{
	LEFT,
	RIGHT
};

class Image;
class Character :
	public MoveObject
{
private:
	vector<Image*> m_vecRunImage;
	vector<Image*> m_vecWinImage;
	Image* m_pDIeImage;
	CHARACTER_STATE m_eState;
	CHARACTER_DIRECTION m_eDirection;
	int score;
public:
	Character();
	~Character();

	virtual void init();
	virtual void update();
	virtual void render(HDC _hdc);
	void render(HDC _hdc, int _x);

	 void setDirection(CHARACTER_DIRECTION _dir) { m_eDirection = _dir; }
	 void setState(CHARACTER_STATE _state) { m_eState = _state; }
	inline int getPositionX() { return m_position.x; }
};

