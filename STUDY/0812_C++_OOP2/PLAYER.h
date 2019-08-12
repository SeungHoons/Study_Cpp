#pragma once
class PLAYER
{
private:
	S_POINT point;
	int score;
public:
	PLAYER();
	~PLAYER();

	void Input();
	void set(int _x, int _y);
	
};

struct S_POINT
{
	int x;
	int y;
};
