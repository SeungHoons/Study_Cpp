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

	//�ʱ� ������ ����
	void loadWord();
	void createWord();

	void init(HWND _hWnd);
	void print(HDC _hdc);
	void update();
	
	void randomRain();
	void setOrder();		//�Ѵܾ ������ ������ �׳� �ƿ� ���ο� ��ü�� �־��ش�. ���߿�

};

