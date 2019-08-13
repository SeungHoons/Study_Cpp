#pragma once
#include "MAP.h"
#include <conio.h>
#include <vector>
using namespace std;

struct BODY;
class MAP;
enum STATE;

class SNAKE
{
private:
	vector<BODY> Snake;
	MAP *pMap;
	STATE State;
	int Score;
public:
	SNAKE();
	~SNAKE();

	void Init(MAP* _map);
	void Input();
	bool Move();
	
	inline int getScore()
	{
		return Score;
	}

};

struct BODY
{
	int x;
	int y;
	STATE state;
};

enum STATE
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

