#pragma once	//��� �ߺ� ��Ŭ��带 �����ִ� ��� ��ǥ��
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


// ª�� �ټ��Լ� ������� �ζ����� �տ� �����ָ� �ӵ� ��� ������ �ȴ�.



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

