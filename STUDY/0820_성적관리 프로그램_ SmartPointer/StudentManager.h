#pragma once
#include "Student.h"
#include <vector>
using namespace std;

class StudentManager
{
private:
	vector<shared_ptr<Student>> st;
	//vector<Student*> st;
public:

	void LoadFile();
	void InputStudent();
	void OutputStudent();
	void SaveFile();
	void PrintMenu();
	void Sort(int i);
	void SortWhat();

	StudentManager();
	~StudentManager();
};

