#pragma once	//헤더 중복 인클루드를 막아주는 기능 비표준
#include <iostream>
using namespace std;




class POINT
{
public:
	int x;
	int y;

	void AddPoint(POINT ptOther)
	{
		x += ptOther.x;
		y += ptOther.y;
	}

};


// 짧은 겟셋함수 같은경우 인라인을 앞에 붙혀주면 속도 향상에 도움이 된다.



class STUDENT3
{

private:
protected:
public:
	static int aaa;
	int no;
	char *pOut;

public:
	STUDENT3(int _no);

	STUDENT3(const STUDENT3& other);

	~STUDENT3();
	void Print();
};

