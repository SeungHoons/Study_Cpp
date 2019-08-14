#include "GameMain.h"
#include "MapTool.h"

int main()
{
	

	GameManager gameManager;
	MapTool mapTool;
	gameManager.init(TITLE);
	STATE nowScene = gameManager.getScene();

	int input;

	//STATE  

	while (true)
	{
		nowScene = gameManager.getScene();
		switch (nowScene)
		{
		case TITLE:
			system("cls");
			gameManager.printMenu();
			gameManager.inputMenu();
			break;
		case INTRO:
			break;
		case INGAME:
			break;
		case ENDING:
			break;
		case MAP_MAKE:
			mapTool
			break;
		default:
			break;
		}

		
		_sleep(1000 / 200);
	}
	return 0;
}