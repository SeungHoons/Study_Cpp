#pragma once
#include <stdio.h>
#include <string>
using namespace std;

class Student
{
private:

	int no;
	string szName;
	int kor;
	int eng;
	int math;

public:
	void LoadStudent(FILE* pFile);
	void SaveStudent(FILE* pFile);
	void PrintLine();
	void InputLine(const int iCurStudent);

	Student();
	~Student();
};

