#pragma once
#include "Global.h"

class Rain
{
private:
	string str;
	POINT point;
	bool active;
	RECT rc;
	int speed;
public:
	Rain();
	~Rain();

	void init(string &_str);
	void print(HDC hdc);
	void move();
	
	void setPoint(POINT _point);

	void setActive(bool b);
	inline bool getActive() { return active; }
};

