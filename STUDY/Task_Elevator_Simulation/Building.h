#pragma once
#include "Global.h"

class People;
class ElevatorManager;
class Elevator;
struct Floor
{
	multimap<int, People*> waitPeople;
	Button button;
};

class Building
{
private:
	int count = 0;
	Floor floor[MAX_FLOOR];
	bool autoMode;
	ElevatorManager *pElevatorManager;
	int cursor;
public:
	Building();
	~Building();

	//UI
	void setMode();
	inline void cursorUp() { cursor++; }
	inline void cursorDown() { cursor--; }

	void init();
	void update();
	void print();

	void addPeople();
	void randomPeople();

	void callElevator();
	void changeButton(int index);
	void equelElevator();
};

