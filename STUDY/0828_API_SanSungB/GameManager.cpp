
#include "GameManager.h"
#include "RainManager.h"
#include "User.h"
#include "KeyManager.h"

GameManager::GameManager()
{
	rainManager = new RainManager();
}


GameManager::~GameManager()
{
}

void GameManager::init()
{
	rainManager->loadWord();
	rainManager->createWord();
}
