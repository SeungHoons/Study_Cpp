#pragma once
#include "MAP.h"
#include <vector>
using namespace std;

struct BODY;
class MAP;
class SNAKE
{
private:
	vector<BODY> SnakeBodys;
	MAP *pMap;
public:
	SNAKE();
	~SNAKE();

	void Init(MAP* _map);
	void Input();

};

struct BODY
{
	int x;
	int y;
};

