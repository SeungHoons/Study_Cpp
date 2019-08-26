#pragma once
//라이브러리
#include<iostream>
#include<vector>
#include<deque>	
#include<list>	
#include<set>	
#include<time.h>
#include<utility>
#include<map>
using namespace std;

//개인 헤더


//디파인
#define MAX_FLOOR 20
#define MAX_PEOPLE 100;
#define MAX_ELEVATOR 4

////이넘
//현재 엘리베이터 상태
enum STATE
{
	UP,
	DOWN,
	STOP
};
//엘리베이터가 어디 전용인지.
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