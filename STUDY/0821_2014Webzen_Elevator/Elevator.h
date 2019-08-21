#pragma once


#define MAX_WEIGHT 600

enum STATE
{
	UP,
	DOWN,
	STOP
};



class Elevator
{
	int floor;
	int people;
	int weight;
	STATE state;


public:
	Elevator();
	~Elevator();
};

