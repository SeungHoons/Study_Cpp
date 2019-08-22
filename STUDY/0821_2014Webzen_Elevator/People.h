#pragma once

#include"Global.h"

class People
{
	int count;			//몇 번 기다렸는지.
	int weight;			//무게
	int destination;	//목적지
	int floor;			//현재 층수
public:
	People();
	~People();

	void setDestination();
};

