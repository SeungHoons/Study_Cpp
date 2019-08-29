#include "Rain.h"


Rain::Rain()
{
	active = false;
	//�׽�Ʈ
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
		//��Ƽ����Ʈ�� �����ڵ� �������� �ٲ��ִ��Լ�.
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
	point.x = rand() % (_point.x - (10 * str.size())); // ���� ���� �ش� str ���̰��� ���ϴ� ����
	point.y = -1;
}

void Rain::setActive(bool b)
{
	active = b;
}
