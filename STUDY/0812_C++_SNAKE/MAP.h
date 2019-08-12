#pragma once
#include <iostream>
using namespace std;

#define HEIGHT 20
#define WIDTH 40

enum E_MAP
{
	EMPTY,
	BLOCK,
	PLAYER,
	ITEM
};

class MAP
{
private:
	E_MAP map[HEIGHT][WIDTH];


public:
	MAP();
	~MAP();

	void Init();
	void DrawMap();

	inline void SetPlayer(int x, int y)
	{
		map[y][x] = PLAYER;
	}

	inline void SetEmpty(int x, int y)
	{
		map[y][x] = EMPTY;
	}

	inline E_MAP isWhatObject(int x, int y)
	{
		return map[y][x];
	}

};


