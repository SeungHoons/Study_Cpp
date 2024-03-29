// 0807_Pointer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

using namespace std;

int My_strlen(const char* szSource)
{
	int count = 0;

	while (true)
	{
		if (szSource[count] == NULL)
			break;
		count++;
	}
	return count;
}
const char* My_strstr(const char* mainstr, const char* sub)
{
	int index = 0;
	int subIndex = 0;

	while (true)
	{
		if (mainstr[index] == sub[0])
		{
			while (true)
			{
				if (sub[subIndex] != NULL)
				{
					if (mainstr[index + subIndex] == sub[subIndex])
					{
						subIndex++;
						continue;
					}
					else
					{
						subIndex = 0;
						break;
					}
				}
				else if (sub[subIndex] == NULL)
				{
					return &mainstr[index];
				}

			}
		}
		index++;
		if (mainstr[index] == NULL)
		{
			return mainstr;
		}
	}
}

void My_strcpy(char* szDest, const char* szSource)
{
	int index = 0;
	while (true)
	{
		szDest[index] = szSource[index];
		index++;

		if (szSource[index] == NULL)
		{
			szDest[index] = NULL;
			break;
		}
	}
}
int main()
{
	char arr[256] = "fdsafsafa";


	//My_strcpy(arr, "ccccc");
	cout << arr << endl;

	cout << My_strstr(arr, "af") << endl;

	//char szHello[256] = "JHeasddsds";

	//cout << &szHello[0] << endl;
	//cout << &szHello << endl;
	//cout << szHello << endl;


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
