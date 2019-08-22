#pragma once
#include "Global.h"

#define MAX_WEIGHT 600


class Elevator
{
	int floor;
	int people;
	int weight;
	STATE state;
	ELEVATOR_TYPE type;


public:
	Elevator();
	~Elevator();

	void print();
	void move(STATE _state);
	void setState(STATE _state);
	void setType(ELEVATOR_TYPE _type);

	//지울지 말지 나중에 판단
	inline int getFloor() { return floor; }
	inline int getPople() { return people; }
	inline int getWeight() { return weight; }
	inline STATE getState() { return state; }

};

