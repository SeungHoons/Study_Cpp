#pragma once
#include<iostream>

using namespace std;

enum BLOCK
{

};

class Map;
class MapTool
{
private:
	Map ** map;
	int input;
public:
	MapTool();
	~MapTool();

	void printMenu();
	void toolMenu();
	void save();
	void exit();
};

