#pragma once
#include <iostream>
using namespace std;

#define HEIGHT 20
#define WIDTH 20

enum E_MAP;
class MAP
{
private:
	E_MAP map[HEIGHT][WIDTH];


public:
	MAP();
	~MAP();

	void Init();
	void DrawMap();

};



enum E_MAP
{
	EMPTY,
	BLOCK,
	PLAER
};