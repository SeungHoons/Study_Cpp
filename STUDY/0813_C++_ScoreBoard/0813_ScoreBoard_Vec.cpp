#include <iostream>
#include <vector>

using namespace std;


//����ǥ
//1. �Է�
//2. ���
//3. ����
//
//1 �Է�  �̸� �� �� ��
//2
//��ȣ	�̸�	��	��	��	��� ����
//3 ����


void printMenu()
{
	cout << " \n����ǥ ���� ���α׷��Դϴ�. \n1. �Է� \n2. ��� \n3. ����\n";

}

struct student
{
	int no;
	int kor;
	int eng;
	int math;
	char szName[256];
};

int main()
{
	vector<student*> st;
	//vector<student>* stp = &st;
	st.reserve(5);
	int input = 0;
	int stnum = 0;
	student* temp;


	//vector pointer
	//(*stp)[0].kor;


	while (true)
	{
		switch (input)
		{
		case 0:
			printMenu();
			cin >> input;
			break;
		case 1:
			cout << "�̸� ���� ���� ����\n";
			temp = new student;

			cin >> temp->szName >> temp->kor >> temp->eng >> temp->math;
			temp->no = stnum;


			st.push_back(temp);

			if (st.size() <= stnum)
				st.reserve(stnum + 5);
			stnum++;
			input = 0;
			break;

		case 2:
			cout << "��ȣ\t" << "�̸�\t" << "��\t" << "��\t" << "��\t" << "���\t" << "����\n";

			for (int i = 0; i < st.size(); i++)
			{
				cout << st[i]->no << "\t" << st[i]->szName << "\t" << st[i]->kor << "\t" << st[i]->eng << "\t" << st[i]->math << "\t"
					<< (st[i]->kor + st[i]->eng + st[i]->math) / 3 << "\t" << st[i]->kor + st[i]->eng + st[i]->math << "\n";
			}
			cout << "\n\n";

			input = 0;

			break;
		case 3:

			for (auto autoSt : st)
			{
				delete autoSt;
			}

			st.clear();

			
			return 0;
			break;
		default:
			break;
		}
	}






	return 0;
}