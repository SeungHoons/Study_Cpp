#pragma once
#include "Global.h"

class People
{
private:
	int count;			//�� �� ��ٷȴ���.
	int weight;			//����
	int destination;	//������
	int floor;			//���� ����
	STATE direction;	//������ ����
public:
	People();
	~People();

	void setDestination(int _floor);
	int getDestination() { return destination; }
	void setDirection();

	STATE getDiarecton() { return direction; }
	inline void countUp() { count++; }
};

