#pragma once
#include <iostream>


#define WIDTH 19
#define HEIGHT 19


class MAP
{
private:
	int **site;
public:
	MAP();
	~MAP();

	void Init();
	void Print();
};

enum E_MAP
{
	EMPTY,
	BLOCK,
	ITEM,
	USER
};

