#pragma once
#include "Global.h"
enum STATE
{
	TITLE,
	INTRO,
	INGAME,
	ENDING,
	MAP_MAKE
};


class Player
{
private:
	bool inMenu;
	STATE sceneState;
	POINT point;

public:
	Player();
	~Player();

	inline POINT getXY()
	{
		return point;
	}
	inline void setXY(POINT p)
	{
		point = p;
	}
	void setScene(STATE scene);
	STATE getScene();

	void input();
	void move();
};

