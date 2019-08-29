#include "RainManager.h"
#include "Rain.h"
#include<iostream>

RainManager::RainManager()
{
	wordCount = 0;
	respawnTime = 0;
}


RainManager::~RainManager()
{
}

void RainManager::loadWord()
{
	FILE* ps;
	ps = fopen("word.txt", "r");
	char sz;

	while ((sz = fgetc(ps)) != EOF)
	{
		if (sz == ',')
			wordCount++;
		loadStirng += sz;
	}
	//if (ps != nullptr)
	//{
	//	getline(cin, loadStirng, '\0');
	//}
}

void RainManager::createWord()
{
	int index=0;
	int index2 = 0;
	string *tempString;
	char c;
	for (int i = 0; i < wordCount; i++)
	{
		tempString = new string();
		for (index; index < loadStirng.size(); index++)
		{
			if (loadStirng[index] == *",")
			{
				break;
			}
			c = loadStirng[index];
			*tempString = *tempString + c;
		}
		pRain.push_back(new Rain());
		pRain[pRain.size() - 1]->init(*tempString);
		//pRain.push_back(tempString);
		index+=2;
	}
}

void RainManager::init(HWND _hWnd)
{
	loadWord();
	createWord();
	hWnd = _hWnd;
	//pRain[0]->setActive(TRUE);
	for (int i = 0; i < pRain.size(); i++)
	{
		setOrder();
	}
	startTime = clock();
	respawnTime = 1000 *1;
}

void RainManager::print(HDC _hdc)
{
	for (int i = 0; i < pRain.size(); i++)
	{
		pRain[i]->print(_hdc);
	}
}

void RainManager::update()
{
	if (clock() - startTime > respawnTime)
	{
		randomRain();
		startTime = clock();
	}
	for (int i = 0; i < pRain.size(); i++)
	{
		pRain[i]->move();
	}

}

void RainManager::randomRain()
{
	int ran = rand() % pRain.size();
	RECT _rc;
	POINT _point;
	while (true)
	{
		GetClientRect(hWnd, &_rc);
		_point = { _rc.right, _rc.bottom };
		if (!pRain[ran]->getActive())
		{
			pRain[ran]->setActive(true);
			pRain[ran]->setPoint(_point);
			break;
		}
	}
}

void RainManager::setOrder()
{
	order.push(pRain[rand() % pRain.size()]);
}


