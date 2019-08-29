#include "Rain.h"


Rain::Rain()
{
	active = false;
	//테스트
	point.x = 30;
	point.y = 30;
	speed = 1;
}

Rain::~Rain()
{
}

void Rain::init(string &_str)
{
	str = _str;
	RECT tempRc = { point.x,point.y,point.x + (10 * str.size()),point.y + 20 };
	rc = tempRc;
}

void Rain::print(HDC hdc)
{
	if (active)
	{
		Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
		TCHAR sz[256];
		//멀티바이트를 유니코드 형식으로 바꿔주는함수.
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str.c_str(), -1, sz, 256);
		DrawText(hdc, sz,-1,&rc, strlen(str.c_str()));
	}
}

void Rain::move()
{
	if(active)
		point.y += speed;
	RECT tempRc = { point.x,point.y,point.x + (10 * str.size()),point.y + 20 };
	rc.top = point.y;
	rc.bottom = rc.top + 20;
}

void Rain::setPoint(POINT _point)
{
	point.x = rand() % (_point.x - (10 * str.size())); // 빼는 값은 해당 str 길이값에 비레하는 길이
	point.y = -1;
}

void Rain::setActive(bool b)
{
	active = b;
}
