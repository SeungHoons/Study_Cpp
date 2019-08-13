#include <iostream>
#include <vector>

using namespace std;


//성적표
//1. 입력
//2. 출력
//3. 종료
//
//1 입력  이름 국 영 수
//2
//번호	이름	국	영	수	평균 총점
//3 종료


void printMenu()
{
	cout << " \n성적표 관리 프로그램입니다. \n1. 입력 \n2. 출력 \n3. 종료\n";

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
			cout << "이름 국어 영어 수학\n";
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
			cout << "번호\t" << "이름\t" << "국\t" << "영\t" << "수\t" << "평균\t" << "총점\n";

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