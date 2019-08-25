#pragma once
#include "Global.h"

class People;
class ElevatorManager;
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

	void addPeople();
	void randomPeople();

	void init();
	void update();
	void print();

	void callElevator();
	void changeButton(int index);
};

