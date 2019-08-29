#pragma once
#include"Global.h"
class Rain;
class RainManager
{
private:
	vector<Rain*>  pRain;
	string loadStirng;
	queue<Rain*> order;
	int wordCount;
	HWND hWnd;

	int respawnTime;
	long startTime;
public:
	RainManager();
	~RainManager();

	//초기 데이터 저장
	void loadWord();
	void createWord();

	void init(HWND _hWnd);
	void print(HDC _hdc);
	void update();
	
	void randomRain();
	void setOrder();		//한단어를 여러번 오더에 그냐 아예 새로운 객체를 넣어준다. 나중에

};

