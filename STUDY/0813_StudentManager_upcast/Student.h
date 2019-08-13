#pragma once
#include <stdio.h>
#include <string>
using namespace std;

class Student
{
protected:

	int no;
	string szName;
	int kor;
	int eng;
	int math;

public:
	virtual void LoadStudent(FILE* pFile);
	virtual void SaveStudent(FILE* pFile);
	virtual void PrintLine();
	virtual void InputLine(const int iCurStudent);

	Student();
	virtual ~Student();
};

