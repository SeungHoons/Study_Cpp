#include "StudentManager.h"
#include <iostream>
using namespace std;

StudentManager::StudentManager()
{
	st.reserve(20);
}


StudentManager::~StudentManager()
{
	for (auto iter = st.begin(); iter != st.end(); iter++)
	{
		delete *iter;
	}

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
			Student* pNew = new Student();
			pNew->LoadStudent(pFile);
			st.push_back(pNew);
		}
		fclose(pFile);
	}
}

void StudentManager::PrintMenu()
{
	cout << "1.�Է�" << endl;
	cout << "2.���" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
}

int StudentManager::InputSubject()
{
	int input;
	cout << "�̰� 1 || ���� 2" << endl;
	cin >> input; 
	return input;
}


void StudentManager::InputStudent()
{
	Student* pNew =nullptr;
	int subject = InputSubject();

	if (subject == 1)
	{
		pNew = new Science();
		Science* science = dynamic_cast<Science*>(pNew);
		//science->InputLine();
		pNew->InputLine(st.size());
	}
	else if (subject == 2)
	{
		pNew = new Social();
		Social* social = dynamic_cast<Social*>(pNew);
		social->InputLine();

		//pNew->InputLine(st.size());
	}
	//switch (subject)
	//{
	//case 1: 
	//	pNew = new Science();
	//	Science* science = dynamic_cast<Science*>(pNew);
	//	science->InputLine();
	//	break;
	//case 2:
	//	pNew = new Social();
	//	break;
	//default:
	//	break;
	//}

	//Student* pNew = new Student();
	//pNew->InputLine(st.size());
	//st.push_back(pNew);
}

void StudentManager::OutputStudent()
{
	cout << "��ȣ\t�̸�\t����\t����\t����\t����\t���"<< endl;
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
