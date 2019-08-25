#pragma once
#include "Global.h"

class People
{
private:
	int count;			//몇 번 기다렸는지.
	int weight;			//무게
	int destination;	//목적지
	int floor;			//현재 층수
	STATE direction;	//목적지 방향
public:
	People();
	~People();

	void setDestination(int _floor);
	int getDestination() { return destination; }
	void setDirection();

	STATE getDiarecton() { return direction; }
	inline void countUp() { count++; }
};

