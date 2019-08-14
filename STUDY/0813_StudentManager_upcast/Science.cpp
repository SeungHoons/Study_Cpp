#include "Science.h"
#include <iostream>


Science::Science()
{
}


Science::~Science()
{
}

void Science::PrintLine()
{
	
	float fSum = kor + eng + math;
	float fAvg = fSum / 3;
	cout << no << "\t" << szName << "\t" <<
		kor << "\t" << eng << "\t" <<
		math << "\t" <<
		fSum << "\t" << fAvg << endl;
}

void Science::InputLine(const int iCurStudent)
{
	Student::InputLine(no);
	cout << "¼öÇÐ2" << endl;
	cin >> math2;
}
