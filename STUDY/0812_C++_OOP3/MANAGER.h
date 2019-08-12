#pragma once
#include <string>
#include <iostream>
using namespace std;

#define STUDENT_NUM 20

class MANAGER
{
	S_STUDENT st[20];
	int stnum;
public:
	MANAGER();
	~MANAGER();
	void Menu();
	void Print();
	void Input();
	void Exit();
};


struct S_STUDENT
{
	int no;
	string strName;
	int kor;
	int eng;
	int math;
};
