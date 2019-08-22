#pragma once
//라이브러리
#include<iostream>
#include<vector>
#include<deque> // 순차적인 탐방	
//deque를 사용하려 했으나 앞에서 부터 팝이 벡터에 비해 빠르다고 해도 결국 앞에만 계속 자르다 보면 뒤 메모리 공간까지 접근해서 
//뒤 메모리 공간에 메모리가 있을경우 다시 할당할것
//리스트 중에서도 단방향 리스트가 가볍다 생각되어 
#include<list>
#include<set>
#include<time.h>
using namespace std;

//개인 헤더


//디파인
#define MAX_FLOOR 20
#define MAX_PEOPLE 100;


//이넘
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