#pragma once
#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

#define TITLE_SIZE_XY 30

enum MENUNAME
{
	
};

class Player;
class MapTool;
class GameManager
{
private:
	int titleBackground[TITLE_SIZE_XY][TITLE_SIZE_XY];
	string strTitle[5];
	Player *player;
	int input;
public:
	GameManager();
	~GameManager();
	

	void init(STATE i);

	//Ÿ��Ʋ ����
	void initTitle();

	//ĳ����
	STATE getScene();

	void printMenu();
	void inputMenu();
};

