// 0807.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
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

int main()
{
	vector<student> st;
	vector<student>* stp = &st;
	st.reserve(5);
	int input = 0;
	int stnum = 0;
	student temp;


	//vector pointer
	(*stp)[0].kor;


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
				cout << st[i].no << "\t" << st[i].szName << "\t" << st[i].kor << "\t" << st[i].eng << "\t" << st[i].math << "\t"
					<< (st[i].kor + st[i].eng + st[i].math) / 3 << "\t" << st[i].kor + st[i].eng + st[i].math << "\n";
			}
			cout << "\n\n";

			input = 0;

			break;
		case 3:
			return 0;
			break;
		default:
			break;
		}
	}






	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
