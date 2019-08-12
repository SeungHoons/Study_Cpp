#include "MANAGER.h"



MANAGER::MANAGER()
{
	stnum = 0;
}


MANAGER::~MANAGER()
{
}

void MANAGER::Menu()
{
	cout << " \n성적표 관리 프로그램입니다. \n1. 입력 \n2. 출력 \n3. 종료\n";
	int input;
	cin >> input;

	switch (input)
	{
	case 1: 
		Input();
		break;
	case 2:
		Print();
		break;
	case 3:
		Exit();
		break;

	default:
		break;
	}
}

void MANAGER::Print()
{
	cout << "번호\t" << "이름\t" << "국\t" << "영\t" << "수\t" << "평균\t" << "총점\n";

	for (int i = 0; i < stnum; i++)
	{
		cout << st[i].no << "\t" << st[i].strName << "\t" << st[i].kor << "\t" << st[i].eng << "\t" << st[i].math << "\t"
			<< (st[i].kor + st[i].eng + st[i].math) / 3 << "\t" << st[i].kor + st[i].eng + st[i].math << "\n";
	}
	cout << "\n\n";
}

void MANAGER::Input()
{
	S_STUDENT temp;
	cout << "이름 국어 영어 수학\n";

	cin >> temp.strName >> temp.kor >> temp.eng >> temp.math;
	temp.no = stnum;

	st[stnum] = temp;
	stnum++;
}


void MANAGER::Exit()
{
	return;
}

//
//#include "Student.h"
//#include <iostream>
//using namespace std;
//
//Student::Student()
//{
//}
//
//
//Student::~Student()
//{
//}
//
//void Student::InputLine(const int iCurStudent)
//{
//	no = iCurStudent + 1;
//	cout << "이름" << endl;
//	cin >> szName;
//	cout << "국어" << endl;
//	cin >> kor;
//	cout << "영어" << endl;
//	cin >> eng;
//	cout << "수학" << endl;
//	cin >> math;
//}
//
//void Student::PrintLine()
//{
//	float fSum = kor + eng + math;
//	float fAvg = fSum / 3;
//	cout << no << "\t" << szName << "\t" <<
//		kor << "\t" << eng << "\t" <<
//		math << "\t" <<
//		fSum << "\t" << fAvg << endl;
//}
//
//void Student::LoadStudent(FILE* pFile)
//{
//	char szBuf[256];
//	fscanf(pFile, "%d %s %d %d %d\n", &no, szBuf,
//		&kor, &eng, &math);
//
//	szName = szBuf;
//}
//
//void Student::SaveStudent(FILE* pFile)
//{
//	fprintf(pFile, "%d %s %d %d %d\n", no, szName.c_str(),
//		kor, eng, math);
//}