#pragma once
#include "Global.h"

#define MAX_WEIGHT 600

class People;
class Elevator
{
private:
	int floor;
	int peopleNum;
	int weight;
	int target;
	STATE state;
	ELEVATOR_TYPE type;
	map<int, People*> peopleInElevator;
public:
	Elevator();
	~Elevator();

	void print();
	void move();
	void inElevator(People *_pPeople);
	void arrival();
	void targetUpdate();

	void setState(STATE _state);
	void setType(ELEVATOR_TYPE _type);
	void setTarget(int _target) { target = _target; }

	inline int getTarget() { return target; }
	inline int getFloor() { return floor; }
	inline int getWeight() { return weight; }
	inline STATE getState() { return state; }
	inline ELEVATOR_TYPE getType() { return type; }

	//지울지 말지 나중에 판단
	inline int getPople() { return peopleNum; }	//인원수 제한 둘떄


};

