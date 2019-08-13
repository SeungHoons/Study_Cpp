#pragma once
#include "Student.h"
class Social :
	public Student
{
private:
	int history;
public:
	Social();
	virtual ~Social();

	virtual void InputLine();

};

