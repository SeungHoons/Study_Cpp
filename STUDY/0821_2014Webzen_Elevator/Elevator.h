#pragma once
#include "Global.h"

#define MAX_WEIGHT 600

class People;
class Elevator
{
	int floor;
	int people;
	int weight;
	int target;
	STATE state;
	ELEVATOR_TYPE type;
	deque<People*> inPeople;

public:
	Elevator();
	~Elevator();

	void print();
	void move();
	void inElevator(People *_pPeople);

	void setState(STATE _state);
	void setType(ELEVATOR_TYPE _type);
	void setTarget(int _target) { target = _target; }

	//지울지 말지 나중에 판단
	inline int getFloor() { return floor; }
	inline int getPople() { return people; }
	inline int getWeight() { return weight; }
	inline STATE getState() { return state; }
	inline ELEVATOR_TYPE getType() { return type; }

};

