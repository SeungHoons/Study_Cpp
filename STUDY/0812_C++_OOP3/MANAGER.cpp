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
	cout << " \n����ǥ ���� ���α׷��Դϴ�. \n1. �Է� \n2. ��� \n3. ����\n";
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
	cout << "��ȣ\t" << "�̸�\t" << "��\t" << "��\t" << "��\t" << "���\t" << "����\n";

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
	cout << "�̸� ���� ���� ����\n";

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
//	cout << "�̸�" << endl;
//	cin >> szName;
//	cout << "����" << endl;
//	cin >> kor;
//	cout << "����" << endl;
//	cin >> eng;
//	cout << "����" << endl;
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