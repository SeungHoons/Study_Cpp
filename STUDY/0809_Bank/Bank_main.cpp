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


//성적표
//1. 입력
//2. 출력
//3. 종료
//
//1 입력  이름 국 영 수
//2
//번호	이름	국	영	수	평균 총점
//3 종료

//1. 입력
//2. 출력
//3. 저장
//4. 종료


void printMenu()
{
	cout << " \n성적표 관리 프로그램입니다. \n1. 입력 \n2. 출력 \n3. 저장\n4. 종료\n";

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
			cout << "이름 국어 영어 수학\n";
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
			cout << "번호\t" << "이름\t" << "국\t" << "영\t" << "수\t" << "평균\t" << "총점\n";

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