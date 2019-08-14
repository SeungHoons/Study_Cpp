#include "GameManager.h"
#include "MapTool.h"


GameManager::GameManager()
{
	initTitle();
	player = new Player();
	
}


GameManager::~GameManager()
{
}

void GameManager::init(STATE scene)
{
	player->setScene(scene);
}

void GameManager::initTitle()
{
	for (int i = 0; i < TITLE_SIZE_XY; i++)
	{
		for (int j = 0; j < TITLE_SIZE_XY; j++)
		{
			if ((i == 0 || i == TITLE_SIZE_XY - 1) || (j == 0 || j == TITLE_SIZE_XY - 1))
			{
				titleBackground[i][j] = 1;	//º®;
			}
			else
			{
				titleBackground[i][j] = 0;  //ºó°ø°£
			}
		}
	}

	strTitle[0] = "A dangerous adventure ";
	strTitle[1] = "1. S T A R T";
	strTitle[2] = "2. L O A D";
	strTitle[3] = "3. E X I T";
	strTitle[4] = "  4. MAP MAKING ";
}

STATE GameManager::getScene()
{
	return player->getScene();
}

void GameManager::printMenu()
{
	for (int i = 0; i < TITLE_SIZE_XY; i++)
	{
		for (int j = 0; j < TITLE_SIZE_XY; j++)
		{
			if (i == 6 && j == (TITLE_SIZE_XY / 2) - (strTitle[0].size() / 2))
			{
				cout << strTitle[0];
				j += (strTitle[0].size() / 2);
			}
			else if (i == 18 && j == (TITLE_SIZE_XY / 2) - (strTitle[1].size()/4))//(sizeof(strTitle[1]) / 4)
			{
				cout << strTitle[1];
				j += TITLE_SIZE_XY/2 - strTitle[1].size();
			}
			else if (i == 20 && j == (TITLE_SIZE_XY / 2) - (strTitle[2].size() / 4))
			{
				cout << strTitle[2];
				j = j + strTitle[2].size() - strTitle[2].size() / 2;
			}
			else if (i == 22 && j == (TITLE_SIZE_XY / 2) - (strTitle[3].size() / 4))
			{
				cout << strTitle[3];
				j = j + strTitle[3].size() - strTitle[3].size() / 2;
			}
			else if (i == 24 && j == (TITLE_SIZE_XY / 2) - (strTitle[4].size() / 4))
			{
				cout << strTitle[4];
				j = j + strTitle[4].size() - strTitle[4].size() / 2;
			}

			
			if (titleBackground[i][j] == 1)
				cout << "¢Ã";
			else if (titleBackground[i][j] == 0)
				cout << "  ";
		}
		cout << "\n";
	}

}

void GameManager::inputMenu()
{
	cin >> input;
	switch (input)			//1.start	2.Load	3.Exit 4.Mapmaking
	{
	case 1: 
		break;
	case 2:
		break;
	case 3:
		break;
	case 4: 
		player->setScene(MAP_MAKE);
		break;
	default:
		break;
	}
}
