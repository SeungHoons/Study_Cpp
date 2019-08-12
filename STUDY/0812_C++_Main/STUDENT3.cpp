#include "STUDENT3.h"

int STUDENT3::aaa = 0;

STUDENT3::STUDENT3(int _no)
{
	pOut = new char[256];
	no = _no;
	cout << "호출" << endl;
}
STUDENT3::STUDENT3(const STUDENT3& other)
{
	no = other.no;
	pOut = new char[256];
}

STUDENT3::~STUDENT3()
{
	delete pOut;
	cout << "제거완료" << endl;
}


void STUDENT3::Print()
{
	cout << aaa << endl;
	cout << no << endl;
	cout << endl;
}

