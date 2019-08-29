#pragma once
#include "Global.h"

class RainManager;
class User;
class KeyManager;
class GameManager
{
private:
	RainManager* rainManager;
	User* user;
public:
	GameManager();
	~GameManager();

	void init();
};

