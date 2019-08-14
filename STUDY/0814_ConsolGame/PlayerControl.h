#pragma once
#include <conio.h>

class PlayerControl
{
private:
	bool inMenu;
	
public:
	PlayerControl();
	~PlayerControl();

	void input();
};

