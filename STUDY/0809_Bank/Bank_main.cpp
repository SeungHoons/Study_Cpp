#include <iostream>
#include <vector>

using namespace std;

struct student
{
	int no;
	char szName[256];
	int kor;
	int eng;
	int math;
};


//����ǥ
//1. �Է�
//2. ���
//3. ����
//
//1 �Է�  �̸� �� �� ��
//2
//��ȣ	�̸�	��	��	��	��� ����
//3 ����

//1. �Է�
//2. ���
//3. ����
//4. ����


void printMenu()
{
	cout << " \n����ǥ ���� ���α׷��Դϴ�. \n1. �Է� \n2. ��� \n3. ����\n4. ����\n";

}

int main()
{
	vector<student> st;
	//vector<student>* stp = &st;
	st.reserve(5);
	int input = 0;
	int stnum = 1;
	student temp;

	FILE* p;
	p = fopen("School.txt", "r");

	int test1;
	char test2[20];
	
	if (p != nullptr)
	{
		while (p==EOF)
		{
			fscanf(p, "%d %s %d %d %d", &temp.no, &temp.szName, &temp.kor, &temp.eng, &temp.math);
			st.push_back(temp);
			stnum++;
		}
	}

	//fscanf(p, "")

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
			cin >> temp.szName >> temp.kor >> temp.eng >> temp.math;
			temp.no = stnum;

			p = fopen("School.txt", "w");
			for (int i = 0; i < st.size(); i++)
			{
				fprintf(p, "%d %s %d %d %d\n", st[i].no, st[i].szName, st[i].kor, st[i].eng, st[i].math);
			}

			//st.push_back(temp);

			//if (st.size() <= stnum)
			//	st.reserve(stnum + 5);
			stnum++;
			input = 0;
			break;

			
		case 2:
			cout << "��ȣ\t" << "�̸�\t" << "��\t" << "��\t" << "��\t" << "���\t" << "����\n";

			for (int i = 0; i < st.size(); i++)
			{
				cout << st[i].no << "\t" << st[i].szName << "\t" << st[i].kor << "\t" << st[i].eng << "\t" << st[i].math << "\t"
					<< (st[i].kor + st[i].eng + st[i].math) / 3 << "\t" << st[i].kor + st[i].eng + st[i].math << "\n";
			}
			cout << "\n\n";

			input = 0;

			break;

		case 3:

			/*for (int i = 0; i < st.size(); i++)
			{
				fprintf(p, "%d %s %d %d %d\n", st[i].no, st[i].szName, st[i].kor, st[i].eng, st[i].math);
			}*/
			input = 0;
			break;
		case 4:
			return 0;
			break;
		default:
			break;
		}
	}



	fclose(p);


	return 0;
}