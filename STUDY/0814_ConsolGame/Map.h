#pragma once
#include "Global.h"

enum BLOCK
{
	EMPTY= 1,
	WALL,
	PLAYER,
	ITEM,
	ENEMY
};

class Map
{
private: 
	int maxWidth;
	int maxHeight;
	BLOCK **block;
	POINT *mapPlayer;
public:
	Map();
	~Map();

	void init(int _height, int _width);
	void setBlock(int _height, int _width, int _block);
	void setPlayer(POINT *pp)
	{
		mapPlayer = pp;
	}
	POINT getMapxy()
	{
		POINT rePo = { maxHeight,maxWidth };
		return rePo;
	}
	int getBlock(int _height, int width)
	{
		return (int)block[_height][width];
	}
	void printMap();
};

