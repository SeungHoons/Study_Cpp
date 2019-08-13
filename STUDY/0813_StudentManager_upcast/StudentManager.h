#pragma once
#include "Student.h"
#include "Science.h"
#include "Social.h"
#include <vector>
using namespace std;

class StudentManager
{
private:
	vector<Student*> st;
public:

	void LoadFile();
	void InputStudent();
	void OutputStudent();
	void SaveFile();
	void PrintMenu();
	int InputSubject();

	StudentManager();
	~StudentManager();
};

