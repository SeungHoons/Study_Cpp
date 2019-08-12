#include <iostream>
#include "STUDENT3.h"
#include <string>
using namespace std;


int main()
{
	string str;
	char a[256];
	str.reserve(256);
	str = "dddaad";

	cout << str.find("d", 3) << endl;

	strcpy(a, str.c_str());
	cout << a;
	return 0;
}


//int main()
//{
//	STUDENT3 d(3);
//	d.Print();
//
//	STUDENT3::aaa = 10;			//스태틱 변수는 이런식으로 사용
//	
//
//	return 0;
//}