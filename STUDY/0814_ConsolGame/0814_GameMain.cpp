#include "GameMain.h"
#include "MapTool.h"
#include "Player.h"

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
		switch (nowScene)					//씬관리
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
			system("cls");
			mapTool.mainMenu();

			int mapInput;
			cin >> mapInput;
			while (mapInput!=5)
			{
				system("cls");

				switch (mapInput)
				{
				case 1:		//새로 만들기
					mapTool.newMap();
					while (mapInput==1)
					{
						system("cls");
						mapInput = mapTool.toolMain();
						_sleep(1000 / 200);
					}
					break;
				case 2:		//수정하기
					break;
				case 3:		//나가기
					mapInput = 5;
					gameManager.getPlayer()->setScene(TITLE);
					break;
				case 4:		//멥툴 메인메뉴
					system("cls");
					mapTool.mainMenu();
					cin >> mapInput;
					break;
				default:
					break;
				}
			}
			break;
		default:
			break;
		}

		
		_sleep(1000 / 200);
	}
	return 0;
}