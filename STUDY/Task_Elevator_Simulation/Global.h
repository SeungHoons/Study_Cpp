#pragma once
//���̺귯��
#include<iostream>
#include<vector>
#include<deque>	
#include<list>	
#include<set>	
#include<time.h>
#include<utility>
#include<map>
using namespace std;

//���� ���


//������
#define MAX_FLOOR 20
#define MAX_PEOPLE 100;
#define MAX_ELEVATOR 4

////�̳�
//���� ���������� ����
enum STATE
{
	UP,
	DOWN,
	STOP
};
//���������Ͱ� ��� ��������.
enum ELEVATOR_TYPE
{
	HIGH,
	LOW,
	ALL
};

struct Button
{
	bool upButton = 0;
	bool downButton = 0;
	bool call = 0;
};