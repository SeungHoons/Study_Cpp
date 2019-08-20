#include "StudentManager.h"
#include <iostream>
#include <algorithm>
using namespace std;

StudentManager::StudentManager()
{
	st.reserve(20);
}


StudentManager::~StudentManager()
{
	//for (auto iter = st.begin(); iter != st.end(); iter++)
	//{
	//	delete *iter;
	//}

	st.clear();
}

void StudentManager::LoadFile()
{
	FILE* pFile = fopen("save.txt", "r");
	if (pFile != nullptr)
	{
		int iCount = 0;
		fscanf(pFile, "%d\n", &iCount);
		for (int i = 0; i < iCount; i++)
		{
			shared_ptr<Student> pNew = make_shared<Student>();
			pNew->LoadStudent(pFile);
			st.push_back(pNew);

		}
		fclose(pFile);
	}
}

void StudentManager::PrintMenu()
{
	cout << "1.입력" << endl;
	cout << "2.출력" << endl;
	cout << "3.저장" << endl;
	cout << "4.종료" << endl;
	cout << "5.정렬" << endl;
}

void StudentManager::Sort(int i)
{
	int input;
	if (i == 1)
	{
		cout << "1.내림\n2.올림" << endl;
		cin >> input;
		if (input == 1)
		{
			sort(st.begin(), st.end(), [](shared_ptr<Student> l, shared_ptr<Student> r)->bool {return l->GetKor() < r->GetKor(); });
		}
		else if (input == 2)
		{
			sort(st.begin(), st.end(), [](shared_ptr<Student> l, shared_ptr<Student> r)->bool {return l->GetKor() > r->GetKor(); });
		}
		
	}
	else if (i == 2)
	{
		cout << "1.내림\n2.올림" << endl;
		cin >> input;
		if (input == 1)
		{
			sort(st.begin(), st.end(), [](shared_ptr<Student> l, shared_ptr<Student> r)->bool {return l->GetAve() < r->GetAve(); });
		}
		else if (input == 2)
		{
			sort(st.begin(), st.end(), [](shared_ptr<Student> l, shared_ptr<Student> r)->bool {return l->GetAve() > r->GetAve(); });
		}
	}
}

void StudentManager::SortWhat()
{
	
	int input;
	cout << "1.국어\n2.평균" << endl;
	cout << "\n";
	cin >> input;

	Sort(input);
}


void StudentManager::InputStudent()
{
	shared_ptr<Student> pNew = make_shared<Student>();
	pNew->InputLine(st.size());
	st.push_back(pNew);
}

void StudentManager::OutputStudent()
{
	cout << "번호\t이름\t국어\t영어\t수학\t총점\t평균" << endl;
	//vector<Student*>::iterator
	for (auto iter = st.begin(); iter != st.end(); iter++)
	{
		(*iter)->PrintLine();
	}
}

void StudentManager::SaveFile()
{
	FILE* pFile = fopen("save.txt", "w");
	fprintf(pFile, "%d\n", st.size());
	for (auto iter = st.begin(); iter != st.end(); iter++)
	{
		(*iter)->SaveStudent(pFile);
	}
	fclose(pFile);
}
