#pragma once
#include "Global.h"

class People;
class ElevatorManager;
class Elevator;
struct Floor
{
	map<int, People*> waitPeople;
	Button button;
};

class Building
{
private:
	Floor floor[MAX_FLOOR];
	bool autoMode;
	ElevatorManager *pElevatorManager;
	int cursor;
public:
	Building();
	~Building();

	//UI
	void setMode();
	void cursorUp() { cursor++; }
	void cursorDown() { cursor--; }

	void init();
	void update();
	void print();

	void addPeople();
	void randomPeople();

	void callElevator();
	void changeButton(int index);
	void moveInElevator();
	void equelElevator();
	void test1(Elevator* _pElevator);
};

