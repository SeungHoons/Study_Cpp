#pragma once
#include "Student.h"
class Science :
	public Student
{
private:
	int math2;
public:
	Science();
	virtual ~Science();

	virtual void PrintLine();
	virtual void InputLine();
};

